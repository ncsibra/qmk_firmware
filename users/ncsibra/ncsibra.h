#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#ifdef LEADER_TIMEOUT
#undef LEADER_TIMEOUT
#endif

#define LEADER_TIMEOUT 500
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS

#define MOD_ACTIVE(mod) ((keyboard_report->mods & MOD_BIT(mod)) || ((get_oneshot_mods() & MOD_BIT(mod)) && !has_oneshot_mods_timed_out()))

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// tap-hold settings
#define TH_DELAY 300

#define TH_EVENTS_COUNT 12
#define TH_FIRST TH_ESC
#define TH_LAST TH_BSPC

enum layers {
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
#define KEYMAP_5x12(...)           KEYMAP_USER(__VA_ARGS__)

#define VIM_NORMAL_LAYER \
  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, VIM_DLR,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_0,   XXXXXXX, \
  XXXXXXX,       XXXXXXX, VIM_W,   XXXXXXX, XXXXXXX,     XXXXXXX,  VIM_Y,   VIM_U,   VIM_I,   VIM_O,   VIM_P,   XXXXXXX, \
  TO(_QWERTY),   VIM_A,   VIM_S,   VIM_D,   XXXXXXX,     VIM_G,    VIM_H,   VIM_J,   VIM_K,   VIM_L,   XXXXXXX, KC_ENT, \
  OSM(MOD_LSFT), XXXXXXX, VIM_X,   VIM_C,   TO(_VIM_V),  VIM_B,    XXXXXXX, XXXXXXX, XXXXXXX, VIM_DOT, XXXXXXX, OSM(MOD_RSFT), \
  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define VIM_INSERT_LAYER \
  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, VIM_V_DLR,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_V_0, XXXXXXX, \
  XXXXXXX,       XXXXXXX, VIM_V_W, XXXXXXX, XXXXXXX,     XXXXXXX,  VIM_V_Y, XXXXXXX, VIM_I,   XXXXXXX, VIM_V_P, XXXXXXX, \
  TO(_VIM_N),    XXXXXXX, VIM_V_S, VIM_V_D, XXXXXXX,     VIM_V_G,  VIM_V_H, VIM_V_J, VIM_V_K, VIM_V_L, XXXXXXX, KC_ENT, \
  OSM(MOD_LSFT), XXXXXXX, VIM_X,   VIM_V_C, VIM_V_V,     VIM_V_B,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_RSFT), \
  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

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

#endif
