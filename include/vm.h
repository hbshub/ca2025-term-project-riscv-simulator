#ifndef VM_H
#define VM_H
#include <vm_config.h>
#include "cpu.h"
#include "ram.h"

typedef struct vm {
    ram_t *ram;
    cpu_t *cpu;
    size_t code_size;
} vm_t;

vm_t *vm_new(uint8_t *code, size_t code_size);
void vm_free(vm_t *vm);
vm_step_result_t vm_step(vm_t *vm);
vm_step_result_t vm_run(vm_t *vm, uint32_t tohost_addr);

#endif // VM_H