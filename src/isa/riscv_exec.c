#include "riscv_exec.h"

static inst_handler_t dispatch_table[RV32IM_INVALID + 1];


// default invalid handler
static vm_step_result_t invalid_handler(cpu_t *cpu, rv32im_instruction inst, uint32_t raw, uint32_t pc) {
    fatal("Illegal or Unregistered Instruction: 0x%08x (ID: %d)", raw, inst);
    return VM_STEP_RESULT_ILLEGAL;
}

// init dispatch table, called by cpu.c
void riscv_init_dispatch_table(const ext_t **ext_list, size_t count) {
    
    // mistake prevention
    for (int i = 0; i <= RV32IM_INVALID; i++) {
        dispatch_table[i] = invalid_handler;
    }

    // register extensions from the provided list
    for (size_t i = 0; i < count; i++) {
        const ext_t *ext = ext_list[i];
        
        for (int id = ext->start_id; id <= ext->end_id; id++) {
            dispatch_table[id] = ext->exec;
        }
    }
}

vm_step_result_t riscv_execute(cpu_t *cpu, uint32_t raw, uint32_t pc_current)
{
    // I, M extension  decode
    rv32im_instruction inst_id = rv32im_decode(&raw);
    // lookup dispatch table and execute
    return dispatch_table[inst_id](cpu, inst_id, raw, pc_current);
    fatal("Unknown instruction: 0x%08x at PC: 0x%08x\n", raw, pc_current);
}