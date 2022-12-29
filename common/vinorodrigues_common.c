// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "vinorodrigues_common.h"
#include "keychron_factory_test_common.h"

/*
uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
HSV hsv = rgb_matrix_config.hsv;
hsv.h = time;
RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
*/

bool __consumer_send(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        host_consumer_send(data);
    } else {
        host_consumer_send(0);
    }
    return false;
}

bool __code_1(keyrecord_t *record, uint16_t data) {
    if (record->event.pressed) {
        register_code(data);
    } else {
        unregister_code(data);
    }
    return false;
}

bool __code_2(keyrecord_t *record, uint16_t data1, uint16_t data2) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
    } else {
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;
}

bool __code_3(keyrecord_t *record, uint16_t data1, uint16_t data2, uint16_t data3) {
    if (record->event.pressed) {
        register_code(data1);
        register_code(data2);
        register_code(data3);
    } else {
        unregister_code(data3);
        unregister_code(data2);
        unregister_code(data1);
    }
    return false;
}

void housekeeping_task_keychron(void) {
    housekeeping_task_ft();
}

bool process_record_keychron(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_ft(keycode, record)) {
        return false;
    }

    switch (keycode) {
        // macOS
        case KC_MISSION_CONTROL: return __consumer_send(record, _AC_SHOW_ALL_WINDOWS);
        case KC_LAUNCHPAD: return __consumer_send(record, _AC_SHOW_ALL_APPS);
        case KC_LOPTN: return __code_1(record, KC_LOPT);
        case KC_ROPTN: return __code_1(record, KC_ROPT);
        case KC_LCMMD: return __code_1(record, KC_LCMD);
        case KC_RCMMD: return __code_1(record, KC_RCMD);
        case KC_SIRI: return __code_2(record, KC_LOPT, KC_SPACE);
        case KC_SNAP: return __code_3(record, KC_LSFT, KC_LCMD, KC_4);

        // Windows
        case KC_TASK: return __code_2(record, KC_LWIN, KC_TAB);
        case KC_FLXP: return __code_2(record, KC_LWIN, KC_E);
        case KC_CRTA: return __code_2(record, KC_LWIN, KC_C);

        // Vino's stuff
        case KC_CLEAR_EEPROM:
            factory_reset();
            return false;

        case KC_VERSION:
            if (!get_mods()) {
                if (!record->event.pressed) {
                    SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " (v" QMK_VERSION ") [E");
                    #ifdef EEPROM_ENABLE
                    SEND_STRING("EPROM");
                    #else EFL_WL_ENABLE
                    SEND_STRING("FL/WL");
                    #endif
                    SEND_STRING("]");
                }
            }
            return false;

        default:
            return true;  // Process all other keycodes normally
    }
}

#ifdef RAW_ENABLE
bool dip_switch_update_keychron(uint8_t index, bool active) {
    if (!dip_switch_update_ft(index, active)) {
        return false;
    }
    return true;
}
#endif // RAW_ENABLE

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_keychron(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_ft(led_min, led_max)) {
        return false;
    }
    return true;
}
#endif // RGB_MATRIX_ENABLE
