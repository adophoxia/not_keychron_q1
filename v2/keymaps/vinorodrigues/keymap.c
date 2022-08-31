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


/* ------------
 * LED OVERRIDE
 * ------------ */

#ifdef RGB_MATRIX_ENABLE

#define LED_FLAG_ALPHA_KEY 0x10  // Alpha keys (for Caps Lock)
#define LED_FLAG_LAYER_IND 0x20  // Layer indicator
#define LED_FLAG_UNUSED    0xC0  // 0b11000000

const uint8_t g_led_config_new_flags[DRIVER_LED_TOTAL] = {
    // Extended LED Index to Flag
    0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x21, 0x21, 0x21, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x01,       0x01,
    0x01, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x04, 0x04, 0x04,       0x01,
    0x09, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x04, 0x04,       0x01,       0x01,
    0x01,       0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x04, 0x04, 0x04,       0x01, 0x01,
    0x01, 0x01, 0x01,                   0x04,                   0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};

void keyboard_pre_init_user(void) {
    // override config.flags with new values
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) g_led_config.flags[i] = g_led_config_new_flags[i];
}

#endif  // RGB_MATRIX_ENABLE


/* --------------
 * LED Indicators
 * -------------- */

#ifdef RGB_MATRIX_ENABLE

typedef union {
    uint32_t raw;
    struct {
        bool caps_led:1;
        bool lyr_led:1;
    };
} led_sngltn_t;

led_sngltn_t led_sngltn;

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
        rgb_matrix_set_flags(LED_FLAG_UNUSED);  // don't use 0, disables LED to off condition
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
    led_sngltn.raw = 0;
    get_q1_rgb_mode();
}

void eeconfig_init_user(void) {
    // EEPROM is getting reset!
    user_config.raw = 0;
    update_q1_rgb_mode();
}

void __rgb_matrix_set_all_color_by_flag(uint8_t flag, uint8_t R, uint8_t G, uint8_t B) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (0 != (g_led_config.flags[i] & flag)) {
            rgb_matrix_set_color(i, R, G, B);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

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

    // caps-lock indicators
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, v, v, v);  // white
        if (!user_config.rgb_disable_led)
            __rgb_matrix_set_all_color_by_flag(LED_FLAG_ALPHA_KEY, v, 0, 0);  // red
        if (!led_sngltn.caps_led && user_config.rgb_disable_led)
            led_sngltn.caps_led = true;
    } else if (led_sngltn.caps_led) {
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, HSV_OFF);  // off, if it was on before
        __rgb_matrix_set_all_color_by_flag(LED_FLAG_ALPHA_KEY, 0, 0, 0);
        led_sngltn.caps_led = false;
    }

    // layer indicators
    switch (layer) {
        case MAC_FN:
            __rgb_matrix_set_all_color_by_flag(LED_FLAG_LAYER_IND, 0, 0, v);  // blue
            if (!led_sngltn.lyr_led)
                led_sngltn.lyr_led = true;
            break;

        case WIN_FN:
            __rgb_matrix_set_all_color_by_flag(LED_FLAG_LAYER_IND, 0, v, 0);  // green
            if (!led_sngltn.lyr_led && user_config.rgb_disable_led)
                led_sngltn.lyr_led = true;
            break;

        // case MAC_BASE:
        // case WIN_BASE:
        default:
            if (led_sngltn.lyr_led && user_config.rgb_disable_led) {
                __rgb_matrix_set_all_color_by_flag(LED_FLAG_LAYER_IND, 0, 0, 0);  // off
                led_sngltn.lyr_led = false;
            }
            break;  // do nothing
    }
}


/* ---------------------------------
 * Extra keys and RGB Toggle handler
 * --------------------------------- */

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
