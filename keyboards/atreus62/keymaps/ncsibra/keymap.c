#include "ncsibra.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = VA_KEYMAP(COLEMAK_LAYER, NUM_MID),

[_QWERTY] = VA_KEYMAP(QWERTY_LAYER, NUM_MID),

[_LOWER] = VA_KEYMAP(LOWER_LAYER, BLANK_MID),

[_RAISE] = VA_KEYMAP(RAISE_LAYER, BLANK_MID),

[_NUM] = VA_KEYMAP(NUM_LAYER, BLANK_MID),

[_VIM_N] = VA_KEYMAP(VIM_NORMAL_LAYER, BLANK_MID),

[_VIM_V] = VA_KEYMAP(VIM_INSERT_LAYER, BLANK_MID),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void matrix_scan_keymap(void) {};
