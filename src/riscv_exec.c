#include "riscv_exec.h"


extern const ext_t ext_rv32i;

static const ext_t *rv32_extensions[] = {
    &ext_rv32i,
};

void riscv_decode(uint32_t raw, insn_t *inst)
{
    uint8_t opcode = raw & OPCODE_MASK;
    uint8_t rd = (raw >> RD_SHIFT) & REG_ADDR_MASK;
    uint8_t rs1 = (raw >> RS1_SHIFT) & REG_ADDR_MASK;
    uint8_t rs2 = (raw >> RS2_SHIFT) & REG_ADDR_MASK;
    uint8_t funct3 = (raw >> FUNCT3_SHIFT) & FUNCT3_MASK;

    inst->opcode = opcode;
    inst->rd = rd, inst->rs1 = rs1, inst->rs2 = rs2;
    inst->funct3 = funct3;
}

vm_step_result_t riscv_execute(cpu_t *cpu, uint32_t raw, uint32_t pc_current)
{
    for (size_t i = 0; i < sizeof(rv32_extensions) / sizeof(rv32_extensions[0]); i++) {
        const ext_t *ext = rv32_extensions[i];
        if (ext->match(raw, 4)) {
            vm_step_result_t result = ext->exec(cpu, raw, 4, pc_current);
            cpu->regs[0] = 0;
            return result;
        }
    }
    fatal("Unknown instruction: 0x%08x at PC: 0x%08x\n", raw, pc_current);
}