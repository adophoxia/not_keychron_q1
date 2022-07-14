// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "version.h"
#include "test.h"

enum layers {
    _M0,
    _MF,
    _W2,
    _WF
};

enum custom_keycodes {
    #if VIA_ENABLE
    KC_MISSION_CONTROL = USER00,
    KC_LAUNCHPAD,
    KC_LEFT_OPTION,
    KC_RIGHT_OPTION,
    KC_LEFT_COMMAND,
    KC_RIGHT_COMMAND,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_VERSION = USER09
    #else
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LEFT_OPTION,
    KC_RIGHT_OPTION,
    KC_LEFT_COMMAND,
    KC_RIGHT_COMMAND,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_VERSION
    #endif
};

enum macos_consumer_usages {
    _AC_SHOW_ALL_WINDOWS = 0x29F,  // mapped to KC_MCON
    _AC_SHOW_ALL_APPS    = 0x2A0   // mapped to KC_LPAD
};

#define MC_MCON KC_MISSION_CONTROL
#define MC_LPAD KC_LAUNCHPAD
#define MC_LOPT KC_LEFT_OPTION
#define MC_ROPT KC_RIGHT_OPTION
#define MC_LCMD KC_LEFT_COMMAND
#define MC_RCMD KC_RIGHT_COMMAND
#define WC_TASK KC_TASK_VIEW
#define WC_FLXP KC_FILE_EXPLORER
#define KC_VRSN KC_VERSION
#define RGB_RMD RGB_RMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐┌───┐
     * │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12││Del││Mut│
     * ├───┼┴──┬┴──┬┴──┬┴──┬┴┴─┬─┴─┬─┴─┬─┴─┬─┴┴┬──┴┬──┴┬──┴┬──┴┴───┤├───┤
     * │`~ │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backspc││PgU│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤├───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  ││PgD│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤├───┤
     * │*Caps*│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter ││Hom│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬┬──┴┼───┘
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │      ││ ↑ │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬┬──┴┼───┼───┐
     * │Ctrl│Opt │Cmd │                        │Cmd│Fn1│Ctl││ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┘└───┴───┴───┘
     */
    [_M0] = LAYOUT_ansi(
        KC_ESC,  KC_BRID, KC_BRIU, MC_MCON, MC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           KC_MUTE, KC_VOLD, KC_VOLU,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL, MC_LOPT, MC_LCMD,                            KC_SPC,                             MC_RCMD, MO(_MF), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_MF] = LAYOUT_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          RGB_TOG, RGB_VAD, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, NK_TOGG, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_RMD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          QK_BOOT, _______, _______, KC_VRSN, _______, NK_TOGG, _______, _______, _______, EEP_RST,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______),

    [_W2] = LAYOUT_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE, KC_VOLD, KC_VOLU,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_WF), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_WF] = LAYOUT_ansi(
        _______, KC_BRID, KC_BRIU, WC_TASK, WC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          RGB_TOG, RGB_VAD, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, NK_TOGG, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_RMD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          QK_BOOT, _______, _______, KC_VRSN, _______, NK_TOGG, _______, _______, _______, EEP_RST,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______),
};


/* ----- Rotary Encoder ----- */

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

static uint8_t  encoder_state = 0;
// ***NB:*** K58 & K59 are placeholders in the dynamic memory and used for the encoder in VIA
static keypos_t encoder_cw  = { 8, 5 };
static keypos_t encoder_ccw = { 7, 5 };

void encoder_action_unregister(void) {
    if (encoder_state) {
        keyevent_t encoder_event = (keyevent_t) {
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
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw : encoder_ccw,
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif  // VIA_ENABLE && ENCODER_ENABLE


/* ----- DIP Switch ----- */

bool dip_switch_update_user(uint8_t index, bool active) {
    /* Send default layer state to host */
    system_switch_state_report(index, active);
    return true;
}


/* ----- Custom keycodes ----- */

bool __consumer_send(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        host_consumer_send(data);
    } else {
        host_consumer_send(0);
    }
    return false;  // Skip all further processing of this key
}

bool __code_1(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        register_code(data);
    } else {
        unregister_code(data);
    }
    return false;  // Skip all further processing of this key
}

bool __code_2(keyrecord_t *record, uint16_t data1, uint16_t data2) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
    } else {
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;  // Skip all further processing of this key
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // macOS keys
        case KC_MISSION_CONTROL: return __consumer_send(record, _AC_SHOW_ALL_WINDOWS);
        case KC_LAUNCHPAD: return __consumer_send(record, _AC_SHOW_ALL_APPS);
        case KC_LEFT_OPTION: return __code_1(record, KC_LOPT);
        case KC_RIGHT_OPTION: return __code_1(record, KC_ROPT);
        case KC_LEFT_COMMAND: return __code_1(record, KC_LCMD);
        case KC_RIGHT_COMMAND: return __code_1(record, KC_RCMD);

        // Windows keys
        case KC_TASK_VIEW: return __code_2(record, KC_LWIN, KC_TAB);
        case KC_FILE_EXPLORER: return __code_2(record, KC_LWIN, KC_E);

        // print firmware version
        case KC_VERSION:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");
                }
            }
            return false;

        default:
            return true;   // Process all other keycodes normally
    }
}
