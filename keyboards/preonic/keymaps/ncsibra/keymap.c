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
#include "vim.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = {
  {TH_ESC,         TH_1,     TH_2,     TH_3,           TH_4,         TH_5,    TH_6,    TH_7,        TH_8,     TH_9,     TH_0,     TH_BSPC},
  {KC_TAB,         KC_Q,     KC_W,     KC_E,           KC_R,         KC_T,    KC_Y,    KC_U,        KC_I,     KC_O,     KC_P,     KC_QUOT},
  {KC_ESC,         KC_A,     KC_S,     KC_D,           KC_F,         KC_G,    KC_H,    KC_J,        KC_K,     KC_L,     KC_SCLN,  KC_ENT},
  {OSM(MOD_LSFT),  KC_Z,     KC_X,     KC_C,           KC_V,         KC_B,    KC_N,    KC_M,        KC_COMM,  KC_DOT,   KC_SLSH,  OSM(MOD_RSFT)},
  {TT(_NUM),       KC_LGUI,  KC_LALT,  CTL_T(KC_DEL),  OSL(_LOWER),  KC_SPC,  KC_BSPC, TT(_RAISE),  KC_RCTRL, KC_RALT,  TG(_NUM), KC_LEAD}
},

/* Lower
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |   !  |   [  |   ]  |   *  |   &  |   |  |      |   '  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   @  |   #  |   `  |   :  |   (  |   )  |   =  |   +  |   "  |      |   "  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   ^  |   %  |   $  |   ~  |   {  |   }  |   _  |   -  |   \  |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      | Lower|      |      |Raise |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = {
  {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,    KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_EXLM,     KC_LBRC,    KC_RBRC,   KC_ASTR,     KC_AMPR,    KC_PIPE,   XXXXXXX,    KC_QUOT},
  {_______,    KC_AT,      KC_HASH,    KC_GRV,     KC_COLN,     KC_LPRN,    KC_RPRN,   KC_EQL,      KC_PLUS,    KC_DQUO,   XXXXXXX,    KC_DQUO},
  {_______,    KC_CIRC,    KC_PERC,    KC_DLR,     KC_TILD,     KC_LCBR,    KC_RCBR,   KC_UNDS,     KC_MINS,    KC_BSLS,   XXXXXXX,    _______},
  {_______,    _______,    _______,    _______,    _______,    _______,     KC_DEL,    TO(_VIM_N),    _______,    _______,   _______,    XXXXXXX}
},

[_RAISE] = {
  {RESET,      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSPC},
  {DEBUG,      XXXXXXX,    LSFT(KC_HOME), LSFT(KC_UP),   LSFT(KC_END),   XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    KC_DEL},
  {KC_CAPS,    XXXXXXX,    LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,    _______},
  {_______,    XXXXXXX,    LSFT(KC_PGUP), XXXXXXX,       LSFT(KC_PGDN),  XXXXXXX,    XXXXXXX,    KC_PGUP,    XXXXXXX,    KC_PGDN,    XXXXXXX,    _______},
  {_______,    _______,    _______,       _______,       TO(_VIM_N),       _______,    _______,    _______,    _______,    _______,    _______,    _______}
},

[_NUM] = {
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,    KC_NUMLOCK, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,    KC_KP_7,    KC_KP_8,     KC_KP_9,     KC_KP_MINUS,    XXXXXXX},
  {KC_VOLU,    LCTL(KC_A), LCTL(KC_S),    XXXXXXX,      LCTL(KC_F),   XXXXXXX,   XXXXXXX,    KC_KP_4,    KC_KP_5,     KC_KP_6,     KC_KP_PLUS,     KC_KP_ENTER},
  {KC_VOLD,    LCTL(KC_Z), LCTL(KC_X),    LCTL(KC_INS), LSFT(KC_INS), XXXXXXX,   XXXXXXX,    KC_KP_1,    KC_KP_2,     KC_KP_3,     XXXXXXX,        XXXXXXX},
  {_______,    _______,    _______,       TO(_QWERTY),  XXXXXXX,      KC_SPC,    KC_BSPC,    KC_KP_0,    KC_KP_DOT,   XXXXXXX,     TO(_QWERTY),    XXXXXXX}
},

[_VIM_N] = {
  {XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, VIM_DLR,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_0,   XXXXXXX},
  {XXXXXXX,       XXXXXXX, VIM_W,   XXXXXXX, XXXXXXX,     XXXXXXX,  VIM_Y,   VIM_U,   VIM_I,   VIM_O,   VIM_P,   XXXXXXX},
  {TO(_QWERTY),   VIM_A,   VIM_S,   VIM_D,   XXXXXXX,     VIM_G,    VIM_H,   VIM_J,   VIM_K,   VIM_L,   XXXXXXX, KC_ENT},
  {OSM(MOD_LSFT), XXXXXXX, VIM_X,   VIM_C,   TO(_VIM_V),  VIM_B,    XXXXXXX, XXXXXXX, XXXXXXX, VIM_DOT, XXXXXXX, OSM(MOD_RSFT)},
  {XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[_VIM_V] = {
  {XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, VIM_V_DLR,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_V_0, XXXXXXX},
  {XXXXXXX,       XXXXXXX, VIM_V_W, XXXXXXX, XXXXXXX,     XXXXXXX,  VIM_V_Y, XXXXXXX, VIM_I,   XXXXXXX, VIM_V_P, XXXXXXX},
  {TO(_VIM_N),    XXXXXXX, VIM_V_S, VIM_V_D, XXXXXXX,     VIM_V_G,  VIM_V_H, VIM_V_J, VIM_V_K, VIM_V_L, XXXXXXX, KC_ENT},
  {OSM(MOD_LSFT), XXXXXXX, VIM_X,   VIM_V_C, VIM_V_V,     VIM_V_B,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RSFT)},
  {XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
}
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void matrix_scan_keymap(void) {}
