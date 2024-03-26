#pragma once
#include <stdbool.h>

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define PERMISSIVE_HOLD
#define TAPPING_TERM 200

/* Encoder support */
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2

// Mouse Wheel Delay
#define MOUSEKEY_WHEEL_DELAY 160

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_OLED_ENABLE
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define SPLIT_USB_DETECT

#define USB_MAX_POWER_CONSUMPTION 100

#define NO_SUSPEND_POWER_DOWN

// OS Detection
#define OS_DETECTION_DEBOUNCE 200
#define OS_DETECTION_KEYBOARD_RESET

#if !defined(__ASSEMBLER__) 
enum layer_number {
  _QWERTY = 0,
  _GAME,
  _NAVIGATION,
  _RIGHT_NUMBER,
  _FUNCTION,
  _MOUSE,
  _NUMBER,
};
#endif