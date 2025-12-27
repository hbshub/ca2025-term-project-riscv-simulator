# RISC-V toolchain
CROSS_COMPILE = riscv-none-elf-
RV_CC         = $(CROSS_COMPILE)gcc
RV_OBJCOPY    = $(CROSS_COMPILE)objcopy
RV_CFLAGS     = -march=rv32i -mabi=ilp32 -nostdlib -T link.ld

# Pie Generator Settings
PIE_DIR      = pie
CONFIG_DIR   = pie_config
CORE_DIR     = src/core
ISA_DIR      = src/isa
GEN_OUT_DIR  = src/isa/generated
TARGET_ARCH  = rv32i

# Host toolchain
CC          = gcc
CFLAGS      = -Wall -g -O2 -Iinclude -I$(GEN_OUT_DIR)

# Simulator Source Files
SIM_SRCS     = src/main.c \
               $(wildcard $(CORE_DIR)/*.c) \
               $(wildcard $(ISA_DIR)/*.c) \
               $(wildcard $(GEN_OUT_DIR)/*.c)
SIM_OBJS     = $(SIM_SRCS:.c=.o)

# RISC-V Assembly Tests
SRCS_ASM     = $(wildcard test/*.S)
BINS         = $(SRCS_ASM:.S=.bin)


.INTERMEDIATE: $(SIM_OBJS)
.PHONY: all clean hello gen_pie sim

# Generate binaries and simulator
all: $(BINS) sim

# --- Target Rules (Build RISC-V Binaries) ---
%.elf: %.S
	@echo "RV_CC   $<"
	@$(RV_CC) $(RV_CFLAGS) $< -o $@

%.bin: %.elf
	@echo "EXTRACT $@"
	@$(RV_OBJCOPY) -O binary -j .text -j .data $< $@
	@chmod -x $@

# --- Host Rules (Build Simulator) ---
sim: $(SIM_OBJS)
	@echo "LINK    main"
	@$(CC) $(CFLAGS) -o main $(SIM_OBJS)

# 1. Main
src/main.o: src/main.c
	@echo "CC      $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# 2. Core Modules (cpu, ram, vm)
$(CORE_DIR)/%.o: $(CORE_DIR)/%.c
	@echo "CC      $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# 3. ISA Modules (exec, ext_rv32i)
$(ISA_DIR)/%.o: $(ISA_DIR)/%.c
	@echo "CC      $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# 4. Generated Files (Pie)
$(GEN_OUT_DIR)/%.o: $(GEN_OUT_DIR)/%.c
	@echo "CC      $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# --- Utility Rules ---
clean:
	rm -f test/*.elf src/*.o $(GEN_OUT_DIR)/*.o main test/*.bin

hello:
	@echo "--- Running Simulator ---"
	@./main test/hello.bin /dev/null 0 0 0

# --- Pie Generation Rules ---
PIE_TARGETS  = pie-$(TARGET_ARCH)-decoder.c \
               pie-$(TARGET_ARCH)-decoder.h \
               pie-$(TARGET_ARCH)-field-decoder.c \
               pie-$(TARGET_ARCH)-field-decoder.h

ISA_PARTS    = $(CONFIG_DIR)/rv32i.txt

gen_pie:
	@echo "--- Generating PIE sources for $(TARGET_ARCH) ---"
	@mkdir -p $(GEN_OUT_DIR)
	
	cat $(ISA_PARTS) > $(PIE_DIR)/$(TARGET_ARCH).txt

	# generate PIE sources
	cd $(PIE_DIR) && $(MAKE) ARCH=$(TARGET_ARCH) $(PIE_TARGETS)
	
	# move ouput files to GEN_OUT_DIR
	mv $(PIE_DIR)/pie-$(TARGET_ARCH)-*.c $(GEN_OUT_DIR)/
	mv $(PIE_DIR)/pie-$(TARGET_ARCH)-*.h $(GEN_OUT_DIR)/
	
	rm $(PIE_DIR)/$(TARGET_ARCH).txt
	@echo "--- Done! Generated $(TARGET_ARCH) in $(GEN_OUT_DIR) ---"

RISCOF_CONFIG := config.ini
ARCH_TEST_DIR := $(abspath ./riscv-arch-test)
.PHONY: riscof clean-riscof

riscof: sim
	@echo "--- Running RISC-V Architecture Tests ---"
	cd riscof_env && riscof run --config=$(RISCOF_CONFIG) \
								--suite=$(ARCH_TEST_DIR)/riscv-test-suite/ \
								--env=$(ARCH_TEST_DIR)/riscv-test-suite/env \
								--no-browser
clean-riscof:
	cd riscof_env && rm -rf riscof_work