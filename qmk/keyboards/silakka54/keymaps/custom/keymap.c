/* Copyright 2025 QMK Contributors
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Silakka54 keymap — mirrors Lily58 ZMK layout.
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

    /*
     * Layer 0 — Letters (QWERTY + home-row mods)
     *
     * Row 0 — all &trans (outside Corne footprint, empty on Silakka54)
     * Row 1 — QWERTY (outer columns removed, on thumbs instead)
     * Row 2 — Home row with mod-tap
     * Row 3 — Bottom row (Shift only via home-row mods)
     * Row 4 — Thumbs (adapted from 4→3 per side)
     *
     *   ┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
     *   │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │ TRNS  │   Q   │   W   │   E   │   R   │   T   │ │   Y   │   U   │   I   │   O   │   P   │ TRNS  │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │  ESC  │ A/CMD │ S/Opt │D/Ctrl │F/Shft │   G   │ │   H   │J/Shft │K/Ctrl │ L/Opt │;/CMD  │   '   │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │ TRNS  │   Z   │   X   │   C   │   V   │   B   │ │   N   │   M   │   ,   │   .   │   /   │ TRNS  │
     *   └───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
     *               ┌───────┬───────┬───────┐               ┌───────┬───────┬───────┐
     *               │  LWR  │  TAB  │ BSPC  │               │  SPC  │  ENT  │  RSE  │
     *               └───────┴───────┴───────┘               └───────┴───────┴───────┘
     */
    [BASE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
        KC_ESC,  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,
                                                                     KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                                    MO(1),   KC_TAB,  KC_BSPC,       KC_SPC,  KC_ENT,  MO(2)
    ),

    /*
     * Layer 1 — Numerals & Symbols (no Shift available, all direct)
     *
     *   ┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
     *   │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │   !   │   #   │   ^   │   &   │   *   │   ?   │ │   =   │   7   │   8   │   9   │   +   │   -   │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │   `   │   [   │   (   │   ]   │   )   │   ~   │ │   @   │   4   │   5   │   6   │   /   │   \   │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │   %   │   <   │   {   │   >   │   }   │   |   │ │   0   │   1   │   2   │   3   │   $   │   _   │
     *   └───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
     *               ┌───────┬───────┬───────┐               ┌───────┬───────┬───────┐
     *               │ TRNS  │ TRNS  │ TRNS  │               │ TRNS  │ TRNS  │ TRNS  │
     *               └───────┴───────┴───────┘               └───────┴───────┴───────┘
     */
    [NUM_SYM] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_EXLM, KC_HASH, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,      KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_MINS,
        KC_GRV,  KC_LBRC, KC_LPRN, KC_RBRC, KC_RPRN, KC_TILD,      KC_AT,   KC_4,    KC_5,    KC_6,    KC_SLSH, KC_BSLS,
        KC_PERC, KC_LT,   KC_LCBR, KC_GT,   KC_RCBR, KC_PIPE,      KC_0,    KC_1,    KC_2,    KC_3,    KC_DLR,  KC_UNDS,
                                    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /*
     * Layer 2 — Functional (F-keys, navigation, bootloader)
     *
     *   ┌───────┬───────┬───────┬───────┬───────┬───────┐ ┌───────┬───────┬───────┬───────┬───────┬───────┐
     *   │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │  F1   │  F2   │  F3   │  F4   │  F5   │  F6   │ │ HOME  │ PGDN  │ PGUP  │  END  │  INS  │  DEL  │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │  F7   │  F8   │  F9   │  F10  │  F11  │  F12  │ │ LEFT  │ DOWN  │  UP   │ RIGHT │ TRNS  │ TRNS  │
     *   ├───────┼───────┼───────┼───────┼───────┼───────┤ ├───────┼───────┼───────┼───────┼───────┼───────┤
     *   │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │ TRNS  │
     *   └───────┴───────┴───────┴───────┴───────┴───────┘ └───────┴───────┴───────┴───────┴───────┴───────┘
     *               ┌───────┬───────┬───────┐               ┌───────┬───────┬───────┐
     *               │ BOOT  │ TRNS  │ TRNS  │               │ TRNS  │ TRNS  │ TRNS  │
     *               └───────┴───────┴───────┘               └───────┴───────┴───────┘
     */
    [FUNC] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_DEL,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    QK_BOOT, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

/* Native QMK combos */
const uint16_t PROGMEM esc_combo[]  = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo,  KC_ESC),
    COMBO(caps_combo, KC_CAPS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}
