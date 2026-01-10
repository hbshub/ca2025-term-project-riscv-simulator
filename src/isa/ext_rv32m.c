#include "ext.h"
#include "riscv_exec.h"
#include "pie-rv32im-decoder.h"
#include "pie-rv32im-field-decoder.h"

static vm_step_result_t pie_rv32m_exec(cpu_t *cpu, rv32im_instruction inst_id, uint32_t raw, uint32_t pc) {

    // I, M PC increment
    cpu->pc = pc + 4;

    // pie decode fields
    unsigned int rd, rs1, rs2;

    switch (inst_id) {
    
        /* === M-Type (Register-Register) === */
        /* multiply: rd = (rs1 * rs2)[31:0] */
        case RV32IM_MUL: {
            rv32im_mul_decode_fields(&raw, &rd, &rs1, &rs2);
            cpu->regs[rd] = cpu->regs[rs1] * cpu->regs[rs2];
            break;
        }

        /* multiply high (signed * signed): rd = (rs1 * rs2)[63:32] */
        case RV32IM_MULH: {
            rv32im_mulh_decode_fields(&raw, &rd, &rs1, &rs2);
            int64_t a = (int64_t)(int32_t)cpu->regs[rs1];
            int64_t b = (int64_t)(int32_t)cpu->regs[rs2];
            cpu->regs[rd] = (uint32_t)((a * b) >> 32);
            break;
        }

        /* multiply high (signed * unsigned): rd = (rs1 * rs2)[63:32] */
        case RV32IM_MULHSU: {
            rv32im_mulhsu_decode_fields(&raw, &rd, &rs1, &rs2);
            int64_t a = (int64_t)(int32_t)cpu->regs[rs1]; // Signed ext
            uint64_t b = (uint64_t)cpu->regs[rs2];        // Zero ext
            cpu->regs[rd] = (uint32_t)((a * b) >> 32);
            break;
        }

        /* multiply high (unsigned * unsigned): rd = (rs1 * rs2)[63:32] */
        case RV32IM_MULHU: {
            rv32im_mulhu_decode_fields(&raw, &rd, &rs1, &rs2);
            uint64_t a = (uint64_t)cpu->regs[rs1];
            uint64_t b = (uint64_t)cpu->regs[rs2];
            cpu->regs[rd] = (uint32_t)((a * b) >> 32);
            break;
        }

        /* divide signed: rd = rs1 / rs2 */
        case RV32IM_DIV: {
            rv32im_div_decode_fields(&raw, &rd, &rs1, &rs2);
            int32_t a = (int32_t)cpu->regs[rs1]; // dividend
            int32_t b = (int32_t)cpu->regs[rs2]; // divisor
            /* division by zero */
            if (b == 0) { cpu->regs[rd] = -1; }
            /* signed overflow: -2^31 / -1 should be -2^31 */
            else if (a == INT32_MIN && b == -1) { cpu->regs[rd] = a; }
            /* normal division */
            else { cpu->regs[rd] = (uint32_t)(a / b); }
            break;
        }

        /* divide unsigned: rd = rs1 / rs2 */
        case RV32IM_DIVU: {
            rv32im_divu_decode_fields(&raw, &rd, &rs1, &rs2);
            uint32_t a = cpu->regs[rs1];
            uint32_t b = cpu->regs[rs2];
            /* division by zero ? -1 : quotient */
            cpu->regs[rd] = (b == 0) ? -1 : (a / b);
            break;
        }

        /* remainder signed: rd = rs1 % rs2 */
        case RV32IM_REM: {
            rv32im_rem_decode_fields(&raw, &rd, &rs1, &rs2);
            int32_t a = (int32_t)cpu->regs[rs1]; // remainder dividend
            int32_t b = (int32_t)cpu->regs[rs2]; // remainder divisor
            /* remainder by zero is dividend */
            if (b == 0) { cpu->regs[rd] = (uint32_t)a; }
            /* signed overflow remainder is 0 */
            else if (a == INT32_MIN && b == -1) { cpu->regs[rd] = 0; }
            /* normal remainder */
            else { cpu->regs[rd] = (uint32_t)(a % b); }
            break;
        }

        /* remainder unsigned: rd = rs1 % rs2 */
        case RV32IM_REMU: {
            rv32im_remu_decode_fields(&raw, &rd, &rs1, &rs2);
            uint32_t a = cpu->regs[rs1];
            uint32_t b = cpu->regs[rs2];
            /* remainder by zero ? dividend : remainder */
            cpu->regs[rd] = (b == 0) ? a : (a % b);
            break;
        }

        default:
            fatal("Illegal Instruction 0x%x at PC 0x%x\n", raw, pc);
            break;
    }
    cpu->regs[0] = 0; // x0 is always zero
    return VM_STEP_RESULT_OK;
}

const ext_t ext_rv32m = {
    .name = "RV32M",
    .start_id = RV32IM_MUL,
    .end_id = RV32IM_REMU,
    .exec = pie_rv32m_exec
};