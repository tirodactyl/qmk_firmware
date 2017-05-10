#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "action_tapping.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3
#define _GUI 4
#define _KEYBOARD 16

// Special key codes
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NAV,
  GUI,
  KEYBOARD,
};

#define MACSLEEP LSFT(LCTL(KC_POWER))
#define WINSLEEP KC_SLEP

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___x___ KC_NO

// Macros
#define HYPER_LCBK 11
#define HYPER_RCBK 12
#define ALT_LABK 13
#define ALT_RABK 14

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base layer (Qwerty)
 * NOTE: Hyper = Ctrl + Shift + Alt + Gui
 *                ,-----------------------------------------------------------------------.
 *                | Tab | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | '   |
 *                |-----------------------------------------------------------------------|
 * Tap for Esc -- |Ctrl | A   | S   | D   | F   | G   | H   | J   | K   | L   |; Fn4|Ctrl | -- Tap for Enter
 *                |-----------------------------------------------------------------------|
 *   Tap for ( -- |Shift| Z   | X   | C   | V   | B   | N   | M   | ,   | .   | /   |Shift| -- Tap for )
 *                |-----------------------------------------------------------------------|
 *   Tap for [ -- | Fn3 |Hyper| Alt |GUI  | Fn1 | Bsp | Spc | Fn2 |GUI  | Alt |Hyper| Fn3 | -- Tap for ]
 *                `-----------------------------------------------------------------------'
 *                        /                                                     /
 *   Tap for { } --------'-----------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,          KC_W,        KC_E,    KC_R,  KC_T,    KC_Y, KC_U,  KC_I,    KC_O,        KC_P,            KC_QUOT, \
  F(5),    KC_A,          KC_S,        KC_D,    KC_F,  KC_G,    KC_H, KC_J,  KC_K,    KC_L,        F(1),            F(6), \
  KC_LSPO, KC_Z,          KC_X,        KC_C,    KC_V,  KC_B,    KC_N, KC_M,  KC_COMM, KC_DOT,      KC_SLSH,         KC_RSPC, \
  F(3),    F(HYPER_LCBK), F(ALT_LABK), KC_LGUI, LOWER, KC_BSPC, F(7), RAISE, KC_RGUI, F(ALT_RABK), F(HYPER_RCBK),   F(4) \
),

/* Numeric layer
 *                ,-----------------------------------------------------------------------.
 * Application -- |D-Grv| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | #   |
 *      window    |-----------------------------------------------------------------------|
 *    switcher    |     | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   |     |
 *                |-----------------------------------------------------------------------|
 *                |     | -   | =   | `   | \   | a   | b   | c   | d   | e   | f   |     |
 *                |-----------------------------------------------------------------------|
 *                |     |     |     |     |     | Bsp | Bsp |     |     |     |     |
 *                `-----------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  LGUI(KC_GRV), KC_F1,         KC_F2,       KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7, KC_F8,   KC_F9,       KC_F10,        S(KC_3), \
  F(5),         KC_1,          KC_2,        KC_3,    KC_4,    KC_5,    KC_6,    KC_7,  KC_8,    KC_9,        KC_0,          F(6), \
  KC_LSPO,      KC_MINS,       KC_EQL,      KC_GRV,  KC_BSLS, KC_A,    KC_B,    KC_C,  KC_D,    KC_E,        KC_F,          KC_RSPC, \
  F(3),         F(HYPER_LCBK), F(ALT_LABK), KC_LGUI, LOWER,   KC_BSPC, KC_BSPC, RAISE, KC_RGUI, F(ALT_RABK), F(HYPER_RCBK), F(4) \
),

/* Symbol layer
 *                ,-----------------------------------------------------------------------.
 * Application -- |D-Tab| F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | #   |
 *    switcher    |-----------------------------------------------------------------------|
 *                |     | !   | @   | #   | $   | %   | ^   | &   | *   | '   | "   |     | \
 *                |-----------------------------------------------------------------------|  |-- Mostly shifted version
 *                |     | _   | +   | ~   | |   |     |ndash|mdash|     |     |     |     | /    of lower layer
 *                |-----------------------------------------------------------------------|
 *                |     |     |     |     |     | Del | Del |     |     |     |     |     |
 *                `-----------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  LGUI(KC_TAB), KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,        KC_F17,           KC_F18,  KC_F19,  KC_F20,     S(KC_3), \
  _______,      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6),       S(KC_7),          S(KC_8), KC_QUOT, S(KC_QUOT), _______, \
  _______,      KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, ___x___, LALT(KC_MINS), S(LALT(KC_MINS)), ___x___, ___x___, ___x___,    _______, \
  _______,      _______, _______, _______, _______, KC_DEL,  KC_DEL,        _______,          _______, _______, _______,    _______ \
),

/* Directional navigation layer
 *
 *         Large movements -----/```````````````````\   /```````````````````\----- Vim-style arrow keys
 *                ,-----------------------------------------------------------------------.
 *                |     |     |     |     |     |     |     |     |     |     |     |     |
 *                |-----------------------------------------------------------------------|
 *                |     |     |Home |PgUp |PgDn | End |Left |Down | Up  |Right|     |     |
 *                |-----------------------------------------------------------------------|
 *                |     |     |     |     |     |     |     |     |     |     |     |     |
 *                |-----------------------------------------------------------------------|
 *                |     |     |     |     |     |     |     |     |     |     |     |     |
 *                `-----------------------------------------------------------------------'
 */
[_NAV] = KEYMAP( \
  ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
  _______, ___x___, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, F(1),    _______, \
  _______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, _______, \
  _______, _______, _______, _______, ___x___, ___x___, ___x___, ___x___, _______, _______, _______, _______ \
),

/* GUI (window management/mouse/media controls) layer
 *
 *        Mouse keys -----/```````````````````\               /```````````````````\----- Window manager
 *                ,-----------------------------------------------------------------------.
 *                |     |Ms B2|Ms Up|Ms B1|Ms WD|     |     |Prev | TL  | Top | TR  |     |
 *                |-----------------------------------------------------------------------|
 *                |     |Ms L |Ms Dn|Ms R |Ms WU|     |     |Full |Left |Centr|Right|     |
 *                |-----------------------------------------------------------------------|
 *                |     |Ms WL|Ms B3|Ms WR|     |     |     |Next | BL  | Bot | BR  |     |
 *                |-----------------------------------------------------------------------|
 *                |     |Prev |Play |Next |Brig-|Sleep|Sleep|Brig+|Mute |Vol- |Vol+ |     |
 *                `-----------------------------------------------------------------------'
 *                        \___ Media ___/   \___ Screen/sleep __/   \___ Volume __/
 */
[_GUI] = KEYMAP( \
  _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D, ___x___,  ___x___,  LCTL(LALT(LGUI(KC_LEFT))), LCTL(LGUI(KC_LEFT)),    LALT(LGUI(KC_UP)),   LCTL(LGUI(KC_RGHT)),    _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, ___x___,  ___x___,  LALT(LGUI(KC_F)),          LALT(LGUI(KC_LEFT)),    LALT(LGUI(KC_C)),    LALT(LGUI(KC_RGHT)),    _______, \
  _______, KC_WH_L, KC_BTN3, KC_WH_R, ___x___, ___x___,  ___x___,  LCTL(LALT(LGUI(KC_RGHT))), S(LCTL(LGUI(KC_LEFT))), LALT(LGUI(KC_DOWN)), S(LCTL(LGUI(KC_RGHT))), _______, \
  _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_SLCK, MACSLEEP, MACSLEEP, KC_PAUS,                   KC_MUTE,                KC_VOLD,             KC_VOLU,                _______ \
),

/* Keyboard settings layer
 *                ,-----------------------------------------------------------------------.
 *    Firmware -- |     |Reset|     |     |     |     |     |     |     |     |     |     |
 *                |-----------------------------------------------------------------------|
 *   Set layer -- |     |Qwert|     |     | ... |     |     |     |     |     |     |     |
 *                |-----------------------------------------------------------------------|
 *       Audio -- |     |Voic-|Voic+|Mus +|Mus -|MIDI+|MIDI-|     |     |Aud +|Aud -|     |
 *                |-----------------------------------------------------------------------|
 *                |     |     |     |     |     |  Toggle   |     |Toggl| BL- | BL+ |     |
 *                `-----------------------------------------------------------------------'
 *                                                    \_____________\_ Backlight _/
 */
[_KEYBOARD] = KEYMAP( \
  ___x___, RESET,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
  ___x___, QWERTY,  ___x___, ___x___,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
  ___x___, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  ___x___, ___x___, AU_ON,   AU_OFF,  ___x___, \
  ___x___, ___x___, ___x___, ___x___, LOWER,   BL_TOGG, BL_TOGG, RAISE,   BL_TOGG, BL_DEC,  BL_INC,  ___x___ \
)
};

const uint16_t PROGMEM fn_actions[] = {
  // Layer switching
  [1] = ACTION_LAYER_TAP_KEY(_NAV, KC_SCOLON),
  [2] = ACTION_LAYER_TAP_KEY(_NAV, KC_O),
  [3] = ACTION_LAYER_TAP_KEY(_GUI, KC_LBRACKET),
  [4] = ACTION_LAYER_TAP_KEY(_GUI, KC_RBRACKET),

  // Modifiers
  [5] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [6] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),
  [7] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SPC),
  [HYPER_LCBK] = ACTION_MACRO_TAP(HYPER_LCBK),
  [HYPER_RCBK] = ACTION_MACRO_TAP(HYPER_RCBK),
  [ALT_LABK] = ACTION_MACRO_TAP(ALT_LABK),
  [ALT_RABK] = ACTION_MACRO_TAP(ALT_RABK)
};

// Helper function taken from keyboards/kitten_paw/keymaps/ickerwx/keymap.c
void tap_helper(keyrecord_t *record, uint16_t orig_mod, uint16_t macro_mod, uint16_t macro_kc ) {
  if (record->event.pressed) {
      if (record->tap.count > 0 && !record->tap.interrupted) {
          if (record->tap.interrupted) {
              register_mods(MOD_BIT(orig_mod));
          }
      } else {
          register_mods(MOD_BIT(orig_mod));
      }
  } else {
      if (record->tap.count > 0 && !(record->tap.interrupted)) {
          add_weak_mods(MOD_BIT(macro_mod));
          send_keyboard_report();
          register_code(macro_kc);
          unregister_code(macro_kc);
          del_weak_mods(MOD_BIT(macro_mod));
          send_keyboard_report();
          record->tap.count = 0;  // ad hoc: cancel tap
      } else {
          unregister_mods(MOD_BIT(orig_mod));
      }
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case HYPER_LCBK:
      tap_helper(record, (MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI), KC_LSFT, KC_LBRC);
      break;
    case HYPER_RCBK:
      tap_helper(record, (MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI), KC_LSFT, KC_RBRC);
      break;
    case ALT_LABK:
      tap_helper(record, KC_LALT, KC_LSFT, KC_COMM);
      break;
    case ALT_RABK:
      tap_helper(record, KC_RALT, KC_LSFT, KC_DOT);
      break;
  }
  return MACRO_NONE;
}

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _KEYBOARD);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _KEYBOARD);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _KEYBOARD);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _KEYBOARD);
      }
      return false;
      break;
    case GUI:
      if (record->event.pressed) {
        layer_on(_GUI);
      } else {
        layer_off(_GUI);
      }
      return false;
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      return false;
      break;
    case KEYBOARD:
      if (record->event.pressed) {
        layer_on(_KEYBOARD);
      } else {
        layer_off(_KEYBOARD);
      }
      return false;
      break;
  }
  return true;
}
