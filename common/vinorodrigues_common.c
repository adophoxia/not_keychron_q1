// Copyright 2022 Vino Rodrigues (@vinorodrigues)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "vinorodrigues_common.h"


/*
uint8_t time = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed / 4, 1));
HSV hsv = rgb_matrix_config.hsv;
hsv.h = time;
RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b);
*/
