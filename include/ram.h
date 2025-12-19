#ifndef RAM_H
#define RAM_H
#include "vm_config.h"

typedef struct {
    uint8_t *mem;
} ram_t;

ram_t *ram_new();
void ram_free(ram_t *mem);
uint32_t ram_load(ram_t *mem, uint32_t addr, uint8_t size);
void ram_store(ram_t *mem, uint32_t addr, uint32_t value);
void ram_load_image(ram_t *mem, uint8_t *code, size_t code_size, uint32_t base_addr);

#endif // RAM_H