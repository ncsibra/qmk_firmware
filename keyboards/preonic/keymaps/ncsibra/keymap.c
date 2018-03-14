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

#include "keymap.h"

// Tap hold keys
static taphold_t th_events[] = {
  { .is_pressed = false, .timer = 0, .kc_tap = KC_GRV,  .kc_hold = KC_F11 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_1,    .kc_hold = KC_F1 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_2,    .kc_hold = KC_F2 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_3,    .kc_hold = KC_F3 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_4,    .kc_hold = KC_F4 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_5,    .kc_hold = KC_F5 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_6,    .kc_hold = KC_F6 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_7,    .kc_hold = KC_F7 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_8,    .kc_hold = KC_F8 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_9,    .kc_hold = KC_F9 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_0,    .kc_hold = KC_F10 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_BSPC, .kc_hold = KC_F12 },


  { .is_pressed = false, .timer = 0, .kc_tap = KC_X,    .kc_hold = LCTL(KC_X) },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_C,    .kc_hold = LCTL(KC_INS) },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_V,    .kc_hold = LSFT(KC_INS) },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_S,    .kc_hold = LCTL(KC_S) },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {TH_GRV,  TH_1,    TH_2,    TH_3,    TH_4,    TH_5,    TH_6,    TH_7,    TH_8,    TH_9,    TH_0,    TH_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT},
  {SFT_T(KC_ESC),  KC_A,    TH_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SFT_T(KC_ENT)},
  {KC_LCTL, KC_Z,    TH_X,    TH_C,    TH_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL},
  {KC_LEAD, KC_QUOT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_GRV,  KC_1,    KC_2,    KC_UP,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {_______,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_END,  KC_F8,   KC_F9,   KC_F10,  KC_PGDN, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return process_record_user_taphold(keycode, record);
};

bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      scan_tap_hold(TAPPED);
  }

  if (keycode < TH_FIRST || keycode > TH_LAST) { return true; }

  taphold_t *th_event = &th_events[keycode - TH_FIRST];

  if (record->event.pressed) {
      th_event->timer = timer_read();
      th_event->is_pressed = true;
  } else if (th_event->is_pressed) {
      register_code16(th_event->kc_tap);
      unregister_code16(th_event->kc_tap);
      th_event->is_pressed = false;
  }

  return false;
}

void scan_tap_hold(taphold_state state) {
  for (uint8_t index = 0 ; index < TH_EVENTS_COUNT ; ++index ) {
      taphold_t *th_event = &th_events[index];
      if (!th_event->is_pressed) { continue; }
      if (state == TAPPED || timer_elapsed(th_event->timer) > TH_DELAY) {
          uint16_t code = state == HELD ? th_event->kc_hold : th_event->kc_tap;
          register_code16(code);
          unregister_code16(code);
          th_event->is_pressed = false;
      }
  }
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Intellij shortcuts

    // rename
    SEQ_ONE_KEY(KC_R) {
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_R);

      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      unregister_code(KC_R);
    }
  }

  scan_tap_hold(HELD);
}
