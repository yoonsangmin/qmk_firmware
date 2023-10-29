#pragma once
#include <stdbool.h>

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

/* Encoder support */
#define ENCODER_RESOLUTION 2

// Mouse Wheel Delay
#define MOUSEKEY_WHEEL_DELAY 160

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_OLED_ENABLE
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define SPLIT_USB_DETECT

#define USB_MAX_POWER_CONSUMPTION 100

#if !defined(__ASSEMBLER__) 
enum layer_number {
  _QWERTY = 0,
  _GAME1,
  _GAME2,
  _MOUSE,
  _NUMBER,
  _NAVIGATION,
  _FUNCTION,
};

extern bool isDefaultRedoMode;
#endif