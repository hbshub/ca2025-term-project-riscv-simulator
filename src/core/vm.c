#include "vm.h"
#include "riscv_exec.h"

vm_t *vm_new(uint8_t *code, size_t code_size)
{
    vm_t *vm = malloc(sizeof(vm_t));
    vm->ram = ram_new();
    ram_load_image(vm->ram, code, code_size, RAM_BASE);
    vm->cpu = cpu_new(vm->ram);
    vm->code_size = code_size;
    return vm;
}

void vm_free(vm_t *vm)
{
    cpu_free(vm->cpu);
    ram_free(vm->ram);
    free(vm);
}

vm_step_result_t vm_step(vm_t *vm)
{
    cpu_t *cpu = vm->cpu;
    uint32_t pc_current = cpu->pc;
    uint32_t raw = cpu_fetch(cpu);
    vm_step_result_t result = riscv_execute(cpu, raw, pc_current);
    
   return result;
}

vm_step_result_t vm_run(vm_t *vm, uint32_t tohost_addr)
{
    vm_step_result_t result;
    while (1) {
        result = vm_step(vm);

        // ecall or illegal instruction
        if (result != VM_STEP_RESULT_OK) { break; }

        // monitor tohost_addr for termination signal
        if (tohost_addr != 0) {
            uint32_t val = ram_load(vm->ram, tohost_addr, 32); 
            if (val != 0) { return VM_STEP_RESULT_HALT; }
        }
    }
    return result;
}