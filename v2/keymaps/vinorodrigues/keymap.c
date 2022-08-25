// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "keymaps.h"

#ifdef RGB_MATRIX_ENABLE

typedef union {
    uint32_t raw;
    struct {
        bool rgb_disable_led:1;
    };
} user_config_t;

user_config_t user_config;

#endif  // RGB_MATRIX_ENABLE


enum {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

#define Q1_M_FN MO(MAC_FN)
#define Q1_M_FC LT(MAC_FN, KC_CAPS)
#define Q1_W_FN LT(WIN_FN, KC_APP)
#define Q1_W_FC LT(WIN_FN, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_knob(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE, KC_VOLD, KC_VOLU,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        Q1_M_FC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             Q1_RCMD, Q1_M_FN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC_FN] = LAYOUT_ansi_knob(
        _______, KC_BRID, KC_BRIU, Q1_MCON, Q1_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          RGB_TOG, RGB_VAD, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ERAS,          KC_INS,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        KC_CAPS, RGB_RMD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          KC_PENT,          KC_END,
        _______,          QK_BOOT, Q1_EECL, _______, Q1_VRSN, _______, NK_TOGG, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [WIN_BASE] = LAYOUT_ansi_knob(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE, KC_VOLD, KC_VOLU,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        Q1_W_FC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                            KC_SPC,                             KC_RALT, Q1_W_FN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [WIN_FN] = LAYOUT_ansi_knob(
        _______, KC_BRID, KC_BRIU, Q1_TASK, Q1_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          RGB_TOG, RGB_VAD, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        KC_CAPS, RGB_RMD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          QK_BOOT, _______, _______, Q1_VRSN, _______, NK_TOGG, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    )
};

/* --------------
 * ROTARY ENCODER
 * -------------- */

#ifdef ENCODER_ENABLE

static uint8_t  encoder_state = 0;
static keypos_t encoder_cw    = {8, 5};
static keypos_t encoder_ccw   = {7, 5};

void encoder_action_unregister(void) {
    if (encoder_state) {
        keyevent_t encoder_event = (keyevent_t){
            .key = encoder_state >> 1 ? encoder_cw : encoder_ccw,
            .pressed = false,
            .time = (timer_read() | 1)
        };
        encoder_state = 0;
        action_exec(encoder_event);
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    if (index != 0) return;

    keyevent_t encoder_event = (keyevent_t){
        .key = clockwise ? encoder_cw : encoder_ccw,
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif  // ENCODER_ENABLE


/* ------------
 * Key specific
 * ------------ */

void matrix_scan_user(void) {
    #ifdef ENCODER_ENABLE
    encoder_action_unregister();
    #endif  // ENCODER_ENABLE
}


/* --------------
 * LED Indicators
 * -------------- */

#ifdef RGB_MATRIX_ENABLE

bool led_sngltn;

#ifndef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define Q1_INDICATOR_MAX_BRIGHTNESS 0xFF
#else
    #define Q1_INDICATOR_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#ifndef RGB_MATRIX_VAL_STEP
    #define Q1_INDICATOR_VAL_STEP 8
#else
    #define Q1_INDICATOR_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

void update_q1_rgb_mode(void) {
    if (user_config.rgb_disable_led) {
        rgb_matrix_set_flags(0xF0);  // don't use 0, disables LED to off condition
        rgb_matrix_set_color_all(HSV_OFF);
    } else {
        rgb_matrix_set_flags(LED_FLAG_ALL);
        rgb_matrix_enable_noeeprom();
    }

    eeconfig_update_kb(user_config.raw);  // write back to EEPROM
}

void get_q1_rgb_mode(void) {
    user_config.raw = eeconfig_read_kb();  // read config from EEPROM
    update_q1_rgb_mode();
}

void keyboard_post_init_user(void) {
    led_sngltn = false;
    get_q1_rgb_mode();
}

void eeconfig_init_user(void) {
    // EEPROM is getting reset!
    user_config.raw = 0;
    update_q1_rgb_mode();
}

void rgb_matrix_indicators_user(void) {
    uint8_t v = rgb_matrix_get_val();
    if (v < Q1_INDICATOR_VAL_STEP) {
        v = Q1_INDICATOR_VAL_STEP;
    } else if (v < (Q1_INDICATOR_MAX_BRIGHTNESS - Q1_INDICATOR_VAL_STEP)) {
        if (!user_config.rgb_disable_led) {
            v += Q1_INDICATOR_VAL_STEP;  // inc. by one more step than current brightness
        }  // else leave as current brightness
    } else {
        v = Q1_INDICATOR_MAX_BRIGHTNESS;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, v, v, v);  // white
        if (!led_sngltn) led_sngltn = true;
    } else if (led_sngltn) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, HSV_OFF);  // off, if it was on before
        led_sngltn = false;
    }
}

/*
 * Extra keys and RGB Toggle handler
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case QK_BOOT:
            if (record->event.pressed) {
                rgb_matrix_set_color_all(Q1_INDICATOR_MAX_BRIGHTNESS, 0, 0);  // All red
                rgb_matrix_driver.flush();
                wait_ms(10);  // give it time to go red
            }
            return true;

        case RGB_TOG:
            /* |    Level    | LED |
             * |-------------|-----|
             * | 0 (default) | on  |
             * |     1       | OFF |
             */
            if (record->event.pressed) {
                    user_config.rgb_disable_led = user_config.rgb_disable_led ? 0 : 1;
                update_q1_rgb_mode();
            }
            return false;  // block default RGB_TOG

        case EE_CLR:
            if (!record->event.pressed) {  // on release
                get_q1_rgb_mode();
            }
            return true;  // let this one pass on

        default:
            return true; /* Process all other keycodes normally */
    }
}

#endif  // RGB_MATRIX_ENABLE
