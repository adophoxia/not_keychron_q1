// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define KEYBOARD_keychron_q1_q1_ansi_stm32l432_ec11  // legacy
#define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x04  // override of the layout options default value.

#undef FORCE_NKRO  // NKRO stops macOS Fn key functionality

/* ----
 * Vial
 * ---- */

#define VIAL_KEYBOARD_UID {0x04, 0x17, 0xC1, 0xE0, 0x8A, 0x00, 0x25, 0x1B}
// Unlock with Esc + Enter
#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }
