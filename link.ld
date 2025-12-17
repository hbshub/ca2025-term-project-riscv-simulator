OUTPUT_ARCH( "riscv" )
ENTRY( _start )

MEMORY
{
  /* 2M MEMORY */
  ram (wxa) : ORIGIN = 0x00000000, LENGTH = 2M
}

SECTIONS
{
  . = 0x00000000;

  /* Code Data */
  .text : {
    *(.text .text.*)
  } > ram

  /* Read-only Data */
  .rodata : {
    *(.rodata .rodata.*)
  } > ram

  /* Data */
  .data : {
    *(.data .data.*)
  } > ram
}