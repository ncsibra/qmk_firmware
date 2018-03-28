#include "ncsibra.h"
#include "vim.h"

#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

static uint16_t queue = KC_NO;
static vim_operation_fn last_operation;
static vim_move_state last_move = { .held = false, .timer = 0, .key = KC_NO };

static void clear_shifted_state(void) {
  RELEASE(KC_LSFT);
  RELEASE(KC_RSFT);
  clear_oneshot_mods();
}

static void reset_last_move(void) {
  last_move.key = KC_NO;
  last_move.held = false;
}

static void TAP(uint16_t keycode) {
    PRESS(keycode);
    RELEASE(keycode);
}

static void CTRL(uint16_t keycode) {
  PRESS(KC_LCTRL);
    TAP(keycode);
  RELEASE(KC_LCTRL);
}

/**
 * Sets the `queue` variable to the incoming keycode.
 * Pass `KC_NO` to cancel the operation.
 * @param keycode
 */
static void VIM_LEADER(uint16_t keycode) {
  queue = keycode;
}

/**
 * Record the last function call, so we can recall it on dot command.
 */
static void VIM_REC(vim_operation_fn op) {
  last_operation = op;
  op();
}

static void VIM_MOVE(uint16_t key, vim_operation_fn op) {
  last_move.key = key;
  last_move.op = op;
  last_move.timer = timer_read();
  op();
}

/***
 *     #######  #     #  #######       #####   #     #  #######  #######
 *     #     #  ##    #  #            #     #  #     #  #     #     #
 *     #     #  # #   #  #            #        #     #  #     #     #
 *     #     #  #  #  #  #####         #####   #######  #     #     #
 *     #     #  #   # #  #                  #  #     #  #     #     #
 *     #     #  #    ##  #            #     #  #     #  #     #     #
 *     #######  #     #  #######       #####   #     #  #######     #
 *
 */

/**
 * Vim-like `.` command, only make sense for some function.
 */
static void VIM_DOT_REPEAT(void) {
  if (last_operation) {
    last_operation();
  }
}

/**
 * Vim-like `append` command.
 * Works by sending →.
 */
static void VIM_APPEND(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_RIGHT);
  layer_move(_QWERTY);
}

/**
 * Vim-like `back` command
 * Simulates vim's `b` command by sending ⌥←
 */
static void VIM_BACK(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_LEFT);
}

/**
 * Vim-like `cut` command
 * Simulates vim's `x` command by sending ⇧→ then ⌘X.
 */
static void VIM_CUT(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_X);
  layer_move(_VIM_N);
}

static void VIM_DELETE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
}

/**
 * Vim-like `down` command
 * Sends ↓
 */
static void VIM_DOWN(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DOWN);
}

/**
 * Vim-like `left` command
 * Sends ←
 */
static void VIM_LEFT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_LEFT);
}

/**
 * Vim-like `open` command.
 * Works by sending ⌘→ to move to the end of the line, `enter` to open a new line,
 * then switching to insert mode.
 */
static void VIM_OPEN(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_ENTER);
  layer_move(_QWERTY);
}

/**
 * Vim-like `put` command for a line
 * Simulates vim's `p` command by sending ⌘V
 */
static void VIM_PUT_WHOLE_LINE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_ENTER);
  CTRL(KC_V);
}

static void VIM_PUT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_RIGHT);
  CTRL(KC_V);
}

/**
 * Vim-like `put before` command for a line
 * Simulates vim's `P` command by sending ↑, ⌘←, then ⌘V
 */
static void VIM_PUT_WHOLE_LINE_BEFORE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  TAP(KC_UP);
  TAP(KC_END);
  TAP(KC_ENTER);
  CTRL(KC_V);
}

static void VIM_PUT_BEFORE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  CTRL(KC_V);
}

/**
 * Vim-like `right` command
 * Sends →
 */
static void VIM_RIGHT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_RIGHT);
}

/**
 * Vim-like `substitute` command
 * Simulates vim's `s` command by sending ⇧→ to select the next character, then
 * ⌘X to cut it, then entering insert mode.
 */
static void VIM_SUBSTITUTE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
  layer_move(_QWERTY);
}

/**
 * Vim-like `undo` command
 * Simulates vim's `u` command by sending ⌘Z
 */
static void VIM_UNDO(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_Z);
}

/**
 * Vim-like `up` command
 * Sends ↑
 */
static void VIM_UP(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_UP);
}

/**
 * Vim-like `word` command
 * Simulates vim's `w` command by moving the cursor first to the
 * end of the current word, then to the end of the next word,
 * then to the beginning of that word.
 */
static void VIM_WORD(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_RIGHT);
}

/**
 * Vim-like `yank line` command
 * Simulates vim's `y` command by sending ⌘← then ⇧⌘→ then ⌘C
 */
static void VIM_YANK_LINE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  CTRL(KC_C);
}

static void VIM_LINE_HOME(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
}

static void VIM_LINE_END(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
}

static void VIM_YANK_WHOLE_LINE(void) {
  VIM_LEADER(KC_NO);

  TAP(KC_HOME);
  PRESS(KC_LSFT);
    TAP(KC_END);
  RELEASE(KC_LSFT);
  CTRL(KC_C);
}

/***
 *      #####   #     #  ###  #######  #######  #######  ######
 *     #     #  #     #   #   #           #     #        #     #
 *     #        #     #   #   #           #     #        #     #
 *      #####   #######   #   #####       #     #####    #     #
 *           #  #     #   #   #           #     #        #     #
 *     #     #  #     #   #   #           #     #        #     #
 *      #####   #     #  ###  #           #     #######  ######
 *
 */

/**
 * Vim-like `append to line` command
 * Simulates vim's `A` command by sending ⌘→ then switching to insert mode.
 */
static void VIM_APPEND_LINE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  TAP(KC_END);
  layer_move(_QWERTY);
}

/**
 * Vim-like 'delete line' command
 * Simulates vim's `D` command by sending ⌃K to kill the line
 */
static void VIM_DELETE_LINE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  TAP(KC_DEL);
}

/**
 * Vim-like `change line` command
 * Simulates vim's `C` command by sending ⌃K then switching to insert mode.
 */
static void VIM_CHANGE_LINE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  VIM_DELETE_LINE();
  layer_move(_QWERTY);
}

/**
 * Vim-like 'join lines' command
 * Simulates vim's `J` command by sending ⌘→ to go to the end of the line, then
 * DELETE to join the lines
 */
static void VIM_JOIN(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  TAP(KC_END);
  TAP(KC_DELETE);
}

/**
 * Vim-like 'open above' command
 * Simulates vim's `O` command by sending ⌘→ to go to the start of the line,
 * enter to move the line down, ↑ to move up to the new line, then switching to
 * insert mode.
 */
static void VIM_OPEN_ABOVE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  TAP(KC_UP);
  TAP(KC_END);
  TAP(KC_ENTER);
  layer_move(_QWERTY);
}

/**
 * Vim-like 'change whole line' command
 * Simulates vim's `S` `cc` or `c$` commands by sending ⌘← to go to the start of the line,
 * ⌃K to kill the line, then switching to insert mode.
 */
static void VIM_CHANGE_WHOLE_LINE(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  TAP(KC_HOME);
  VIM_CHANGE_LINE();
}

static void VIM_JUMP_HOME(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_HOME);
}

static void VIM_JUMP_END(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  CTRL(KC_END);
}

/***
 *     ######       ######   ######   #######  #######  ###  #     #  #######  ######
 *     #     #      #     #  #     #  #        #         #    #   #   #        #     #
 *     #     #      #     #  #     #  #        #         #     # #    #        #     #
 *     #     #      ######   ######   #####    #####     #      #     #####    #     #
 *     #     #      #        #   #    #        #         #     # #    #        #     #
 *     #     #      #        #    #   #        #         #    #   #   #        #     #
 *     ######       #        #     #  #######  #        ###  #     #  #######  ######
 *
 */

/**
 * Vim-like `delete whole line` command
 * Simulates vim's `dd` command by sending ⌘← to move to start of line,
 * selecting the whole line, then sending ⌘X to cut the line.
 * alternate method: ⌘⌫, ⌃K
 */
static void VIM_DELETE_WHOLE_LINE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  TAP(KC_DEL);
  TAP(KC_BSPC);
  TAP(KC_DOWN);
}

/**
 * Vim-like `delete word` command
 * Simulates vim's `dw` command by sending ⌥⇧→→← then ⌘X to select to the start
 * of the next word then cut.
 */
static void VIM_DELETE_WORD(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_DEL);
}

/**
 * Vim-like `delete back` command
 * Simulates vim's `db` command by selecting to the end of the word then deleting.
 */
static void VIM_DELETE_BACK(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_BSPC);
}

/**
 * Vim-like `delete left` command
 * Simulates vim's `dh` command by sending ⇧← then ⌘X.
 */
static void VIM_DELETE_LEFT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_BSPC);
}

/**
 * Vim-like `delete right` command
 * Simulates vim's `dl` command by sending ⇧→ then ⌘X.
 */
static void VIM_DELETE_RIGHT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
}

/**
 * Vim-like `delete up` command
 * Simulates vim's `dk` command by sending ↑ then deleting the line.
 */
static void VIM_DELETE_UP(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  PRESS(KC_LSHIFT);
    TAP(KC_HOME);
    TAP(KC_UP);
    TAP(KC_HOME);
  RELEASE(KC_LSHIFT);
  TAP(KC_DEL);
}

/**
 * Vim-like `delete down` command
 * Simulates vim's `dj` command by sending ↓ then deleting the line.
 */
static void VIM_DELETE_DOWN(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
    TAP(KC_DOWN);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  TAP(KC_DEL);
}

/***
 *     ######   ###      ######   ######   #######  #######  ###  #     #  #######  ######
 *     #     #   #       #     #  #     #  #        #         #    #   #   #        #     #
 *     #     #   #       #     #  #     #  #        #         #     # #    #        #     #
 *     #     #   #       ######   ######   #####    #####     #      #     #####    #     #
 *     #     #   #       #        #   #    #        #         #     # #    #        #     #
 *     #     #   #       #        #    #   #        #         #    #   #   #        #     #
 *     ######   ###      #        #     #  #######  #        ###  #     #  #######  ######
 *
 */

/**
 * Vim-like `delete inner word` command
 * Simulates vim's `diw` command by moving back then cutting to the end of the word.
 */
static void VIM_DELETE_INNER_WORD(void) {
  VIM_LEADER(KC_NO);
  VIM_BACK();
  VIM_DELETE_WORD();
}

/***
 *      #####        ######   ######   #######  #######  ###  #     #  #######  ######
 *     #     #       #     #  #     #  #        #         #    #   #   #        #     #
 *     #             #     #  #     #  #        #         #     # #    #        #     #
 *     #             ######   ######   #####    #####     #      #     #####    #     #
 *     #             #        #   #    #        #         #     # #    #        #     #
 *     #     #       #        #    #   #        #         #    #   #   #        #     #
 *      #####        #        #     #  #######  #        ###  #     #  #######  ######
 *
 */

/**
 * Vim-like `change back` command
 * Simulates vim's `cb` command by first deleting to the start of the word,
 * then switching to insert mode.
 */
static void VIM_CHANGE_BACK(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_BACK();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change down` command
 * Simulates vim's `cj` command by sending ↓ then changing the line.
 */
static void VIM_CHANGE_DOWN(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_DOWN();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change left` command
 * Simulates vim's `ch` command by deleting left then switching to insert mode.
 */
static void VIM_CHANGE_LEFT(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_LEFT();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change right` command
 * Simulates vim's `cl` command by deleting right then switching to insert mode.
 */
static void VIM_CHANGE_RIGHT(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_RIGHT();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change up` command
 * Simulates vim's `ck` command by deleting up then switching to insert mode.
 */
static void VIM_CHANGE_UP(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_UP();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change word` command
 * Simulates vim's `cw` command by first deleting to the end of the word,
 * then switching to insert mode.
 */
static void VIM_CHANGE_WORD(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_WORD();
  layer_move(_QWERTY);
}

/***
 *      #####   ###      ######   ######   #######  #######  ###  #     #  #######  ######
 *     #     #   #       #     #  #     #  #        #         #    #   #   #        #     #
 *     #         #       #     #  #     #  #        #         #     # #    #        #     #
 *     #         #       ######   ######   #####    #####     #      #     #####    #     #
 *     #         #       #        #   #    #        #         #     # #    #        #     #
 *     #     #   #       #        #    #   #        #         #    #   #   #        #     #
 *      #####   ###      #        #     #  #######  #        ###  #     #  #######  ######
 *
 */

/**
 * Vim-like `change inner word` command
 * Simulates vim's `ciw` command by deleting the inner word then switching to insert mode.
 */
static void VIM_CHANGE_INNER_WORD(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_INNER_WORD();
  layer_move(_QWERTY);
}

/***
 *     #     #      ######   ######   #######  #######  ###  #     #  #######  ######
 *     #     #      #     #  #     #  #        #         #    #   #   #        #     #
 *     #     #      #     #  #     #  #        #         #     # #    #        #     #
 *     #     #      ######   ######   #####    #####     #      #     #####    #     #
 *      #   #       #        #   #    #        #         #     # #    #        #     #
 *       # #        #        #    #   #        #         #    #   #   #        #     #
 *        #         #        #     #  #######  #        ###  #     #  #######  ######
 *
 */

/**
 * Vim-like `visual select back` command
 * Simulates vim's `vb` command by selecting to the enc of the word.
 */
static void VIM_VISUAL_BACK(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_BACK();
  RELEASE(KC_LSHIFT);
}

/**
 * Vim-like `visual select word` command
 * Simulates vim's `vw` command by selecting to the end of the word.
 */
static void VIM_VISUAL_WORD(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_WORD();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_SUBSTITUTE(void) {
  VIM_LEADER(KC_NO);
  VIM_SUBSTITUTE();
}

static void VIM_VISUAL_DELETE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
}

static void VIM_VISUAL_CHANGE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
  layer_move(_QWERTY);
}

static void VIM_VISUAL_LINE_END(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_LINE_END();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_JUMP_END(void) {
  VIM_LEADER(KC_NO);
  clear_shifted_state();

  PRESS(KC_LSHIFT);
    CTRL(KC_END);
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_JUMP_HOME(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_JUMP_HOME();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_YANK(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_C);
  layer_move(_VIM_N);
}

static void VIM_VISUAL_LEFT(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_LEFT();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_DOWN(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_DOWN();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_UP(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_UP();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_RIGHT(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_RIGHT();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_LINE_HOME(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    VIM_LINE_HOME();
  RELEASE(KC_LSHIFT);
}

static void VIM_VISUAL_PASTE(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_V);
}

/***
 *     #     #  ###      ######   ######   #######  #######  ###  #     #  #######  ######
 *     #     #   #       #     #  #     #  #        #         #    #   #   #        #     #
 *     #     #   #       #     #  #     #  #        #         #     # #    #        #     #
 *     #     #   #       ######   ######   #####    #####     #      #     #####    #     #
 *      #   #    #       #        #   #    #        #         #     # #    #        #     #
 *       # #     #       #        #    #   #        #         #    #   #   #        #     #
 *        #     ###      #        #     #  #######  #        ###  #     #  #######  ######
 *
 */

/**
 * Vim-like `visual inner word` command
 * Simulates vim's `viw` command by moving back then selecting to the end of the word.
 */
static void VIM_VISUAL_INNER_WORD(void) {
  VIM_LEADER(KC_NO);
  VIM_BACK();
  VIM_VISUAL_WORD();
}

bool process_record_user_vim_normal(uint16_t keycode, keyrecord_t *record) {
  if (!IS_LAYER_ON(_VIM_N)) {
    if (last_move.key != KC_NO) {
      reset_last_move();
    }
    return true;
  }

  if (!record->event.pressed) {
    if (keycode == last_move.key) {
      reset_last_move();
      return false;
    }
    return true;
  }

  bool SHIFTED = MOD_ACTIVE(KC_LSFT) || MOD_ACTIVE(KC_RSFT);

  switch (keycode) {
    case VIM_A:
      SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND();
      return false;

    case VIM_B:
      switch(queue) {
        case KC_NO: VIM_MOVE(keycode, VIM_BACK); break;
        case VIM_C: VIM_CHANGE_BACK(); break;
        case VIM_D: VIM_REC(VIM_DELETE_BACK); break;
      }
      return false;

    case VIM_C:
      switch(queue) {
        case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
        case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
      }
      return false;

    case VIM_D:
      switch(queue) {
        case KC_NO: SHIFTED ? VIM_REC(VIM_DELETE_LINE) : VIM_LEADER(VIM_D); break;
        case VIM_D: VIM_REC(VIM_DELETE_WHOLE_LINE); break;
      }
      return false;

    case VIM_G:
      switch (queue) {
        case KC_NO: SHIFTED ? VIM_JUMP_END() : VIM_LEADER(VIM_G); break;
        case VIM_G: VIM_JUMP_HOME(); break;
      }
      return false;

    case VIM_H:
      switch (queue) {
        case KC_NO: VIM_MOVE(keycode, VIM_LEFT); break;
        case VIM_C: VIM_CHANGE_LEFT(); break;
        case VIM_D: VIM_REC(VIM_DELETE_LEFT); break;
      }
      return false;

    case VIM_I:
      switch (queue) {
        case KC_NO: layer_move(_QWERTY); break;
        case VIM_C: VIM_LEADER(VIM_CI); break;
        case VIM_D: VIM_LEADER(VIM_DI); break;
      }
      return false;

    case VIM_J:
      switch (queue) {
        case KC_NO: SHIFTED ? VIM_JOIN() : VIM_MOVE(keycode, VIM_DOWN); break;
        case VIM_C: VIM_CHANGE_DOWN(); break;
        case VIM_D: VIM_REC(VIM_DELETE_DOWN); break;
      }
      return false;

    case VIM_K:
      switch (queue) {
        case KC_NO: VIM_MOVE(keycode, VIM_UP); break;
        case VIM_C: VIM_CHANGE_UP(); break;
        case VIM_D: VIM_REC(VIM_DELETE_UP); break;
      }
      return false;

    case VIM_L:
      switch (queue) {
        case KC_NO: VIM_MOVE(keycode, VIM_RIGHT); break;
        case VIM_C: VIM_CHANGE_RIGHT(); break;
        case VIM_D: VIM_REC(VIM_DELETE_RIGHT); break;
      }
      return false;

    case VIM_N:
      SHIFTED ? VIM_PUT_WHOLE_LINE_BEFORE() : VIM_PUT_WHOLE_LINE();
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
      VIM_MOVE(keycode, VIM_UNDO);
      return false;

    case VIM_W:
      switch (queue) {
        case KC_NO: VIM_MOVE(keycode, VIM_WORD); break;
        case VIM_C: VIM_CHANGE_WORD(); break;
        case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
        case VIM_D: VIM_REC(VIM_DELETE_WORD); break;
        case VIM_DI: VIM_REC(VIM_DELETE_INNER_WORD); break;
        case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
      }
      return false;

    case VIM_X:
      VIM_MOVE(keycode, VIM_DELETE);
      return false;

    case VIM_Y:
      switch (queue) {
        case KC_NO: SHIFTED ? VIM_YANK_LINE() : VIM_LEADER(VIM_Y); break;
        case VIM_Y: VIM_YANK_WHOLE_LINE(); break;
      }
      return false;
    case VIM_DOT:
      VIM_MOVE(keycode, VIM_DOT_REPEAT);
      return false;
    case VIM_0:
      VIM_LINE_HOME();
      return false;
    case VIM_DLR:
      VIM_LINE_END();
      return false;
  }

  return true;
}

bool process_record_user_vim_visual(uint16_t keycode, keyrecord_t *record) {
if (IS_LAYER_ON(_VIM_V) && record->event.pressed) {
    bool SHIFTED = MOD_ACTIVE(KC_LSFT) || MOD_ACTIVE(KC_RSFT);

    switch (keycode) {

      case VIM_V_W:
        VIM_MOVE(keycode, VIM_VISUAL_WORD);
        return false;
      case VIM_V_S:
        VIM_VISUAL_SUBSTITUTE();
        return false;
      case VIM_X:
        VIM_CUT();
        return false;
      case VIM_V_D:
        VIM_VISUAL_DELETE();
        return false;
      case VIM_V_C:
        VIM_VISUAL_CHANGE();
        return false;
      case VIM_V_DLR:
        VIM_VISUAL_LINE_END();
        return false;
      case VIM_V_V:
        layer_move(_VIM_N);
        return false;
      case VIM_V_G:
        switch (queue) {
          case KC_NO: SHIFTED ? VIM_VISUAL_JUMP_END() : VIM_LEADER(VIM_V_G); break;
          case VIM_V_G: VIM_VISUAL_JUMP_HOME(); break;
        }
        return false;
      case VIM_V_B:
        VIM_MOVE(keycode, VIM_VISUAL_BACK);
        return false;
      case VIM_V_Y:
        VIM_VISUAL_YANK();
        return false;
      case VIM_V_H:
        VIM_MOVE(keycode, VIM_VISUAL_LEFT);
        return false;
      case VIM_V_J:
        VIM_MOVE(keycode, VIM_VISUAL_DOWN);
        return false;
      case VIM_I:
        layer_move(_QWERTY);
        return false;
      case VIM_V_K:
        VIM_MOVE(keycode, VIM_VISUAL_UP);
        return false;
      case VIM_V_L:
        VIM_MOVE(keycode, VIM_VISUAL_RIGHT);
        return false;
      case VIM_V_0:
        VIM_VISUAL_LINE_HOME();
        return false;
      case VIM_V_P:
        VIM_VISUAL_PASTE();
        return false;
    }
  }

  return true;
}

void matrix_scan_vim() {
  if (last_move.key != KC_NO) {
    if (last_move.held) {
      last_move.op();
    } else if (timer_elapsed(last_move.timer) > TAPPING_TERM) {
      last_move.held = true;
    }
  }
}
