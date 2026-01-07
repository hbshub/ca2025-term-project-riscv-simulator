#include "ext.h"
#include "riscv_exec.h"
#include "pie-rv32i-decoder.h"
#include "pie-rv32i-field-decoder.h"

enum { 
    SYSCALL_WRITE = 64,
    SYSCALL_READ = 63,
    SYSCALL_EXIT = 93 
};
enum { 
    STDOUT = 1,
    STDERR = 2 
};

vm_step_result_t ecall_handler(cpu_t *cpu) {
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
            fatal("Unknown syscall: %d\n", syscall_nr);
    }
}

static vm_step_result_t pie_rv32i_exec(cpu_t *cpu, rv32i_instruction inst_id, uint32_t raw, uint32_t pc) {
    // pie decoder method
    rv32i_instruction inst_type = rv32i_decode(&raw);

    // I, M pc increment
    cpu->pc = pc + 4;

    // pie decode fields
    unsigned int rd, rs1, rs2;
    unsigned int raw_imm;      // for I/U/J type
    unsigned int immhi, immlo; // for S/B type
    unsigned int shamt;        // for Shift instructions
    int32_t imm;               // for the sign-extended immediate

    switch (inst_type) {
    
        /* === R-Type (Register-Register) === */
        case RV32I_ADD:
            rv32i_add_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = cpu->regs[rs1] + cpu->regs[rs2];
            break;
        case RV32I_SUB:
            rv32i_sub_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = (int32_t)cpu->regs[rs1] - (int32_t)cpu->regs[rs2];
            break;
        case RV32I_XOR:
            rv32i_xor_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = cpu->regs[rs1] ^ cpu->regs[rs2];
            break;
        case RV32I_OR:
            rv32i_or_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = cpu->regs[rs1] | cpu->regs[rs2];
            break;
        case RV32I_AND:
            rv32i_and_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = cpu->regs[rs1] & cpu->regs[rs2];
            break;
        case RV32I_SLL:
            rv32i_sll_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = cpu->regs[rs1] << (cpu->regs[rs2] & 0x1F);
            break;
        case RV32I_SRL:
            rv32i_srl_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = (uint32_t)cpu->regs[rs1] >> (cpu->regs[rs2] & 0x1F);
            break;
        case RV32I_SRA:
            rv32i_sra_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = (int32_t)cpu->regs[rs1] >> (cpu->regs[rs2] & 0x1F);
            break;
        case RV32I_SLT:
            rv32i_slt_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = ((int32_t)cpu->regs[rs1] < (int32_t)cpu->regs[rs2]) ? 1 : 0;
            break;
        case RV32I_SLTU:
            rv32i_sltu_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = (cpu->regs[rs1] < cpu->regs[rs2]) ? 1 : 0;
            break;

        /* === I-Type (Register-Immediate) === */
        case RV32I_ADDI:
            rv32i_addi_decode_fields(&raw, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = cpu->regs[rs1] + pie_i_imm(raw_imm);
            break;
        case RV32I_XORI:
            rv32i_xori_decode_fields(&raw, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = cpu->regs[rs1] ^ pie_i_imm(raw_imm);
            break;
        case RV32I_ORI:
            rv32i_ori_decode_fields(&raw, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = cpu->regs[rs1] | pie_i_imm(raw_imm);
            break;
        case RV32I_ANDI:
            rv32i_andi_decode_fields(&raw, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = cpu->regs[rs1] & pie_i_imm(raw_imm);
            break;
        case RV32I_SLTI:
            rv32i_slti_decode_fields(&raw, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = ((int32_t)cpu->regs[rs1] < pie_i_imm(raw_imm)) ? 1 : 0;
            break;
        case RV32I_SLTIU:
            rv32i_sltiu_decode_fields(&raw, &rd, &rs1, &raw_imm);
            cpu->regs[rd] = ((uint32_t)cpu->regs[rs1] < (uint32_t)pie_i_imm(raw_imm)) ? 1 : 0;
            break;
        
        // Shift Immediate 比較特殊，有 shamt 欄位
        case RV32I_SLLI:
            rv32i_slli_decode_fields(&raw, &rd, &rs1, &shamt);
            cpu->regs[rd] = cpu->regs[rs1] << shamt;
            break;
        case RV32I_SRLI:
            rv32i_srli_decode_fields(&raw, &rd, &rs1, &shamt);
            cpu->regs[rd] = (uint32_t)cpu->regs[rs1] >> shamt;
            break;
        case RV32I_SRAI:
            rv32i_srai_decode_fields(&raw, &rd, &rs1, &shamt);
            cpu->regs[rd] = (int32_t)cpu->regs[rs1] >> shamt;
            break;

        /* === Load Instructions === */
        case RV32I_LB:
        case RV32I_LH:
        case RV32I_LW:
        case RV32I_LBU:
        case RV32I_LHU: {

            rv32i_lw_decode_fields(&raw, &rd, &rs1, &raw_imm);
            
            uint32_t addr = cpu->regs[rs1] + pie_i_imm(raw_imm);
            switch (inst_type) {
                case RV32I_LB:
                    cpu->regs[rd] = (int8_t)cpu_load(cpu, addr, 8); break;
                case RV32I_LBU:
                    cpu->regs[rd] = (uint8_t)cpu_load(cpu, addr, 8); break;
                case RV32I_LH:
                    if (addr & 1) fatal("Unaligned LOAD (LH): 0x%x\n", addr);
                    cpu->regs[rd] = (int16_t)cpu_load(cpu, addr, 16); break;
                case RV32I_LHU:
                    if (addr & 1) fatal("Unaligned LOAD (LHU): 0x%x\n", addr);
                    cpu->regs[rd] = (uint16_t)cpu_load(cpu, addr, 16); break;
                case RV32I_LW:
                    if (addr & 3) fatal("Unaligned LOAD (LW): 0x%x\n", addr);
                    cpu->regs[rd] = (int32_t)cpu_load(cpu, addr, 32); break;
                default: break;
            }
            break;
        }

        /* === Store Instructions (S-Type) === */
        case RV32I_SB:
        case RV32I_SH:
        case RV32I_SW: {

            rv32i_sw_decode_fields(&raw, &rs2, &rs1, &immhi, &immlo);

            uint32_t addr = cpu->regs[rs1] + pie_s_imm(immhi, immlo);
            switch (inst_type) {
                case RV32I_SB:
                    cpu_store(cpu, addr, 8, cpu->regs[rs2] & 0xFF); break;
                case RV32I_SH:
                    if (addr & 1) fatal("Unaligned STORE (SH): 0x%x\n", addr);
                    cpu_store(cpu, addr, 16, cpu->regs[rs2] & 0xFFFF); break;
                case RV32I_SW:
                    if (addr & 3) fatal("Unaligned STORE (SW): 0x%x\n", addr);
                    cpu_store(cpu, addr, 32, cpu->regs[rs2]); break;
                default: break;
            }
            break;
        }

        /* === Branch Instructions (B-Type) === */
        case RV32I_BEQ:
        case RV32I_BNE:
        case RV32I_BLT:
        case RV32I_BGE:
        case RV32I_BLTU:
        case RV32I_BGEU: {

            rv32i_beq_decode_fields(&raw, &rs1, &rs2, &immhi, &immlo);
            
            imm = pie_b_imm(immhi, immlo);
            uint32_t target_pc = pc + imm;
            bool take_branch = false;

            switch (inst_type) {
                case RV32I_BEQ:  take_branch = (cpu->regs[rs1] == cpu->regs[rs2]); break;
                case RV32I_BNE:  take_branch = (cpu->regs[rs1] != cpu->regs[rs2]); break;
                case RV32I_BLT:  take_branch = ((int32_t)cpu->regs[rs1] < (int32_t)cpu->regs[rs2]); break;
                case RV32I_BGE:  take_branch = ((int32_t)cpu->regs[rs1] >= (int32_t)cpu->regs[rs2]); break;
                case RV32I_BLTU: take_branch = (cpu->regs[rs1] < cpu->regs[rs2]); break;
                case RV32I_BGEU: take_branch = (cpu->regs[rs1] >= cpu->regs[rs2]); break;
                default: break;
            }

            if (take_branch) cpu->pc = target_pc;
            break;
        }

        /* === U-Type Instructions === */
        case RV32I_LUI:
        case RV32I_AUIPC: {
            
            rv32i_lui_decode_fields(&raw, &rd, &raw_imm);
            int32_t imm = pie_u_imm(raw_imm);

            if (inst_type == RV32I_LUI) { // LUI
                cpu->regs[rd] = imm;
            }
            else { // AUIPC
                cpu->regs[rd] = pc + imm;
            }
            break;
        }

        /* === Jump Instructions === */
        case RV32I_JAL: { // J-Type
            rv32i_jal_decode_fields(&raw, &rd, &raw_imm);
            cpu->regs[rd] = pc + 4;
            cpu->pc = pc + pie_j_imm(raw_imm);
            break;
        }
        case RV32I_JALR: { // I-Type style immediate
            rv32i_jalr_decode_fields(&raw, &rd, &rs1, &raw_imm);
            uint32_t target = (cpu->regs[rs1] + pie_i_imm(raw_imm)) & ~1;
            if (rd != 0) cpu->regs[rd] = pc + 4;
            cpu->pc = target;
            break;
        }

        /* === System Instructions === */
        case RV32I_ECALL: {
            vm_step_result_t result = ecall_handler(cpu);
            if (result != VM_STEP_RESULT_OK) return result;
            break;
        }

        case RV32I_EBREAK:
            return VM_STEP_RESULT_HALT;

        case RV32I_FENCE:
            // No-op
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
    .start_id = RV32I_LUI,
    .end_id = RV32I_EBREAK,
    .exec = pie_rv32i_exec
};