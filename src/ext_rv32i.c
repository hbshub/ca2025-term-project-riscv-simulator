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
            // RISC-V Linux ABI returns number of bytes written in a0
            cpu->regs[10] = count;
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

    switch (inst.opcode) {
    case INTEGER_COMP_RR: {
        switch (inst.funct3) {
        case ADD_SUB:
            if ((inst.funct7 >> 5) & 0x1) // SUB
                cpu->regs[inst.rd] = (int32_t)cpu->regs[inst.rs1] - (int32_t)cpu->regs[inst.rs2];
            else // ADD
                cpu->regs[inst.rd] = cpu->regs[inst.rs1] + cpu->regs[inst.rs2];
            break;
        case XOR:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] ^ cpu->regs[inst.rs2];
            break;
        case OR:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] | cpu->regs[inst.rs2];
            break;
        case AND:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] & cpu->regs[inst.rs2];
            break;
        case SLL:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] << (cpu->regs[inst.rs2] & 0x1F);
            break;
        case SRL_SRA:
            if ((inst.funct7 >> 5) & 0x1) // SRA
                cpu->regs[inst.rd] = (int32_t)cpu->regs[inst.rs1] >> (cpu->regs[inst.rs2] & 0x1F);
            else // SRL
                cpu->regs[inst.rd] = (uint32_t)cpu->regs[inst.rs1] >> (cpu->regs[inst.rs2] & 0x1F);
            break;
        case SLT:
            cpu->regs[inst.rd] = ((int32_t)cpu->regs[inst.rs1] < (int32_t)cpu->regs[inst.rs2]) ? 1 : 0;
            break;
        case SLTU:
            cpu->regs[inst.rd] = (cpu->regs[inst.rs1] < cpu->regs[inst.rs2]) ? 1 : 0;
            break;
        default:
            fatal("Unknown FUNCT3 for INTEGER_COMP_RR: 0x%x\n", inst.funct3);
        }
        break;
    }

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
        case ANDI:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] & imm;
            break;
        case SLLI:
            cpu->regs[inst.rd] = cpu->regs[inst.rs1] << (imm & 0x1F);
            break;
        case SRLI_SRAI:
            if ((inst.funct7 >> 5) & 0x1) // SRAI
                cpu->regs[inst.rd] = (int32_t)cpu->regs[inst.rs1] >> (imm & 0x1F);
            else // SRLI
                cpu->regs[inst.rd] = (uint32_t)cpu->regs[inst.rs1] >> (imm & 0x1F);
            break;
        case SLTI:
            cpu->regs[inst.rd] = ((int32_t)cpu->regs[inst.rs1] < imm) ? 1 : 0;
            break;
        case SLTIU:
            cpu->regs[inst.rd] = ((uint32_t)cpu->regs[inst.rs1] < (uint32_t)imm) ? 1 : 0;
            break;
        default:
            fatal("Unknown FUNCT3 for INTEGER_COMP_RI: 0x%x\n", inst.funct3);
        }
        break;
    }

    case LOAD: {
        int32_t imm = i_imm(raw);
        uint32_t addr = cpu->regs[inst.rs1] + imm;
        switch (inst.funct3) {
        case LB:
            cpu->regs[inst.rd] = (int8_t)cpu_load(cpu, addr, 8);
            break;
        case LH:
            if (addr & 1) fatal("Unaligned LOAD (LH): 0x%x\n", addr);
            cpu->regs[inst.rd] = (int16_t)cpu_load(cpu, addr, 16);
            break;
        case LW:
            if (addr & 3) fatal("Unaligned LOAD (LW): 0x%x\n", addr);
            cpu->regs[inst.rd] = (int32_t)cpu_load(cpu, addr, 32);
            break;
        case LBU:
            cpu->regs[inst.rd] = (uint8_t)cpu_load(cpu, addr, 8);
            break;
        case LHU:
            if (addr & 1) fatal("Unaligned LOAD (LHU): 0x%x\n", addr);
            cpu->regs[inst.rd] = (uint16_t)cpu_load(cpu, addr, 16);
            break;
        default:
            fatal("Unknown FUNCT3 for LOAD: 0x%x\n", inst.funct3);
        }
        break;
    }

    case STORE: {
        int32_t imm = s_imm(raw);
        uint32_t addr = cpu->regs[inst.rs1] + imm;
        uint32_t val = cpu->regs[inst.rs2];
        switch (inst.funct3) {
        case SB:
            cpu_store(cpu, addr, 8, val & 0xFF);
            break;
        case SH:
            if (addr & 1) fatal("Unaligned STORE (SH): 0x%x\n", addr);
            cpu_store(cpu, addr, 16, val & 0xFFFF);
            break;
        case SW:
            if (addr & 3) fatal("Unaligned STORE (SW): 0x%x\n", addr);
            cpu_store(cpu, addr, 32, val);
            break;
        default:
            fatal("Unknown FUNCT3 for STORE: 0x%x\n", inst.funct3);
        }
        break;
    }

    case BRANCH: {
        int32_t imm = b_imm(raw);
        uint32_t target_pc = pc + imm;
        bool take_branch = false;
        switch (inst.funct3) {
        case BEQ:
            take_branch = (cpu->regs[inst.rs1] == cpu->regs[inst.rs2]);
            break;
        case BNE:
            take_branch = (cpu->regs[inst.rs1] != cpu->regs[inst.rs2]);
            break;
        case BLT:
            take_branch = ((int32_t)cpu->regs[inst.rs1] < (int32_t)cpu->regs[inst.rs2]);
            break;
        case BGE:
            take_branch = ((int32_t)cpu->regs[inst.rs1] >= (int32_t)cpu->regs[inst.rs2]);
            break;
        case BLTU:
            take_branch = (cpu->regs[inst.rs1] < cpu->regs[inst.rs2]);
            break;
        case BGEU:
            take_branch = (cpu->regs[inst.rs1] >= cpu->regs[inst.rs2]);
            break;
        default:
            fatal("Unknown FUNCT3 for BRANCH: 0x%x\n", inst.funct3);
        }
        if (take_branch) {
            cpu->pc = target_pc;
        }
        break;
    }

    case JAL: {
        int32_t imm = j_imm(raw);
        cpu->regs[inst.rd] = pc + len;
        cpu->pc = pc + imm;
        break;
    }

    case JALR: {
        int32_t imm = i_imm(raw);
        uint32_t target = (cpu->regs[inst.rs1] + imm) & ~1;
        // cpu->regs[inst.rd] = pc + len;
        if (inst.rd != 0) {
            cpu->regs[inst.rd] = pc + len;
        }
        cpu->pc = target;
        break;
    }

    case AUIPC: {
        int32_t imm = u_imm(raw);
        cpu->regs[inst.rd] = pc + imm;
        break;
    }

    case LUI: {
        int32_t imm = u_imm(raw);
        cpu->regs[inst.rd] = imm;
        break;
    }

    case ECALL: {
        // EBREAK stop execution
        if (raw == 0x100073) return VM_STEP_RESULT_HALT;
        vm_step_result_t result = ecall_handler(cpu);
        if (result != VM_STEP_RESULT_OK) {
            return result;
        }
        break;
    }

    case FENCE: {
        // No operation for FENCE in this simple simulator
        break;
    }

    default:
        fatal("Illegal Instruction 0x%x at PC 0x%x\n", inst.opcode, pc);
    }
    cpu->regs[0] = 0; // x0 is always zero
    return VM_STEP_RESULT_OK;
}

const ext_t ext_rv32i = {
    .name = "RV32I",
    .match = rv32i_match,
    .exec = rv32i_exec
};