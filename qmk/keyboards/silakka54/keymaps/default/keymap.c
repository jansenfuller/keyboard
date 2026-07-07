/* Copyright 2025 QMK Contributors
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Silakka54 keymap adapted from Lily58 ZMK config.
 * Mac-oriented: GUI = CMD, ALT = Opt.
 * Home-row mods: D=Ctrl, F=Shift, J=Shift, K=Ctrl
 */

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NUM_SYM,
    FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
        // Row 0 (top) — all KC_TRNS (outside Corne footprint, available on Silakka54)
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 1 (QWERTY) — TAB and BSPC removed, on thumbs instead
        KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
        // Row 2 (home row) — home-row mods using mod-tap
        KC_ESC,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,
                                                                     KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        // Row 3 (bottom) — Shift only via home-row mods
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
        // Row 4 (thumbs)
                                    MO(1),   KC_TAB,  KC_BSPC,       KC_SPC,  KC_ENT,  MO(2)
    ),

    [NUM_SYM] = LAYOUT(
        // Row 0 — top row symbols (no Shift available, so all direct)
        KC_EXLM, KC_HASH, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,      KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_MINS,
        // Row 1
        KC_GRV,  KC_LBRC, KC_LPRN, KC_RBRC, KC_RPRN, KC_TILD,     KC_AT,   KC_4,    KC_5,    KC_6,    KC_SLSH, KC_BSLS,
        // Row 2
        KC_PERC, KC_LT,   KC_LCBR, KC_GT,   KC_RCBR, KC_PIPE,     KC_0,    KC_1,    KC_2,    KC_3,    KC_DLR,  KC_ESC,
        // Row 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 4 (thumbs)
                                    KC_TRNS, KC_UNDS, KC_QUOT,      KC_COLN, KC_DOT,  KC_TRNS
    ),

    [FUNC] = LAYOUT(
        // Row 0 — F-keys and navigation
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_DEL,
        // Row 1
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        // Row 2
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 3
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Row 4 (thumbs)
                                    QK_BOOT, KC_TRNS, QK_BOOTLOADER, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
