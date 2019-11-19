/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum keyboard_layers {
	_BASE = 0,  // Base Layer
	_FN1,      // Function Layer
	_FN2       // Control Layer
};

enum unicode_names {
	AEU,
	AEL,
	OEU,
	OEL,
	EUR
};

const uint32_t PROGMEM unicode_map[] = {
	[AEU] = 0x00C4,  // umlaut a upper
	[AEL] = 0x00E4,  // umlaut a lower
	[OEU] = 0x00F6,  // umlaut o upper 
	[OEL] = 0x00D6,  // umlaut o lower
	[EUR] = 0x20AC,  // euro
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT_60_ansi(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		MO(_FN1),         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
		KC_LCTL, MO(_FN2),         KC_LALT,                   KC_SPC,                             MO(_FN1),KC_RALT, KC_RGUI,          KC_RCTL),

	[_FN1] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, X(EUR),  _______, _______, _______, _______, _______, XP(OEL,OEU), _______, _______, _______, _______,
		_______,      XP(AEL,AEU), _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,
		_______,          _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______,          _______,                   _______,                            _______, _______,          _______, _______),

	[_FN2] = LAYOUT_60_ansi(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,          _______, _______, _______, _______, _______, _______, KC_HOME, C(KC_LEFT), C(KC_RGHT), KC_END,  _______, _______, RESET,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______,          _______,                   _______,                            _______, _______,          _______, _______)
};
