#pragma once
#include QMK_KEYBOARD_H

void render_layer(void)
{
    // Host Keyboard Layer Status
    oled_write_P(PSTR("====="), false);
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwert\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("Numb \n"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR("Navi \n"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Func \n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game \n"), true);
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

    if (isDefaultRedoMode)
    {
        oled_write_P(PSTR("ctr+y"), false);
    }
    else
    {
        oled_write_P(PSTR("ctr+Z"), false);
    }
}