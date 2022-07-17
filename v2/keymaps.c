// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "keymaps.h"
#include "version.h"

/* ----- Rotary Encoder ----- */

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 8, 5 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 5 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
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

#ifdef DIP_SWITCH_ENABLE

bool dip_switch_update_user(uint8_t index, bool active) {
    /* Send default layer state to host */
    system_switch_state_report(index, active);
    return true;
}

#endif  // DIP_SWITCH_ENABLE


/* ----- Custom keycodes ----- */

#ifdef USE_FACTORY_RESET

#define MAC_FN 1
#define WIN_FN 3

static void timer_3s_task(void);
static void timer_300ms_task(void);

#define KEY_PRESS_FN (0x1<<0)
#define KEY_PRESS_J  (0x1<<1)
#define KEY_PRESS_Z  (0x1<<2)
#define KEY_PRESS_FACTORY_RESET (KEY_PRESS_FN | KEY_PRESS_J | KEY_PRESS_Z)

uint16_t key_press_status = 0;
uint32_t timer_3s_buffer = 0;
uint32_t timer_300ms_buffer = 0;
uint8_t factory_reset_count = 0;

void matrix_scan_kb(void) {
    if (timer_3s_buffer) {
        timer_3s_task();
    }
    if (timer_300ms_buffer) {
        timer_300ms_task();
    }

    matrix_scan_user();
}

static void timer_3s_task(void) {
    if (sync_timer_elapsed32(timer_3s_buffer) > 3000) {
        timer_3s_buffer = 0;
        if (key_press_status == KEY_PRESS_FACTORY_RESET) {
            timer_300ms_buffer = sync_timer_read32() | 1;
            factory_reset_count++;
            layer_state_t default_layer_tmp = default_layer_state;
            eeconfig_init();
            default_layer_set(default_layer_tmp);
        }
        key_press_status = 0;
    }
}

static void timer_300ms_task(void) {
    if (timer_300ms_buffer && sync_timer_elapsed32(timer_300ms_buffer) > 300) {
        if (factory_reset_count++ > 6) {
            timer_300ms_buffer = 0;
            factory_reset_count = 0;
        } else {
            timer_300ms_buffer = sync_timer_read32() | 1;
        }
    }
}

bool __factory_rt(keyrecord_t *record, uint8_t data) {
    if (record->event.pressed) {
        key_press_status |= data;
        if ((key_press_status == KEY_PRESS_FACTORY_RESET) && (KEY_PRESS_FN != data)) {
            timer_3s_buffer = sync_timer_read32() | 1;
        }
    } else {
        key_press_status &= ~data;
        timer_3s_buffer = 0;
    }
    return true;
}

#endif

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

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // macOS keys
        case KC_MISSION_CONTROL: return __consumer_send(record, _AC_SHOW_ALL_WINDOWS);
        case KC_LAUNCHPAD: return __consumer_send(record, _AC_SHOW_ALL_APPS);
        case KC_LEFT_OPTION: return __code_1(record, Q1_LOPT);
        case KC_RIGHT_OPTION: return __code_1(record, Q1_ROPT);
        case KC_LEFT_COMMAND: return __code_1(record, Q1_LCMD);
        case KC_RIGHT_COMMAND: return __code_1(record, Q1_RCMD);

        // Windows keys
        case Q1_TASK_VIEW: return __code_2(record, KC_LWIN, KC_TAB);
        case KC_FILE_EXPLORER: return __code_2(record, KC_LWIN, KC_E);

        // clear EEPROM
        case KC_CLEAR_EEPROM:
            eeconfig_init_quantum();
            soft_reset_keyboard();
            return false;

        // print firmware version
        case KC_VERSION:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ")");
                    // #ifdef VIA_ENABLE
                    // /* show the Layout Options stored in VIA */
                    // char str[9];
                    // itoa(via_get_layout_options(), str, 16);
                    // SEND_STRING(" [0x");
                    // send_string_with_delay(str, 0);
                    // SEND_STRING("]");
                    // #endif
                }
            }
            return false;

        // -----

        #ifdef USE_FACTORY_RESET

        #ifdef DIP_SWITCH_ENABLE
        case MO(WIN_FN):
        #endif
        case MO(MAC_FN): return __factory_rt(record, KEY_PRESS_FN);
        case KC_J: return __factory_rt(record, KEY_PRESS_J);
        case KC_Z: return __factory_rt(record, KEY_PRESS_Z);

        #endif  // USE_FACTORY_RESET

        // -----

        default:
            return true;   // Process all other keycodes normally
    }
}
