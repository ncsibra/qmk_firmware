#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define MOD_ACTIVE(mod) ((keyboard_report->mods & MOD_BIT(mod)) || ((get_oneshot_mods() & MOD_BIT(mod)) && !has_oneshot_mods_timed_out()))

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// tap-hold settings
#define TH_DELAY 300

#define TH_EVENTS_COUNT 12
#define TH_FIRST TH_ESC
#define TH_LAST TH_BSPC

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUM,
  _VIM_N,
  _VIM_V
};

enum preonic_keycodes {
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

void scan_tap_hold(taphold_state state);
bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record);

#endif
