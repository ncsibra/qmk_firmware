/* Copyright 2017 Wunder
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
#include "xd75.h"

// helpers
#define LEN(x) (sizeof (x) / sizeof (*(x)))

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define _QW  0
#define _FN  1
#define _BR  2
#define _MOV 3

// layer switches
#define F_DUAL  LT(_BR, KC_F)
#define J_DUAL  LT(_MOV, KC_J)
#define LG_DUAL LT(_FN, KC_LGUI)
#define RG_DUAL LT(_FN, KC_RGUI)

// Tap dance shortcuts
#define TD_MINS TD(TD_MINS_UND)
#define TD_ASTR TD(TD_ASTR_AMPR)
#define TD_EQL  TD(TD_EQL_PLUS)
#define TD_LSFT TD(TD_LSFT_LCTL)
#define TD_RSFT TD(TD_RSFT_RCTL)

//Tap Dance Declarations
enum {
  TD_MINS_UND = 0,
  TD_ASTR_AMPR,
  TD_EQL_PLUS,
  TD_LSFT_LCTL,
  TD_RSFT_RCTL
};

uint16_t tap_dance_keys[][2] = {
    [TD_LSFT_LCTL] = {KC_LSFT, KC_LCTL},
    [TD_RSFT_RCTL] = {KC_RSFT, KC_RCTL},
};

// Tap dance functions
void dance_sft_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][0]);
  } else {
    for (int i = 0; i < LEN(tap_dance_keys[state->keycode - QK_TAP_DANCE]); i++) {
      register_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][i]);
    }
  }
}

void dance_sft_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][0]);
  } else {
    for (int i = 0; i < LEN(tap_dance_keys[state->keycode - QK_TAP_DANCE]); i++) {
      unregister_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][i]);
    }
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MINS_UND]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
  [TD_ASTR_AMPR] = ACTION_TAP_DANCE_DOUBLE(KC_ASTR, KC_AMPR),
  [TD_EQL_PLUS]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL,  KC_PLUS),
  [TD_LSFT_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_finished, dance_sft_reset),
  [TD_RSFT_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_finished, dance_sft_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QW] = {
        /* QWERTY */
        {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
        {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT},
        {KC_CAPS, KC_A,    KC_S,    KC_D,    F_DUAL,  KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    J_DUAL,  KC_K,    KC_L,    KC_SCLN, KC_ENT},
        {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
        {KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  KC_SPC,  TD_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, TD_RSFT, KC_ENT,  KC_BSPC, KC_RALT, MO(_FN), KC_RCTL},
    },

    [_FN] = {
        /* FUNCTION */
        {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
        {_______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, KC_P6,   KC_P5,   KC_P4,   KC_PLUS, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, KC_P3,   KC_P2,   KC_P1,   KC_PENT, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU},
        {RESET,   _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, _______, _______, _______, _______, _______},
    },

    [_BR] = {
        /* Brackets */
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, TD_ASTR, KC_LCBR, KC_RCBR, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_LPRN, KC_RPRN, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______, _______},
        {_______, _______, _______, _______, KC_LSFT, KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    },

    [_MOV] = {
        /* Movement */
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, KC_END,  _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    }};

// some info on this: https://github.com/tmk/tmk_core/blob/master/doc/keymap.md#2-action
const uint16_t PROGMEM fn_actions[] = {

};
