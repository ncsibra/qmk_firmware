#pragma once

#include "quantum.h"

#define MOD_ACTIVE(mod) ((keyboard_report->mods & MOD_BIT(mod)) || ((get_oneshot_mods() & MOD_BIT(mod)) && !has_oneshot_mods_timed_out()))
#define OSK_ACTIVE()    ((get_oneshot_mods()) || is_oneshot_layer_active())

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define REPEAT_DELAY 500
#define REPEAT_RATE 30

enum layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM,
  _VIM_N,
  _VIM_V
};

enum keycodes {
  // layer keys
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,

  // tap-hold keys
  TH_ESC,
  TH_1,
  TH_2,
  TH_3,
  TH_4,
  TH_5,
  TH_6,
  TH_7,
  TH_8,
  TH_9,
  TH_0,
  TH_BSPC,

    // vim
  VIM_A,
  VIM_B,
  VIM_C,
  VIM_CI,
  VIM_D,
  VIM_DI,
  VIM_G,
  VIM_H,
  VIM_I,
  VIM_J,
  VIM_K,
  VIM_L,
  VIM_N,
  VIM_O,
  VIM_P,
  VIM_S,
  VIM_U,
  VIM_V,
  VIM_VI,
  VIM_W,
  VIM_X,
  VIM_Y,
  VIM_DOT,
  VIM_0,
  VIM_DLR,
  VIM_V_P,
  VIM_V_0,
  VIM_V_L,
  VIM_V_K,
  VIM_V_J,
  VIM_V_H,
  VIM_V_Y,
  VIM_V_B,
  VIM_V_G,
  VIM_V_V,
  VIM_V_DLR,
  VIM_V_C,
  VIM_V_D,
  VIM_V_S,
  VIM_V_W,

  NEW_SAFE_RANGE
};

// Expand arguments to be able to call our custom KEYMAP macro.
#define VA_KEYMAP(...)           KB_KEYMAP(__VA_ARGS__)

#define COLEMAK_LAYER \
  KC_ESC,         TH_1,     TH_2,           TH_3,           TH_4,         TH_5,    TH_6,     TH_7,        TH_8,           TH_9,     TH_0,      KC_BSPC, \
  KC_TAB,         KC_Q,     KC_W,           KC_F,           KC_P,         KC_B,    KC_J,     KC_L,        KC_U,           KC_Y,     KC_SCLN,   KC_QUOT, \
  KC_ESC,         KC_A,     KC_R,           KC_S,           KC_T,         KC_G,    KC_M,     KC_N,        KC_E,           KC_I,     KC_O,      KC_ENT, \
  KC_LSFT,        KC_Z,     KC_X,           KC_C,           KC_D,         KC_V,    KC_K,     KC_H,        KC_COMM,        KC_DOT,   KC_SLSH,   KC_RSFT, \
  MO(_NUM),       KC_LGUI,  KC_LALT,        KC_LCTL,        MO(_LOWER),   KC_SPC,  KC_BSPC,  MO(_RAISE),  KC_DEL,         KC_RALT,  KC_LEAD,   KC_DEL

#define QWERTY_LAYER \
  KC_ESC,         TH_1,     TH_2,           TH_3,           TH_4,         TH_5,    TH_6,     TH_7,        TH_8,           TH_9,           TH_0,      KC_BSPC, \
  KC_TAB,         KC_Q,     KC_W,           KC_E,           KC_R,         KC_T,    KC_Y,     KC_U,        KC_I,           KC_O,           KC_P,      KC_QUOT, \
  KC_ESC,         KC_A,     KC_S,           KC_D,           KC_F,         KC_G,    KC_H,     KC_J,        KC_K,           KC_L,           KC_SCLN,   KC_ENT, \
  KC_LSFT,        KC_Z,     KC_X,           KC_C,           KC_V,         KC_B,    KC_N,     KC_M,        KC_COMM,        KC_DOT,         KC_SLSH,   KC_RSFT, \
  MO(_NUM),       KC_LGUI,  KC_LALT,       KC_LCTL,         MO(_LOWER),   KC_SPC,  KC_BSPC,  MO(_RAISE),  KC_DEL,         KC_RALT,        KC_LEAD,   KC_DEL

/* Lower
* ,-----------------------------------------------------------------------------------.
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |   !  |   [  |   ]  |   *  |   &  |   |  |      |   '  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   @  |   #  |   `  |   :  |   (  |   )  |   =  |   +  |   "  |      |   "  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   ^  |   %  |   $  |   ~  |   {  |   }  |   -  |   _  |   \  |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      | Lower|      |      |Raise |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
#define LOWER_LAYER \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,         KC_F6,    KC_7,     KC_F8,           KC_F9,    KC_F10,   KC_F11,   KC_F12, \
  RESET,    RESET,    XXXXXXX,  XXXXXXX,  KC_EXLM,       KC_LBRC,  KC_RBRC,  KC_ASTR,         KC_AMPR,  KC_PIPE,  XXXXXXX,  KC_QUOT, \
  _______,  KC_AT,    KC_HASH,  KC_GRV,   KC_COLN,       KC_LPRN,  KC_RPRN,  KC_EQL,          KC_PLUS,  KC_DQUO,  XXXXXXX,  KC_DQUO, \
  _______,  KC_CIRC,  KC_DLR,   KC_PERC,  KC_TILD,       KC_LCBR,  KC_RCBR,  KC_MINS,         KC_UNDS,  KC_BSLS,  XXXXXXX,  _______, \
  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,         _______,  _______,  _______,  XXXXXXX

#define RAISE_LAYER \
  RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX, DF(_QWERTY),  XXXXXXX,       XXXXXXX,     DF(_COLEMAK), XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, \
  DEBUG,    XXXXXXX,  XXXXXXX,  KC_LSFT,  XXXXXXX,     XXXXXXX,       XXXXXXX,     KC_HOME,      KC_UP,    KC_END,     XXXXXXX,  KC_DEL, \
  _______,  KC_LGUI,  KC_LALT,  XXXXXXX,  KC_LCTRL,    XXXXXXX,       XXXXXXX,     KC_LEFT,      KC_DOWN,  KC_RIGHT,   XXXXXXX,  _______, \
  KC_CAPS,  _______,  _______,  _______,  _______,     _______,       XXXXXXX,     KC_PGUP,      XXXXXXX,  KC_PGDN,    XXXXXXX,  _______, \
  _______,  _______,  _______,  _______,  _______   ,  LCTL(KC_SPC),  _______,     _______,      _______,  TG(_RAISE), _______,  _______


#define NUM_LAYER \
  XXXXXXX,       XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,  KC_NUMLOCK,  KC_KP_EQUAL,  KC_KP_SLASH,  KC_KP_ASTERISK,  KC_BSPC, \
  LCTL(KC_TAB),  XXXXXXX,     XXXXXXX,     XXXXXXX,       XXXXXXX,     XXXXXXX,       XXXXXXX,  KC_KP_7,     KC_KP_8,      KC_KP_9,      KC_KP_MINUS,     XXXXXXX, \
  KC_VOLU,       LCTL(KC_A),  LCTL(KC_S),  XXXXXXX,       LCTL(KC_F),  XXXXXXX,       XXXXXXX,  KC_KP_4,     KC_KP_5,      KC_KP_6,      KC_KP_PLUS,      KC_KP_ENTER, \
  KC_VOLD,       LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_INS),  XXXXXXX,     LSFT(KC_INS),  XXXXXXX,  KC_KP_1,     KC_KP_2,      KC_KP_3,      XXXXXXX,         XXXXXXX, \
  _______,       _______,     _______,     TO(_COLEMAK),  XXXXXXX,     KC_SPC,        KC_BSPC,  KC_KP_0,     KC_KP_DOT,    KC_KP_DOT,    TO(_COLEMAK),    XXXXXXX


#define VIM_NORMAL_LAYER \
  XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_DLR,      XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_0,    XXXXXXX, \
  XXXXXXX,        XXXXXXX,  VIM_W,    XXXXXXX,  VIM_P,        VIM_B,      VIM_J,    VIM_L,    VIM_U,    XXXXXXX,  VIM_Y,    XXXXXXX, \
  TO(_COLEMAK),   VIM_A,    XXXXXXX,  VIM_S,    XXXXXXX,      VIM_G,      XXXXXXX,  VIM_N,    XXXXXXX,  VIM_I,    VIM_O,    KC_ENT, \
  OSM(MOD_LSFT),  XXXXXXX,  VIM_X,    VIM_C,    VIM_D,        TO(_VIM_V), VIM_K,    VIM_H,    XXXXXXX,  VIM_DOT,  XXXXXXX,  OSM(MOD_RSFT), \
  XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(_COLEMAK), XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX

#define VIM_INSERT_LAYER \
  XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_V_DLR,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_V_0,  XXXXXXX, \
  XXXXXXX,        XXXXXXX,  VIM_V_W,  XXXXXXX,  VIM_V_P,      VIM_V_B,  VIM_V_J,  VIM_V_L,  XXXXXXX,  XXXXXXX,  VIM_V_Y,  XXXXXXX, \
  TO(_VIM_N),     XXXXXXX,  XXXXXXX,  VIM_V_S,  XXXXXXX,      VIM_V_G,  XXXXXXX,  XXXXXXX,  XXXXXXX,  VIM_I,    XXXXXXX,  KC_ENT, \
  OSM(MOD_LSFT),  XXXXXXX,  VIM_X,    VIM_V_C,  VIM_V_D,      VIM_V_V,  VIM_V_K,  VIM_V_H,  XXXXXXX,  XXXXXXX,  XXXXXXX,  OSM(MOD_RSFT), \
  XXXXXXX,        XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(_COLEMAK), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX

// tap-hold settings
#define TH_DELAY 300

#define TH_EVENTS_COUNT 12
#define TH_FIRST TH_ESC
#define TH_LAST TH_BSPC

typedef struct {
    bool is_pressed;
    bool is_double;
    uint16_t timer;
    uint16_t kc_tap;
    uint16_t kc_hold;
} taphold_t;

typedef enum {
    TAPPED,
    HELD,
} taphold_state;

void matrix_scan_tap_hold(taphold_state state);
bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record);

