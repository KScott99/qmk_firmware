/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_right_ball(
    KC_Q     , KC_W     , KC_F     , KC_P     , KC_B     ,                            KC_J     , KC_L     , KC_U     , KC_Y     , KC_QUOTE ,
    KC_A     , KC_R     , KC_S     , KC_T     , KC_G     ,                            KC_M     , KC_N     , KC_E     , KC_I     , KC_O     ,
    KC_Z     , KC_X     , KC_C     , KC_D     , KC_V     ,                            KC_K     , KC_H     , KC_COMM  , KC_DOT   , OSM(MOD_LSFT),
    XXXXXXX , XXXXXXX, XXXXXXX,       XXXXXXX, LT(2,KC_SPC), KC_ENT,        LT(4,KC_BSPC), OSL(3),                           MO(1)
  ),

  [1] = LAYOUT_right_ball(
    CPI_D100 , SCRL_DVI , SCRL_DVD , CPI_I100 , KBC_RST  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    KC_LSFT  , SCRL_MO  , MS_BTN2  , MS_BTN1  , MS_BTN3  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_MNXT  ,
    KBC_SAVE , AML_D50  , AML_TO   , AML_I50  , XXXXXXX  ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  ,    XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX,                                XXXXXXX
  ),

  [2] = LAYOUT_right_ball(
    KC_F1   , KC_F2     , KC_F3     , KC_F4   , KC_F5    ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_LGUI , KC_LALT   , KC_LSFT   , KC_LCTL , KC_MUTE  ,                            KC_DEL   , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  ,
    KC_F11  , KC_F12    , KC_VOLD   , KC_VOLU , KC_BRID  ,                            KC_BRIU  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  ,    XXXXXXX, XXXXXXX, XXXXXXX,                 KC_BSPC, KC_ESC,                                 XXXXXXX
  ),

  [3] = LAYOUT_right_ball(
    KC_LBRC , KC_7      , KC_8      , KC_9    , KC_RBRC  ,                            KC_QUESTION , KC_UNDS , OSM(MOD_LALT), XXXXXXX, KC_DQUO,
    KC_SCLN , KC_4      , KC_5      , KC_6    , KC_EQL   ,                            KC_TAB   , TO(1)    , OSM(MOD_LCTL),OSM(MOD_LSFT),OSM(MOD_LGUI),
    KC_GRV  , KC_1      , KC_2      , KC_3    , KC_BSLS  ,                            KC_SLASH  , KC_MINS , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    XXXXXXX , XXXXXXX   , XXXXXXX   ,    XXXXXXX, KC_SPC, KC_0,                   CW_TOGG, KC_ESC,                                 XXXXXXX
  ),

  [4] = LAYOUT_right_ball(
    KC_EXLM  , KC_LABK , KC_RABK , KC_MINUS   , KC_PIPE,                              KC_QUESTION , KC_HASH, KC_RPRN, KC_LPRN , KC_ASTERISK,
    KC_LPRN  , KC_RPRN , KC_COLON, KC_EQUAL   , KC_AMPR,                              KC_BACKSLASH, KC_CIRC, KC_RCBR, KC_LCBR , KC_DLR,
    KC_TILDE , KC_SLASH, KC_PLUS , KC_ASTERISK, KC_PERC,                              KC_SLASH    , KC_LABK, KC_PIPE, KC_MINUS,  KC_RABK,
    XXXXXXX , XXXXXXX   , XXXXXXX ,     XXXXXXX, KC_SPC, KC_BSPC,                  XXXXXXX, XXXXXXX,                                 XXXXXXX
  ),
};
// clang-format on

/* layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
} */

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
