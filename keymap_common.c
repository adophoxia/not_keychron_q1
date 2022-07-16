// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_common.h"
#include "version.h"
#include "test.h"

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
