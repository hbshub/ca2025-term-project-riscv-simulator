#ifndef RISCV_ISA_H
#define RISCV_ISA_H

enum {
    /* I-type integer computation */
    INTEGER_COMP_RI = 0x13,
    /* Load instructions */
    LOAD = 0x03,
    /* Store instructions */
    STORE = 0x23,
    /* Jump and link register */
    JALR = 0x67,
    /* Add upper immediate to PC */
    AUIPC = 0x17,
    /* ECALL */
    ECALL = 0x73,
};

/* FUNCT3 for INTEGER_COMP_RI */
enum {
    ADDI = 0x0,
    XORI = 0x4,
    ORI = 0x6,
};

/* FUNCT3 for LOAD */
enum { 
    LW = 0x2, 
};

/* FUNCT3 for STORE */
enum { 
    SW = 0x2,
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
};

/* 3-bit sub-opcode */
enum { 
    FUNCT3_MASK = 0x7, 
};

#endif // RISCV_ISA_H