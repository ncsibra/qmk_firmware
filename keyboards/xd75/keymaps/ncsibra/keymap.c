#include "ncsibra.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = {
  {TH_ESC,         TH_1,     TH_2,     TH_3,           TH_4,         TH_5,    KC_MINS, KC_GRV,  KC_EQL,   TH_6,    TH_7,        TH_8,          TH_9,     TH_0,     TH_BSPC},
  {KC_TAB,         KC_Q,     KC_W,     KC_E,           KC_R,         KC_T,    KC_LBRC, KC_BSLS, KC_RBRC,  KC_Y,    KC_U,        KC_I,          KC_O,     KC_P,     KC_QUOT},
  {KC_ESC,         KC_A,     KC_S,     KC_D,           KC_F,         KC_G,    KC_HOME, KC_DEL,  KC_PGUP,  KC_H,    KC_J,        KC_K,          KC_L,     KC_SCLN,  KC_ENT},
  {OSM(MOD_LSFT),  KC_Z,     KC_X,     KC_C,           KC_V,         KC_B,    KC_END,  KC_UP,   KC_PGDN,  KC_N,    KC_M,        KC_COMM,       KC_DOT,   KC_SLSH,  OSM(MOD_RSFT)},
  {TT(_NUM),       KC_LGUI,  KC_LALT,  OSM(MOD_LCTL),  OSL(_LOWER),  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_BSPC, TT(_RAISE),  CTL_T(KC_DEL), KC_RALT,  TO(_NUM), KC_LEAD}
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
  {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,     XXXXXXX,    XXXXXXX,   XXXXXXX,    KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_EXLM,     KC_LBRC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RBRC,   KC_ASTR,     KC_AMPR,    KC_PIPE,   XXXXXXX,    KC_QUOT},
  {_______,    KC_AT,      KC_HASH,    KC_GRV,     KC_COLN,     KC_LPRN,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RPRN,   KC_EQL,      KC_PLUS,    KC_DQUO,   XXXXXXX,    KC_DQUO},
  {_______,    KC_CIRC,    KC_PERC,    KC_DLR,     KC_TILD,     KC_LCBR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RCBR,   KC_MINS,     KC_UNDS,    KC_BSLS,   XXXXXXX,    _______},
  {_______,    _______,    _______,    _______,    _______,    _______,   _______,  _______,  _______,  KC_DEL,    TO(_VIM_N),  _______,    _______,   _______,     XXXXXXX}
},

[_RAISE] = {
  {RESET,      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BSPC},
  {DEBUG,      XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     XXXXXXX,    KC_DEL},
  {KC_CAPS,    XXXXXXX,    KC_LCTRL,      KC_LALT,       KC_LSFT,        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,    _______},
  {_______,    KC_LGUI,    XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    KC_PGUP,    XXXXXXX,    KC_PGDN,    XXXXXXX,    _______},
  {_______,    _______,    _______,       _______,       TO(_VIM_N),     _______,  _______,  _______,  _______,  _______,    _______,    _______,    _______,    _______,    _______}
},

[_NUM] = {
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_NUMLOCK, KC_KP_EQUAL, KC_KP_SLASH, KC_KP_ASTERISK, KC_BSPC},
  {XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,      XXXXXXX,      XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_KP_7,    KC_KP_8,     KC_KP_9,     KC_KP_MINUS,    XXXXXXX},
  {KC_VOLU,    LCTL(KC_A), LCTL(KC_S),    XXXXXXX,      LCTL(KC_F),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_KP_4,    KC_KP_5,     KC_KP_6,     KC_KP_PLUS,     KC_KP_ENTER},
  {KC_VOLD,    LCTL(KC_Z), LCTL(KC_X),    LCTL(KC_INS), LSFT(KC_INS), XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_KP_1,    KC_KP_2,     KC_KP_3,     XXXXXXX,        XXXXXXX},
  {_______,    _______,    _______,       TO(_QWERTY),  XXXXXXX,      KC_SPC,    _______,   _______,   _______,   KC_BSPC,    KC_KP_0,    KC_KP_DOT,   XXXXXXX,     TO(_QWERTY),    XXXXXXX}
},

[_VIM_N] = KEYMAP_5x12(VIM_NORMAL_LAYER),

[_VIM_V] = KEYMAP_5x12(VIM_INSERT_LAYER),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
};

void matrix_scan_keymap(void) {};
