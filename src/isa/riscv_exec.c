#include "riscv_exec.h"

static inst_handler_t dispatch_table[RV32IMC_INVALID + 1];


// default invalid handler
static vm_step_result_t invalid_handler(cpu_t *cpu, rv32imc_instruction inst, uint32_t raw, uint32_t pc) {
    // Check if it's an RVC HINT instruction (Compressed NOPs)
    // These instructions are usually c.add, c.mv, c.li, etc., but with rd=0
    // Characteristics:
    // 1. is compressed instruction (Bit[1:0] != 11)
    // 2. target register rd (Bit[11:7]) is 0
    
    if ((raw & 0x3) != 0x3) { // 16-bit instruction
        uint16_t inst16 = (uint16_t)raw;
        
        // extract rd (Bit 11-7)
        uint32_t rd = (inst16 >> 7) & 0x1F;
        
        if (rd == 0) {
            // HINT instruction (e.g., c.add x0, x2)
            // decoder marks it as illegal, in hardware this is just a NOP
            cpu->pc = pc + 2;
            return VM_STEP_RESULT_OK;
        }
    }
    fatal("Illegal or Unregistered Instruction: 0x%08x (ID: %d)", raw, inst);
    return VM_STEP_RESULT_ILLEGAL;
}

// init dispatch table, called by cpu.c
void riscv_init_dispatch_table(const ext_t **ext_list, size_t count) {
    
    // mistake prevention
    for (int i = 0; i <= RV32IMC_INVALID; i++) {
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
    // I, M, C extension  decode, C is 16-bit instruction
    rv32imc_instruction inst_id = rv32imc_decode((uint16_t*)&raw);
    // lookup dispatch table and execute
    return dispatch_table[inst_id](cpu, inst_id, raw, pc_current);
    fatal("Unknown instruction: 0x%08x at PC: 0x%08x\n", raw, pc_current);
}