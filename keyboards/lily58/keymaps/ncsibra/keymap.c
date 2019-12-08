#include "ncsibra.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = VA_KEYMAP(COLEMAK_LAYER),

[_QWERTY] = VA_KEYMAP(QWERTY_LAYER),

[_LOWER] = VA_KEYMAP(LOWER_LAYER),

[_RAISE] = VA_KEYMAP(RAISE_LAYER),

[_NUM] = VA_KEYMAP(NUM_LAYER),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void matrix_scan_keymap(void) {}
