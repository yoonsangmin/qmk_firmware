#pragma once
#include QMK_KEYBOARD_H
#include "os_detection.h"

static const char PROGMEM qwerty[] = {
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0xB0, 0xD8, 0x58, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x30, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x03, 0x00, 0x00, 0x00, 0xF8, 0x04, 0x02, 0x02, 0x72, 0x72, 0x02, 0x02, 0x04, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x30, 0x30, 0x30, 0x1E, 0x1E, 0x30, 0x30, 0x30, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM game[] = {
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0xB0, 0xD8, 0x58, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x30, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x03, 0x78, 0x8C, 0x72, 0x89, 0x25, 0x75, 0x25, 0x2A, 0x0A, 0x05, 0x05, 0x05, 0x89, 0x72, 0x84, 0x78, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x12, 0x14, 0x28, 0x28, 0x14, 0x12, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM navi[] = {
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0xB0, 0xD8, 0x58, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x30, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x03, 0x00, 0x00, 0x00, 0xFC, 0x02, 0x02, 0x02, 0x0C, 0x3C, 0x02, 0x02, 0x02, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x38, 0x38, 0x38, 0x1F, 0x1C, 0x38, 0x38, 0x38, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM func[] = {
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0xB0, 0xD8, 0x58, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x30, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x02, 0x02, 0x02, 0x32, 0x32, 0x32, 0xF2, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x38, 0x38, 0x38, 0x1F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM mouse[] = {
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0xB0, 0xD8, 0x58, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x30, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x03, 0x00, 0x00, 0xFC, 0x02, 0x02, 0x02, 0x8C, 0x10, 0x10, 0x8C, 0x02, 0x02, 0x02, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x38, 0x38, 0x38, 0x1F, 0x07, 0x07, 0x1F, 0x38, 0x38, 0x38, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
};

static const char PROGMEM number[] = {
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0xB0, 0xD8, 0x58, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x30, 0x30, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xE4, 0x02, 0x02, 0x02, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x38, 0x38, 0x38, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x0C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
};

void render_layer(void)
{
    // Host Keyboard Layer Status
    oled_write_P(PSTR("====="), false);
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_raw_P(qwerty, 128);
            break;
        case _GAME:
            oled_write_raw_P(game, 128);
            break;
        case _NAVIGATION:
            oled_write_raw_P(navi, 128);
            break;
        case _RIGHT_NUMBER:
            oled_write_raw_P(number, 128);
            break;
        case _FUNCTION:
            oled_write_raw_P(func, 128);
            break;
        case _MOUSE:
            oled_write_raw_P(mouse, 128);
            break;
        case _NUMBER:
            oled_write_raw_P(number, 128);
            break;
        default:
            oled_write_ln_P(PSTR("Undef\n"), false);
    }
}

void render_stats(void)
{
    oled_write_P(PSTR("====="), false);
    oled_write_P(PSTR("Stats"), false);
    oled_write_P(PSTR("-----"), false);
    
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("Num:"), false);
    oled_write_P(led_state.num_lock ? PSTR("*") : PSTR("."), false);
    oled_write_P(PSTR("Cap:"), false);
    oled_write_P(led_state.caps_lock ? PSTR("*") : PSTR("."), false);
    oled_write_P(PSTR("Scr:"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("*") : PSTR("."), false);
}

void render_redo_mod(void)
{
    oled_write_P(PSTR("====="), false);
    oled_write_P(PSTR("Redo "), false);
    oled_write_P(PSTR("-----"), false);

    os_variant_t host_os = detected_host_os();
    if (host_os == OS_MACOS || host_os == OS_IOS) {
        oled_write_P(PSTR("CMD+Z"), false);
    } else {
        if (isDefaultRedoMode) {
            oled_write_P(PSTR("CTL+y"), false);
        } else {
            oled_write_P(PSTR("CTL+Z"), false);
        }
    }
}