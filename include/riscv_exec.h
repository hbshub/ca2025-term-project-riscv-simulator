#ifndef RISCV_EXEC_H
#define RISCV_EXEC_H
#include "vm_config.h"
#include "ext.h"

vm_step_result_t riscv_execute(cpu_t *cpu, uint32_t raw, uint32_t pc_current);
/* Initialize the dispatch table with a list of extensions */
void riscv_init_dispatch_table(const ext_t **ext_list, size_t count);

#endif // RISCV_EXEC_H