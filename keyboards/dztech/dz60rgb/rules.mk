# MCU name
MCU = STM32F303

BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = lite           # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no              # Mouse keys
EXTRAKEY_ENABLE = yes              # Audio control and System control
CONSOLE_ENABLE = no                # Console for debug
COMMAND_ENABLE = no                # Commands for debug and configuration
SLEEP_LED_ENABLE = no            # Breathing sleep LED during USB suspend
NKRO_ENABLE = no                 # USB Nkey Rollover
AUDIO_ENABLE = no
RGB_MATRIX_ENABLE = IS31FL3733     # Use RGB matrix
NO_USB_STARTUP_CHECK = no          # Disable initialization only when usb is plugged in
UNICODEMAP_ENABLE = yes

LAYOUTS = 60_ansi
