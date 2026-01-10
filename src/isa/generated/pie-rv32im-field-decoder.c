#include "pie-rv32i-field-decoder.h"
void rv32i_lui_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32i_auipc_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32i_jal_decode_fields (
	uint32_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32i_jalr_decode_fields (
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
void rv32i_beq_decode_fields (
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
void rv32i_bne_decode_fields (
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
void rv32i_blt_decode_fields (
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
void rv32i_bge_decode_fields (
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
void rv32i_bltu_decode_fields (
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
void rv32i_bgeu_decode_fields (
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
void rv32i_lb_decode_fields (
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
void rv32i_lh_decode_fields (
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
void rv32i_lw_decode_fields (
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
void rv32i_lbu_decode_fields (
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
void rv32i_lhu_decode_fields (
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
void rv32i_sb_decode_fields (
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
void rv32i_sh_decode_fields (
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
void rv32i_sw_decode_fields (
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
void rv32i_addi_decode_fields (
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
void rv32i_slti_decode_fields (
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
void rv32i_sltiu_decode_fields (
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
void rv32i_xori_decode_fields (
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
void rv32i_ori_decode_fields (
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
void rv32i_andi_decode_fields (
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
void rv32i_slli_decode_fields (
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
void rv32i_srli_decode_fields (
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
void rv32i_srai_decode_fields (
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
void rv32i_add_decode_fields (
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
void rv32i_sub_decode_fields (
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
void rv32i_sll_decode_fields (
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
void rv32i_slt_decode_fields (
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
void rv32i_sltu_decode_fields (
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
void rv32i_xor_decode_fields (
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
void rv32i_srl_decode_fields (
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
void rv32i_sra_decode_fields (
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
void rv32i_or_decode_fields (
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
void rv32i_and_decode_fields (
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
void rv32i_fence_decode_fields (
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
