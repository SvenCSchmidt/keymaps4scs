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

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4
#define _LAYER5 5

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LAYER0] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_QUOT, KC_MINS, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), KC_BSLS, SC_LSPO, KC_Z, RALT_T(KC_X), KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, RALT_T(KC_DOT), KC_SLSH, SC_RSPC, LT(4,QK_GESC), KC_BSPC, LT(1,KC_TAB), LT(2,KC_ENT), LT(5,KC_SPC), LT(3,KC_DEL)),

[_LAYER1] = LAYOUT(KC_NO, KC_INS, KC_DEL, KC_UP, KC_PGUP, LCTL(KC_Y), KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_SCRL, KC_RCTL, KC_RSFT, KC_LALT, KC_RALT, KC_NO, KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), KC_PGDN, LCTL(KC_V), KC_PAUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_TRNS, KC_NO, KC_ENT, KC_SPC, KC_DEL),

[_LAYER2] = LAYOUT(KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO, KC_NO, LGUI_T(KC_1), LALT_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5, KC_6, RCTL_T(KC_7), RSFT_T(KC_8), LALT_T(KC_9), RGUI_T(KC_0), KC_NO, KC_NO, KC_NO, RALT_T(KC_DQUO), KC_EQL, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_MINS, RALT_T(KC_NO), KC_NO, KC_NO, KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

[_LAYER3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_Y), KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_Q), KC_NO, LSFT_T(RALT(KC_S)), KC_NO, KC_NO, KC_NO, KC_NO, RSFT_T(RALT(KC_5)), KC_NO, RALT(KC_P), KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_ESC, KC_NO, KC_F11, KC_F12, KC_NO, KC_NO),

[_LAYER4] = LAYOUT(KC_NO, KC_BRIU, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, RGB_TOG, RGB_MOD, RGB_M_P, RGB_M_B, BL_TOGG, KC_NO, KC_NO, KC_BRID, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, BL_UP, BL_STEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, BL_DOWN, BL_BRTG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

[_LAYER5] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PEQL, KC_NO, KC_4, KC_5, KC_6, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_DOT, KC_NO, KC_NO, KC_NO) 

};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
