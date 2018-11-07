#pragma once

#include "action.h"

typedef void (*vim_operation_fn)(void);
typedef struct {
  uint16_t key;
  vim_operation_fn op;
  bool held;
  uint16_t timer;
} vim_move_state;

bool process_record_user_vim_normal(uint16_t keycode, keyrecord_t *record);
bool process_record_user_vim_visual(uint16_t keycode, keyrecord_t *record);
void matrix_scan_vim(void);
