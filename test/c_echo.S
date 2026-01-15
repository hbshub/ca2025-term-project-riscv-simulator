.section .text
    .globl _start
# c.li / c.mv: values in range -32 to +31 (6-bit signed).
_start:
    .option rvc         # enable compressed instructions support
    # read(fd=0, buf, 256)
    c.li    a0, 0
    la      a1, buf
    li      a2, 256
    li      a7, 63
    ecall

    blez    a0, done

    # write(fd=1, buf, nbytes)
    c.mv    a2, a0
    c.li    a0, 1
    la      a1, buf
    li      a7, 64
    ecall

    c.j     _start

done:
    c.li    a0, 0
    li      a7, 93
    ecall

    .section .bss
    .balign 4
buf:
    .skip 256
    