OUTPUT_ARCH( "riscv" )
ENTRY( _start )

MEMORY
{
  /* 256M MEMORY */
  ram (rwx) : ORIGIN = 0x80000000, LENGTH = 256M
}

SECTIONS
{
  . = 0x80000000;

  /* Code Data */
  .text : {
    *(.text .text.*)
  } > ram

  /* Read-only Data */
  .rodata : {
    . = ALIGN(4);
    *(.rodata .rodata.*)
  } > ram

  /* Data */
  .data : {
    . = ALIGN(8);
    *(.data .data.*)
  } > ram

  /* BSS */
  .bss : {
    . = ALIGN(8);
    _sbss = .;
    *(.bss .bss.*)
    *(COMMON)
    . = ALIGN(8);
    _ebss = .;
  } > ram

  /* Stack */
  . = ALIGN(16);
  PROVIDE( _stack_top = ORIGIN(ram) + LENGTH(ram) );
}