CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
EXTRAKEY_ENABLE = yes   # required for KC_MPLY, KC_VOLU, KC_VOLD in encoder.c
# Eager debounce: register key press immediately, mask bounce afterwards.
# Default sym_defer_g adds a fixed 5ms delay before every keypress registers.
DEBOUNCE_TYPE = sym_eager_pr
SRC += encoder.c
SRC += ghosting.c
SRC += matrix.c
