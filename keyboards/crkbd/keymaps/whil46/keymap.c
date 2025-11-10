/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum custom_keycodes {
  SWE_AA = SAFE_RANGE
 ,SWE_AE
 ,SWE_OE
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _BASE
 ,_LOWER
 ,_RAISE
 ,_ADJUST
};

// Define keys to keep them short in the config below

#define RAISE    LT(_RAISE, KC_SPC)
#define LOWER    MO(_LOWER)
#define GUI_ENT  LGUI_T(KC_ENT)
#define ALT_SPC  LALT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3_ex2(
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   KC_NO,      KC_NO,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_BSPC,
      KC_LCTL,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  QK_REP,     QK_REP,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, GUI_ENT,
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
                                           KC_ENT, ALT_SPC, KC_LSFT,      LOWER,   RAISE,  KC_LALT
  ),
  [_LOWER] = LAYOUT_split_3x6_3_ex2(
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,    _______, KC_PPLS,   KC_P7,   KC_P8,   KC_P9, KC_PAST, _______,
      _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,    _______, KC_PDOT,   KC_P4,   KC_P5,   KC_P6,   KC_P0, _______,
      _______,  KC_GRV, KC_BSLS, KC_SCLN, KC_MINS,  KC_EQL,                      KC_PMNS,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, _______,
                                          _______, _______, _______,    _______, _______, _______
  ),
  [_RAISE] = LAYOUT_split_3x6_3_ex2(
      _______, KC_PSCR, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, _______,    _______,  KC_INS,  SWE_AA,  SWE_AE,  SWE_OE, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, _______,    _______,  KC_DEL, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
      _______, KC_TILD, KC_PIPE, KC_COLN, KC_UNDS, KC_PLUS,                       KC_ESC, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
                                          _______, _______, _______,    _______, _______, _______
  ),
  [_ADJUST] = LAYOUT_split_3x6_3_ex2(
       UC_MAC, UC_LINX,  UC_WIN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  KC_APP,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,
                                          XXXXXXX, XXXXXXX, XXXXXXX,    _______, _______, XXXXXXX
                                     )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {

  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

uint32_t swe_unicodes[][2] = {
    {
      0x00E5, // å
      0x00C5, // Å
    },
    {
      0x00E4, // ä
      0x00C4, // Ä
    },
    {
      0x00F6, // ö
      0x00D6, // Öarstarstarstwww
    },
};

// Codes that work on mac without custom Unicode Hex input mode
char *swe_mac_US_codes[][2] = {
    {
        SS_RALT("a"), // Option+a → å
        SS_RALT("A"), // Option+A → Å
    },
    {
        SS_RALT("u")"a", // Option+u, a → ä
        SS_RALT("u")"A", // Option+u, A → Ä
    },
    {
        SS_RALT("u")"o", // Option+u, o → ö
        SS_RALT("u")"O", // Option+u, O → Ö
    },
};

// Codes that work on windows without any custom changes in OS or extra software
char *swe_win_alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_4)), // Alt+134 → å
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_3)), // Alt+143 → Å

    },
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_3)SS_TAP(X_KP_2)), // Alt+132 → ä
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_2)), // Alt+142 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_4)SS_TAP(X_KP_8)), // Alt+148 → ö
        SS_LALT(SS_TAP(X_KP_1)SS_TAP(X_KP_5)SS_TAP(X_KP_3)), // Alt+153 → Ö
    },
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* Custom SWEDISH Keycodes START */
  case SWE_AA:
  case SWE_AE:
  case SWE_OE:
    if (record->event.pressed) {
      uint8_t mods = get_mods();
      clear_mods();

      // Send code based on which key was pressed and whether Shift was held.
      uint16_t index = keycode - SWE_AA;
      uint8_t shift = mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
      uint8_t unicode_mode = get_unicode_input_mode();
      if (unicode_mode == UNICODE_MODE_MACOS) {
        send_string(swe_mac_US_codes[index][(bool)shift]);
      } else if (unicode_mode == UNICODE_MODE_WINDOWS) {
        send_string(swe_win_alt_codes[index][(bool)shift]);
      } else {
        register_unicode(swe_unicodes[index][(bool)shift]);
      }
      set_mods(mods);
    }
    return false;
    break;
  }
  return true;
}
