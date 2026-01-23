#include "vm.h"
#include "loader.h"

static uint32_t TARGET_SIG_START = 0;
static uint32_t TARGET_SIG_END = 0;
static uint32_t TARGET_TOHOST = 0;
static const char *SIG_OUTPUT_FILE = NULL;

void dump_signature(vm_t *vm) {
    if (!SIG_OUTPUT_FILE) return;
    
    FILE *fp = fopen(SIG_OUTPUT_FILE, "w");
    if (!fp) {
        printf("Failed to open signature output file %s\n", SIG_OUTPUT_FILE);
        return;
    }
    // Dump signature region from RAM to output file
    for (uint32_t addr = TARGET_SIG_START; addr < TARGET_SIG_END; addr += 4) {
        uint32_t val = ram_load(vm->ram, addr, 32);
        // Write human readable hex format, not use fwrite()
        fprintf(fp, "%08x\n", val);
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    // 1: binary_file
    // 2: signature_output_file
    // 3: sig_start_addr (hex)
    // 4: sig_end_addr (hex)
    // 5: tohost_addr (hex)

    if (argc >= 6) {
        SIG_OUTPUT_FILE = argv[2];
        TARGET_SIG_START = strtoul(argv[3], NULL, 16);
        TARGET_SIG_END = strtoul(argv[4], NULL, 16);
        TARGET_TOHOST = strtoul(argv[5], NULL, 16);
    } else if (argc == 2) {
        // Only binary file provided, no signature dumping
        SIG_OUTPUT_FILE = NULL;
    } else {
        // Usage reminder
        printf("Usage:\n");
        printf("  Run:  %s <bin_file>\n", argv[0]);
        printf("  Test: %s <bin_file> <sig_file> <sig_start> <sig_end> <tohost>\n", argv[0]);
        exit(-1);
    }

    const char *filename = argv[1];

    /* Initialize RAM, CPU and load code to the RAM */
    vm_t *vm = vm_new();
    uint32_t entry_point = load_program(vm, filename);
    vm->cpu->pc = entry_point;

    // 3. Determine if the program runs at low address (0x0) or high address (0x80000000)
    // vm->cpu->regs[2] = (RAM_SIZE - 0x100000) + (entry_point & 0x80000000);
    if (entry_point < 0x80000000) {
        // Prebuilt Benchmarks
        // Stack is set at the end of physical RAM (256MB location)
        // Since it starts at 0x0, SP directly equals RAM_SIZE - 0x100000
        vm->cpu->regs[2] = (RAM_SIZE - 0x100000); 
    } else {
        // RISCOF / Linker Script 0x80000000
        // Stack is set at the end of mapped virtual address
        vm->cpu->regs[2] = (RAM_SIZE - 0x100000) + 0x80000000;
    }

    #ifdef DEBUG
        printf("[System] PC set to: 0x%x, SP set to: 0x%x\n", vm->cpu->pc, vm->cpu->regs[2]);
    #endif
    vm_step_result_t result = vm_run(vm, TARGET_TOHOST);
    dump_signature(vm);
    vm_free(vm);

    return (result == VM_STEP_RESULT_HALT) ? 0 : -1;

}
