#include "xd75.h"

// helpers
#define LEN(x) (sizeof (x) / sizeof (*(x)))

// increase readability
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// tap-hold settings
#define TH_DELAY 300

#define TH_EVENTS_COUNT 15
#define TH_FIRST TH_1
#define TH_LAST TH_V

enum tap_hold_keys {
  TH_1 = SAFE_RANGE,
  TH_2,
  TH_3,
  TH_4,
  TH_5,
  TH_MINS,
  TH_GRV,
  TH_EQL,
  TH_6,
  TH_7,
  TH_8,
  TH_9,

  TH_X,
  TH_C,
  TH_V,
};

enum layers {
  _QW = 0,
  _FN, 
  _BR, 
  _MOV
};

// enum tap_dance_indexes {
//   TD_MINS_UND = 0,
//   TD_ASTR_AMPR,
//   TD_EQL_PLUS,
//   TD_LSFT_LCTL,
//   TD_RSFT_RCTL
// };

typedef struct {
    bool is_pressed;
    uint16_t timer;
    uint16_t kc_tap;
    uint16_t kc_hold;
} taphold_t;

typedef enum {
    TAPPED,
    HELD,
} taphold_state;

// void dance_sft_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_sft_reset(qk_tap_dance_state_t *state, void *user_data);

void scan_tap_hold(taphold_state state);
bool process_record_user_taphold(uint16_t keycode, keyrecord_t *record);