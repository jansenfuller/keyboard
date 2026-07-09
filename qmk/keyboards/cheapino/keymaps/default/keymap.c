/* Copyright 2025 QMK Contributors
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Cheapino 5-column layout — 4 layers.
 * Mac-oriented: GUI = CMD, Alt = Opt.
 * Home-row mods: D=Ctrl, F=Shift, J=Shift, K=Ctrl
 *
 * Thumbs: MO(1) TAB BSPC  |  SPACE ENT MO(2)
 * Layer 3: press opposite layer key while on L1 or L2
 *
 * ┌───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┐
 * │   Q   │   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   │   P   │
 * ├───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┤
 * │ A/CMD │ S/Opt │D/Ctrl │F/Shft │   G   │ │   H   │J/Shft │K/Ctrl │ L/Opt │;/CMD  │
 * ├───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┤
 * │   Z   │   X   │   C   │   V   │   B   │ │   N   │   M   │   ,   │   .   │   /   │
 * └───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┘
 *            ┌───────┬───────┬───────┐         ┌───────┬───────┬───────┐
 *            │ MO(1) │  TAB  │ BSPC  │         │ SPACE │  ENT  │ MO(2) │
 *            └───────┴───────┴───────┘         └───────┴───────┴───────┘
 */

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    NUM_SYM,
    ARR_NAV,
    SYS,
};

enum combos {
    CMB_ESC,
    CMB_LENGTH,
};

const uint16_t PROGMEM esc_combo[]  = {KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
    [CMB_ESC]  = COMBO(esc_combo,  KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Layer 0 — Letters (QWERTY + home-row mods)
     */
    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,
                                                            KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                        KC_BSPC, KC_TAB,  MO(1),           KC_SPC,  KC_ENT,  MO(2)
    ),

    /*
     * Layer 1 — Numbers & Symbols (left thumb MO(1) held)
     * Right thumb outer = MO(3) → layer 3 when both thumbs held
     */
    [NUM_SYM] = LAYOUT_split_3x5_3(
        KC_HASH, KC_QUOT, KC_DQT,  KC_AT,   KC_QUES,      KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS,
        KC_LBRC, KC_LPRN, KC_RBRC, KC_RPRN, KC_UNDS,      KC_ASTR, KC_4,    KC_5,    KC_6,    KC_SLSH,
        KC_LT,   KC_LCBR, KC_GT,   KC_RCBR, KC_BSLS,      KC_0,    KC_1,    KC_2,    KC_3,    KC_DLR,
                        KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, MO(3)
    ),

    /*
     * Layer 2 — Arrows + Overflow Symbols (right thumb MO(2) held)
     * Left thumb inner = MO(3) → layer 3 when both thumbs held
     */
    [ARR_NAV] = LAYOUT_split_3x5_3(
        KC_TILD, KC_CIRC, KC_AMPR, KC_TRNS, KC_TRNS,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
        KC_EXLM, KC_MINS, KC_GRV,  KC_PERC, KC_PIPE,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        MO(3),   KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /*
     * Layer 3 — F-keys + System (both thumbs held)
     */
    [SYS] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12,  KC_TRNS, QK_REBOOT, QK_BOOT,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
