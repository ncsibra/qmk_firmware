/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ncsibra.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = VA_KEYMAP(COLEMAK_LAYER),

[_QWERTY] = VA_KEYMAP(QWERTY_LAYER),

[_LOWER] = VA_KEYMAP(LOWER_LAYER),

[_RAISE] = VA_KEYMAP(RAISE_LAYER),

[_NUM] = VA_KEYMAP(NUM_LAYER),

[_VIM_N] = VA_KEYMAP(VIM_NORMAL_LAYER),

[_VIM_V] = VA_KEYMAP(VIM_INSERT_LAYER),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void matrix_scan_keymap(void) {}
