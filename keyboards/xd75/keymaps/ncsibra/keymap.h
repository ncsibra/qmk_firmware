#include "xd75.h"
#include "action_layer.h"

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
  _NUM
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
  TH_BSPC
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
