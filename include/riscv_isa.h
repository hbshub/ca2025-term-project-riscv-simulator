#ifndef RISCV_ISA_H
#define RISCV_ISA_H

enum {
    /* R-type integer computation */
    INTEGER_COMP_RR = 0x33,
    /* I-type integer computation */
    INTEGER_COMP_RI = 0x13,
    /* Load instructions */
    LOAD = 0x03,
    /* Store instructions */
    STORE = 0x23,
    /* Branch instructions */
    BRANCH = 0x63,
    /* Jump and link register */
    JALR = 0x67,
    /* Jump and link */
    JAL = 0x6F,
    /* Add upper immediate to PC */
    AUIPC = 0x17,
    /* Load upper immediate */
    LUI = 0x37,
    /* ECALL and EBREAK */
    ECALL = 0x73,
    /* FENCE */
    FENCE = 0x0F
};

enum {
    ADD_SUB = 0x0,
    XOR = 0x4,
    OR = 0x6,
    AND = 0x7,
    SLL = 0x1,
    SRL_SRA = 0x5,
    SLT = 0x2,
    SLTU = 0x3,
};

/* FUNCT3 for INTEGER_COMP_RI */
enum {
    ADDI = 0x0,
    XORI = 0x4,
    ORI = 0x6,
    ANDI = 0x7,
    SLLI = 0x1,
    SRLI_SRAI = 0x5, /* SRLI and SRAI share the same FUNCT3 */
    SLTI = 0x2,
    SLTIU = 0x3,
};

/* FUNCT3 for LOAD */
enum {
    LB = 0x0,
    LH = 0x1, 
    LW = 0x2,
    LBU = 0x4,
    LHU = 0x5,
};

/* FUNCT3 for STORE */
enum {
    SB = 0x0,
    SH = 0x1,
    SW = 0x2,
};

/* FUNCT3 for BRANCH */
enum {
    BEQ = 0x0,
    BNE = 0x1,
    BLT = 0x4,
    BGE = 0x5,
    BLTU = 0x6,
    BGEU = 0x7,
};

enum { 
    OPCODE_MASK = 0x7F,
    REG_ADDR_MASK = 0x1F 
};

/* Instruction field bit offsets (LSB = bit 0) */
enum {
    RD_SHIFT     = 7,   /* bits [11:7]  */
    FUNCT3_SHIFT = 12,  /* bits [14:12] */
    RS1_SHIFT    = 15,  /* bits [19:15] */
    RS2_SHIFT    = 20,  /* bits [24:20] */
    FUNCT7_SHIFT = 25   /* bits [31:25] */
};

/* 3-bit sub-opcode */
enum { 
    FUNCT3_MASK = 0x7,
    FUNCT7_MASK = 0x7F
};

#endif // RISCV_ISA_H