#include "ram.h"
#include "cpu.h"

cpu_t *cpu_new(ram_t *ram)
{
    cpu_t *cpu = malloc(sizeof(cpu_t));
    memset(cpu->regs, 0, sizeof(cpu->regs));
    /* Stack pointer */
    cpu->regs[2] = RAM_BASE + RAM_SIZE;
    cpu->pc = RAM_BASE;
    cpu->ram = ram;
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
    return cpu_load(cpu, cpu->pc, 32);
}