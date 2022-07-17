// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

enum custom_keycodes {
    #if VIA_ENABLE
        KC_MISSION_CONTROL = USER00,
        KC_LAUNCHPAD,
        KC_LEFT_OPTION,
        KC_RIGHT_OPTION,
        KC_LEFT_COMMAND,
        KC_RIGHT_COMMAND,
        Q1_TASK_VIEW,
        KC_FILE_EXPLORER,
        KC_CLEAR_EEPROM,
        KC_VERSION = USER09
    #else
        KC_MISSION_CONTROL = SAFE_RANGE,
        KC_LAUNCHPAD,
        KC_LEFT_OPTION,
        KC_RIGHT_OPTION,
        KC_LEFT_COMMAND,
        KC_RIGHT_COMMAND,
        Q1_TASK_VIEW,
        KC_FILE_EXPLORER,
        KC_CLEAR_EEPROM,
        KC_VERSION
    #endif
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
#define Q1_TASK Q1_TASK_VIEW
#define Q1_FLXP KC_FILE_EXPLORER
#define Q1_EECL KC_CLEAR_EEPROM
#define Q1_VRSN KC_VERSION
#define RGB_RMD RGB_RMOD
