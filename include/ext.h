#ifndef EXT_H
#define EXT_H
#include "cpu.h"
#include "pie-rv32i-decoder.h"

typedef vm_step_result_t (*inst_handler_t)(
    cpu_t *cpu,
    rv32i_instruction inst_id,
    uint32_t raw, 
    uint32_t pc_current
);

typedef struct {
  const char *name;
  
  /* decide the extension instruction handle range */
  rv32i_instruction start_id;
  rv32i_instruction end_id;

  /* execute function */
  inst_handler_t exec;

} ext_t;

#endif // EXT_H