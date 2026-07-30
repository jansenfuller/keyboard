/* Cheapino v2 — Standard QMK keymap. Home-row mods: F=Shift, J=Shift, D=Ctrl, K=Ctrl */

#include QMK_KEYBOARD_H

enum layers { BASE = 0, NUM_SYM, ARR_NAV, SYS };
enum combos { CMB_ESC, CMB_CAPS, CMB_LENGTH };
const uint16_t PROGMEM esc_combo[]  = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM caps_combo[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
    [CMB_ESC]  = COMBO(esc_combo,  KC_ESC),
    [CMB_CAPS] = COMBO(caps_combo, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,
                                                            KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                        LT(1,KC_TAB), KC_BSPC, KC_TRNS,    KC_TRNS, KC_SPC,  LT(2,KC_ENT)
    ),

    [NUM_SYM] = LAYOUT_split_3x5_3(
        KC_TILD, KC_EXLM, KC_UNDS, KC_PIPE, KC_CIRC,      KC_EQL,  KC_7,    KC_8,    KC_9,    KC_QUOT,
        KC_PERC, KC_AT,   KC_HASH, KC_DLR,  KC_AMPR,      KC_ASTR, KC_4,    KC_5,    KC_6,    KC_DQT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_0,    KC_1,    KC_2,    KC_3,    KC_PLUS,
                        KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, MO(3)
    ),

    [ARR_NAV] = LAYOUT_split_3x5_3(
        KC_MINS, KC_EQL,  KC_GRV,  KC_BSLS, KC_PIPE,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
        KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AMPR,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
        KC_LBRC, KC_RBRC, KC_LT,   KC_GT,   KC_EXLM,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, MO(3),           KC_TRNS, KC_TRNS, MO(3)
    ),

    [SYS] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,
        KC_TRNS, KC_TRNS, KC_TRNS, QK_REBOOT, QK_BOOT,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
