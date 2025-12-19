#ifndef RISCV_EXEC_H
#define RISCV_EXEC_H
#include "vm_config.h"
#include "riscv_isa.h"
#include "ext.h"

typedef struct {
    uint8_t opcode;
    uint8_t rd, rs1, rs2, funct3;
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

#endif // RISCV_EXEC_H