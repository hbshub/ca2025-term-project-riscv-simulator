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
    size_t code_size = vm->code_size;

    if (cpu->pc >= code_size) {
        return VM_STEP_RESULT_HALT;
    }

    uint32_t pc_current = cpu->pc;
    uint32_t raw = cpu_fetch(cpu);

    if (cpu->pc > code_size) {
        return VM_STEP_RESULT_HALT;
    }

    vm_step_result_t result = riscv_execute(cpu, raw, pc_current);
    
   return result;
}

vm_step_result_t vm_run(vm_t *vm)
{
    vm_step_result_t result;
    do {
        result = vm_step(vm);
    } while (result == VM_STEP_RESULT_OK);
    return result;
}