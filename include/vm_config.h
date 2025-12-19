#ifndef VM_CONFIG_H
#define VM_CONFIG_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define fatal(args...)     \
    do {                   \
        printf("Fatal: "); \
        printf(args);      \
        exit(-1);          \
    } while (0)

enum {
    RAM_SIZE = 1024 * 1024 * 2, /* 2 MiB */
    RAM_BASE = 0x0,
};

typedef enum {
    VM_STEP_RESULT_OK,
    VM_STEP_RESULT_HALT,
    VM_STEP_RESULT_ILLEGAL,
} vm_step_result_t;


#endif // VM_CONFIG_H