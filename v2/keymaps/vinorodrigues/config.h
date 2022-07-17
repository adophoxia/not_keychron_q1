// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
    #undef DYNAMIC_KEYMAP_LAYER_COUNT
#endif
#define DYNAMIC_KEYMAP_LAYER_COUNT 7  // why not

#undef DIP_SWITCH_ENABLE  // don't need the DIP switch

// #ifdef ENCODER_RESOLUTION
//     #undef ENCODER_RESOLUTION
// #endif
// #define ENCODER_RESOLUTION 4

#ifdef FORCE_NKRO
    #undef FORCE_NKRO
#endif
