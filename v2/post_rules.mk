# Define your variant from the `make` command line `EEPROM=1`
# or by adding `EEPROM yes` to the keymap rules.mk file.

EEPROM ?= yes
ifneq ($(strip $(EEPROM)), yes)
	OPT_DEFS += -DUSE_EEPROM
else
	OPT_DEFS += -DUSE_EFL_WL
endif
