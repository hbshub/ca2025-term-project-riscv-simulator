CC = riscv-none-elf-gcc
OBJCOPY = riscv-none-elf-objcopy

CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -T link.ld

SRCS_ASM = $(wildcard test/*.S)

BINS = $(SRCS_ASM:.S=.bin)


all: $(BINS) sim


%.elf: %.S
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $< -o $@

%.bin: %.elf
	@echo "Extracting binary to $@"
	@$(OBJCOPY) -O binary -j .text -j .data $< $@
	@chmod -x $@

sim: src/sim.c
	gcc -Wall -o sim src/sim.c

clean:
	rm -f sim test/*.elf test/*.bin src/*.o

run: all
	@echo "--- Running Simulator ---"
	@./sim test/hello.bin