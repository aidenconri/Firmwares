#include QMK_KEYBOARD_H

#define HOME 0
#define FN 1
#define FNCHAR 2
#define FKEYS 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_P7, KC_P8, KC_P9, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_P4, KC_P5, KC_P6, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
		KC_P1, KC_P2, KC_P3, MT(MOD_LCTL, KC_Z), MT(MOD_LALT, KC_X), LT(1, KC_C), LT(2, KC_V), MT(MOD_LSFT, KC_SPC), MT(MOD_RGUI,KC_B), MT(MOD_RALT, KC_N), MT(MOD_RCTL, KC_M)),

	[FN] = LAYOUT(
		KC_INS, KC_HOME, KC_PGUP, KC_ESC, KC__MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO,
		KC_DEL, KC_UP, KC_PGDN, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC,
		KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_LALT, KC_TRNS, MO(3), MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL),

	[FNCHAR] = LAYOUT(
		KC_NLCK,KC_NO,KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_NO,KC_NO,KC_NO, KC_GRV,KC_NO,KC_MINS,KC_EQL,KC_BSLS,KC_LBRC,KC_RBRC,KC_SCLN,KC_QUOT,KC_BSPC,
		KC_NO,KC_NO,KC_NO, KC_LCTL, KC_LALT, MO(3), KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH),

	[FKEYS] = LAYOUT(
		KC_NO,KC_NO,KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_NO,KC_NO,KC_NO, KC_F11,KC_F12,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_DEL,
		KC_NO,KC_NO,KC_NO, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, MT(MOD_LSFT, KC_SPC), KC_RGUI, KC_RALT, KC_RCTL),
};

void matrix_init_user(void) {
  setPinOutput(D3);
  writePinLow(D3);
}

void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinHigh(D3);
    } else {
        writePinLow(D3);
    }
}