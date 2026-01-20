#ifndef RISCV_UTILS_H
#define RISCV_UTILS_H
#include "vm_config.h"
#include "cpu.h"

/* =========================================================================
 * Core Execution Logic (ALU & State Mutation)
 * Used to implement shared ALU/LSU logic for extensions with x0 protection
 * ========================================================================= */

/* Generic Add: Handles both Register-Register (ADD) and Register-Immediate (ADDI)
 * Covers: ADD, ADDI, C.ADD, C.ADDI, C.MV, C.LI, C.NOP, C.ADDI16SP, C.ADDI4SPN
 * Note: For C.MV/C.LI, pass rs1=0 (x0). */
static inline void utils_exec_add(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t val2) {
    if (rd == 0) return;
    cpu->regs[rd] = cpu->regs[rs1] + val2;
}

static inline void utils_exec_sub(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t val2) {
    if (rd == 0) return;
    cpu->regs[rd] = cpu->regs[rs1] - val2;
}

/* Generic Logic: Handles AND/ANDI, OR/ORI, XOR/XORI
 * Parameter val2: Can be cpu->regs[rs2] OR immediate value */
static inline void utils_exec_and(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t val2) {
    if (rd == 0) return;
    cpu->regs[rd] = cpu->regs[rs1] & val2;
}

static inline void utils_exec_or(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t val2) {
    if (rd == 0) return;
    cpu->regs[rd] = cpu->regs[rs1] | val2;
}

static inline void utils_exec_xor(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t val2) {
    if (rd == 0) return;
    cpu->regs[rd] = cpu->regs[rs1] ^ val2;
}

/* Generic Shift: Handles SLL/SLLI, SRL/SRLI, SRA/SRAI
 * Parameter shamt: Can be cpu->regs[rs2] OR immediate value */
static inline void utils_exec_sll(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t shamt) {
    if (rd == 0) return;
    cpu->regs[rd] = cpu->regs[rs1] << (shamt & 0x1F);
}

static inline void utils_exec_srl(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t shamt) {
    if (rd == 0) return;
    cpu->regs[rd] = (uint32_t)cpu->regs[rs1] >> (shamt & 0x1F);
}

static inline void utils_exec_sra(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t shamt) {
    if (rd == 0) return;
    cpu->regs[rd] = (int32_t)cpu->regs[rs1] >> (shamt & 0x1F);
}

/* load immediates upper */
static inline void utils_exec_lui(cpu_t *cpu, uint32_t rd, uint32_t imm) {
    if (rd == 0) return;
    cpu->regs[rd] = imm;
}

/* load / store word operations */
static inline void utils_exec_lw(cpu_t *cpu, uint32_t rd, uint32_t rs1, uint32_t offset) {
    if (rd == 0) return;
    uint32_t addr = cpu->regs[rs1] + offset;
    cpu->regs[rd] = cpu_load(cpu, addr, 32);
}

static inline void utils_exec_sw(cpu_t *cpu, uint32_t rs2, uint32_t rs1, uint32_t offset) {
    uint32_t addr = cpu->regs[rs1] + offset;
    cpu_store(cpu, addr, 32, cpu->regs[rs2]);
}

/* branch / jump operations */
static inline bool utils_exec_beq(cpu_t *cpu, uint32_t rs1, uint32_t rs2) {
    return cpu->regs[rs1] == cpu->regs[rs2];
}

static inline bool utils_exec_bne(cpu_t *cpu, uint32_t rs1, uint32_t rs2) {
    return cpu->regs[rs1] != cpu->regs[rs2];
}

/*
 * Generic Jump and Link
 * Covers: JAL, JALR, C.J, C.JAL, C.JR, C.JALR
 * rd: Link register (usually x1 or x0)
 * return_addr: The address to save into rd (Current PC + 2 or 4)
 * target_addr: The final destination address
 * (Note: Caller must handle LSB masking for JALR/JR variants)
 */
static inline void utils_exec_jump_link(
    cpu_t *cpu, uint32_t rd,
    uint32_t return_addr, uint32_t target_addr
) {
    if (rd != 0) { cpu->regs[rd] = return_addr; }
    cpu->pc = target_addr; 
}

#endif // RISCV_UTILS_H