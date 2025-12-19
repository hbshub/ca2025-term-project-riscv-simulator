#ifndef CPU_H
#define CPU_H
#include "vm_config.h"
#include "ram.h"

typedef struct {
    uint32_t regs[32];
    uint32_t pc;
    ram_t *ram;
} cpu_t;

cpu_t *cpu_new(ram_t *ram);
void cpu_free(cpu_t *cpu);
uint32_t cpu_load(cpu_t *cpu, uint32_t addr, uint8_t size);
void cpu_store(cpu_t *cpu, uint32_t addr, uint32_t value);
uint32_t cpu_fetch(cpu_t *cpu);

#endif // CPU_H