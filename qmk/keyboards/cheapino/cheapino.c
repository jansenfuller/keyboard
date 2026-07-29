#include "quantum.h"

// Keep state between callbacks — when 0, the initial RGB flash is done
uint8_t _hue_countdown = 50;

// 2.5 second color display on startup using deferred executor
uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    rgblight_sethsv(_hue_countdown * 5, 230, 70);
    _hue_countdown--;
    if (_hue_countdown == 0) {
        // After startup flash, always switch to rainbow swirl
        rgblight_sethsv(0, 255, 64);
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
        return 0;
    }
    return 50;
}

void keyboard_post_init_user(void) {
    // Flash colors on startup, then start rainbow
    defer_exec(50, flash_led, NULL);
}
