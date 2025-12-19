#include "ext.h"
#include "riscv_exec.h"
#include "riscv_isa.h"

enum { 
    SYSCALL_WRITE = 64,
    SYSCALL_EXIT = 93 
};
enum { 
    STDOUT = 1,
    STDERR = 2 
};

vm_step_result_t ecall_handler(cpu_t *cpu) {
    uint32_t syscall_nr = cpu->regs[17];
    switch (syscall_nr) {
        case SYSCALL_WRITE: {
            uint32_t fd = cpu->regs[10];
            uint32_t addr = cpu->regs[11];
            uint32_t count = cpu->regs[12];
            
            FILE *stream = (fd == STDOUT) ? stdout : (fd == STDERR) ? stderr : NULL;
            if (!stream) fatal("Invalid file descriptor: %d\n", fd);
            for (uint32_t i = 0; i < count; i++) {
                fprintf(stream, "%c", cpu_load(cpu, addr + i, 8));
            }
            return VM_STEP_RESULT_OK;
        }
        case SYSCALL_EXIT: {
            int32_t exit_code = cpu->regs[10];
            printf("Program exited with code: %d\n", exit_code);
            return VM_STEP_RESULT_HALT;
        }
        default:
            fatal("Unknown syscall: %d\n", syscall_nr);
    }
}

static bool rv32i_match(uint32_t raw, int len) {
  return len == 4;
}

static vm_step_result_t rv32i_exec(cpu_t *cpu, uint32_t raw, int len, uint32_t pc) {
    insn_t inst;
    riscv_decode(raw, &inst);
    
    cpu->pc = pc + len;
    cpu->regs[0] = 0;

    switch (inst.opcode) {
    case INTEGER_COMP_RI: {
        int32_t imm = i_imm(raw);
        switch (inst.funct3) {
        case ADDI:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] + imm;
            break;
        case XORI:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] ^ imm;
            break;
        case ORI:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] | imm;
            break;
        default:
            fatal("Unknown FUNCT3 for INTEGER_COMP_RI: 0x%x\n", inst.funct3);
        }
        return VM_STEP_RESULT_OK;
    }

    case LOAD: {
        int32_t imm = i_imm(raw);
        uint32_t addr = cpu->regs[inst.rs1] + imm;
        if (inst.funct3 != LW)
            fatal("Unknown FUNCT3 for LOAD: 0x%x\n", inst.funct3);
        cpu->regs[inst.rd] = cpu_load(cpu, addr, 32);
        return VM_STEP_RESULT_OK;
    }

    case STORE: {
        int32_t imm = s_imm(raw);
        uint32_t addr = cpu->regs[inst.rs1] + imm;
        if (inst.funct3 != SW)
            fatal("Unknown FUNCT3 for STORE: 0x%x\n", inst.funct3);
        cpu_store(cpu, addr, cpu->regs[inst.rs2]);
        return VM_STEP_RESULT_OK;
    }

    case JALR: {
        int32_t imm = i_imm(raw);
        uint32_t target = (cpu->regs[inst.rs1] + imm) & ~1;
        cpu->regs[inst.rd] = pc + len;
        cpu->pc = target;
        return VM_STEP_RESULT_OK;
    }

    case AUIPC: {
        int32_t imm = u_imm(raw);
        cpu->regs[inst.rd] = pc + imm;
        return VM_STEP_RESULT_OK;
    }

    case ECALL: {
        if (raw == 0x100073) return VM_STEP_RESULT_OK; // EBREAK
        vm_step_result_t result = ecall_handler(cpu);
        return result;
    }

    default:
        fatal("Illegal Instruction 0x%x at PC 0x%x\n", inst.opcode, cpu->pc);
    }
}

const ext_t ext_rv32i = {
    .name = "RV32I",
    .match = rv32i_match,
    .exec = rv32i_exec
};