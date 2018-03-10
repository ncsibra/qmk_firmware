#include "keymap.h"

// layer switches
#define F_DUAL  LT(_BR, KC_F)
#define J_DUAL  LT(_MOV, KC_J)

#define MT_Z    SFT_T(KC_Z)
#define MT_SLSH SFT_T(KC_SLSH)
#define MT_LCTL CTL_T(KC_ESC)
// #define MT_ASFT MT(MOD_LSFT, KC_A)
// #define MT_CSFT MT(MOD_LSFT, KC_SCLN)
// #define MT_RSCP MT(MOD_LSFT, KC_SPC)
// #define MT_RENT MT(MOD_RSFT, KC_ENT)

// Tap dance shortcuts
#define TD_QUOT TD(TD_BSPC_QUOT)

// static uint16_t tap_dance_keys[][2] = {
//     [TD_LSFT_LCTL] = {KC_LSFT, KC_LCTL},
//     [TD_RSFT_RCTL] = {KC_RSFT, KC_RCTL},
// };

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_BSPC_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DEL),
  // [TD_RSFT_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sft_finished, dance_sft_reset)
};

// Tap hold keys
static taphold_t th_events[] = {
  { .is_pressed = false, .timer = 0, .kc_tap = KC_1,    .kc_hold = KC_F1 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_2,    .kc_hold = KC_F2 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_3,    .kc_hold = KC_F3 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_4,    .kc_hold = KC_F4 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_5,    .kc_hold = KC_F5 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_MINS, .kc_hold = KC_F6 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_GRV,  .kc_hold = KC_F7 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_EQL,  .kc_hold = KC_F8 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_6,    .kc_hold = KC_F9 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_7,    .kc_hold = KC_F10 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_8,    .kc_hold = KC_F11 },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_9,    .kc_hold = KC_F12 },

  { .is_pressed = false, .timer = 0, .kc_tap = KC_BSPC,    .kc_hold = KC_DEL },

  { .is_pressed = false, .timer = 0, .kc_tap = KC_X,    .kc_hold = LCTL(KC_X) },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_C,    .kc_hold = LCTL(KC_INS) },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_V,    .kc_hold = LSFT(KC_INS) },
  { .is_pressed = false, .timer = 0, .kc_tap = KC_S,    .kc_hold = LCTL(KC_S) },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QW] = {
      /* QWERTY */
      {KC_ESC,  TH_1,    TH_2,    TH_3,    TH_4,    TH_5,    TH_MINS, TH_GRV,  TH_EQL,  TH_6,    TH_7,    TH_8,     TH_9,    KC_0,    KC_BSPC},
      {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    TD_QUOT},
      {MT_LCTL, KC_A,    TH_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_ENT},
      {KC_LSFT, MT_Z,    TH_X,    TH_C,    TH_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM,  KC_DOT,  MT_SLSH, KC_RSFT},
      {KC_LCTL, KC_LGUI, KC_LALT, OSL(_BR),KC_SPC,  KC_LEAD, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  KC_BSPC, OSL(_MOV),KC_RALT, OSL(_FN),KC_RCTL},
  },

  [_FN] = {
      /* FUNCTION */
      {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
      {_______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, _______, _______, _______},
      {_______, _______, _______, _______, _______, _______, KC_P6,   KC_P5,   KC_P4,   KC_PLUS, _______, _______, _______, _______, KC_VOLU},
      {_______, _______, _______, _______, _______, _______, KC_P3,   KC_P2,   KC_P1,   KC_PENT, _______, _______, _______, KC_MUTE, KC_VOLD},
      {RESET,   _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, _______, _______, _______, _______, _______},
  },

  [_BR] = {
      /* Brackets */
      {_______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_AT,   KC_HASH, KC_PERC, KC_DLR,  _______, KC_DEL},
      {_______, _______, _______, _______, _______, _______, _______, _______, KC_CIRC, KC_EXLM, KC_LBRC, KC_RBRC, KC_ASTR, _______, _______},
      {_______, _______, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, _______, KC_GRV,  KC_MINS, KC_LPRN, KC_RPRN, KC_AMPR, _______, _______},
      {_______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_EQL,  KC_BSLS, _______, _______, _______, _______},
      {_______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, KC_DEL,  _______, _______, _______, _______},
  },

  [_MOV] = {
      /* Movement */
      {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
      {_______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
      {_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, _______, _______, _______, _______, KC_RSFT, KC_RCTL, KC_RALT, _______, _______},
      {_______, KC_END,  _______, _______, _______, KC_PGDN, _______, _______, _______, _______, KC_RSFT, _______, _______, _______, _______},
      {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______},
  }};

// some info on this: https://github.com/tmk/tmk_core/blob/master/doc/keymap.md#2-action
const uint16_t PROGMEM fn_actions[] = {

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_user_taphold(keycode, record);
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

// Tap dance functions
// void dance_sft_finished(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     register_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][0]);
//   } else {
//     for (int i = 0; i < LEN(tap_dance_keys[state->keycode - QK_TAP_DANCE]); i++) {
//       register_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][i]);
//     }
//   }
// }

// void dance_sft_reset(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     unregister_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][0]);
//   } else {
//     for (int i = 0; i < LEN(tap_dance_keys[state->keycode - QK_TAP_DANCE]); i++) {
//       unregister_code(tap_dance_keys[state->keycode - QK_TAP_DANCE][i]);
//     }
//   }
// }

