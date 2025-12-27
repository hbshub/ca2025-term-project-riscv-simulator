#ifndef RISCV_EXEC_H
#define RISCV_EXEC_H
#include "vm_config.h"
#include "ext.h"

vm_step_result_t riscv_execute(cpu_t *cpu, uint32_t raw, uint32_t pc_current);

/* =========================================================================
 * Pie Decoder Adapters
 * Used to reconstruct raw fragments from pie-*-field-decoder into signed 32-bit
 * ========================================================================= */

/*
 * I-Type: Sign-extend 12-bit raw value
 */
static inline int32_t pie_i_imm(uint32_t raw_imm) {
    int32_t imm = (int32_t)raw_imm;
    return (imm << 20) >> 20; 
}

/*
 * S-Type: Combine high/low chunks and sign-extend
 */
static inline int32_t pie_s_imm(uint32_t immhi, uint32_t immlo) {
    int32_t imm = (immhi << 5) | immlo;
    return (imm << 20) >> 20;
}

/*
 * B-Type: Shuffle bits and sign-extend
 * immhi contains bits 12|10:5
 * immlo contains bits 4:1|11
 */
static inline int32_t pie_b_imm(uint32_t immhi, uint32_t immlo) {
    uint32_t bit_12   = (immhi >> 6) & 0x1;
    uint32_t bit_10_5 = immhi & 0x3F;
    uint32_t bit_4_1  = (immlo >> 1) & 0xF;
    uint32_t bit_11   = immlo & 0x1;
    
    int32_t imm = (bit_12 << 12) | (bit_11 << 11) | (bit_10_5 << 5) | (bit_4_1 << 1);
    return (imm << 19) >> 19;
}

/*
 * U-Type: Shift 20-bit raw value back to upper position
 */
static inline int32_t pie_u_imm(uint32_t raw_imm) {
    return (int32_t)(raw_imm << 12);
}

/*
 * J-Type: Shuffle bits from the raw 20-bit extraction
 * raw_chunk is inst[31:12]
 */
static inline int32_t pie_j_imm(uint32_t raw_chunk) {
    uint32_t imm_20    = (raw_chunk >> 19) & 0x1;
    uint32_t imm_10_1  = (raw_chunk >> 9) & 0x3FF;
    uint32_t imm_11    = (raw_chunk >> 8) & 0x1;
    uint32_t imm_19_12 = raw_chunk & 0xFF;
    
    int32_t imm = (imm_20 << 20) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1);
    return (imm << 11) >> 11;
}

#endif // RISCV_EXEC_H