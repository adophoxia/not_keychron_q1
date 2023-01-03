// Copyright 2021-2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

/* ------
 * Matrix
 * ------ */

// *** MATRIX_ROW_PINS & MATRIX_COL_PINS from `info.json`

/* Pin connected to DS of 74HC595 */
#define DATA_PIN_74HC595 A7
/* Pin connected to SH_CP of 74HC595 */
#define CLOCK_PIN_74HC595 B1
/* Pin connected to ST_CP of 74HC595 */
#define LATCH_PIN_74HC595 B0


/* ----------
 * DIP Switch
 * ---------- */

/* DIP switch */
#define DIP_SWITCH_MATRIX_GRID  { {5,4} }

/* Disable DIP switch in matrix data */
#define MATRIX_MASKED



/* ---
 * I2C
 * --- */

/* Increase I2C speed to 1000 KHz */
#define I2C1_TIMINGR_PRESC 0U
#define I2C1_TIMINGR_SCLDEL 3U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 15U
#define I2C1_TIMINGR_SCLL 51U


/* -----------------
 * EEPROM Management
 * ----------------- */

#ifdef EEPROM_ENABLE
    /* An assumption is made that a ST `M24C32-FMN6TP` 32Kbit module is used */
    /* EEPROM Driver Configuration */
    #define EXTERNAL_EEPROM_I2C_BASE_ADDRESS 0b10100010  // Base I2C address for the EEPROM – shifted left by 1 as per i2c_master requirements
    #define EXTERNAL_EEPROM_BYTE_COUNT 4096              // Total size of the EEPROM in bytes
    // #define EXTERNAL_EEPROM_PAGE_SIZE 32                 // Page size of the EEPROM in bytes, as specified in the datasheet
    // #define EXTERNAL_EEPROM_ADDRESS_SIZE 2               // The number of bytes to transmit for the memory location within the EEPROM
    // #define EXTERNAL_EEPROM_WRITE_TIME 5                 // Write cycle time of the EEPROM, as specified in the datasheet
    // #undef EXTERNAL_EEPROM_WP_PIN                        // If defined the WP pin will be toggled appropriately when writing to the EEPROM.	none
#elif EFL_WL_ENABLE
    /* EFL/WL Driver Configuration */
    #define WEAR_LEVELING_LOGICAL_SIZE 4096                              // Number of bytes "exposed" to the rest of QMK and denotes the size of the usable EEPROM.
    #define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)  // Number of bytes used by the wear-leveling algorithm for its underlying storage, and needs to be a multiple of the logical size.
#else
    #error "Please define the compile type in the `rules.mk` file"
#endif


/* -------
 * General
 * ------- */

/* Enable receive custom command from host */
#define RAW_HID_CMD 0xAB

/* make tap and hold keys work better for fast typists, or for high TAPPING_TERM settings  */
#define HOLD_ON_OTHER_KEY_PRESS



/* ----------
 * RGB Matrix
 * ---------- */

//#ifdef RGB_MATRIX_ENABLE

    /* CKLED2001 driver */
    #define PHASE_CHANNEL MSKPHASE_9CHANNEL
    #define CKLED2001_CURRENT_TUNE { 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50, 0xA6, 0xA6, 0x50 }

    /* Disable RGB lighting when PC is in suspend */
    #define RGB_DISABLE_WHEN_USB_SUSPENDED

    /* RGB Matrix Animations */
    #define RGB_MATRIX_KEYPRESSES

    #define RGB_MATRIX_STARTUP_MODE 16  // just for sh!ts and giggles

    #define ENABLE_RGB_MATRIX_SOLID_COLOR               // Static single color
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS               // Static dual hue, speed is hue for secondary hue
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN          // Static gradient top to bottom, speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT       // Static gradient left to right, speed controls how much gradient changes
    #define ENABLE_RGB_MATRIX_BREATHING                 // Single hue brightness cycling animation
    #define ENABLE_RGB_MATRIX_BAND_SAT                  // Single hue band fading saturation scrolling left to right
    #define ENABLE_RGB_MATRIX_BAND_VAL                  // Single hue band fading brightness scrolling left to right
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT         // Single hue 3 blade spinning pinwheel fades saturation
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL         // Single hue 3 blade spinning pinwheel fades brightness
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT           // Single hue spinning spiral fades saturation
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL           // Single hue spinning spiral fades brightness
    #define ENABLE_RGB_MATRIX_CYCLE_ALL                 // Full keyboard solid hue cycling through full gradient
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT          // Full gradient scrolling left to right
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN             // Full gradient scrolling top to bottom
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN              // Full gradient scrolling out to in
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL         // Full dual gradients scrolling out to in
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    // Full gradient Chevron shaped scrolling left to right
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL            // Full gradient spinning pinwheel around center of keyboard
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL              // Full gradient spinning spiral around center of keyboard
    #define ENABLE_RGB_MATRIX_DUAL_BEACON               // Full gradient spinning around center of keyboard
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON            // Full tighter gradient spinning around center of keyboard
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS         // Full dual gradients spinning two halfs of keyboard
    #define ENABLE_RGB_MATRIX_RAINDROPS                 // Randomly changes a single key's hue
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS       // Randomly changes a single key's hue and saturation
    #define ENABLE_RGB_MATRIX_HUE_BREATHING             // Hue shifts up a slight amount at the same time, then shifts back
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM              // Hue shifts up a slight amount in a wave to the right, then back to the left
    #define ENABLE_RGB_MATRIX_HUE_WAVE                  // Hue shifts up a slight amount and then back down in a wave to the right

    /* RGB_MATRIX_FRAMEBUFFER_EFFECTS) */
    // #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    // #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

    /* RGB_MATRIX_KEYPRESSES) | defined(RGB_MATRIX_KEYRELEASES) */
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
    #define ENABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
    #define ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
//#endif  // RGB_MATRIX_ENABLE


/* --------
 * Encoders
 * -------- */

// *** ENCODERS_PAD_A, ENCODERS_PAD_B from `info.json`
#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3


/* --------
 * Keychron
 * -------- */

#define CAPS_LOCK_LED_INDEX 45
