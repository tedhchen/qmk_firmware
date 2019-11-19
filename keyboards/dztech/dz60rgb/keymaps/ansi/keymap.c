#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

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
	[OEU] = 0x00D6,  // umlaut o upper 
	[OEL] = 0x00F6,  // umlaut o lower
	[EUR] = 0x20AC,  // euro
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_LAYER0] = LAYOUT_60_ansi(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		MO(1),            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
		KC_LCTL, MO(2),            KC_LALT,                   KC_SPC,                             MO(1),   KC_RALT, KC_RGUI,          KC_RCTL),

	[_LAYER1] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_PGUP, _______,
		_______,          _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______,          _______,                   _______,                            _______, _______,          _______, _______),

	[_LAYER2] = LAYOUT_60_ansi(
		RGB_TOG, UC_M_WC, UC_M_LN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______,          _______, _______, X(EUR),  _______, _______, _______, _______, _______, XP(OEL,OEU), _______, _______, _______, RESET,
		_______,      XP(AEL,AEU), _______, _______, _______, _______, _______, KC_HOME, C(KC_LEFT), C(KC_RGHT), KC_END, _______, _______,
		_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______,          _______,                   _______,                            _______, _______,          _______, _______),
		};

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue, bool default_layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
        rgb_matrix_set_color( i, red, green, blue );
    }
  }
}

void rgb_matrix_indicators_user(void) {
	  uint8_t this_led = host_keyboard_leds();
	  if (!g_suspend_state) {
	    switch (biton32(layer_state)) {
	      case _LAYER1:
		    rgb_matrix_layer_helper(0xFF, 0x00, 0x00, false); break;
	      case _LAYER2:
	        rgb_matrix_layer_helper(0x00, 0xFF, 0x00, false); break;
	    							  }
	                        }
	  if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
	        rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
	  }

}

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

	bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	  return true;
	}
