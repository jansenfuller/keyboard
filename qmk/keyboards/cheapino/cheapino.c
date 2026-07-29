#include "wait.h"
#include "quantum.h"

// Keep state between callbacks — when 0, the initial RGB flash is done
uint8_t _hue_countdown = 50;

// Track user-selected color so we can restore after flash
uint8_t _hue;
uint8_t _saturation;
uint8_t _value;

// 2.5 second color display on startup using deferred executor
uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    rgblight_sethsv(_hue_countdown * 5, 230, 70);
    _hue_countdown--;
    if (_hue_countdown == 0) {
        // Restore user-chosen LED color
        rgblight_sethsv(_hue, _saturation, _value);
        return 0;
    }
    return 50;
}

void keyboard_post_init_user(void) {
    // Store user-selected RGB HSV
    _hue = rgblight_get_hue();
    _saturation = rgblight_get_sat();
    _value = rgblight_get_val();

    // Flash colors on startup
    defer_exec(50, flash_led, NULL);
}
