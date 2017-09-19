#include "ergodox.h"
#include "action_layer.h"
#include "led.h"
#include "keymap_extras/keymap_neo2.h"

#define BASE 0 // default layer, based on Neo2 OS-Layout
#define QWRZ 2 // German QWERTZ layer (mimic ISO keyboard where possible)
#define NAVI 4 // Cursor keys (left) and num-block (right)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: default
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  ESC  │  F1 │  F2 │  F3 │  F4 │  F5 │  F6 │     │  F7 │  F8 │  F9 │ F10 │ F11 │ F12 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   y   │  x  │  v  │  l  │  c  │  w  │ DEL │     │ INS │  k  │  h  │  g  │  f  │  q  │  ß    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │  TAB  │  u  │  i  │  a  │  e  │  o  ├─────┤     ├─────┤  s  │  n  │  r  │  t  │  d  │  y    │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │  ü  │  ö  │  ä  │  p  │  z  │ F11 │     │ F12 │  b  │  m  │  ,  │  .  │  j  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │  ^  │  `  │  ´  │ Mod4│                             │ Mod4│  ´  │  `  │  ^  │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ CTRL│ WIN │ │ WIN │ CTRL│
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ ALT │ │ ALT │     │     │
 *                             │BCKSP│ TAB ├─────┤ ├─────┤Enter│Space│
 *                             │>NAVI│Shift│Mod3 │ │Mod3 │Shift│>NAVI│
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */

// NEO_ keycodes: OS-Layout is neo2


[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,
        NEO_Y,      NEO_X,      NEO_V,      NEO_L,   NEO_C,   NEO_W,   KC_DELT,
        KC_TAB,     NEO_U,      NEO_I,      NEO_A,   NEO_E,   NEO_O,
        KC_TRNS,    NEO_UE,     NEO_OE,     NEO_AE,  NEO_P,   NEO_Z,   KC_F11,
        KC_TRNS,    NEO_CIRC,   NEO_GRV,    NEO_ACUT,NEO_L2_L,
                                                             KC_LCTL,KC_LGUI,
                                                                     KC_LALT,
                                            LT(NAVI,KC_BSPC),SFT_T(KC_TAB),NEO_L1_L,
        // right hand
        KC_F7,       KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_TRNS,
        KC_INS,      NEO_K,     NEO_H,     NEO_G,     NEO_F,     NEO_Q,     NEO_SS,
                     NEO_S,     NEO_N,     NEO_R,     NEO_T,     NEO_D,     NEO_Y,
        KC_12,       NEO_B,     NEO_M,     NEO_COMM,  NEO_DOT,   NEO_J,     KC_TRNS,
                                NEO_L2_R,  NEO_ACUT,  NEO_GRV,   NEO_CIRC,  KC_TRNS,
                     KC_LGUI,  KC_LCTL,
                     KC_LALT,
                     NEO_L1_R, SFT_T(KC_ENT), LT(NAVI,KC_SPC)
    ),


/* Layer 0: default
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  ESC  │  1  │  2  │  3  │  4  │  5  │     │     │     │  6  │  7  │  8  │  9  │  0  │   ß   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  Tab  │  q  │  w  │  e  │  r  │  t  │     │     │     │  z  │  u  │  i  │  o  │  p  │  ü    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │  Caps │  a  │  s  │  d  │  f  │  g  ├─────┤     ├─────┤  h  │  j  │  k  │  l  │  ö  │  ä    │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ LShift│  y  │  x  │  c  │  v  │  b  │     │     │     │  n  │  m  │  ,  │  .  │  -  │RShift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │LCtrl│     │     │     │     │                             │     │     │     │     │RCtrl│
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */

[QWRZ] = KEYMAP(  // QWERTZ (german standard) characters with QWERTZ keycodes
        // left hand
        KC_ESC,          KC_1,           KC_2,     KC_3,     KC_4,     KC_5,   KC_NO,
        KC_TAB,          DE_Q,           DE_W,     DE_E,     DE_R,     DE_T,   KC_NO,
        KC_CAPS,         DE_A,           DE_S,     DE_D,     DE_F,     DE_G,
        KC_LSFT,         DE_Y,           DE_X,     DE_C,     DE_V,     DE_B,   KC_NO,
        KC_LCTL,         KC_NO,          KC_NO,    KC_NO,    KC_NO,
                                                       KC_NO, KC_NO,
                                                              KC_NO,
                                                KC_NO, KC_NO, KC_NO,
        // right hand
        KC_NO,       KC_6,   KC_7,    KC_8,    KC_9,   KC_0,             DE_SS,
        KC_NO,       DE_Z,   DE_U,    DE_I,    DE_O,   DE_P,             DE_UE,
                     DE_H,   DE_J,    DE_K,    DE_L,   DE_OE,            DE_AE,
        KC_NO,       DE_N,   DE_M,    KC_COMM, KC_DOT, DE_MINS,   KC_RSFT,
                             KC_NO,   KC_NO,   KC_NO,  KC_NO,            KC_RCTL,
        KC_NO, KC_NO,
        KC_NO,
        KC_NO, KC_NO, KC_NO
    ),


/* 
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │bcksp│  up │ del │ pgup│     │     │     │     │  7  │  8  │  9  │     │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │ home│ left│ down│right│ end ├─────┤     ├─────┤     │  4  │  5  │  6  │  ,  │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │ ESC │ menu│space│enter│pgdwn│     │     │     │     │  1  │  2  │  3  │  .  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │  0  │     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
// Navigation Keys + Numpad
[NAVI] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_NO,   KC_BSPC, KC_UP,   KC_DELT, KC_PGUP, KC_TRNS,
       KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
       KC_TRNS, KC_ESC,  KC_APP,  KC_SPC,  KC_ENT,  KC_PGDN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_TRNS,
                 KC_NO,   KC_4,    KC_5,    KC_6,    KC_COMM, KC_TRNS,
       KC_TRNS,  KC_NO,   KC_1,    KC_2,    KC_3,    KC_DOT,  KC_TRNS,
                          KC_0,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
       ),

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
            }
            else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NAVI:
          ergodox_right_led_3_on();
          break;
//        default:
//        break;
    }

};
/*
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     ├─────┤     ├─────┤     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │     │     │     │                             │     │     │     │     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
