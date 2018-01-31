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
    LEGACY_KEYMAP(
		ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC, BSPC, \
		TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS, \
		LCTL, A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT, NUHS, ENT,  \
		LSFT, NUBS, Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,   NO, RSFT, NO, \
		FN1,  LGUI, LALT,            KC_SPACE,                   RALT, RGUI,  APP,  RCTL),

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
    LEGACY_KEYMAP(
		GRV,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  TRNS, DEL,  \
		TRNS, MPRV, MPLY, MNXT, MSTP, TRNS, HOME, PGDN, PGUP, END,  TRNS, SLCK, PAUS, INS,  \
		TRNS, VOLD, MUTE, VOLU, TRNS, TRNS, LEFT, DOWN, UP,   RGHT, TRNS, TRNS, PENT, \
		TRNS, TRNS, PSCR, FN1,  FN2,  FN3,  CALC, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, CAPS, TRNS, \
		TRNS, TRNS, TRNS,             TRNS,                         TRNS, TRNS, TRNS, TRNS),
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
