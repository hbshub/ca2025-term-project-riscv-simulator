#ifndef LOADER_H
#define LOADER_H
#include "vm.h"

uint32_t load_elf(vm_t *vm, const char *filename);
uint32_t load_bin(vm_t *vm, const char *filename, uint32_t base_addr);
uint32_t load_program(vm_t *vm, const char *filename);

#endif // LOADER_H