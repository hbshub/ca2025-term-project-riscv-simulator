#ifndef RISCV_EXEC_H
#define RISCV_EXEC_H
#include "vm_config.h"
#include "riscv_isa.h"
#include "ext.h"

typedef struct {
    uint8_t opcode;
    uint8_t rd, rs1, rs2, funct3, funct7;
} insn_t;

void riscv_decode(uint32_t raw, insn_t *inst);
vm_step_result_t riscv_execute(cpu_t *cpu, uint32_t raw, uint32_t pc_current);

static inline int32_t i_imm(uint32_t raw)
{
    /* imm[11:0] = inst[31:20] */
    return ((int32_t) raw) >> 20;
}

static inline int32_t s_imm(uint32_t raw)
{
    /* imm[11:5] = inst[31:25], imm[4:0] = inst[11:7] */
    uint32_t imm_11_5 = (raw >> 25) & 0x7F;
    uint32_t imm_4_0 = (raw >> 7) & 0x1F;
    int32_t imm = (imm_11_5 << 5) | imm_4_0;
    /* Sign extend from bit 11 */
    if (imm & 0x800) {
        imm |= 0xFFFFF000;
    }
    return imm;
}

static inline int32_t u_imm(uint32_t raw)
{
    /* imm[31:12] = inst[31:12] */
    return ((int32_t) raw & 0xFFFFF000);
}

static inline int32_t b_imm(uint32_t raw)
{
    /* imm[12] = inst[31], imm[10:5] = inst[30:25], imm[4:1] = inst[11:8], imm[11] = inst[7] */
    /* imm[0] = 0, 2 byte aligned */
    uint32_t imm_12 = (raw >> 31) & 0x1;
    uint32_t imm_10_5 = (raw >> 25) & 0x3F;
    uint32_t imm_4_1 = (raw >> 8) & 0xF;
    uint32_t imm_11 = (raw >> 7) & 0x1;
    int32_t imm = (imm_12 << 12) | (imm_11 << 11) | (imm_10_5 << 5) | (imm_4_1 << 1);
    /* Sign extend from bit 12 */
    if (imm & 0x1000) {
        imm |= 0xFFFFE000;
    }
    return imm;
}

static inline int32_t j_imm(uint32_t raw)
{
    /* imm[20] = inst[31], imm[10:1] = inst[30:21], imm[11] = inst[20], imm[19:12] = inst[19:12] */
    /* imm[0] = 0, 2 byte aligned */
    uint32_t imm_20 = (raw >> 31) & 0x1;
    uint32_t imm_10_1 = (raw >> 21) & 0x3FF;
    uint32_t imm_11 = (raw >> 20) & 0x1;
    uint32_t imm_19_12 = (raw >> 12) & 0xFF;
    int32_t imm = (imm_20 << 20) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1);
    /* Sign extend from bit 20 */
    if (imm & 0x100000) {
        imm |= 0xFFE00000;
    }
    return imm;
}

#endif // RISCV_EXEC_H