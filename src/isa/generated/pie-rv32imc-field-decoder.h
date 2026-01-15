#ifndef __RV32IMC_PIE_FIELD_DECODER_H__
#define __RV32IMC_PIE_FIELD_DECODER_H__
#include <stdint.h>
void rv32imc_lui_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *imm);
void rv32imc_auipc_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *imm);
void rv32imc_jal_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *imm);
void rv32imc_jalr_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_beq_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_bne_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_blt_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_bge_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_bltu_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_bgeu_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_lb_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_lh_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_lw_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_lbu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_lhu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_sb_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_sh_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_sw_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_addi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_slti_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_sltiu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_xori_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_ori_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_andi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm);
void rv32imc_slli_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt);
void rv32imc_srli_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt);
void rv32imc_srai_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt);
void rv32imc_add_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_sub_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_sll_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_slt_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_sltu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_xor_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_srl_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_sra_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_or_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_and_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_fence_decode_fields (
	uint16_t *address,
	unsigned int *fm,
	unsigned int *pred,
	unsigned int *succ);
void rv32imc_csrrw_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *rs1);
void rv32imc_csrrs_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *rs1);
void rv32imc_csrrc_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *rs1);
void rv32imc_csrrwi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *uimm);
void rv32imc_csrrsi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *uimm);
void rv32imc_csrrci_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *uimm);
void rv32imc_mul_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_mulh_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_mulhsu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_mulhu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_div_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_divu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_rem_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_remu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2);
void rv32imc_c_addi4spn_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *nzuimm);
void rv32imc_c_lw_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *uimmhi,
	unsigned int *uimmlo);
void rv32imc_c_sw_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *uimmhi,
	unsigned int *uimmlo);
void rv32imc_c_nop_decode_fields (
	uint16_t *address,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo);
void rv32imc_c_addi_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo);
void rv32imc_c_jal_decode_fields (
	uint16_t *address,
	unsigned int *imm);
void rv32imc_c_li_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo);
void rv32imc_c_addi16sp_decode_fields (
	uint16_t *address,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo);
void rv32imc_c_lui_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo);
void rv32imc_c_srli_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzuimmhi,
	unsigned int *nzuimmlo);
void rv32imc_c_srai_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzuimmhi,
	unsigned int *nzuimmlo);
void rv32imc_c_andi_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_c_sub_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2);
void rv32imc_c_xor_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2);
void rv32imc_c_or_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2);
void rv32imc_c_and_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2);
void rv32imc_c_j_decode_fields (
	uint16_t *address,
	unsigned int *imm);
void rv32imc_c_beqz_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_c_bnez_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo);
void rv32imc_c_slli_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzuimmhi,
	unsigned int *nzuimmlo);
void rv32imc_c_lwsp_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *uimmhi,
	unsigned int *uimmlo);
void rv32imc_c_jr_decode_fields (
	uint16_t *address,
	unsigned int *rs1);
void rv32imc_c_mv_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs2);
void rv32imc_c_jalr_decode_fields (
	uint16_t *address,
	unsigned int *rs1);
void rv32imc_c_add_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2);
void rv32imc_c_swsp_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *uimm);
#endif
