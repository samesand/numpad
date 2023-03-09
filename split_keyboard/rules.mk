# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
MOUSEKEY_ENABLE = no     # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

NO_USB_STARTUP_CHECK = yes  # Disable initialization only when usb is plugged in
TAP_DANCE_ENABLE = yes
LTO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
NKRO_ENABLE = yes           # Enable N-Key Rollover
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
CAPS_WORD_ENABLE = yes

RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no  
RGBLIGHT_DRIVER = WS2812

