#ifndef __RV32IM_PIE_FIELD_DECODER_H__
#define __RV32IM_PIE_FIELD_DECODER_H__
#include <stdint.h>
void rv32im_lui_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm);
void rv32im_auipc_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm);
void rv32im_jal_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm);
void rv32im_jalr_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_beq_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_bne_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_blt_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_bge_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_bltu_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_bgeu_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_lb_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_lh_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_lw_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_lbu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_lhu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_sb_decode_fields (
	uint32_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_sh_decode_fields (
	uint32_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_sw_decode_fields (
	uint32_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32im_addi_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_slti_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_sltiu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_xori_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_ori_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_andi_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32im_slli_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt);
void rv32im_srli_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt);
void rv32im_srai_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt);
void rv32im_add_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_sub_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_sll_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_slt_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_sltu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_xor_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_srl_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_sra_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_or_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_and_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_fence_decode_fields (
	uint32_t *address,
	unsigned int *fm,
	unsigned int *pred,
	unsigned int *succ);
void rv32im_mul_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_mulh_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_mulhsu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_mulhu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_div_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_divu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_rem_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32im_remu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
#endif
