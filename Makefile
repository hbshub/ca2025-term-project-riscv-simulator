CC = riscv-none-elf-gcc
OBJCOPY = riscv-none-elf-objcopy
CFLAGS = -march=rv32i -mabi=ilp32 -nostdlib -T link.ld

SRCS_ASM = $(wildcard test/*.S)
BINS = $(SRCS_ASM:.S=.bin)

SIM_SRCS = $(wildcard src/*.c)
SIM_OBJS = $(SIM_SRCS:.c=.o)

.INTERMEDIATE: $(SIM_OBJS)
.PHONY: all clean run

# Generate binaries and simulator
all: $(BINS) sim

%.elf: %.S
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $< -o $@

%.bin: %.elf
	@echo "Extracting binary to $@"
	@$(OBJCOPY) -O binary -j .text -j .data $< $@
	@chmod -x $@

# Build the simulator
sim: $(SIM_OBJS)
	@gcc -Wall -o main $(SIM_OBJS)

src/%.o: src/%.c
	@gcc -Wall -Iinclude -c $< -o $@

clean:
	rm -f test/*.elf src/*.o

run:
	@echo "--- Running Simulator ---"
	@./main test/hello.bin