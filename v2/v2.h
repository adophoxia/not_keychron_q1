// Copyright 2021-2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "quantum.h"

#if   defined(KEYBOARD_keychron_q1_ansi_atmega32u4)
#    include "ansi_atmega32u4.h"
#elif defined(KEYBOARD_keychron_q1_ansi_atmega32u4_encoder)
#    include "ansi_atmega32u4_encoder.h"
#elif defined(KEYBOARD_keychron_q1_iso_atmega32u4)
#    include "iso_atmega32u4.h"
#elif defined(KEYBOARD_keychron_q1_iso_atmega32u4_encoder)
#    include "iso_atmega32u4_encoder.h"
#elif defined(KEYBOARD_keychron_q1_ansi_stm32l432)
#    include "ansi_stm32l432.h"
#elif defined(KEYBOARD_keychron_q1_ansi_stm32l432_encoder)
#    include "ansi_stm32l432_encoder.h"
#elif defined(KEYBOARD_keychron_q1_iso_stm32l432)
#    include "iso_stm32l432.h"
#elif defined(KEYBOARD_keychron_q1_iso_stm32l432_encoder)
#    include "iso_stm32l432_encoder.h"
#elif defined(KEYBOARD_keychron_q1_jis_stm32l432)
#    include "jis_stm32l432.h"
#elif defined(KEYBOARD_keychron_q1_jis_stm32l432_encoder)
#    include "jis_stm32l432_encoder.h"
#endif
