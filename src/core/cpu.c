#include "ram.h"
#include "cpu.h"
#include "riscv_exec.h"

extern const ext_t ext_rv32i;
extern const ext_t ext_rv32m;
extern const ext_t ext_rv32c;
static const ext_t *rv32_extensions[] = {
    &ext_rv32i,
    &ext_rv32m,
    &ext_rv32c,
};

cpu_t *cpu_new(ram_t *ram)
{
    cpu_t *cpu = malloc(sizeof(cpu_t));
    memset(cpu->regs, 0, sizeof(cpu->regs));
    cpu->ram = ram;
    
    /* Init dispatch table */
    riscv_init_dispatch_table(
        rv32_extensions, 
        sizeof(rv32_extensions) / sizeof(rv32_extensions[0])
    );
    return cpu;
}

void cpu_free(cpu_t *cpu)
{
    free(cpu);
}

uint32_t cpu_load(cpu_t *cpu, uint32_t addr, uint8_t size) 
{
    return ram_load(cpu->ram, addr, size);
}

void cpu_store(cpu_t *cpu, uint32_t addr, uint8_t size, uint32_t value)
{
    ram_store(cpu->ram, addr, size, value);
}

uint32_t cpu_fetch(cpu_t *cpu)
{
    #ifdef DEBUG
        printf("[Debug] Fetching at PC: 0x%x\n", cpu->pc);
    #endif
    return cpu_load(cpu, cpu->pc, 32);
}