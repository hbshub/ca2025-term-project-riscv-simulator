#ifndef VM_CONFIG_H
#define VM_CONFIG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <elf.h>

#define fatal(args...)     \
    do {                   \
        printf("Fatal: "); \
        printf(args);      \
        exit(-1);          \
    } while (0)

enum {
    // stream need 230 MiB bss space
    RAM_SIZE = 1024 * 1024 * 256, /* 256 MiB */
    RAM_BASE = 0x80000000,
};

typedef enum {
    VM_STEP_RESULT_OK,
    VM_STEP_RESULT_HALT,
    VM_STEP_RESULT_ILLEGAL,
} vm_step_result_t;


#endif // VM_CONFIG_H