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
