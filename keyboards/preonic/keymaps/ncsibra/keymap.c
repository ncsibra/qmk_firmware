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

// #include "keymap.h"
#include "vim.h"

// Tap hold keys
static taphold_t th_events[] = {
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_ESC,  .kc_hold = KC_F11 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_1,    .kc_hold = KC_F1 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_2,    .kc_hold = KC_F2 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_3,    .kc_hold = KC_F3 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_4,    .kc_hold = KC_F4 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_5,    .kc_hold = KC_F5 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_6,    .kc_hold = KC_F6 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_7,    .kc_hold = KC_F7 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_8,    .kc_hold = KC_F8 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_9,    .kc_hold = KC_F9 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_0,    .kc_hold = KC_F10 },
  { .is_pressed = false, .is_double = false, .timer = 0, .kc_tap = KC_BSPC, .kc_hold = KC_F12 },
};

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
  {_______,    _______,    _______,    _______,    _______,    _______,     KC_DEL,    TG(_VIM),    _______,    _______,   _______,    XXXXXXX}
},

[_RAISE] = {
  {RESET,      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSPC},
  {DEBUG,      XXXXXXX,    LSFT(KC_HOME), LSFT(KC_UP),   LSFT(KC_END),   XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    KC_DEL},
  {KC_CAPS,    XXXXXXX,    LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,    _______},
  {_______,    XXXXXXX,    LSFT(KC_PGUP), XXXXXXX,       LSFT(KC_PGDN),  XXXXXXX,    XXXXXXX,    KC_PGUP,    XXXXXXX,    KC_PGDN,    XXXXXXX,    _______},
  {_______,    _______,    _______,       _______,       TG(_VIM),       _______,    _______,    _______,    _______,    _______,    _______,    _______}
},

[_VIM] = {
  {XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX,     XXXXXXX, VIM_W,   VIM_E,   XXXXXXX,     XXXXXXX, VIM_Y,   VIM_U,   VIM_I,   VIM_O,   VIM_P,   XXXXXXX},
  {TO(_QWERTY), VIM_A,   VIM_S,   VIM_D,   XXXXXXX,     XXXXXXX, VIM_H,   VIM_J,   VIM_K,   VIM_L,   XXXXXXX, XXXXXXX},
  {XXXXXXX,     XXXXXXX, VIM_X,   VIM_C,   VIM_V,       VIM_B,   XXXXXXX, XXXXXXX, XXXXXXX, VIM_DOT, XXXXXXX, XXXXXXX},
  {XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

[_NUM] = {
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    KC_NUMLOCK, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,    XXXXXXX,    KC_KP_7,    KC_KP_8,     KC_KP_9,     KC_KP_MINUS,    XXXXXXX},
  {KC_VOLU,    XXXXXXX,    LCTL(KC_S),    XXXXXXX,      LCTL(KC_F),   XXXXXXX,    XXXXXXX,    KC_KP_4,    KC_KP_5,     KC_KP_6,     KC_KP_PLUS,     KC_KP_ENTER},
  {KC_VOLD,    LCTL(KC_Z), LCTL(KC_X),    LCTL(KC_INS), LSFT(KC_INS), XXXXXXX,    XXXXXXX,    KC_KP_1,    KC_KP_2,     KC_KP_3,     XXXXXXX,        XXXXXXX},
  {_______,    _______,    _______,       TO(_QWERTY),  XXXXXXX,      KC_SPC,     KC_BSPC,    KC_KP_0,    KC_KP_DOT,   XXXXXXX,     TO(_QWERTY),    XXXXXXX}
}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (IS_LAYER_ON(_VIM) && record->event.pressed) {
    bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                  (keyboard_report->mods & MOD_BIT(KC_RSFT));

    switch (keycode) {

      case VIM_A:
        SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND();
        return false;

      case VIM_B:
        switch(VIM_QUEUE) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
        return false;

      case VIM_C:
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
        return false;

      case VIM_D:
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_REC(VIM_DELETE_WHOLE_LINE); break;
        }
        return false;

      case VIM_E:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
        return false;

      case VIM_H:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_LEFT(); break;
          case VIM_C: VIM_CHANGE_LEFT(); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
        }
        return false;

      case VIM_I:
        switch (VIM_QUEUE) {
          case KC_NO: layer_on(_QWERTY); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
        }
        return false;

      case VIM_J:
        switch (VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
          case VIM_C: VIM_CHANGE_DOWN(); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
        }
        return false;

      case VIM_K:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_UP(); break;
          case VIM_C: VIM_CHANGE_UP(); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
        }
        return false;

      case VIM_L:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_RIGHT(); break;
          case VIM_C: VIM_CHANGE_RIGHT(); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
        }
        return false;

      case VIM_O:
        SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN();
        return false;

      case VIM_P:
        SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT();
        return false;

      case VIM_S:
        SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE();
        return false;

      case VIM_U:
        VIM_UNDO();
        return false;

      case VIM_V:
        VIM_LEADER(VIM_V);
        return false;

      case VIM_W:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_REC(VIM_DELETE_WORD); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
        return false;

      case VIM_X:
        VIM_CUT();
        return false;

      case VIM_Y:
        SHIFTED ? VIM_YANK_LINE() : VIM_YANK();
        return false;
      case VIM_DOT:
        VIM_DOT_REPEAT();
        return false;
    }
  }

  return process_record_user_taphold(keycode, record);
};

static uint16_t prev_th_key = KC_NO;
static uint16_t prev_th_time = 0;

bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      scan_tap_hold(TAPPED);
  }

  if (keycode < TH_FIRST || keycode > TH_LAST) { return true; }

  taphold_t *th_event = &th_events[keycode - TH_FIRST];

  // if pressed twice fast, hold KC_TAP instead of usual logic, Mod Tap functionality works similarly
  if (record->event.pressed) {
    if (keycode == prev_th_key && timer_elapsed(prev_th_time) < TH_DELAY) {
      register_code16(th_event->kc_tap);
      th_event->is_double = true;
      return false;
    } else {
      prev_th_key = keycode;
      prev_th_time = timer_read();
    }
  }

  if (record->event.pressed) {
      th_event->timer = timer_read();
      th_event->is_pressed = true;
  } else if (th_event->is_pressed) {
      register_code16(th_event->kc_tap);
      unregister_code16(th_event->kc_tap);
      th_event->is_pressed = false;
  } else if (th_event->is_double) {
      unregister_code16(th_event->kc_tap);
      th_event->is_double = false;
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
