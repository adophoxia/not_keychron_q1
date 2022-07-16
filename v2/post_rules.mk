# Define your variant from the `make` command line

EEPROM ?= yes
ifneq ($(strip $(EEPROM)), yes)
	OPT_DEFS += -DUSE_EEPROM
else
	OPT_DEFS += -DUSE_EFL_WL
endif
