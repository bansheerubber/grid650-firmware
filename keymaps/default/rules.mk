# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu
# BOOTLOADER = halfkay


# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency in Hz. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
#
#     This will be an integer division of F_USB below, as it is sourced by
#     F_USB after it has run through any CPU prescalers. Note that this value
#     does not *change* the processor frequency - it should merely be updated to
#     reflect the processor speed set externally so that the code can use accurate
#     software delays.
F_CPU = 8000000

#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Input clock frequency.
#     This will define a symbol, F_USB, in all source code files equal to the
#     input clock frequency (before any prescaling is performed) in Hz. This value may
#     differ from F_CPU if prescaling is used on the latter, and is required as the
#     raw input clock is fed directly to the PLL sections of the AVR for high speed
#     clock generation for the USB and other AVR subsections. Do NOT tack on a 'UL'
#     at the end, this will be done automatically to create a 32-bit value in your
#     source code.
#
#     If no clock division is performed on the input clock inside the AVR (via the
#     CPU clock adjust registers or the clock division fuses), this will be equal to F_CPU.
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
EXTRAFLAGS += -flto

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes
# MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
MOUSEKEY_ENABLE = yes       # Mouse keys
# EXTRAKEY_ENABLE = no       # Audio control and System control
# CONSOLE_ENABLE = yes        # Console for debug test
CONSOLE_ENABLE = no        # Console for debug test
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover

BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality test
BACKLIGHT_DRIVER = pwm # test
# BACKLIGHT_DRIVER = software

RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support
BLUETOOTH_DRIVER = AdafruitBLE       # Enable Bluetooth with the Adafruit EZ-Key HID
BLUETOOTH_ENABLE = yes
AUDIO_ENABLE = no           # Audio output
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
HD44780_ENABLE = no         # Enable support for HD44780 based LCDs

DEBOUNCE_TYPE = sym_eager_pr
CUSTOM_MATRIX    = yes

# SRC += analog.c

SRC += matrix.c \
	   analog.c

	   
QUANTUM_LIB_SRC += i2c_master.c

VIA_ENABLE = no

# BOOTLOADER = halfkay


# # Build Options
# #   comment out to disable the options.
# #
# BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration
# MOUSEKEY_ENABLE  = yes # Mouse keys
# EXTRAKEY_ENABLE  = yes # Audio control and System control
# CONSOLE_ENABLE   = no  # Console for debug
# COMMAND_ENABLE   = yes # Commands for debug and configuration
# CUSTOM_MATRIX    = yes # Custom matrix file for the ErgoDox EZ
# NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# UNICODE_ENABLE   = yes # Unicode
# SWAP_HANDS_ENABLE= yes # Allow swapping hands of keyboard
# SLEEP_LED_ENABLE = no
# API_SYSEX_ENABLE = no
# RGBLIGHT_ENABLE = no
# RGBLIGHT_CUSTOM_DRIVER = no

# RGB_MATRIX_ENABLE = no # enable later
# DEBOUNCE_TYPE = eager_pr

# # project specific files
# SRC += matrix.c \
# 	   analog.c
# QUANTUM_LIB_SRC += i2c_master.c

# LAYOUTS = default
