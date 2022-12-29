// Copyright 2021-2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/* ----------
 * DIP switch
 * ---------- */

#define DIP_SWITCH_MATRIX_GRID  { {5,4} }
#define MATRIX_MASKED


/* ---------------------
 * Encoder Configuration
 * --------------------- */

//#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { A10 }
    #define ENCODERS_PAD_B { A8 }
    #define ENCODER_RESOLUTION 4
    #define ENCODER_DEFAULT_POS 0x3
//#endif  // ENCODER_ENABLE

/* ----------
 * RGB Matrix
 * ---------- */

//#ifdef RGB_MATRIX_ENABLE
    /* RGB Matrix Driver Configuration */
    #define DRIVER_COUNT 2
    #define DRIVER_ADDR_1 0b1110111
    #define DRIVER_ADDR_2 0b1110100

    /* Scan phase of led driver set as MSKPHASE_9CHANNEL(defined as 0x03 in CKLED2001.h) */
    #define PHASE_CHANNEL MSKPHASE_9CHANNEL
    #define CKLED2001_CURRENT_TUNE { 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50 }

    /* RGB Matrix Configuration */
    #define DRIVER_1_LED_TOTAL 45
    #define DRIVER_2_LED_TOTAL 37
    #define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)  // new, Dec '22
    #define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)  // legacy
//#endif  // RGB_MATRIX_ENABLE


/* ---------------------
 * Special function keys
 * --------------------- */

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 45
