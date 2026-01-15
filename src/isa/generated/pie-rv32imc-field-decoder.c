#include "pie-rv32imc-field-decoder.h"
void rv32imc_lui_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32imc_auipc_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32imc_jal_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*imm = (instruction >> 12) & 0xfffff;
}
void rv32imc_jalr_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_beq_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_bne_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_blt_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_bge_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_bltu_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_bgeu_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *rs2,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_lb_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_lh_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_lw_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_lbu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_lhu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_sb_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs2 = (instruction >> 20) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_sh_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs2 = (instruction >> 20) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_sw_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rs2 = (instruction >> 20) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*immhi = (instruction >> 25) & 0x7f;
	*immlo = (instruction >> 7) & 0x1f;
}
void rv32imc_addi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_slti_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_sltiu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_xori_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_ori_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_andi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *imm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*imm = (instruction >> 20) & 0xfff;
}
void rv32imc_slli_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*shamt = (instruction >> 20) & 0x3f;
}
void rv32imc_srli_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*shamt = (instruction >> 20) & 0x3f;
}
void rv32imc_srai_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *shamt)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*shamt = (instruction >> 20) & 0x3f;
}
void rv32imc_add_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_sub_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_sll_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_slt_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_sltu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_xor_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_srl_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_sra_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_or_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_and_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_fence_decode_fields (
	uint16_t *address,
	unsigned int *fm,
	unsigned int *pred,
	unsigned int *succ)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*fm = (instruction >> 28) & 0xf;
	*pred = (instruction >> 24) & 0xf;
	*succ = (instruction >> 20) & 0xf;
}
void rv32imc_csrrw_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *rs1)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*csr = (instruction >> 20) & 0xfff;
	*rs1 = (instruction >> 15) & 0x1f;
}
void rv32imc_csrrs_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *rs1)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*csr = (instruction >> 20) & 0xfff;
	*rs1 = (instruction >> 15) & 0x1f;
}
void rv32imc_csrrc_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *rs1)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*csr = (instruction >> 20) & 0xfff;
	*rs1 = (instruction >> 15) & 0x1f;
}
void rv32imc_csrrwi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *uimm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*csr = (instruction >> 20) & 0xfff;
	*uimm = (instruction >> 15) & 0x1f;
}
void rv32imc_csrrsi_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *uimm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*csr = (instruction >> 20) & 0xfff;
	*uimm = (instruction >> 15) & 0x1f;
}
void rv32imc_csrrci_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *csr,
	unsigned int *uimm)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*csr = (instruction >> 20) & 0xfff;
	*uimm = (instruction >> 15) & 0x1f;
}
void rv32imc_mul_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_mulh_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_mulhsu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_mulhu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_div_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_divu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_rem_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_remu_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *rs2)
{
	uint32_t instruction = (*(address + 1) << 16) | *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs1 = (instruction >> 15) & 0x1f;
	*rs2 = (instruction >> 20) & 0x1f;
}
void rv32imc_c_addi4spn_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *nzuimm)
{
	uint16_t instruction = *address;
	*rd = (instruction >> 2) & 0x7;
	*nzuimm = (instruction >> 5) & 0xff;
}
void rv32imc_c_lw_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs1,
	unsigned int *uimmhi,
	unsigned int *uimmlo)
{
	uint16_t instruction = *address;
	*rd = (instruction >> 2) & 0x7;
	*rs1 = (instruction >> 7) & 0x7;
	*uimmhi = (instruction >> 10) & 0x7;
	*uimmlo = (instruction >> 5) & 0x3;
}
void rv32imc_c_sw_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *rs1,
	unsigned int *uimmhi,
	unsigned int *uimmlo)
{
	uint16_t instruction = *address;
	*rs2 = (instruction >> 2) & 0x7;
	*rs1 = (instruction >> 7) & 0x7;
	*uimmhi = (instruction >> 10) & 0x7;
	*uimmlo = (instruction >> 5) & 0x3;
}
void rv32imc_c_nop_decode_fields (
	uint16_t *address,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo)
{
	uint16_t instruction = *address;
	*nzimmhi = (instruction >> 12) & 0x1;
	*nzimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_addi_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x1f;
	*nzimmhi = (instruction >> 12) & 0x1;
	*nzimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_jal_decode_fields (
	uint16_t *address,
	unsigned int *imm)
{
	uint16_t instruction = *address;
	*imm = (instruction >> 2) & 0x7ff;
}
void rv32imc_c_li_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo)
{
	uint16_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*nzimmhi = (instruction >> 12) & 0x1;
	*nzimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_addi16sp_decode_fields (
	uint16_t *address,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo)
{
	uint16_t instruction = *address;
	*nzimmhi = (instruction >> 12) & 0x1;
	*nzimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_lui_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *nzimmhi,
	unsigned int *nzimmlo)
{
	uint16_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*nzimmhi = (instruction >> 12) & 0x1;
	*nzimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_srli_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzuimmhi,
	unsigned int *nzuimmlo)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*nzuimmhi = (instruction >> 12) & 0x1;
	*nzuimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_srai_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzuimmhi,
	unsigned int *nzuimmlo)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*nzuimmhi = (instruction >> 12) & 0x1;
	*nzuimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_andi_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*immhi = (instruction >> 12) & 0x1;
	*immlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_sub_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*rs2 = (instruction >> 2) & 0x7;
}
void rv32imc_c_xor_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*rs2 = (instruction >> 2) & 0x7;
}
void rv32imc_c_or_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*rs2 = (instruction >> 2) & 0x7;
}
void rv32imc_c_and_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x7;
	*rs2 = (instruction >> 2) & 0x7;
}
void rv32imc_c_j_decode_fields (
	uint16_t *address,
	unsigned int *imm)
{
	uint16_t instruction = *address;
	*imm = (instruction >> 2) & 0x7ff;
}
void rv32imc_c_beqz_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint16_t instruction = *address;
	*rs1 = (instruction >> 7) & 0x7;
	*immhi = (instruction >> 10) & 0x7;
	*immlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_bnez_decode_fields (
	uint16_t *address,
	unsigned int *rs1,
	unsigned int *immhi,
	unsigned int *immlo)
{
	uint16_t instruction = *address;
	*rs1 = (instruction >> 7) & 0x7;
	*immhi = (instruction >> 10) & 0x7;
	*immlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_slli_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *nzuimmhi,
	unsigned int *nzuimmlo)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x1f;
	*nzuimmhi = (instruction >> 12) & 0x1;
	*nzuimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_lwsp_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *uimmhi,
	unsigned int *uimmlo)
{
	uint16_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*uimmhi = (instruction >> 12) & 0x1;
	*uimmlo = (instruction >> 2) & 0x1f;
}
void rv32imc_c_jr_decode_fields (
	uint16_t *address,
	unsigned int *rs1)
{
	uint16_t instruction = *address;
	*rs1 = (instruction >> 7) & 0x1f;
}
void rv32imc_c_mv_decode_fields (
	uint16_t *address,
	unsigned int *rd,
	unsigned int *rs2)
{
	uint16_t instruction = *address;
	*rd = (instruction >> 7) & 0x1f;
	*rs2 = (instruction >> 2) & 0x1f;
}
void rv32imc_c_jalr_decode_fields (
	uint16_t *address,
	unsigned int *rs1)
{
	uint16_t instruction = *address;
	*rs1 = (instruction >> 7) & 0x1f;
}
void rv32imc_c_add_decode_fields (
	uint16_t *address,
	unsigned int *rs1_rd,
	unsigned int *rs2)
{
	uint16_t instruction = *address;
	*rs1_rd = (instruction >> 7) & 0x1f;
	*rs2 = (instruction >> 2) & 0x1f;
}
void rv32imc_c_swsp_decode_fields (
	uint16_t *address,
	unsigned int *rs2,
	unsigned int *uimm)
{
	uint16_t instruction = *address;
	*rs2 = (instruction >> 2) & 0x1f;
	*uimm = (instruction >> 7) & 0x3f;
}
