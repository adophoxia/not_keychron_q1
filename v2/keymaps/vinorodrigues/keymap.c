// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "keymaps.h"

enum {
    _BASE,
    _F1,
    _F2,
    _F3,
    _F4,
    _F5,
    _F6
};

#define KC_FN1 MO(_F1)
#define KC_FN2 MO(_F2)
#define KC_FN3 MO(_F3)
#define KC_FN4 MO(_F4)
#define KC_FN5 MO(_F5)
#define KC_FN6 MO(_F6)
#define KC_C_L LT(_F1, KC_CAPS)

#define LED_LAYER_INDICATOR 0x10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ansi_knob(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MPLY, KC_VOLD, KC_VOLU,        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_C_L,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_FN1,  KC_FN2,  KC_FN3,  KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_F1] = LAYOUT_ansi_knob(
        _______, KC_BRID, KC_BRIU, Q1_MCON, Q1_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          KC_MUTE, KC_MFFD, KC_MRWD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ERAS,          KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PENT,          KC_END,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, KC_FN4,  KC_FN5,  _______, _______, _______
    ),

    [_F2] = LAYOUT_ansi_knob(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_TOG, RGB_VAD, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PSCR,
        RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_SLCK,
        _______, RGB_RMD, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI,          _______,          KC_PAUS,
        _______,          QK_BOOT, _______, _______, Q1_VRSN, _______, _______, _______, _______, RGB_HUD, RGB_SAD,          _______, RGB_VAI,
        _______, _______, _______,                            _______,                            KC_FN4,  _______, KC_FN6,  RGB_SPD, RGB_VAD, RGB_SPI
    ),

    [_F3] = LAYOUT_ansi_knob(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            KC_FN5,  KC_FN6,  _______, _______, _______, _______
    ),

    [_F4] = LAYOUT_ansi_knob(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_F5] = LAYOUT_ansi_knob(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [_F6] = LAYOUT_ansi_knob(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    )
};

// uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // mod_state = get_mods();

    switch (keycode) {

        // handle RGB toggle key - this ensures caps lock always works
        case QK_BOOT:
        case QK_CLEAR_EEPROM:
        case KC_CLEAR_EEPROM:
            if (record->event.pressed) {
                rgb_matrix_set_color_all(RGB_MATRIX_MAXIMUM_BRIGHTNESS, 0, 0);  // All red
                rgb_matrix_driver.flush();
            }
            return true;

        default:
            return true; /* Process all other keycodes normally */
    }
}


#ifndef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define Q1_MATRIX_MAX_BRIGHTNESS 0xFF
#else
    #define Q1_MATRIX_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#ifndef RGB_MATRIX_VAL_STEP
    #define Q1_MATRIX_VAL_STEP 8
#else
    #define Q1_MATRIX_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t val = rgb_matrix_get_val();
    if (val < Q1_MATRIX_VAL_STEP) {
        val = Q1_MATRIX_VAL_STEP;  // lowest non-0
    } else if (val < (Q1_MATRIX_MAX_BRIGHTNESS - Q1_MATRIX_VAL_STEP)) {
        // if (!user_config.rgb_disable_perkey) {
        //     val += ID61_CAPS_LOCK_VAL_STEP;  // inc. by one more step than current brightness
        // }  // else leave as current brightness
    } else {
        val = Q1_MATRIX_MAX_BRIGHTNESS;
    }

    // ----- Caps Lock -----

    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_INDICATOR) {
                rgb_matrix_set_color(i, val, val, val);  // white
            }
        }
    }

    // ----- Layer Indicator -----

    uint8_t lyr = get_highest_layer(layer_state | default_layer_state);

    if (default_layer_state != lyr) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_LAYER_INDICATOR) {
                switch(lyr) {
                    case 1: rgb_matrix_set_color(i, 0, 0, val); break;  // blue
                    case 2: rgb_matrix_set_color(i, 0, val, 0); break;  // green
                    case 3: rgb_matrix_set_color(i, val, 0, 0); break;  // red
                    case 4: rgb_matrix_set_color(i, val, 0, val); break;  // magenta
                    case 5: rgb_matrix_set_color(i, 0, val, val); break;  // cyan
                    case 6: rgb_matrix_set_color(i, val, val, 0); break;  // yellow
                    default: break;
                }
            }
        }
    }
}
