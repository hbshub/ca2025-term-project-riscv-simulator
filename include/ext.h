#ifndef EXT_H
#define EXT_H
#include "cpu.h"

typedef struct {
  const char *name;
  
  /* decide the extension whether to handle this instruction */
  bool (*match)(uint32_t raw, int len);

  /* execute the instruction */
  vm_step_result_t (*exec)(cpu_t *cpu, uint32_t raw, int len, uint32_t pc_current);

} ext_t;

#endif // EXT_H