// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _B 0
#define _L 1
#define _R 2
#define _S 3



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
	[_B] = LAYOUT(
		KC_GRAVE,			KC_Q,		KC_W,	KC_E,			KC_R,				KC_T,
		KC_LCTL, 			KC_A,		KC_S,	KC_D,			KC_F,				KC_G,
		KC_LALT,			KC_Z,		KC_X,	KC_C,			KC_V,				KC_B,
		KC_CAPS,			KC_NO,		KC_NO,	KC_LEFT_GUI,	LT(_R, KC_TAB),	    LSFT_T(KC_SPC),	LT(_L, KC_ENT),


                                KC_Y,				KC_U,				KC_I,				KC_O,		KC_P,		KC_LEFT_BRACKET,
                                KC_H,				KC_J,				KC_K,				KC_L,		KC_SCLN,	RCTL_T(KC_QUOTE),
                                KC_N,				KC_M,				KC_COMM,			KC_DOT,	    KC_SLASH,	RALT_T(KC_BACKSLASH),
			LT(_L, KC_ESC),     LSFT_T(KC_BSPC),	LT(_R, KC_DEL),	    LGUI_T(KC_RCBR),	KC_D,		KC_E,       KC_F
	),
	[_L] = LAYOUT(
		LALT_T(KC_PEQL),	KC_1,		KC_2,	KC_3,			KC_4,		KC_5,
		LCTL_T(KC_PLUS),	KC_EXLM,	KC_AT,	KC_HASH,		KC_DLR,		KC_PERC,
		KC_UNDS, 			KC_F1,		KC_F2,	KC_F3,			KC_F4,		KC_F5,
		KC_NO,				KC_NO,		KC_NO,	KC_LEFT_GUI,	KC_TRNS,	LSFT_T(KC_SPC),	KC_TRNS,

                        KC_6,			    KC_7,			KC_8,		    KC_9,		KC_0,		KC_RALT,
                        KC_CIRC,		    KC_AMPR,		KC_ASTR,	    KC_LPRN,	KC_RPRN,	RCTL_T(KC_KP_MINUS),
                        KC_F6,			    KC_F7,			KC_F8,		    KC_F9,		KC_F10,	    KC_F11,
            KC_TRNS,    LSFT_T(KC_BSPC),	KC_TRNS,		LGUI_T(KC_F12),	KC_NO,		KC_NO,		KC_NO
	),
	[_R] = LAYOUT(
		KC_NUM,			    KC_PSLS,	KC_7,	KC_8,			KC_9,		KC_PMNS,
		LCTL_T(KC_PEQL), 	KC_PAST,	KC_4,	KC_5,			KC_6,		KC_PPLS,
		KC_LALT,			KC_0,		KC_1,	KC_2,			KC_3,		KC_PDOT,
		KC_NO,				KC_NO,		KC_NO,	KC_LEFT_GUI,	KC_TRNS,	LSFT_T(KC_SPC),	KC_TRNS,

                    KC_VOLU,		    KC_HOME,	KC_PSCR,	KC_PGUP,	KC_SCRL,	KC_CAPS,
                    KC_MUTE,		    KC_LEFT,	KC_UP,		KC_RIGHT,	KC_INS,	    RCTL_T(KC_APP),
                    KC_VOLD,	    	KC_END,		KC_DOWN,	KC_PGDN,	KC_PAUS,	KC_RALT,
		KC_TRNS,	LSFT_T(KC_BSPC),	KC_TRNS,	KC_LGUI,	KC_NO,		KC_NO,		KC_NO
	),
    [_S] = LAYOUT(
		DB_TOGG,			KC_NO,		KC_NO,	KC_NO,			KC_NO,		KC_NO,
		QK_BOOT,			KC_NO,		KC_NO,	KC_NO,			KC_NO,		KC_NO,
		RGB_MOD,			KC_NO,		KC_NO,	KC_NO,			KC_NO,		KC_NO,
		RGB_RMOD,			KC_NO,		KC_NO,	QK_RBT,		    KC_TRNS,	KC_NO,	    KC_TRNS,


                    KC_NO,	KC_NO,		KC_NO,		KC_NO,	KC_NO,	DB_TOGG,
                    KC_NO,	KC_NO,		KC_NO,		KC_NO,	KC_NO,	QK_BOOT,
                    KC_NO,	KC_NO,		KC_NO,		KC_NO,	KC_NO,	KC_NO,
		KC_TRNS,    KC_NO,	KC_TRNS,	QK_RBT,	    KC_NO,	KC_NO,	KC_NO
	),

    // clang-format on
};
