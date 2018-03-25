#ifndef VIM_CONFIG_H
#define VIM_CONFIG_H

#include "action.h"

typedef void (*vim_operation_fn)(void);
typedef struct {
  vim_operation_fn op;
  bool pressed;
} vim_move_state;

bool process_record_user_vim_normal(uint16_t keycode, keyrecord_t *record);
bool process_record_user_vim_visual(uint16_t keycode, keyrecord_t *record);

#endif
