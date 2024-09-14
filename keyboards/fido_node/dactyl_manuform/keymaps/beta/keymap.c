// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later


#include QMK_KEYBOARD_H

#define _B 0
#define _L 1
#define _R 2
#define _S 3

#undef TAPPING_TERM
// default but used in macros
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Left-hand home row mods
#define H_LC(K)    LCTL_T(K)
#define H_LA(K)    LALT_T(K)
#define H_LG(K)    LGUI_T(K)
#define H_LS(K)    LSFT_T(K)
#define H_H(K)     HYPR_T(K)

// Right-hand home row mods
#define H_H(K)     HYPR_T(K)
#define H_RS(K)    RSFT_T(K)
#define H_RG(K)    RGUI_T(K)
#define H_RA(K)    LALT_T(K)
#define H_RC(K)    RCTL_T(K)


#define LT_L(K)    LT(_L, K)
#define LT_R(K)    LT(_R, K)

#define KC_TR      KC_TRNS

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM system_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_RED}, // Light 4 LEDs, starting with LED 6
                                                                          {12, 4, HSV_RED} // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 6, HSV_CYAN});
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS({5, 6, HSV_PURPLE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(system_layer,
                                                                               lower_layer, // Overrides caps lock layer
                                                                               raise_layer  // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _L));
    rgblight_set_layer_state(2, layer_state_cmp(state, _R));
    rgblight_set_layer_state(0, layer_state_cmp(state, _S));
    /* switch (get_highest_layer(state)) { */
    /*     case _R: */
    /*         rgblight_setrgb(0x00, 0x00, 0xFF); */
    /*         break; */
    /*     case _L: */
    /*         rgblight_setrgb(0xFF, 0x00, 0x00); */
    /*         break; */
    /*     case _S: */
    /*         rgblight_setrgb(0x7A, 0x00, 0xFF); */
    /*         break; */
    /*     default: //  for any other layers, or the default layer */
    /*         rgblight_setrgb(0x00, 0xFF, 0xFF); */
    /*         break; */
    /* } */
    return update_tri_layer_state(state, _L, _R, _S);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_B] = LAYOUT(
                        KC_GRAVE,           KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,
                        KC_CAPS,            H_LC(KC_A),     H_LA(KC_S),     H_LG(KC_D),     H_LS(KC_F),     H_H(KC_G),
                        KC_TR,              KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,
                        KC_CAPS,            KC_TR,          KC_TR,          KC_TR,          LT_R(KC_TAB),   KC_SPC,             LT_L(KC_ENT),

                        KC_Y,               KC_U,           KC_I,           KC_O,           KC_P,           KC_LEFT_BRACKET,
                        H_H(KC_H),          H_RS(KC_J),     H_RG(KC_K),     H_RA(KC_L),     H_RC(KC_SCLN),  KC_QUOTE,
                        KC_N,               KC_M,           KC_COMM,        KC_DOT,         KC_SLASH,       KC_BACKSLASH,
        LT_L(KC_ESC),   KC_BSPC,            LT_R(KC_DEL),   KC_RCBR,        KC_TR,          KC_TR,          KC_TR
    ),

    [_L] = LAYOUT(
                        KC_UNDS,            KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,
                        KC_PLUS,            H_LC(KC_EXLM),  H_LA(KC_AT),    H_LG(KC_HASH),  H_LS(KC_DLR),   H_H(KC_PERC),
                        KC_PEQL,            KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
                        KC_TR,              KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_SPC,             KC_TR,

                        KC_F6,              KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
                        H_H(KC_CIRC),       H_RS(KC_AMPR),  H_RG(KC_ASTR),  H_RA(KC_LPRN),  H_LS(KC_RPRN),  KC_KP_MINUS,
                        KC_6,               KC_7,           KC_8,           KC_9,           KC_0,           KC_TR,
        KC_TR,          KC_BSPC,            KC_TR,          KC_F12,         KC_TR,          KC_TR,          KC_TR
    ),

    [_R] = LAYOUT(
                        KC_NUM,             KC_PSLS,        KC_7,           KC_8,           KC_9,           KC_PMNS,
                        KC_PEQL,            H_LC(KC_PAST),  H_LA(KC_4),     H_LG(KC_5),     H_LS(KC_6),     H_H(KC_PPLS),
                        KC_TR,              KC_0,           KC_1,           KC_2,           KC_3,           KC_PDOT,
                        KC_TR,              KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_SPC,             KC_TR,

                        KC_VOLU,            KC_HOME,        KC_PSCR,        KC_PGUP,        KC_SCRL,        KC_CAPS,
                        H_H(KC_MUTE),       H_RS(KC_LEFT),  H_RG(KC_UP),    H_RA(KC_RIGHT), H_LS(KC_INS),   KC_APP,
                        KC_VOLD,            KC_END,         KC_DOWN,        KC_PGDN,        KC_PAUS,        KC_TR,
        KC_TR,          KC_BSPC,            KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_TR
    ),

    [_S] = LAYOUT(
                        DB_TOGG,            KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_TR,
                        QK_BOOT,            KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_TR,
                        RGB_MOD,            KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_TR,
                        RGB_RMOD,           KC_TR,          KC_TR,          QK_RBT,         KC_TR,          KC_TR,              KC_TR,


                        KC_TR,              KC_TR,          KC_TR,          KC_TR,          KC_TR,          DB_TOGG,
                        KC_TR,              KC_TR,          KC_TR,          KC_TR,          KC_TR,          QK_BOOT,
                        KC_TR,              KC_TR,          KC_TR,          KC_TR,          KC_TR,          KC_TR,
        KC_TR,          KC_TR,              KC_TR,          QK_RBT,         KC_TR,          KC_TR,          KC_TR
    ),

    // clang-format on
};
