#include "keymap.h"
#include "keycode.h"
#include "quantum.h"
#include "quantum_keycodes.h"

#define PRESS(keycode) register_code16(keycode)
#define RELEASE(keycode) unregister_code16(keycode)

typedef void (*vim_operation_fn)(void);

uint16_t VIM_QUEUE = KC_NO;
vim_operation_fn VIM_LAST_OPERATION;

void VIM_APPEND(void);
void VIM_APPEND_LINE(void);
void VIM_BACK(void);
void VIM_CHANGE_BACK(void);
void VIM_CHANGE_DOWN(void);
void VIM_CHANGE_END(void);
void VIM_CHANGE_INNER_WORD(void);
void VIM_CHANGE_LEFT(void);
void VIM_CHANGE_LINE(void);
void VIM_CHANGE_RIGHT(void);
void VIM_CHANGE_UP(void);
void VIM_CHANGE_WHOLE_LINE(void);
void VIM_CHANGE_WORD(void);
void VIM_CUT(void);
void VIM_DELETE_BACK(void);
void VIM_DELETE_DOWN(void);
void VIM_DELETE_END(void);
void VIM_DELETE_INNER_WORD(void);
void VIM_DELETE_LEFT(void);
void VIM_DELETE_LINE(void);
void VIM_DELETE_RIGHT(void);
void VIM_DELETE_UP(void);
void VIM_DELETE_WHOLE_LINE(void);
void VIM_DELETE_WORD(void);
void VIM_END(void);
void VIM_JOIN(void);
void VIM_OPEN(void);
void VIM_OPEN_ABOVE(void);
void VIM_PUT(void);
void VIM_SUBSTITUTE(void);
void VIM_UNDO(void);
void VIM_VISUAL_BACK(void);
void VIM_VISUAL_DOWN(void);
void VIM_VISUAL_END(void);
void VIM_VISUAL_INNER_WORD(void);
void VIM_VISUAL_LEFT(void);
void VIM_VISUAL_RIGHT(void);
void VIM_VISUAL_UP(void);
void VIM_VISUAL_WORD(void);
void VIM_WORD(void);
void VIM_YANK(void);

void TAP(uint16_t keycode) {
    PRESS(keycode);
    RELEASE(keycode);
}

void CTRL(uint16_t keycode) {
  PRESS(KC_LCTRL);
    TAP(keycode);
  RELEASE(KC_LCTRL);
}

void SHIFT(uint16_t keycode) {
  PRESS(KC_LSHIFT);
    TAP(keycode);
  RELEASE(KC_LSHIFT);
}

void ALT(uint16_t keycode) {
  PRESS(KC_LALT);
    TAP(keycode);
  RELEASE(KC_LALT);
}

/**
 * Sets the `VIM_QUEUE` variable to the incoming keycode.
 * Pass `KC_NO` to cancel the operation.
 * @param keycode
 */
void VIM_LEADER(uint16_t keycode) {
  VIM_QUEUE = keycode;
}

/**
 * Record the last function call, so we can recall it on dot command.
 */
void VIM_REC(vim_operation_fn op) {
  VIM_LAST_OPERATION = op;
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
void VIM_DOT_REPEAT(void) {
  if (VIM_LAST_OPERATION) {
    VIM_LAST_OPERATION();
  }
}

/**
 * Vim-like `append` command.
 * Works by sending →.
 */
void VIM_APPEND(void) {
  TAP(KC_RIGHT);
  layer_move(_QWERTY);
}

/**
 * Vim-like `back` command
 * Simulates vim's `b` command by sending ⌥←
 */
void VIM_BACK(void) {
  CTRL(KC_LEFT);
}

/**
 * Vim-like `cut` command
 * Simulates vim's `x` command by sending ⇧→ then ⌘X.
 */
void VIM_CUT(void) {
  TAP(KC_DEL);
}

/**
 * Vim-like `down` command
 * Sends ↓
 */
void VIM_DOWN(void) {
  TAP(KC_DOWN);
}

/**
 * Vim-like `end` command
 * Simulates vim's `e` command by sending ⌥→
 */
void VIM_END(void) {
  CTRL(KC_RIGHT);
  TAP(KC_LEFT); // just assume one space between the words...
  TAP(KC_LEFT);
}

/**
 * Vim-like `left` command
 * Sends ←
 */
void VIM_LEFT(void) {
  TAP(KC_LEFT);
}

/**
 * Vim-like `open` command.
 * Works by sending ⌘→ to move to the end of the line, `enter` to open a new line,
 * then switching to insert mode.
 */
void VIM_OPEN(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_ENTER);
  layer_move(_QWERTY);
}

/**
 * Vim-like `put` command for a line
 * Simulates vim's `p` command by sending ⌘V
 */
void VIM_PUT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_ENTER);
  CTRL(KC_V);
}

/**
 * Vim-like `put before` command for a line
 * Simulates vim's `P` command by sending ↑, ⌘←, then ⌘V
 */
void VIM_PUT_BEFORE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_UP);
  TAP(KC_END);
  TAP(KC_ENTER);
  CTRL(KC_V);
}

/**
 * Vim-like `right` command
 * Sends →
 */
void VIM_RIGHT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_RIGHT);
}

/**
 * Vim-like `substitute` command
 * Simulates vim's `s` command by sending ⇧→ to select the next character, then
 * ⌘X to cut it, then entering insert mode.
 */
void VIM_SUBSTITUTE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
  layer_move(_QWERTY);
}

/**
 * Vim-like `undo` command
 * Simulates vim's `u` command by sending ⌘Z
 */
void VIM_UNDO(void) {
  CTRL(KC_Z);
}

/**
 * Vim-like `up` command
 * Sends ↑
 */
void VIM_UP(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_UP);
}

/**
 * Vim-like `word` command
 * Simulates vim's `w` command by moving the cursor first to the
 * end of the current word, then to the end of the next word,
 * then to the beginning of that word.
 */
void VIM_WORD(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_RIGHT);
}

/**
 * Vim-like `yank` command
 * Simulates vim's `y` command by sending ⌘C
 */
void VIM_YANK(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_C);
}

/**
 * Vim-like `yank line` command
 * Simulates vim's `y` command by sending ⌘← then ⇧⌘→ then ⌘C
 */
void VIM_YANK_LINE(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
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
void VIM_APPEND_LINE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  layer_move(_QWERTY);
}

/**
 * Vim-like `change line` command
 * Simulates vim's `C` command by sending ⌃K then switching to insert mode.
 */
void VIM_CHANGE_LINE(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_LINE();
  layer_move(_QWERTY);
}

/**
 * Vim-like 'delete line' command
 * Simulates vim's `D` command by sending ⌃K to kill the line
 */
void VIM_DELETE_LINE(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  CTRL(KC_X);
}

/**
 * Vim-like 'join lines' command
 * Simulates vim's `J` command by sending ⌘→ to go to the end of the line, then
 * DELETE to join the lines
 */
void VIM_JOIN(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  TAP(KC_DELETE);
}

/**
 * Vim-like 'open above' command
 * Simulates vim's `O` command by sending ⌘→ to go to the start of the line,
 * enter to move the line down, ↑ to move up to the new line, then switching to
 * insert mode.
 */
void VIM_OPEN_ABOVE(void) {
  VIM_LEADER(KC_NO);
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
void VIM_CHANGE_WHOLE_LINE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  VIM_CHANGE_LINE();
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
 * Vim-like `delete to end` command
 * Simulates vim's `de` command by sending ⌥⇧→ then ⌘X.
 */
void VIM_DELETE_END(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    CTRL(KC_RIGHT);
  RELEASE(KC_LSHIFT);
  CTRL(KC_X);
}

/**
 * Vim-like `delete whole line` command
 * Simulates vim's `dd` command by sending ⌘← to move to start of line,
 * selecting the whole line, then sending ⌘X to cut the line.
 * alternate method: ⌘⌫, ⌃K
 */
void VIM_DELETE_WHOLE_LINE(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  CTRL(KC_X);
}

/**
 * Vim-like `delete word` command
 * Simulates vim's `dw` command by sending ⌥⇧→→← then ⌘X to select to the start
 * of the next word then cut.
 */
void VIM_DELETE_WORD(void) {
  VIM_LEADER(KC_NO);
  CTRL(KC_RIGHT);
  CTRL(KC_RIGHT);
  CTRL(KC_LEFT); // wont work on the last word in the line
  PRESS(KC_LSHIFT);
    CTRL(KC_LEFT);
  RELEASE(KC_LSHIFT);
  CTRL(KC_X); // delete selection
}

/**
 * Vim-like `delete back` command
 * Simulates vim's `db` command by selecting to the end of the word then deleting.
 */
void VIM_DELETE_BACK(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    CTRL(KC_LEFT);
  RELEASE(KC_LSHIFT);
  CTRL(KC_X);
}

/**
 * Vim-like `delete left` command
 * Simulates vim's `dh` command by sending ⇧← then ⌘X.
 */
void VIM_DELETE_LEFT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_BSPC);
}

/**
 * Vim-like `delete right` command
 * Simulates vim's `dl` command by sending ⇧→ then ⌘X.
 */
void VIM_DELETE_RIGHT(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_DEL);
}

/**
 * Vim-like `delete up` command
 * Simulates vim's `dk` command by sending ↑ then deleting the line.
 */
void VIM_DELETE_UP(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_END);
  PRESS(KC_LSHIFT);
    TAP(KC_HOME);
    TAP(KC_UP);
    TAP(KC_HOME);
  RELEASE(KC_LSHIFT);
  TAP(KC_X);
}

/**
 * Vim-like `delete down` command
 * Simulates vim's `dj` command by sending ↓ then deleting the line.
 */
void VIM_DELETE_DOWN(void) {
  VIM_LEADER(KC_NO);
  TAP(KC_HOME);
  PRESS(KC_LSHIFT);
    TAP(KC_END);
    TAP(KC_DOWN);
    TAP(KC_END);
  RELEASE(KC_LSHIFT);
  TAP(KC_X);
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
void VIM_DELETE_INNER_WORD(void) {
  VIM_LEADER(KC_NO);
  VIM_BACK();
  VIM_DELETE_END();
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
void VIM_CHANGE_BACK(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_BACK();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change down` command
 * Simulates vim's `cj` command by sending ↓ then changing the line.
 */
void VIM_CHANGE_DOWN(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_DOWN();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change to end` command
 * Simulates vim's `ce` command by first deleting to the end of the word,
 * then switching to insert mode.
 */
void VIM_CHANGE_END(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_END();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change left` command
 * Simulates vim's `ch` command by deleting left then switching to insert mode.
 */
void VIM_CHANGE_LEFT(void) {
  VIM_LEADER(KC_NO);
  VIM_DELETE_LEFT();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change right` command
 * Simulates vim's `cl` command by deleting right then switching to insert mode.
 */
void VIM_CHANGE_RIGHT(void) {
  VIM_DELETE_RIGHT();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change up` command
 * Simulates vim's `ck` command by deleting up then switching to insert mode.
 */
void VIM_CHANGE_UP(void) {
  VIM_DELETE_UP();
  layer_move(_QWERTY);
}

/**
 * Vim-like `change word` command
 * Simulates vim's `cw` command by first deleting to the end of the word,
 * then switching to insert mode.
 */
void VIM_CHANGE_WORD(void) {
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
void VIM_CHANGE_INNER_WORD(void) {
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
void VIM_VISUAL_BACK(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    CTRL(KC_LEFT); // select to start of word
  RELEASE(KC_LSHIFT);
}

/**
 * Vim-like `visual select to end` command
 * Simulates vim's `ve` command by selecting to the end of the word.
 */
void VIM_VISUAL_END(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    CTRL(KC_RIGHT); // select to end of this word
  RELEASE(KC_LSHIFT);
}

/**
 * Vim-like `visual select word` command
 * Simulates vim's `vw` command by selecting to the end of the word.
 */
void VIM_VISUAL_WORD(void) {
  VIM_LEADER(KC_NO);
  PRESS(KC_LSHIFT);
    CTRL(KC_RIGHT); // select to end of this word
    CTRL(KC_RIGHT); // select to end of next word
    CTRL(KC_LEFT); // select to start of next word
  RELEASE(KC_LSHIFT);
}

/**
 * Vim-like `visual left` command
 * Simulates vim's `vh` command by sending ⇧←.
 */
void VIM_VISUAL_LEFT(void) {
  VIM_LEADER(KC_NO);
  SHIFT(KC_LEFT);
}

/**
 * Vim-like `visual right` command
 * Simulates vim's `vl` command by sending ⇧→.
 */
void VIM_VISUAL_RIGHT(void) {
  VIM_LEADER(KC_NO);
  SHIFT(KC_RIGHT);
}

/**
 * Vim-like `visual up` command
 * Simulates vim's `vk` command by sending ⇧↑.
 */
void VIM_VISUAL_UP(void) {
  VIM_LEADER(KC_NO);
  SHIFT(KC_UP);
}

/**
 * Vim-like `visual down` command
 * Simulates vim's `vj` command by sending ⇧↓.
 */
void VIM_VISUAL_DOWN(void) {
  VIM_LEADER(KC_NO);
  SHIFT(KC_DOWN);
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
void VIM_VISUAL_INNER_WORD(void) {
  VIM_LEADER(KC_NO);
  VIM_BACK();
  VIM_VISUAL_END();
}
