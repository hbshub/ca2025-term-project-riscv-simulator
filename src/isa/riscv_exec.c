#include "riscv_exec.h"


extern const ext_t ext_rv32i;

static const ext_t *rv32_extensions[] = {
    &ext_rv32i,
};

vm_step_result_t riscv_execute(cpu_t *cpu, uint32_t raw, uint32_t pc_current)
{
    for (size_t i = 0; i < sizeof(rv32_extensions) / sizeof(rv32_extensions[0]); i++) {
        const ext_t *ext = rv32_extensions[i];
        if (ext->match(raw, 4)) {
            vm_step_result_t result = ext->exec(cpu, raw, 4, pc_current);
            return result;
        }
    }
    fatal("Unknown instruction: 0x%08x at PC: 0x%08x\n", raw, pc_current);
}