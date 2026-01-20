#include "riscv_exec.h"

static inst_handler_t dispatch_table[RV32IMC_INVALID + 1];

bool is_rvc_hint(uint16_t inst) {
    // 1. Extract Opcode (Quadrant)
    uint32_t op = inst & 0x3;
    
    // [Important] Quadrant 0 (00) has no HINT!
    // In Q0, rd=0 is Reserved (Illegal), so return false to trigger an error.
    if (op == 0x0) return false;

    // 2. Extract rd (Bit 11-7)
    uint32_t rd = (inst >> 7) & 0x1F;

    // [Rule A] Operations writing to x0 (covers C.LI, C.LUI, C.MV, C.ADD, C.SLLI, etc.)
    if (rd == 0) {
        return true; 
    }

    // [Rule B] Special case for C.ADDI with imm=0 (addi rd, rd, 0)
    // Quadrant 1, Funct3 0 => C.ADDI
    uint32_t funct3 = (inst >> 13) & 0x7;
    if (op == 0x1 && funct3 == 0) {
        // C.ADDI imm check: bit 12 (sign) and bit 6-2 (low bits)
        // If both parts are 0, it's a +0 operation
        if ((inst & 0x107C) == 0) { 
            return true;
        }
    }

    return false;
}

// default invalid handler
static vm_step_result_t invalid_handler(cpu_t *cpu, rv32imc_instruction inst, uint32_t raw, uint32_t pc) {
    // Check if it's an RVC HINT instruction (Compressed NOPs)
    // These instructions are usually c.add, c.mv, c.li, etc., but with rd=0
    // Characteristics:
    // 1. is compressed instruction (Bit[1:0] != 11)
    // 2. writes to x0 (rd = 0) || is c.addi with imm=0
    
    if ((raw & 0x3) != 0x3) { // 16-bit instruction
        uint16_t inst16 = (uint16_t)raw;
        
        if (is_rvc_hint(inst16)) {
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