/* c_hello.S */
.section .text
.global _start
_start:
    .option rvc         # enable compressed instructions support

    c.li a0, 1          # a0 (x10) = 1 (stdout)
    la a1, msg          # a1 (x11) = msg address
    c.li a2, 14         # a2 (x12) = 14 (length)
    li a7, 64           # a7 (x17) = 64 (sys_write)
    ecall

    c.li a0, 0          # a0 = 0
    li a7, 93           # sys_exit
    ecall

.section .data
msg:
    .ascii "Hello Compressed!\n"
# c.li / c.mv: values in range -32 to +31 (6-bit signed).
# c.lui: only handles -32 to +31 (6-bit signed, representing high bits).
# c.addi: also -32 to +31.
# c.addi16sp: larger range, -512 to +496 (requires 16-byte alignment).