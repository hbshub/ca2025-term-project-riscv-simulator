#include "vm.h"

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
    // dump signature region from RAM to output file
    for (uint32_t addr = TARGET_SIG_START; addr < TARGET_SIG_END; addr += 4) {
        uint32_t val = ram_load(vm->ram, addr, 32);
        // write human readable hex format, not use fwrite()
        fprintf(fp, "%08x\n", val);
    }
    fclose(fp);
}

static uint8_t *read_file(const char *filename, size_t *out_size)
{
    /* Read the entire binary contents of a file into a buffer */
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open %s\n", filename);
        exit(-1);
    }
    fseek(file, 0L, SEEK_END);
    size_t code_size = ftell(file);
    rewind(file);

    uint8_t *code = malloc(code_size);
    size_t read_size = fread(code, sizeof(uint8_t), code_size, file);
    if (read_size != code_size) {
        fprintf(stderr, "Failed to read the entire file %s\n", filename);
        fclose(file);
        exit(-1);
    }
    fclose(file);

    *out_size = code_size;
    return code;
}

int main(int argc, char *argv[])
{
    // 1: binary_file
    // 2: signature_output_file
    // 3: sig_start_addr (hex)
    // 4: sig_end_addr (hex)
    // 5: tohost_addr (hex)
    
    if (argc < 6) {
        printf("Usage: %s <bin_file> <sig_file> <sig_start> <sig_end> <tohost>\n", argv[0]);
        exit(-1);
    }

    const char *filename = argv[1];
    SIG_OUTPUT_FILE = argv[2];
    TARGET_SIG_START = strtoul(argv[3], NULL, 16);
    TARGET_SIG_END = strtoul(argv[4], NULL, 16);
    TARGET_TOHOST = strtoul(argv[5], NULL, 16);

    size_t code_size;
    uint8_t *code = read_file(filename, &code_size);

    /* Initialize RAM, CPU, VM and load code to the RAM */
    vm_t *vm = vm_new(code, code_size);
    free(code);
    vm_step_result_t result = vm_run(vm, TARGET_TOHOST);
    dump_signature(vm);
    vm_free(vm);

    return (result == VM_STEP_RESULT_HALT) ? 0 : -1;

}
