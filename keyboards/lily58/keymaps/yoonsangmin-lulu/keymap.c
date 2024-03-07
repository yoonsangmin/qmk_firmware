#include QMK_KEYBOARD_H
#include "os_detection.h"
#ifdef OLED_ENABLE
#include "oled.h"
#include "bongo.h"
#endif // OLED_ENABLE

enum custom_keycodes {
  REDOMOD = SAFE_RANGE,
  CTL,
  GUI,
};

#define TG_GAME    TG(_GAME)
#define TG_NAV     TG(_NAVIGATION)
#define TG_NUM     TG(_RIGHT_NUMBER)

// Layer 0 is used for custom tap-hold functions
#define ESC        LT(0,KC_EQL)

#define MOUSE      LT(_MOUSE,KC_ENT)
#define NUMBER     LT(_NUMBER,KC_GRV)
#define NAV        LT(_NAVIGATION,KC_DEL)
#define FUNC       LT(_FUNCTION,KC_LBRC)

#define SPACE      LSFT_T(KC_SPC)
#define BKSPC      RSFT_T(KC_BSPC)
#define KANJI      RCTL_T(KC_RBRC)

bool isDefaultRedoMode = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   +  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |  ESC |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |-------.    ,-------|   Y  |   U  |   I  |   O  |   P  |   \  |
 * |      |      |      |      |      |      |  Redo |    |  VOL+ |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Undo |    |  VOL- |------+------+------+------+------+------|
 * | LCTRL|   A  |   S  |   D  |   F  |   G  |-------|    |-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * | LCMD |      |      |      |      |      |REDOMOD|    |  Mute |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | LGUI |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RAlt |
 * | LCTRL|      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt |   `  | Enter| / Space/        \BackSP\  |  DEL |   [  |   ]  |
 *                   |      |Number| Mouse|/ LSFT /          \ RSFT \ | NAVI | FUNC | RCTRL|
 *                   `---------------------------'            '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  ESC,      KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  CTL,      KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  GUI,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    REDOMOD, KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                             KC_LALT, NUMBER,  MOUSE,   SPACE,   BKSPC,   NAV,     FUNC,    KANJI
  ),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      | Enter|
 * |      |      |      |      |      |      |  GAME |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |   `  | LSFT | LAlt | / Space/        \      \   |      |      |      |
 *                   |      |      |      |/      /          \      \  |      |      |      |
 *                   `---------------------------'            '-------''--------------------'
 */
  [_GAME] = LAYOUT(
  KC_ESC,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_ENT,
  _______, _______, _______, _______, _______, _______, TG_GAME, _______, _______, _______, _______, _______, _______, _______,
                             KC_GRV,  KC_LSFT, KC_LALT, KC_SPC,  _______, _______, _______, _______
  ),
/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| CAPS | PGDN |  Up  | PGUP |  INS |      |
 * |      |      |      |      |      |      |  BTN5 |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  BTN4 |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| Home | Left | Down | Right|  End |      |
 * |      |      |      |      |      |      |       |    |  NAV  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |      |      |      | /      /        \      \  |  DEL |  NUM |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
  [_NAVIGATION] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   KC_CAPS, KC_PGDN, KC_UP,   KC_PGUP, KC_INS,  _______,
  _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, TG_NAV,  _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, KC_DEL,  TG_NUM,  _______
  ),
/* RIGHT_NUMBER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      | NLCK |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   /  |   7  |   8  |   9  |   -  |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   *  |   4  |   5  |   6  |   +  |      |
 * |      |      |      |      |      |      |       |    |  NUM  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |      |      |      | /      /        \      \  |   0  |      |   .  |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
  [_RIGHT_NUMBER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, KC_NUM,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______,                   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______, TG_NUM,  _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,
                             _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT
  ),
/* FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |NK TOG|EHRGHT|EHLEFT|      | Reset| Flash|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| PSCR |  F7  |  F8  |  F9  |  F12 |      |
 * |      |      |      |      |      |      |  Next |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Prev |    |       |------+------+------+------+------+------|
 * |      |      |      | VOL- | VOL+ | Mute |-------.    ,-------| SLCK |  F4  |  F5  |  F5  |  F11 |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      | Prev | Next | Play |-------|    |-------| PAUS |  F1  |  F2  |  F3  |  F10 |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |      |      |      | /      /        \      \  |  NAV |      |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
  [_FUNCTION] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   NK_TOGG, EH_RGHT, EH_LEFT, _______, EE_CLR,  QK_BOOT,
  _______, _______, _______, _______, _______, _______,                   KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,  _______,
  _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,                   KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
  _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
                             _______, _______, _______, _______, _______, TG_NAV,  _______, _______
  ),
  /* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   _  |   +  |   {  |   }  |   |  |-------.    ,-------| WH L | WH D | MS U | WH U | WH R |      |
 * |      |      |      |      |      |      |       |    |  PGDN |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |  PGUP |------+------+------+------+------+------|
 * |      |   -  |   =  |   [  |   ]  |   \  |-------|    |-------| BTN4 | MS L | MS D | MS R | BTN5 |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   '  |   "  |   (  |   )  |   ~  |-------|    |-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |      | GAME |      | /      /        \ BTN1 \  | BTN3 | BTN2 |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
[_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,                   KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U, KC_WH_R, _______,
  _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,                   KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, _______,
  _______, KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, TG_GAME, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______
  ),
/* NUMBER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Flash| Reset| NLCK |EHLEFT|EHRGHT|NK TOG|                    |      |      |      |      |      |      |
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   /  |   7  |   8  |   9  |   -  |-------.    ,-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |  Tab  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    | RS+Tab|------+------+------+------+------+------|
 * |      |   *  |   4  |   5  |   6  |   +  |-------|    |-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  ESC |   1  |   2  |   3  |BackSP|-------|    |-------|      |      |      |      |      |      |
 * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   |   0  |      |   .  | /      /        \      \  |      |      |      |
 *                   |      |      |      |/      /          \      \ |      |      |      |
 *                   `---------------------------'            '------''--------------------'
 */
[_NUMBER] = LAYOUT(
  QK_BOOT, EE_CLR,  KC_NUM,  EH_LEFT, EH_RGHT, NK_TOGG,                   _______, _______, _______, _______, _______, _______,
  _______, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,                   _______, _______, _______, _______, _______, _______,
  _______, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,                   _______, _______, _______, _______, _______, _______,
  _______, KC_ESC,  KC_P1,   KC_P2,   KC_P3,   KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______,
                             KC_P0,   _______, KC_PDOT, _______, _______, _______, _______, _______
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
      oled_set_cursor(0, 12);
      render_bongo();
  }
  return false;
}
#endif // OLED_ENABLE

void process_platform_combo(uint16_t keycode, keyrecord_t *record) {
  uint8_t  host_os          = detected_host_os();
  uint16_t keycode_to_press = KC_NO;
  if (host_os == OS_MACOS || host_os == OS_IOS) {
      switch (keycode) {
          case CTL:
              keycode_to_press = KC_LGUI;
              break;
          case GUI:
              keycode_to_press = KC_LCTL;
              break;
      }
  } else {
      switch (keycode) {
          case CTL:
              keycode_to_press = KC_LCTL;
              break;
          case GUI:
              keycode_to_press = KC_LGUI;
              break;
      }
  }
  if (record->event.pressed) {
      register_code(keycode_to_press);
  } else {
      unregister_code(keycode_to_press);
  }
}

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
                os_variant_t host_os = detected_host_os();
                if (!(host_os == OS_MACOS || host_os == OS_IOS)) {
                    isDefaultRedoMode = !isDefaultRedoMode;
                }
            }
            return false;
        case CTL:
            process_platform_combo(keycode, record);
            return false;
        case GUI:
            process_platform_combo(keycode, record);
            return false;
  }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
        os_variant_t host_os;
        switch (get_highest_layer(layer_state)) {
            case _NAVIGATION:
                if (clockwise) {
                    tap_code16(KC_BTN4);
                } else {
                    tap_code16(KC_BTN5);
                }
                break;
            case _FUNCTION:
                if (clockwise) {
                    tap_code16(KC_MPRV);
                } else {
                    tap_code16(KC_MNXT);
                }
                break;
            default:
                host_os = detected_host_os();
                if (clockwise) {
                    if (host_os == OS_MACOS || host_os == OS_IOS) {
                        tap_code16(LCMD(KC_Z));
                    } else {
                        tap_code16(LCTL(KC_Z));
                    }
                } else {
                    if (host_os == OS_MACOS || host_os == OS_IOS) {
                        tap_code16(LCMD(LSFT(KC_Z)));
                    } else {
                        if (isDefaultRedoMode) {
                            tap_code16(LCTL(KC_Y));
                        } else {
                            tap_code16(LCTL(LSFT(KC_Z)));
                        }
                    }
                }
                break;
        }
  } else if (index == 1) { /* Second encoder */
        switch (get_highest_layer(layer_state)) {
            case _MOUSE:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _NUMBER:
                if (clockwise) {
                    tap_code(KC_TAB);
                } else {
                    tap_code16(LSFT(KC_TAB));
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
  }
  return false;
}
#endif