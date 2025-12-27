#include "ram.h"

ram_t *ram_new()
{
    ram_t *ram = malloc(sizeof(ram_t));
    ram->mem = malloc(RAM_SIZE);
    memset(ram->mem, 0, RAM_SIZE);
    return ram;
}

void ram_free(ram_t *ram)
{
    free(ram->mem);
    free(ram);
}

static inline void check_addr(uint32_t addr)
{
    size_t index = addr - RAM_BASE;
    if (index >= RAM_SIZE) fatal("out of memory.\n");
}

static uint32_t ram_load8(ram_t *mem, uint32_t addr)
{
    size_t index = addr - RAM_BASE;
    return (uint32_t) mem->mem[index];
}

static uint32_t ram_load16(ram_t *mem, uint32_t addr)
{
    size_t index = addr - RAM_BASE;
    return ((uint32_t) mem->mem[index] | ((uint32_t) mem->mem[index + 1] << 8));
}

static uint32_t ram_load32(ram_t *mem, uint32_t addr)
{
    size_t index = addr - RAM_BASE;
    return ((uint32_t) mem->mem[index] |
            ((uint32_t) mem->mem[index + 1] << 8) |
            ((uint32_t) mem->mem[index + 2] << 16) |
            ((uint32_t) mem->mem[index + 3] << 24));
}

uint32_t ram_load(ram_t *mem, uint32_t addr, uint8_t size) 
{
    check_addr(addr);
    uint32_t r = 0;
    switch (size) {
        case 8: r = ram_load8(mem, addr); break;
        case 16: r = ram_load16(mem, addr); break;
        case 32: r = ram_load32(mem, addr); break;
        default: fatal("RAM: invalid load size(%d)\n", size);
    }
    return r;
}

static void ram_store32(ram_t *mem, uint32_t addr, uint8_t size, uint32_t value)
{
    size_t index = addr - RAM_BASE;
    mem->mem[index] = value & 0xFF;
    mem->mem[index + 1] = (value >> 8) & 0xFF;
    mem->mem[index + 2] = (value >> 16) & 0xFF;
    mem->mem[index + 3] = (value >> 24) & 0xFF;
}

static void ram_store16(ram_t *mem, uint32_t addr, uint8_t size, uint32_t value)
{
    size_t index = addr - RAM_BASE;
    mem->mem[index] = value & 0xFF;
    mem->mem[index + 1] = (value >> 8) & 0xFF;
}

static void ram_store8(ram_t *mem, uint32_t addr, uint8_t size, uint32_t value)
{
    size_t index = addr - RAM_BASE;
    mem->mem[index] = value & 0xFF;
}

void ram_store(ram_t *mem, uint32_t addr, uint8_t size, uint32_t value)
{
    check_addr(addr);
    switch (size) {
        case 8: ram_store8(mem, addr, size, value); break;
        case 16: ram_store16(mem, addr, size, value); break;
        case 32: ram_store32(mem, addr, size, value); break;
        default: fatal("RAM: invalid load size(%d)\n", size);
    }
}

void ram_load_image(ram_t *mem, uint8_t *code, size_t code_size, uint32_t base_addr)
{
    size_t index = base_addr - RAM_BASE;
    memcpy(&mem->mem[index], code, code_size);
}