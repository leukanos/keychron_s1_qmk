/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    MOD
};

enum {
    TD_ESC_CAPS,
    TD_GRAVE_TILD
};

enum custom_keycodes {
    KC_WDEL = SAFE_RANGE
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    // Tap once for Grave, twice for Tilde
    [TD_GRAVE_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD)
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MOD LT(MOD, KC_ESC) // Tap for Escape, hold for the MOD layer

#define MOD_ONLY (1 << MOD)

// Key override definitions, active on the MOD layer only
// Cmd selects text
const key_override_t sel_left  = ko_make_with_layers(MOD_MASK_GUI, KC_LEFT, S(KC_LEFT), MOD_ONLY);
const key_override_t sel_down  = ko_make_with_layers(MOD_MASK_GUI, KC_DOWN, S(KC_DOWN), MOD_ONLY);
const key_override_t sel_up    = ko_make_with_layers(MOD_MASK_GUI, KC_UP,   S(KC_UP),   MOD_ONLY);
const key_override_t sel_right = ko_make_with_layers(MOD_MASK_GUI, KC_RGHT, S(KC_RGHT), MOD_ONLY);
const key_override_t sel_home  = ko_make_with_layers(MOD_MASK_GUI, KC_HOME, S(KC_HOME), MOD_ONLY);
const key_override_t sel_end   = ko_make_with_layers(MOD_MASK_GUI, KC_END,  S(KC_END),  MOD_ONLY);
const key_override_t sel_pgup  = ko_make_with_layers(MOD_MASK_GUI, KC_PGUP, S(KC_PGUP), MOD_ONLY);
const key_override_t sel_pgdn  = ko_make_with_layers(MOD_MASK_GUI, KC_PGDN, S(KC_PGDN), MOD_ONLY);
// Shift switches tabs and apps
const key_override_t tab_prev  = ko_make_with_layers(MOD_MASK_SHIFT, KC_LEFT, C(S(KC_TAB)), MOD_ONLY);
const key_override_t tab_next  = ko_make_with_layers(MOD_MASK_SHIFT, KC_RGHT, C(KC_TAB),    MOD_ONLY);
const key_override_t app_next  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOWN, G(KC_TAB),    MOD_ONLY);
const key_override_t app_prev  = ko_make_with_layers(MOD_MASK_SHIFT, KC_UP,   G(S(KC_TAB)), MOD_ONLY);

const key_override_t *key_overrides[] = {
    &sel_left, &sel_down, &sel_up, &sel_right,
    &sel_home, &sel_end, &sel_pgup, &sel_pgdn,
    &tab_prev, &tab_next, &app_next, &app_prev
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_75_ansi(
        TD(TD_ESC_CAPS),        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,  KC_NO,    KC_DEL,   RM_NEXT,
        TD(TD_GRAVE_TILD),      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,                 KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_MOD,                 KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,             KC_HOME,
        SC_LSPO,                KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              SC_RSPC,           KC_UP,    KC_END,
        KC_LCTL,                KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RALT,  MO(MAC_FN), KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_75_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,   _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,             QK_BOOT,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,   _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_75_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_PSCR,  KC_DEL,   RM_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_75_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,             _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,             _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,   _______,  _______,  _______,  _______),

    [MOD] = LAYOUT_75_ansi(
        HYPR(KC_ESC),  HYPR(KC_F1),   HYPR(KC_F2),   HYPR(KC_F3),   HYPR(KC_F4),   HYPR(KC_F5),   HYPR(KC_F6),   HYPR(KC_F7),   HYPR(KC_F8),   HYPR(KC_F9),   HYPR(KC_F10),  HYPR(KC_F11),  HYPR(KC_F12),  _______,       HYPR(KC_DEL),  _______,
        HYPR(KC_GRV),  HYPR(KC_1),    HYPR(KC_2),    HYPR(KC_3),    HYPR(KC_4),    HYPR(KC_5),    HYPR(KC_6),    HYPR(KC_7),    HYPR(KC_8),    HYPR(KC_9),    HYPR(KC_0),    HYPR(KC_MINS), HYPR(KC_EQL),  HYPR(KC_BSPC), _______,
        HYPR(KC_TAB),  HYPR(KC_Q),    HYPR(KC_W),    HYPR(KC_E),    LCTL(KC_R),    LCTL(KC_T),    HYPR(KC_Y),    KC_HOME,       HYPR(KC_I),    KC_END,        KC_PGUP,       HYPR(KC_LBRC), HYPR(KC_RBRC), HYPR(KC_BSLS), _______,
        _______,       HYPR(KC_A),    HYPR(KC_S),    LCTL(KC_D),    HYPR(KC_F),    HYPR(KC_G),    KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       KC_PGDN,       HYPR(KC_QUOT), HYPR(KC_ENT),  _______,
        _______,       LCTL(KC_Z),    LCTL(KC_X),    LCTL(KC_C),    LCTL(KC_V),    LCTL(KC_B),    KC_WDEL,       KC_BSPC,       KC_DEL,        LALT(KC_DEL),  HYPR(KC_SLSH), _______,       HYPR(KC_UP),   _______,
        KC_LCTL,       KC_LOPT,       KC_LCMD,       HYPR(KC_SPC),  KC_RALT,       MO(MAC_FN),    KC_RCTL,       HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_RGHT)),
};

// clang-format on

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MOD:
            return true;
        default:
            return false;
    }
}

// Opt+Backspace deletes a word. With Cmd held it becomes Cmd+Backspace and deletes the line.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool line_delete;

    if (keycode != KC_WDEL) {
        return true;
    }
    if (record->event.pressed) {
        line_delete = get_mods() & MOD_MASK_GUI;
        if (line_delete) {
            register_code(KC_BSPC);
        } else {
            register_code16(A(KC_BSPC));
        }
    } else if (line_delete) {
        unregister_code(KC_BSPC);
    } else {
        unregister_code16(A(KC_BSPC));
    }
    return false;
}
