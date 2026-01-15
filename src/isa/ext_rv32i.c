#include "ext.h"
#include "riscv_exec.h"
#include "riscv_utils.h"
#include "pie-rv32imc-decoder.h"
#include "pie-rv32imc-field-decoder.h"

/* =========================================================================
 * Pie Decoder Adapters
 * Used to reconstruct raw fragments from pie-*-field-decoder into signed 32-bit
 * ========================================================================= */

/*
 * I-Type: Sign-extend 12-bit raw value
 */
static inline int32_t pie_i_imm(uint32_t raw_imm) {
    int32_t imm = (int32_t)raw_imm;
    return (imm << 20) >> 20; 
}

/*
 * S-Type: Combine high/low chunks and sign-extend
 */
static inline int32_t pie_s_imm(uint32_t immhi, uint32_t immlo) {
    int32_t imm = (int32_t)((immhi << 5) | immlo);
    return (imm << 20) >> 20;
}

/*
 * B-Type: Shuffle bits and sign-extend
 * immhi contains bits 12|10:5
 * immlo contains bits 4:1|11
 */
static inline int32_t pie_b_imm(uint32_t immhi, uint32_t immlo) {
    uint32_t bit_12   = (immhi >> 6) & 0x1;
    uint32_t bit_10_5 = immhi & 0x3F;
    uint32_t bit_4_1  = (immlo >> 1) & 0xF;
    uint32_t bit_11   = immlo & 0x1;
    
    int32_t imm = (int32_t)((bit_12 << 12) | (bit_11 << 11) | (bit_10_5 << 5) | (bit_4_1 << 1));
    return (imm << 19) >> 19;
}

/*
 * U-Type: Shift 20-bit raw value back to upper position
 */
static inline int32_t pie_u_imm(uint32_t raw_imm) {
    return (int32_t)(raw_imm << 12);
}

/*
 * J-Type: Shuffle bits from the raw 20-bit extraction
 * raw_chunk is inst[31:12]
 */
static inline int32_t pie_j_imm(uint32_t raw_chunk) {
    uint32_t imm_20    = (raw_chunk >> 19) & 0x1;
    uint32_t imm_10_1  = (raw_chunk >> 9) & 0x3FF;
    uint32_t imm_11    = (raw_chunk >> 8) & 0x1;
    uint32_t imm_19_12 = raw_chunk & 0xFF;
    
    int32_t imm = (int32_t)((imm_20 << 20) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1));
    return (imm << 11) >> 11;
}

enum { 
    SYSCALL_WRITE = 64,
    SYSCALL_READ = 63,
    SYSCALL_EXIT = 93 
};
enum { 
    STDOUT = 1,
    STDERR = 2 
};

vm_step_result_t ecall_handler(cpu_t *cpu, uint32_t raw, uint32_t pc) {
    uint32_t syscall_nr = cpu->regs[17];
    switch (syscall_nr) {
        case SYSCALL_WRITE: {
            uint32_t fd     = cpu->regs[10];
            uint32_t addr   = cpu->regs[11];
            uint32_t count  = cpu->regs[12];
            
            FILE *stream = (fd == STDOUT) ? stdout : (fd == STDERR) ? stderr : NULL;
            if (!stream) fatal("Invalid file descriptor: %d\n", fd);
            for (uint32_t i = 0; i < count; i++) {
                fprintf(stream, "%c", cpu_load(cpu, addr + i, 8));
            }
            // RISC-V Linux ABI returns number of bytes written in a0
            cpu->regs[10] = count;
            printf("\n");
            return VM_STEP_RESULT_OK;
        }
        case SYSCALL_READ: {
            uint32_t fd     = cpu->regs[10];
            uint32_t addr   = cpu->regs[11];
            uint32_t count  = cpu->regs[12];

            if (fd != 0) fatal("Invalid fd for read: %d\n", fd);

            for (uint32_t i = 0; i < count; i++) {
                int c = fgetc(stdin);
                if (c == '\n') {
                    cpu->regs[10] = i;
                    return VM_STEP_RESULT_OK;
                }
                cpu_store(cpu, addr + i, 8, (uint8_t)c);
            }
            cpu->regs[10] = count;
            return VM_STEP_RESULT_OK;
        }
        case SYSCALL_EXIT: {
            int32_t exit_code = cpu->regs[10];
            printf("Program exited with code: %d\n", exit_code);
            return VM_STEP_RESULT_HALT;
        }
        default:
            // 1. Record the location of the incident (current PC, not the next instruction)
            cpu->mepc = pc; 
            // 2. Record the cause of the incident (11 = Environment call from M-mode)
            cpu->mcause = 11; 
            // 3. Jump to mtvec (Trap Vector)
            // Mask out the last two bits (Mode bits), only take Base Address
            cpu->pc = cpu->mtvec & ~0x3;
            return VM_STEP_RESULT_OK;
            fatal("Unknown syscall: %d\n, 0x%08x", syscall_nr, raw);
    }
}

static vm_step_result_t pie_rv32i_exec(cpu_t *cpu, rv32imc_instruction inst_id, uint32_t raw, uint32_t pc) {

    uint16_t *raw16_ptr = (uint16_t*)&raw;
    // I, M pc increment
    cpu->pc = pc + 4;

    // pie decode fields
    unsigned int rd, rs1, rs2;
    unsigned int raw_imm;      // for I/U/J type
    unsigned int immhi, immlo; // for S/B type
    unsigned int shamt;        // for Shift instructions
    unsigned int csr;

    switch (inst_id) {
    
        /* === R-Type (Register-Register) === */
        case RV32IMC_ADD:
            rv32imc_add_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_add(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_SUB:
            rv32imc_sub_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_sub(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_XOR:
            rv32imc_xor_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_xor(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_OR:
            rv32imc_or_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_or(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_AND:
            rv32imc_and_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_and(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_SLL:
            rv32imc_sll_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_sll(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_SRL:
            rv32imc_srl_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_srl(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        case RV32IMC_SRA:
            rv32imc_sra_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            utils_exec_sra(cpu, rd, rs1, cpu->regs[rs2]);
            break;
        // I extension only
        case RV32IMC_SLT:
            rv32imc_slt_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            cpu->regs[rd] = ((int32_t)cpu->regs[rs1] < (int32_t)cpu->regs[rs2]) ? 1 : 0;
            break;
        case RV32IMC_SLTU:
            rv32imc_sltu_decode_fields(raw16_ptr, &rd, &rs1, &rs2);
            cpu->regs[rd] = (cpu->regs[rs1] < cpu->regs[rs2]) ? 1 : 0;
            break;

        /* === I-Type (Register-Immediate) === */
        case RV32IMC_ADDI: {
            rv32imc_addi_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            utils_exec_add(cpu, rd, rs1, pie_i_imm(raw_imm));
            break;
        }
        case RV32IMC_XORI:
            rv32imc_xori_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            utils_exec_xor(cpu, rd, rs1, pie_i_imm(raw_imm));
            break;
        case RV32IMC_ORI:
            rv32imc_ori_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            utils_exec_or(cpu, rd, rs1, pie_i_imm(raw_imm));
            break;
        case RV32IMC_ANDI:
            rv32imc_andi_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            utils_exec_and(cpu, rd, rs1, pie_i_imm(raw_imm));
            break;
        // I extension only
        case RV32IMC_SLTI:
            rv32imc_slti_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = ((int32_t)cpu->regs[rs1] < pie_i_imm(raw_imm)) ? 1 : 0;
            break;
        case RV32IMC_SLTIU:
            rv32imc_sltiu_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = ((uint32_t)cpu->regs[rs1] < (uint32_t)pie_i_imm(raw_imm)) ? 1 : 0;
            break;
        
        // Shift Immediate
        case RV32IMC_SLLI:
            rv32imc_slli_decode_fields(raw16_ptr, &rd, &rs1, &shamt);
            utils_exec_sll(cpu, rd, rs1, shamt);
            break;
        case RV32IMC_SRLI:
            rv32imc_srli_decode_fields(raw16_ptr, &rd, &rs1, &shamt);
            utils_exec_srl(cpu, rd, rs1, shamt);
            break;
        case RV32IMC_SRAI:
            rv32imc_srai_decode_fields(raw16_ptr, &rd, &rs1, &shamt);
            utils_exec_sra(cpu, rd, rs1, shamt);
            break;

        /* === Load Instructions === */
        case RV32IMC_LB:
        case RV32IMC_LH:
        case RV32IMC_LW:
        case RV32IMC_LBU:
        case RV32IMC_LHU: {
            rv32imc_lw_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            
            uint32_t addr = cpu->regs[rs1] + pie_i_imm(raw_imm);
            switch (inst_id) {
                case RV32IMC_LB:
                    cpu->regs[rd] = (int8_t)cpu_load(cpu, addr, 8); break;
                case RV32IMC_LBU:
                    cpu->regs[rd] = (uint8_t)cpu_load(cpu, addr, 8); break;
                case RV32IMC_LH:
                    if (addr & 1) fatal("Unaligned LOAD (LH): 0x%x\n", addr);
                    cpu->regs[rd] = (int16_t)cpu_load(cpu, addr, 16); break;
                case RV32IMC_LHU:
                    if (addr & 1) fatal("Unaligned LOAD (LHU): 0x%x\n", addr);
                    cpu->regs[rd] = (uint16_t)cpu_load(cpu, addr, 16); break;
                case RV32IMC_LW:
                    if (addr & 3) fatal("Unaligned LOAD (LW): 0x%x\n", addr);
                    utils_exec_lw(cpu, rd, rs1, pie_i_imm(raw_imm));
                    break;
                default: break;
            }
            break;
        }

        /* === Store Instructions (S-Type) === */
        case RV32IMC_SB:
        case RV32IMC_SH:
        case RV32IMC_SW: {

            rv32imc_sw_decode_fields(raw16_ptr, &rs2, &rs1, &immhi, &immlo);
            uint32_t addr = cpu->regs[rs1] + pie_s_imm(immhi, immlo);
            switch (inst_id) {
                case RV32IMC_SB:
                    cpu_store(cpu, addr, 8, cpu->regs[rs2] & 0xFF); break;
                case RV32IMC_SH:
                    if (addr & 1) fatal("Unaligned STORE (SH): 0x%x\n", addr);
                    cpu_store(cpu, addr, 16, cpu->regs[rs2] & 0xFFFF); break;
                case RV32IMC_SW:
                    if (addr & 3) fatal("Unaligned STORE (SW): 0x%x\n", addr);
                    utils_exec_sw(cpu, rs2, rs1, pie_s_imm(immhi, immlo));
                    break;
                default: break;
            }
            break;
        }

        /* === Branch Instructions (B-Type) === */
        case RV32IMC_BEQ:
        case RV32IMC_BNE:
        case RV32IMC_BLT:
        case RV32IMC_BGE:
        case RV32IMC_BLTU:
        case RV32IMC_BGEU: {

            rv32imc_beq_decode_fields(raw16_ptr, &rs1, &rs2, &immhi, &immlo);
            
            uint32_t target_pc = pc + pie_b_imm(immhi, immlo);
            bool take_branch = false;

            switch (inst_id) {
                case RV32IMC_BEQ:  take_branch = utils_exec_beq(cpu, rs1, rs2); break;
                case RV32IMC_BNE:  take_branch = utils_exec_bne(cpu, rs1, rs2); break;
                case RV32IMC_BLT:  take_branch = ((int32_t)cpu->regs[rs1] < (int32_t)cpu->regs[rs2]); break;
                case RV32IMC_BGE:  take_branch = ((int32_t)cpu->regs[rs1] >= (int32_t)cpu->regs[rs2]); break;
                case RV32IMC_BLTU: take_branch = (cpu->regs[rs1] < cpu->regs[rs2]); break;
                case RV32IMC_BGEU: take_branch = (cpu->regs[rs1] >= cpu->regs[rs2]); break;
                default: break;
            }

            if (take_branch) cpu->pc = target_pc;
            break;
        }

        /* === U-Type Instructions === */
        case RV32IMC_LUI:
            rv32imc_lui_decode_fields(raw16_ptr, &rd, &raw_imm);
            utils_exec_lui(cpu, rd, pie_u_imm(raw_imm));
            break;
        // I extension only
        case RV32IMC_AUIPC:
            rv32imc_auipc_decode_fields(raw16_ptr, &rd, &raw_imm);
            cpu->regs[rd] = pc + pie_u_imm(raw_imm);
            break;
        
        /* === Jump Instructions === */
        case RV32IMC_JAL: { // J-Type
            rv32imc_jal_decode_fields(raw16_ptr, &rd, &raw_imm);
            uint32_t target_addr = pc + pie_j_imm(raw_imm);
            utils_exec_jump_link(cpu, rd, pc+4, target_addr);
            break;
        }
        case RV32IMC_JALR: { // I-Type style immediate
            rv32imc_jalr_decode_fields(raw16_ptr, &rd, &rs1, &raw_imm);
            uint32_t target_addr = (cpu->regs[rs1] + pie_i_imm(raw_imm)) & ~1;
            utils_exec_jump_link(cpu, rd, pc+4, target_addr);
            break;
        }

        /* === System Instructions === */
        case RV32IMC_ECALL: {
            vm_step_result_t result = ecall_handler(cpu, raw, pc);
            if (result != VM_STEP_RESULT_OK) return result;
            break;
        }

        case RV32IMC_EBREAK:
            return VM_STEP_RESULT_HALT;

        case RV32IMC_FENCE:
            // No-op
            break;

        case RV32IMC_CSRRW: {
            rv32imc_csrrw_decode_fields(raw16_ptr, &rd, &csr, &rs1);
            uint32_t old_val = 0;
            // read old value
            if (csr == 0x340) old_val = cpu->mscratch;
            else if (csr == 0x305) old_val = cpu->mtvec;
            else if (csr == 0x341) old_val = cpu->mepc;
            else if (csr == 0x342) old_val = cpu->mcause;

            // write new value
            uint32_t new_val = cpu->regs[rs1];
            if (csr == 0x340) cpu->mscratch = new_val;
            else if (csr == 0x305) cpu->mtvec = new_val;
            else if (csr == 0x341) cpu->mepc = new_val;
            else if (csr == 0x342) cpu->mcause = new_val;

            if (rd != 0) cpu->regs[rd] = old_val;
            break;
        }
        case RV32IMC_CSRRS: {
            rv32imc_csrrs_decode_fields(raw16_ptr, &rd, &csr, &rs1);
            uint32_t old_val = 0;
            if (csr == 0x340) old_val = cpu->mscratch;
            else if (csr == 0x305) old_val = cpu->mtvec;
            else if (csr == 0x341) old_val = cpu->mepc;
            else if (csr == 0x342) old_val = cpu->mcause;

            // Only write when rs1 != 0 (Bitwise OR)
            if (rs1 != 0) {
                uint32_t mask = cpu->regs[rs1];
                if (csr == 0x340) cpu->mscratch |= mask;
                else if (csr == 0x305) cpu->mtvec |= mask;
                else if (csr == 0x341) cpu->mepc |= mask;
                else if (csr == 0x342) cpu->mcause |= mask;
            }

            if (rd != 0) cpu->regs[rd] = old_val;
            break;
        }
        case RV32IMC_MRET:
            cpu->pc = cpu->mepc;
            break;

        default:
            fatal("Illegal Instruction 0x%x at PC 0x%x\n", raw, pc);
            break;
    }
    cpu->regs[0] = 0; // x0 is always zero
    return VM_STEP_RESULT_OK;
}

const ext_t ext_rv32i = {
    .name = "RV32I",
    .start_id = RV32IMC_LUI,
    .end_id = RV32IMC_CSRRCI,
    .exec = pie_rv32i_exec
};