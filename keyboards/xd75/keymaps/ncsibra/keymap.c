#include "keymap.h"

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

[_QWERTY] = KEYMAP( \
  TH_ESC,         TH_1,     TH_2,     TH_3,           TH_4,         TH_5,    KC_MINS, KC_GRV,  KC_EQL,   TH_6,    TH_7,        TH_8,     TH_9,     TH_0,     TH_BSPC, \
  KC_TAB,         KC_Q,     KC_W,     KC_E,           KC_R,         KC_T,    KC_LBRC, KC_BSLS, KC_RBRC,  KC_Y,    KC_U,        KC_I,     KC_O,     KC_P,     KC_QUOT, \
  KC_ESC,         KC_A,     KC_S,     KC_D,           KC_F,         KC_G,    KC_HOME, KC_DEL,  KC_PGUP,  KC_H,    KC_J,        KC_K,     KC_L,     KC_SCLN,  KC_ENT, \
  OSM(MOD_LSFT),  KC_Z,     KC_X,     KC_C,           KC_V,         KC_B,    KC_END,  KC_UP,   KC_PGDN,  KC_N,    KC_M,        KC_COMM,  KC_DOT,   KC_SLSH,  OSM(MOD_RSFT), \
  TT(_NUM),       KC_LGUI,  KC_LALT,  CTL_T(KC_DEL),  OSL(_LOWER),  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_BSPC, TT(_RAISE),  KC_RCTRL, KC_RALT,  TG(_NUM), KC_LEAD \
),

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
  {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,    KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_EXLM,     KC_LBRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RBRC,   KC_ASTR,     KC_AMPR,    KC_PIPE,   XXXXXXX,    KC_QUOT},
  {_______,    KC_AT,      KC_HASH,    KC_GRV,     KC_COLN,     KC_LPRN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RPRN,   KC_EQL,      KC_PLUS,    KC_DQUO,   XXXXXXX,    KC_DQUO},
  {_______,    KC_CIRC,    KC_PERC,    KC_DLR,     KC_TILD,     KC_LCBR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RCBR,   KC_UNDS,     KC_MINS,    KC_BSLS,   XXXXXXX,    _______},
  {_______,    _______,    _______,    _______,    _______,    _______,   _______,  _______,  _______,  KC_DEL,    _______,    _______,    _______,   _______,     XXXXXXX}
},

[_RAISE] = {
  {RESET,      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSPC},
  {DEBUG,      XXXXXXX,    LSFT(KC_HOME), LSFT(KC_UP),   LSFT(KC_END),   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    KC_DEL},
  {KC_CAPS,    XXXXXXX,    LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,    _______},
  {_______,    XXXXXXX,    LSFT(KC_PGUP), XXXXXXX,       LSFT(KC_PGDN),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_PGUP,    XXXXXXX,    KC_PGDN,    XXXXXXX,    _______},
  {_______,    _______,    _______,       _______,       _______,        _______,  _______,  _______,  _______,  _______,    _______,    _______,    _______,    _______,    _______}
},

[_NUM] = {
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_NUMLOCK, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_KP_7,    KC_KP_8,     KC_KP_9,     KC_KP_MINUS,    XXXXXXX},
  {KC_VOLU,    XXXXXXX,    LCTL(KC_S),    XXXXXXX,      LCTL(KC_F),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_KP_4,    KC_KP_5,     KC_KP_6,     KC_KP_PLUS,     KC_KP_ENTER},
  {KC_VOLD,    LCTL(KC_Z), LCTL(KC_X),    LCTL(KC_INS), LSFT(KC_INS), XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_KP_1,    KC_KP_2,     KC_KP_3,     XXXXXXX,        XXXXXXX},
  {_______,    _______,    _______,       TO(_QWERTY),  XXXXXXX,      KC_SPC,    _______,   _______,   _______,   KC_BSPC,    KC_KP_0,    KC_KP_DOT,   XXXXXXX,     TO(_QWERTY),    XXXXXXX}
}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
