    .section .text
    .globl _start

_start:
    # read(fd=0, buf, 256)
    li   a0, 0              # stdin
    la   a1, buf
    li   a2, 256
    li   a7, 63             # read
    ecall

    # a0 = read (nbytes)
    blez a0, done           # read 0 bytes, exit

    # write(fd=1, buf, nbytes)
    mv   a2, a0
    li   a0, 1              # stdout
    la   a1, buf
    li   a7, 64             # write
    ecall

    j    _start

done:
    li   a0, 0
    li   a7, 93             # exit
    ecall

    .section .bss
    .balign 4
buf:
    .skip 256
