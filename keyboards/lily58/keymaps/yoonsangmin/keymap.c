#include QMK_KEYBOARD_H
#ifdef OLED_ENABLE
#include "oled.h"
#endif // OLED_ENABLE

enum custom_keycodes {
  REDOMOD = SAFE_RANGE,
  REDO,
};

// Layer 0 is used for custom tap-hold functions
#define ESC        LT(0,KC_EQL)

#define QWERTY     TO(_QWERTY)

#define MOUSE      LT(_MOUSE,KC_ENT)
#define NUMBER     LT(_NUMBER,KC_GRV)
#define NAV        LT(_NAVIGATION,KC_DEL)
#define FUNC       LT(_FUNCTION,KC_LBRC)

#define GAME       TO(_GAME)

#define SPACE      LSFT_T(KC_SPC)
#define BKSPC      RSFT_T(KC_BSPC)
#define KANJI      RCTL_T(KC_RBRC)

#define UNDO       LCTL(KC_Z)
#define CUT        LCTL(KC_X)
#define COPY       LCTL(KC_C)
#define PASTE      LCTL(KC_V)

bool isDefaultRedoMode = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   +  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |  ESC |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |      |      |      |      |      |      |REDOMOD|    |  Mute |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RAlt |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt |   `  | Enter| / Space/        \BackSP\  |  Del |   [  |   ]  |
 *                   |      |Number| Mouse|/ LSFT /          \ RSFT \ |  Nav | Func | RCtrl|
 *                   `---------------------------'            '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  ESC,      KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LGUI,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    REDOMOD, KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                             KC_LALT, NUMBER,  MOUSE,   SPACE,   BKSPC,   NAV,     FUNC,    KANJI
),
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   _  |   +  |   {  |   }  |   |  |                    | WH L | WH D | MS U | WH U | WH R |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   -  |   =  |   [  |   ]  |   \  |-------.    ,-------| BTN4 | MS L | MS D | MS R | BTN5 |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   '  |   "  |   (  |   )  |   ~  |-------|    |-------| Redo | Paste| Copy |  Cut | Undo |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |      |   `  |      | /      /        \ BTN1 \  | BTN3 | BTN2 |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
[_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,                   KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R, _______,
  _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,                   KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, _______,
  _______, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_TILD, _______, _______, REDO,    PASTE,   COPY,    CUT,     UNDO,    _______,
                             _______, KC_GRV,  _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______
),
/* NUMBER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|      |  Num |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |EE CLR|   /  |   7  |   8  |   9  |   -  |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   *  |   4  |   5  |   6  |   +  |-------.    ,-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  Esc |   1  |   2  |   3  |BackSP|-------|    |-------|      |      | Game |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |   0  |      |   .  | /      /        \      \  |  Del |   [  |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */

[_NUMBER] = LAYOUT(
  QK_BOOT, _______, KC_NUM,  _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  EE_CLR,  KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,                   _______, _______, _______, _______, _______, _______,
  _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,                   _______, _______, _______, _______, _______, _______,
  _______, KC_ESC,  KC_P1,   KC_P2,   KC_P3,   KC_BSPC, _______, _______, _______, GAME,    _______, _______, _______, _______,
                             KC_P0,   _______, KC_PDOT, _______, _______, KC_DEL,  KC_LBRC, _______
),
/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   &  |   *  |   (  |      |                    | Caps | PGDN |  Up  | PGUP |  Ins |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   $  |   %  |   ^  |      |-------.    ,-------| Home | Left | Down | Right|  End |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  Esc |   !  |   @  |   #  |BackSP|-------|    |-------| Redo | Paste| Copy |  Cut | Undo |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |   )  |   `  | Enter| /      /        \      \  |      |   [  |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
  [_NAVIGATION] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, _______,                   KC_CAPS, KC_PGDN, KC_UP,   KC_PGUP, KC_INS,  _______,
  _______, _______, KC_DLR,  KC_PERC, KC_CIRC, _______,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
  _______, KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_BSPC, _______, _______, REDO,    PASTE,   COPY,    CUT,     UNDO,    _______,
                             KC_RPRN, KC_GRV,  KC_ENT,  _______, _______, _______, KC_LBRC, _______
  ),
/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |EE CLR|      |      |      |      |      |                    | PSCR |  F7  |  F8  |  F9  |  F12 |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Vol- | Vol+ | Mute |-------.    ,-------| SCRL |  F4  |  F5  |  F5  |  F11 |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      | Prev | Next | Play |-------|    |-------| PAUS |  F1  |  F2  |  F3  |  F10 |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |      |   `  | Enter| /      /        \      \  |  Del |      |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
  [_FUNCTION] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  EE_CLR,  _______, _______, _______, _______, _______,                   KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
  _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,                   KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
  _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                             _______, KC_GRV,  KC_ENT,  _______, _______, KC_DEL,  _______, _______
  ),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   A  |   S  |   D  |   F  |   H  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |      |      |      |      |      |      |  TO0  |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   P  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |   `  | LSFT | LAlt | / Space/        \      \  |       |      |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
  [_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LGUI,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    QWERTY,  _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                             KC_GRV,  KC_LSFT, KC_LALT, KC_SPC,  _______, _______, _______, _______
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
      oled_set_cursor(0, 0);
      render_layer();
      oled_set_cursor(0, 12);
      render_redo_mod();
  } else {
      oled_set_cursor(0, 0);
      render_stats();
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case ESC:
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_ESC); // Intercept hold function to send ESC
                return false;
            }
            return true;             // Return true for normal processing of tap keycode
        case REDOMOD:
            if (record->event.pressed) {
                unregister_code16(LCTL(LSFT(KC_Z)));
                unregister_code16(LCTL(KC_Y));
                isDefaultRedoMode = !isDefaultRedoMode;
            }
            break;
        case REDO:
            if (!record->tap.count) {
                if (record->event.pressed) {
                    if (isDefaultRedoMode) {
                        register_code16(LCTL(KC_Y));
                    } else {
                        register_code16(LCTL(LSFT(KC_Z)));
                    }
                } else {
                    if (isDefaultRedoMode) {
                        unregister_code16(LCTL(KC_Y));
                    } else {
                        unregister_code16(LCTL(LSFT(KC_Z)));
                    }
                }
            }
            return false;
  }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if (isDefaultRedoMode) {
                tap_code16(LCTL(KC_Y));
            } else {
                tap_code16(LCTL(LSFT(KC_Z)));
            }
        } else {
            tap_code16(UNDO);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif