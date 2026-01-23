#include "loader.h"

// Return value: Program entry point (PC Initial Value)
uint32_t load_elf(vm_t *vm, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) fatal("Failed to open ELF file: %s\n", filename);

    // 1. Read ELF Header
    Elf32_Ehdr ehdr;
    if (fread(&ehdr, 1, sizeof(Elf32_Ehdr), f) != sizeof(Elf32_Ehdr)) {
        fatal("File too small to be ELF\n");
    }

    // Check Magic Number
    if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3) {
        fatal("Not a valid ELF file\n");
    }

    // 2. Read Program Headers (describes which segments to load)
    fseek(f, ehdr.e_phoff, SEEK_SET);
    Elf32_Phdr *phdrs = malloc(sizeof(Elf32_Phdr) * ehdr.e_phnum);
    // Check if Program Headers are read successfully
    // fread returns the number of items successfully read
    if (fread(phdrs, sizeof(Elf32_Phdr), ehdr.e_phnum, f) != ehdr.e_phnum) {
        free(phdrs);
        fclose(f);
        fatal("Failed to read program headers\n");
    }

    // 3. Traverse all Headers and load segments with Type PT_LOAD
    for (int i = 0; i < ehdr.e_phnum; i++) {
        if (phdrs[i].p_type == PT_LOAD) {
            // Locate the data position in the file
            fseek(f, phdrs[i].p_offset, SEEK_SET);
            
            // Read data
            uint8_t *buffer = malloc(phdrs[i].p_filesz);
            // [Fix 2] Check if Segment data is read successfully
            if (fread(buffer, 1, phdrs[i].p_filesz, f) != phdrs[i].p_filesz) {
                free(buffer);
                free(phdrs);
                fclose(f);
                fatal("Failed to read segment data\n");
            }

            // Load segment into RAM at specified physical address
            ram_load_image(vm->ram, buffer, phdrs[i].p_filesz, phdrs[i].p_paddr);
            free(buffer);
            #ifdef DEBUG
                printf("[ELF] Segment loaded: 0x%08x (Size: %d)\n", phdrs[i].p_paddr, phdrs[i].p_filesz);
            #endif
        }
    }

    free(phdrs);
    fclose(f);
    
    // Return the program entry point specified by ELF
    return ehdr.e_entry; 
}

uint32_t load_bin(vm_t *vm, const char *filename, uint32_t base_addr) {
    // 1. open file
    FILE *f = fopen(filename, "rb");
    if (!f) fatal("Failed to open BIN file: %s\n", filename);

    // 2. get file size
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    rewind(f);

    // 3. read file content
    uint8_t *buffer = malloc(size);
    if (fread(buffer, 1, size, f) != size) {
        fatal("Failed to read BIN file\n");
    }
    fclose(f);

    // Load to specified base address
    ram_load_image(vm->ram, buffer, size, base_addr);
    vm->code_size = size;
    free(buffer);
    
    printf("[BIN] Loaded %zu bytes at 0x%08x\n", size, base_addr);
    // BIN files typically start execution from base_addr
    return base_addr;
}

// Auto-detect format and load
// Return: Entry Point (PC)
uint32_t load_program(vm_t *vm, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) fatal("File not found: %s\n", filename);

    uint8_t magic[4];
    if (fread(magic, 1, 4, f) != 4) {
        fclose(f);
        return 0; // file too small
    }
    fclose(f); // Close to let the following loader reopen

    // Check if it is ELF
    if (magic[0] == 0x7f && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F') {
        #ifdef DEBUG
            printf("[Info] Format: ELF\n");
        #endif
        return load_elf(vm, filename);
    } 
    else {
        #ifdef DEBUG
            printf("[Info] Format: Raw Binary\n");
        #endif
        return load_bin(vm, filename, 0x80000000); 
    }
}