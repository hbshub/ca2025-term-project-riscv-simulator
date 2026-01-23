#include "ext.h"
#include "riscv_exec.h"
#include "riscv_utils.h"
#include "pie-rv32imc-decoder.h"
#include "pie-rv32imc-field-decoder.h"

#define RVC_MAP(reg) ((reg) + 8)

// Format: CIW
// Inst:   C.ADDI4SPN
// Type:   Zero-extended immediate
static inline int32_t pie_ciw_addi4spn_imm(uint32_t nzuimm) {
    // nzuimm: inst[12:5] -> imm[9:2]
    uint32_t imm = 0;
    imm |= ((nzuimm >> 2) & 0xF) << 6; // inst[10:7]  -> imm[9:6]
    imm |= ((nzuimm >> 6) & 0x3) << 4; // inst[12:11] -> imm[5:4]
    imm |= ((nzuimm >> 0) & 0x1) << 3; // inst[5]     -> imm[3]
    imm |= ((nzuimm >> 1) & 0x1) << 2; // inst[6]     -> imm[2]
    return (int32_t)imm;
}

// Format: CI (Special)
// Inst:   C.ADDI16SP
// Type:   Sign-extended, scaled immediate
static inline int32_t pie_ci_addi16sp_imm(uint32_t nzimmhi, uint32_t nzimmlo) {
    // nzimmhi: inst[12]  -> imm[9]
    // nzimmlo: inst[6:2]  -> imm[4|6|8:7|5]
    uint32_t imm = 0;
    imm |= (nzimmhi & 0x1)  << 9; // inst[12]   -> imm[9]
    imm |= (nzimmlo & 0x6)  << 6; // inst[4:3]  -> imm[8:7]
    imm |= (nzimmlo & 0x8)  << 3; // inst[5]    -> imm[6]
    imm |= (nzimmlo & 0x1)  << 5; // inst[2]    -> imm[5]
    imm |= (nzimmlo & 0x10);      // inst[6]    -> imm[4]
    return ((int32_t)(imm << 22)) >> 22; // sign-extend to 32 bits
}

// Format: CI
// Inst:   C.ADDI, C.LI, C.ANDI (Note: C.ANDI is CB format but shares imm logic)
// Type:   Sign-extended 6-bit immediate
static inline int32_t pie_ci_signed_imm(uint32_t nzimmhi, uint32_t nzimmlo) {
    // immhi: inst[12]   -> imm[5]
    // immlo: inst[6:2]  -> imm[4:0]
    uint32_t val = (nzimmhi << 5) | nzimmlo;
    return ((int32_t)(val << 26)) >> 26; // sign-extend to 32 bits
}

// Format: CI / CB
// Inst:   C.SRLI, C.SRAI (CB), C.SLLI (CI)
// Type:   Zero-extended 6-bit immediate (Shamt)
static inline int32_t pie_ci_shamt_imm(uint32_t nzimmhi, uint32_t nzimmlo) {
    // immhi: inst[12]   -> imm[5]
    // immlo: inst[6:2]  -> imm[4:0]
    uint32_t val = (nzimmhi << 5) | nzimmlo;
    return (int32_t)val;
}

// Format: CI (Special)
// Inst:   C.LUI
// Type:   Sign-extended, shifted left by 12
static inline int32_t pie_ci_lui_imm(uint32_t nzimmhi, uint32_t nzimmlo) {
    // immhi: inst[12]  -> imm[17]
    // immlo: inst[6:2]  -> imm[16:12]
    uint32_t val = (nzimmhi << 5) | nzimmlo;
    return (((int32_t)(val << 26)) >> 26) << 12; // sign-extend then shift
}

// Format: CI (Special)
// Inst:   C.LWSP
// Type:   Zero-extended, scaled immediate
static inline int32_t pie_ci_lwsp_imm(uint32_t uimmhi, uint32_t uimmlo) {
    // uimmhi: inst[12] -> imm[5]
    // uimmlo: inst[6:2]  -> imm[4:2|7:6]
    uint32_t imm = 0;
    imm |= (uimmlo & 0x3) << 6;     // inst[3:2]  -> imm[7:6]
    imm |= (uimmhi & 0x1) << 5;     // inst[12]   -> imm[5]
    imm |= (uimmlo & 0x1C);         // inst[6:4]  -> imm[4:2]
    return (int32_t)imm;
}

// Format: CL / CS
// Inst:   C.LW, C.SW
// Type:   Zero-extended word offset
static inline int32_t pie_cl_cs_offset_imm(uint32_t uimmhi, uint32_t uimmlo) {
    // uimmhi: inst[12:10] -> imm[5:3]
    // uimmlo: inst[6:5]  -> imm[2|6]
    uint32_t imm = 0;
    imm |= (uimmlo & 0x1) << 6; // inst[5]     -> imm[6]
    imm |= (uimmhi & 0x7) << 3; // inst[12:10] -> imm[5:3]
    imm |= (uimmlo & 0x2) << 1; // inst[6]     -> imm[2]
    return (int32_t)imm;
}

// Format: CSS
// Inst:   C.SWSP
// Type:   Zero-extended, scaled immediate
static inline int32_t pie_css_swsp_imm(uint32_t uimm) {
    // uimm: inst[12:7] -> imm[5:2|7:6]
    uint32_t imm = 0;
    imm |= (uimm & 0x03) << 6; // inst[8:7]  -> imm[7:6]
    imm |= (uimm & 0x3C);      // inst[12:9] -> imm[5:2]
    return (int32_t)imm;
}

// Format: CB
// Inst:   C.BEQZ, C.BNEZ
// Type:   Sign-extended branch offset
static inline int32_t pie_cb_branch_imm(uint32_t immhi, uint32_t immlo) {
    // immhi: inst[12:10] -> imm[8|4:3]
    // immlo: inst[6:2]   -> imm[7:6|2:1|5]
    uint32_t offset = 0;
    offset |= (immhi & 0x4) << 6;  // inst[12]    -> imm[8]
    offset |= (immlo & 0x18) << 3; // inst[6:5]   -> imm[7:6]
    offset |= (immlo & 0x1) << 5;  // inst[2]     -> imm[5]
    offset |= (immhi & 0x3) << 3;  // inst[11:10] -> imm[4:3]
    offset |= (immlo & 0x6);       // inst[4:3]   -> imm[2:1]
    return ((int32_t)(offset << 23)) >> 23; // Sign-extend 9-bit to 32-bit
}

// Format: CJ
// Inst:   C.J, C.JAL
// Type:   Sign-extended jump target
static inline int32_t pie_cj_jump_imm(uint32_t imm) {
    // imm: inst[12:2] -> imm[11|4|9:8|10|6|7|3:1|5]
    uint32_t offset = 0;
    offset |= (imm & 0x400) << 1;  // inst[12] -> imm[11]
    offset |= (imm & 0x040) << 4;  // inst[8]  -> imm[10]
    offset |= (imm & 0x180) << 1;  // inst[10:9]-> imm[9:8]
    offset |= (imm & 0x010) << 3;  // inst[6]  -> imm[7]
    offset |= (imm & 0x020) << 1;  // inst[7]  -> imm[6]
    offset |= (imm & 0x001) << 5;  // inst[2]  -> imm[5]
    offset |= (imm & 0x200) >> 5;  // inst[11] -> imm[4]
    offset |= (imm & 0x00E);       // inst[5:3]-> imm[3:1]
    return ((int32_t)(offset << 20)) >> 20; // Sign-extend 11-bit to 32-bit
}

static vm_step_result_t pie_rv32c_exec(cpu_t *cpu, rv32imc_instruction inst_id, uint32_t raw, uint32_t pc) {

    uint16_t raw16 = (uint16_t)raw;
    // C PC increment
    cpu->pc = pc + 2;

    // pie decode fields
    uint32_t rd, rs1, rs2, rs1_rd;
    uint32_t imm, uimm, nzuimm;
    uint32_t immhi, immlo, uimmhi, uimmlo;
    uint32_t nzimmhi, nzimmlo, nzuimmhi, nzuimmlo;
    // reconstruct and sign-extend immediate value
    int32_t real_imm;
    // target address for jumps/branches
    uint32_t target_addr;


    switch (inst_id) {

          /* 1: Stack & Constant Generation */
          case RV32IMC_C_ADDI4SPN: // addi rd, x2, imm
               rv32imc_c_addi4spn_decode_fields(&raw16, &rd, &nzuimm);
               real_imm = pie_ciw_addi4spn_imm(nzuimm);
               // rd = sp + imm, rd in [8,15]
               utils_exec_add(cpu, RVC_MAP(rd), 2, real_imm);
               break;
     
          case RV32IMC_C_ADDI16SP: // addi x2, x2, imm
               rv32imc_c_addi16sp_decode_fields(&raw16, &nzimmhi, &nzimmlo);
               real_imm = pie_ci_addi16sp_imm(nzimmhi, nzimmlo);
               // sp = sp + imm
               utils_exec_add(cpu, 2, 2, real_imm);
               break;

          case RV32IMC_C_ADDI: // addi rd, rd, imm
               rv32imc_c_addi_decode_fields(&raw16, &rs1_rd, &nzimmhi, &nzimmlo);
               real_imm = pie_ci_signed_imm(nzimmhi, nzimmlo);
               // rd = rd + imm
               utils_exec_add(cpu, rs1_rd, rs1_rd, real_imm);
               break;

          case RV32IMC_C_LI:   // rs1 = 0
               rv32imc_c_li_decode_fields(&raw16, &rd, &nzimmhi, &nzimmlo);
               real_imm = pie_ci_signed_imm(nzimmhi, nzimmlo);
               // rd = 0 + imm
               utils_exec_add(cpu, rd, 0, real_imm);
               break;

          case RV32IMC_C_LUI:  // rs1 = 0, rd != 0, 2
               rv32imc_c_lui_decode_fields(&raw16, &rd, &nzimmhi, &nzimmlo);
               real_imm = pie_ci_lui_imm(nzimmhi, nzimmlo);
               // rd = imm
               utils_exec_lui(cpu, rd, real_imm);
               break;

          /* 2: ALU Operations */
          case RV32IMC_C_SUB:
               rv32imc_c_sub_decode_fields(&raw16, &rs1_rd, &rs2);
               utils_exec_sub(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), cpu->regs[RVC_MAP(rs2)]);
               break;
          case RV32IMC_C_XOR:
               rv32imc_c_xor_decode_fields(&raw16, &rs1_rd, &rs2);
               utils_exec_xor(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), cpu->regs[RVC_MAP(rs2)]);
               break;
          case RV32IMC_C_OR:
               rv32imc_c_or_decode_fields(&raw16, &rs1_rd, &rs2);
               utils_exec_or(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), cpu->regs[RVC_MAP(rs2)]);
               break;
          case RV32IMC_C_AND:
               rv32imc_c_and_decode_fields(&raw16, &rs1_rd, &rs2);
               utils_exec_and(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), cpu->regs[RVC_MAP(rs2)]);
               break;
          case RV32IMC_C_ADD:
               rv32imc_c_add_decode_fields(&raw16, &rs1_rd, &rs2);
               utils_exec_add(cpu, rs1_rd, rs1_rd, cpu->regs[rs2]);
               break;
          case RV32IMC_C_MV: // mv rd, rs2 -> add rd, x0, rs2
               rv32imc_c_mv_decode_fields(&raw16, &rd, &rs2);
               utils_exec_add(cpu, rd, 0, cpu->regs[rs2]);
               break;
          case RV32IMC_C_ANDI:
               rv32imc_c_andi_decode_fields(&raw16, &rs1_rd, &immhi, &immlo);
               real_imm = pie_ci_signed_imm(immhi, immlo);
               utils_exec_and(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), real_imm);
               break;

          /* 3: Shifts */
          case RV32IMC_C_SLLI:
               rv32imc_c_slli_decode_fields(&raw16, &rs1_rd, &nzuimmhi, &nzuimmlo);
               real_imm = pie_ci_shamt_imm(nzuimmhi, nzuimmlo);
               utils_exec_sll(cpu, rs1_rd, rs1_rd, real_imm);
               break;
          case RV32IMC_C_SRLI:
               rv32imc_c_srli_decode_fields(&raw16, &rs1_rd, &nzuimmhi, &nzuimmlo);
               real_imm = pie_ci_shamt_imm(nzuimmhi, nzuimmlo);
               utils_exec_srl(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), real_imm);
               break;
          case RV32IMC_C_SRAI:
               rv32imc_c_srai_decode_fields(&raw16, &rs1_rd, &nzuimmhi, &nzuimmlo);
               real_imm = pie_ci_shamt_imm(nzuimmhi, nzuimmlo);
               utils_exec_sra(cpu, RVC_MAP(rs1_rd), RVC_MAP(rs1_rd), real_imm);
               break;

          /* 4: Memory (Loads / Stores) */
          case RV32IMC_C_LW:
               rv32imc_c_lw_decode_fields(&raw16, &rd, &rs1, &uimmhi, &uimmlo);
               real_imm = pie_cl_cs_offset_imm(uimmhi, uimmlo);
               utils_exec_lw(cpu, RVC_MAP(rd), RVC_MAP(rs1), real_imm);
               break;
          case RV32IMC_C_SW:
               rv32imc_c_sw_decode_fields(&raw16, &rs2, &rs1, &uimmhi, &uimmlo);
               real_imm = pie_cl_cs_offset_imm(uimmhi, uimmlo);
               utils_exec_sw(cpu, RVC_MAP(rs2), RVC_MAP(rs1), real_imm);
               break;
               
          case RV32IMC_C_LWSP: // lw rd, offset(sp) // rs1 is fixed to 2
               rv32imc_c_lwsp_decode_fields(&raw16, &rd, &uimmhi, &uimmlo);
               real_imm = pie_ci_lwsp_imm(uimmhi, uimmlo);
               utils_exec_lw(cpu, rd, 2, real_imm);
               break;
          case RV32IMC_C_SWSP: // sw rs2, offset(sp) // rs1 is fixed to 2
               rv32imc_c_swsp_decode_fields(&raw16, &rs2, &uimm);
               real_imm = pie_css_swsp_imm(uimm);
               utils_exec_sw(cpu, rs2, 2, real_imm);
               break;

          /* 5: Control Flow */
          case RV32IMC_C_J: // jal x0, imm
               rv32imc_c_j_decode_fields(&raw16, &imm);
               target_addr = pc + pie_cj_jump_imm(imm);
               utils_exec_jump_link(cpu, 0, pc+2, target_addr);
               break;
          case RV32IMC_C_JAL: // jal ra, imm
               rv32imc_c_jal_decode_fields(&raw16, &imm);
               target_addr = pc + pie_cj_jump_imm(imm);
               utils_exec_jump_link(cpu, 1, pc+2, target_addr);
               break;
               
          case RV32IMC_C_JR: // jalr x0, rs1, 0
               rv32imc_c_jr_decode_fields(&raw16, &rs1);
               target_addr = cpu->regs[rs1] & ~1;
               utils_exec_jump_link(cpu, 0, pc+2, target_addr);
               break;
          case RV32IMC_C_JALR: // jalr ra, rs1, 0
               rv32imc_c_jalr_decode_fields(&raw16, &rs1);
               target_addr = cpu->regs[rs1] & ~1;
               utils_exec_jump_link(cpu, 1, pc+2, target_addr);
               break;
               
          case RV32IMC_C_BEQZ: // beq rs1, x0, imm
               rv32imc_c_beqz_decode_fields(&raw16, &rs1, &immhi, &immlo);
               if (utils_exec_beq(cpu, RVC_MAP(rs1), 0)) {
                   target_addr = pc + pie_cb_branch_imm(immhi, immlo);
                   cpu->pc = target_addr;
               }
               break;
          case RV32IMC_C_BNEZ: // bne rs1, x0, imm
               rv32imc_c_bnez_decode_fields(&raw16, &rs1, &immhi, &immlo);
               if (!utils_exec_beq(cpu, RVC_MAP(rs1), 0)) {
                   target_addr = pc + pie_cb_branch_imm(immhi, immlo);
                   cpu->pc = target_addr;
               }
               break;

          /* 6: System / Misc */
          case RV32IMC_C_NOP:
               // do nothing
               break;
               
          case RV32IMC_C_EBREAK:
               // do nothing, halt execution
               return VM_STEP_RESULT_HALT;
          
          case RV32IMC_C_ILLEGAL:
               // illegal instruction
               fatal("C-ext Illegal Instruction 0x%x at PC 0x%x\n", raw, pc);
               break;

          default:
               break;
     }
     cpu->regs[0] = 0; // x0 is always zero
     return VM_STEP_RESULT_OK;
}

const ext_t ext_rv32c = {
    .name = "RV32C",
    .start_id = RV32IMC_C_ILLEGAL,
    .end_id = RV32IMC_C_SWSP,
    .exec = pie_rv32c_exec
};