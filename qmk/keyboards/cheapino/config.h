// Copyright 2023 Thomas Haukland (@tompi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Pick good defaults for enabling home-row modifiers
#define TAPPING_TERM 230

#define WS2812_DI_PIN GP16
#define RGBLIGHT_LED_COUNT 1
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD
#define RGBLIGHT_DEFAULT_SPD 1
#define RGBLIGHT_DEFAULT_VAL 32

// Custom matrix dimensions
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

// How many "tents" should you turn per action
#define ENCODER_RESOLUTION 1
