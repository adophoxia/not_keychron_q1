// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

enum {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

// remember to override these in your keymap
#define MAC_FN_LAYER MAC_FN
#define WIN_FN_LAYER WIN_FN

enum custom_keycodes {
    #if VIA_ENABLE
        KC_MISSION_CONTROL = USER00,
    #else
        KC_MISSION_CONTROL = SAFE_RANGE,
    #endif
    KC_LAUNCHPAD,
    KC_LEFT_OPTION,
    KC_RIGHT_OPTION,
    KC_LEFT_COMMAND,
    KC_RIGHT_COMMAND,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,

    KC_SIRI,
    KC_SCREEN_SHOT,
    KC_CORTANA,

    KC_CLEAR_EEPROM,
    KC_VERSION
};

enum macos_consumer_usages {
    _AC_SHOW_ALL_WINDOWS = 0x29F,  // mapped to Q1_MCON
    _AC_SHOW_ALL_APPS    = 0x2A0   // mapped to Q1_LPAD
};

#define Q1_MCON KC_MISSION_CONTROL
#define Q1_LPAD KC_LAUNCHPAD
#define Q1_LOPT KC_LEFT_OPTION
#define Q1_ROPT KC_RIGHT_OPTION
#define Q1_LCMD KC_LEFT_COMMAND
#define Q1_RCMD KC_RIGHT_COMMAND
#define Q1_SIRI KC_SIRI
#define Q1_TASK KC_TASK_VIEW
#define Q1_FLXP KC_FILE_EXPLORER
#define Q1_SHOT KC_SCREEN_SHOT
#define Q1_CRTN KC_CORTANA
#define Q1_EECL KC_CLEAR_EEPROM
#define Q1_VRSN KC_VERSION
#define RGB_RMD RGB_RMOD
