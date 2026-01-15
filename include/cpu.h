#ifndef CPU_H
#define CPU_H
#include "vm_config.h"
#include "ram.h"

typedef struct {
    uint32_t regs[32];
    uint32_t pc;
    ram_t *ram;

    // === Machine Mode CSRs ===
    uint32_t mscratch; // (0x340) Temporary storage for machine mode
    uint32_t mtvec;    // (0x305) Trap vector base address (Where to jump on trap)
    uint32_t mepc;     // (0x341) Stored PC at the time of exception
    uint32_t mcause;   // (0x342) Cause of the exception or interrupt
} cpu_t;

cpu_t *cpu_new(ram_t *ram);
void cpu_free(cpu_t *cpu);
uint32_t cpu_load(cpu_t *cpu, uint32_t addr, uint8_t size);
void cpu_store(cpu_t *cpu, uint32_t addr, uint8_t size, uint32_t value);
uint32_t cpu_fetch(cpu_t *cpu);

#endif // CPU_H