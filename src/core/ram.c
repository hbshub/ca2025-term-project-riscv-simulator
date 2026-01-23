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

static inline long get_ram_index(uint32_t addr) {
    if (addr >= RAM_BASE) {
        // situation A: RISCOF (0x8000xxxx -> 0xxxx)
        return addr - RAM_BASE;
    } else {
        // situation B: Prebuilt Benchmarks (0x0000xxxx -> 0xxxx)
        return addr;
    }
}

static inline void check_ram_bounds(size_t index, size_t size) {
    // Check for out-of-bounds access
    if (index + size > RAM_SIZE) {
        fatal("out of memory access at index 0x%zx, size %zu\n", index, size);
    }
}

static uint32_t ram_load8(ram_t *mem, size_t index)
{
    return (uint32_t) mem->mem[index];
}

static uint32_t ram_load16(ram_t *mem, size_t index)
{
    return ((uint32_t) mem->mem[index] | ((uint32_t) mem->mem[index + 1] << 8));
}

static uint32_t ram_load32(ram_t *mem, size_t index)
{
    return ((uint32_t) mem->mem[index] |
            ((uint32_t) mem->mem[index + 1] << 8) |
            ((uint32_t) mem->mem[index + 2] << 16) |
            ((uint32_t) mem->mem[index + 3] << 24));
}

uint32_t ram_load(ram_t *mem, uint32_t addr, uint8_t size) 
{
    // 1. get ram index (0x0 and 0x80000000 both map to 0)
    long idx = get_ram_index(addr);
    
    // 2. check bounds
    // print debug info before fatal
    if (idx < 0 || (size_t)idx + size/8 > RAM_SIZE) {
        #ifdef DEBUG
            printf("[Debug] Crash Addr Load: 0x%08x -> Index: 0x%lx\n", addr, idx);
        #endif
        fatal("RAM: out of bounds\n");
    }
    check_ram_bounds((size_t)idx, size / 8);
    
    uint32_t r = 0;
    switch (size) {
        // 3. pass idx to load functions
        case 8: r = ram_load8(mem, (size_t)idx); break;
        case 16: r = ram_load16(mem, (size_t)idx); break;
        case 32: r = ram_load32(mem, (size_t)idx); break;
        default: fatal("RAM: invalid load size(%d)\n", size);
    }
    return r;
}

static void ram_store32(ram_t *mem, size_t index, uint32_t value)
{
    mem->mem[index] = value & 0xFF;
    mem->mem[index + 1] = (value >> 8) & 0xFF;
    mem->mem[index + 2] = (value >> 16) & 0xFF;
    mem->mem[index + 3] = (value >> 24) & 0xFF;
}

static void ram_store16(ram_t *mem, size_t index, uint32_t value)
{
    mem->mem[index] = value & 0xFF;
    mem->mem[index + 1] = (value >> 8) & 0xFF;
}

static void ram_store8(ram_t *mem, size_t index, uint32_t value)
{
    mem->mem[index] = value & 0xFF;
}

void ram_store(ram_t *mem, uint32_t addr, uint8_t size, uint32_t value)
{
    long index = get_ram_index(addr);

    // print debug info before fatal
    if (index < 0 || (size_t)index + size/8 > RAM_SIZE) {
        #ifdef DEBUG
            printf("[Debug] Crash Addr Store: 0x%08x -> Index: 0x%lx\n", addr, index);
        #endif
        fatal("RAM: out of bounds\n");
    }
    check_ram_bounds((size_t)index, size / 8);

    switch (size) {
        case 8: ram_store8(mem, (size_t)index, value); break;
        case 16: ram_store16(mem, (size_t)index, value); break;
        case 32: ram_store32(mem, (size_t)index, value); break;
        default: fatal("RAM: invalid store size(%d)\n", size);
    }
}

void ram_load_image(ram_t *mem, uint8_t *code, size_t code_size, uint32_t base_addr)
{
    long index = get_ram_index(base_addr);
    if (index < 0 || (size_t)index + code_size > RAM_SIZE) {
        #ifdef DEBUG
        fprintf(stderr, "[Fatal] Load image failed! Addr: 0x%x, Index: %ld, Size: %zu\n", 
            base_addr, index, code_size);
        #endif
        exit(-1);
    }
    memcpy(&mem->mem[index], code, code_size);
    #ifdef DEBUG
        printf("[Info] Loaded at RAM index 0x%lx (Virt: 0x%x)\n", index, base_addr);
    #endif
}