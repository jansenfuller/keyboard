// Copyright 2023 Thomas Haukland (@tompi)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// WS2812 RGB LED
#define WS2812_DI_PIN GP16
#define WS2812_PIO_USE_PIO1
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
#define RGBLIGHT_LED_COUNT 1

// Default LED: smooth slow rainbow swirl
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 64
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_SPD 0
#define RGBLIGHT_RAINBOW_SWIRL_RANGE 255

// Home-row mod timing
#define TAPPING_TERM 230

// Encoder
#define ENCODER_RESOLUTION 1

// Max deferred executors (needed for LED flash dance)
#define MAX_DEFERRED_EXECUTORS 32
