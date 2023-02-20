/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include <stdbool.h>

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

/* Encoder support */
#define ENCODER_RESOLUTION 2

#define SPLIT_LED_STATE_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_OLED_ENABLE

#if !defined(__ASSEMBLER__) 
enum layer_number {
  _QWERTY = 0,
  _MOUSE,
  _NUMBER,
  _NAVIGATION,
  _FUNCTION,
  _GAME
};

extern bool isDefaultRedoMode;
#endif