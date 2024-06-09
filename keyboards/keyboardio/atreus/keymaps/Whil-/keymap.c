// Copyright 2022 Mark Stosberg (@markstos)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Define keys to keep them short in the config below
// For 0 (base) layer
#define CTL_ESC  LCTL_T(KC_ESC)
#define CTL_SPC  RCTL_T(KC_SPC)
#define CTL_TAB  LCTL_T(KC_TAB)
#define CTL_ENT  LCTL_T(KC_ENT)

#define ALT_QUOT LALT_T(KC_QUOT)
#define ALT_ENT  LALT_T(KC_ENT)
#define ALT_MINS LALT_T(KC_MINS)
#define ALT_EQL  RALT_T(KC_EQL)
#define ALT_TAB  RALT_T(KC_TAB)

#define GUI_QUOT RGUI_T(KC_QUOT)
#define GUI_ENT  LGUI_T(KC_ENT)
#define GUI_TAB  LGUI_T(KC_TAB)

#define BSE_MAC  DF(0)
#define BSE_WIN  DF(1)

#define LOW_TAB  LT(2, KC_TAB)
#define LOW_BSPC LT(2, KC_BSPC)

#define RSE_BSPC LT(3, KC_BSPC)
#define RSE_SPC  LT(3, KC_SPC)

#define ADJUST   MO(4)

#define OSM_RALT OSM(MOD_RALT)
#define OSM_SFT  OSM(MOD_RSFT)

// Win
#define GUI_GRV  RGUI_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Mac
  [0] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
  //|--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_BSLS,     KC_GRV,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      CTL_ESC,ALT_MINS, XXXXXXX, GUI_TAB,LOW_BSPC, OSM_SFT,    OSM_SFT, RSE_SPC, CTL_ENT, XXXXXXX, ALT_EQL,GUI_QUOT
  //|-----------------------------------------------------'  `-----------------------------------------------------|
  ),
  // Win (GUI -> ALT, Extra GUI-key)
  [1] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
  //|--------+--------+--------+--------+--------|--------|  |--------+--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_BSLS,    GUI_GRV,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      CTL_ESC,ALT_MINS, KC_LGUI, ALT_TAB,LOW_BSPC, OSM_SFT,    OSM_SFT, RSE_SPC, CTL_ENT, KC_RGUI, ALT_EQL,ALT_QUOT
  //|-----------------------------------------------------'  `-----------------------------------------------------|
  ),

  // Lower
  [2] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_LBRC, KC_LCBR,    KC_RCBR, KC_RBRC, KC_RPRN, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,    _______,  _______, _______, _______, _______, _______
  //|-----------------------------------------------------'  `-----------------------------------------------------|
    ),

  // Raise
  [3] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_DEL, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______
  //|-----------------------------------------------------'  `-----------------------------------------------------|
  ),
  // Adjust
  [4] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       KC_F11,  KC_F12, KC_BTN2, KC_BTN1, KC_BTN3,                       KC_APP, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, BSE_MAC, BSE_WIN, KC_WH_D, KC_WH_U, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //|-----------------------------------------------------'  `-----------------------------------------------------|
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, 2, 3, 4);
  return state;
}
