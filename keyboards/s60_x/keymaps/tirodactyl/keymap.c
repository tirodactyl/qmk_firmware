#include "s60_x.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Layout 0: Default Layer
	* ,-----------------------------------------------------------.
	* |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
	* |-----------------------------------------------------------|
	* |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
	* |-----------------------------------------------------------|
	* |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
	* |-----------------------------------------------------------|
	* |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
	* |-----------------------------------------------------------|
	* |Fn0 |Gui |Alt |         Space          |Alt |Gui |App |Ctrl|
	* `-----------------------------------------------------------'
	*/
    KEYMAP(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_BSPC, \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS, \
		MOD_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  \
		MOD_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO, MOD_RSFT, KC_NO, \
		KC_FN0,  MOD_LGUI, MOD_LALT,            KC_SPACE,                   MOD_RALT, MOD_RGUI,  KC_APP,  MOD_RCTL),

	/* Layout 1: Function Layer
	* ,-----------------------------------------------------------.
	* |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
	* |-----------------------------------------------------------|
	* |     |Prv|Ply|Nxt|Stp|   |Hom|PDn|PUp|End|   |Slk|Pau|Ins  |
	* |-----------------------------------------------------------|
	* |      |Vl-|Mut|Vl+|   |   |Lef||Dow|Up |Rig|   |PEnt    |
	* |-----------------------------------------------------------|
	* |        |Prt|Cut|Cop|Pst|Cal|   |   |   |   |   |CapsLock  |
	* |-----------------------------------------------------------|
	* |    |    |    |                        |    |    |    |    |
	* `-----------------------------------------------------------'
	*/
    KEYMAP(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_DEL,  \
		KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_SLCK, KC_PAUS, KC_INS,  \
		KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_PENT, \
		KC_TRNS, KC_TRNS, KC_PSCR, KC_FN1,  KC_FN2,  KC_FN3,  KC_CALC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, \
		KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

/*
* Fn action definition
*/
const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_LAYER_MOMENTARY(1),            /* Momentary layout 1 */
	[1] = ACTION_MODS_KEY(MOD_LSFT, KC_DEL),    /* Cut  */
	[2] = ACTION_MODS_KEY(MOD_LCTL, KC_INS),    /* Copy  */
	[3] = ACTION_MODS_KEY(MOD_LSFT, KC_INS),    /* Paste */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
