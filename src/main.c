#include "vm.h"

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
    fread(code, sizeof(uint8_t), code_size, file);
    fclose(file);

    *out_size = code_size;
    return code;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(-1);
    }

    const char *filename = argv[1];
    size_t code_size;
    uint8_t *code = read_file(filename, &code_size);

    /* Initialize RAM, CPU, VM and load code to the RAM */
    vm_t *vm = vm_new(code, code_size);
    free(code);
    vm_step_result_t result = vm_run(vm);
    vm_free(vm);

    return (result == VM_STEP_RESULT_HALT) ? 0 : -1;

}
