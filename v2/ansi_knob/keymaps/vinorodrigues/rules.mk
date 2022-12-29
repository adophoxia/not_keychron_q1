# Copyright 2021 Keychron (https://www.keychron.com)
# SPDX-License-Identifier: GPL-2.0-or-later

VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes

VPATH += keyboards/notkeychron/q1/common
SRC += keychron_common.c
SRC += keychron_factory_test_common.c

# --- Vial Specific ---
# VIAL_ENABLE = yes
# VIALRGB_ENABLE = yes
QMK_SETTINGS = no        # save eeprom
TAP_DANCE_ENABLE = no    # save eeprom
COMBO_ENABLE = no        # save eeprom
KEY_OVERRIDE_ENABLE = no # save eeprom
