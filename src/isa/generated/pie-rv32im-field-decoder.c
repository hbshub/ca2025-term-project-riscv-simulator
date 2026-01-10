#include "pie-rv32im-field-decoder.h"
void rv32im_lui_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32im_auipc_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32im_jal_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32im_jalr_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_beq_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_bne_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_blt_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_bge_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_bltu_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_bgeu_decode_fields (
	uint32_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_lb_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_lh_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_lw_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_lbu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_lhu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_sb_decode_fields (
	uint32_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs2 = (instruction >> 20) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_sh_decode_fields (
	uint32_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs2 = (instruction >> 20) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_sw_decode_fields (
	uint32_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = *address;
	*rs2 = (instruction >> 20) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32im_addi_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_slti_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_sltiu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_xori_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_ori_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_andi_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32im_slli_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*shamt = (instruction >> 20) & 0x3f;
}
void rv32im_srli_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*shamt = (instruction >> 20) & 0x3f;
}
void rv32im_srai_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*shamt = (instruction >> 20) & 0x3f;
}
void rv32im_add_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_sub_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_sll_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_slt_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_sltu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_xor_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_srl_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_sra_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_or_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_and_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_fence_decode_fields (
	uint32_t *address,
	unsigned int *fm,
	unsigned int *pred,
	unsigned int *succ)
{
	uint32_t instruction = *address;
	*fm = (instruction >> 28) & 0xf;
	*pred = (instruction >> 24) & 0xf;
	*succ = (instruction >> 20) & 0xf;
}
void rv32im_mul_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_mulh_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_mulhsu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_mulhu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_div_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_divu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_rem_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32im_remu_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
