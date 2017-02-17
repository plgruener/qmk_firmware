#include "ergodox.h"
#include "action_layer.h"
#include "led.h"
#include "keymap_extras/keymap_neo2.h"

#define BASE 0 // default layer, based on Neo2 OS-Layout

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
 * │       │  ü  │  ö  │  ä  │  p  │  z  │     │     │     │  b  │  m  │  ,  │  .  │  j  │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │  ^  │  `  │  ´  │ Mod4│                             │ Mod4│  ´  │  `  │  ^  │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ CTRL│ WIN │ │ WIN │ CTRL│
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ ALT │ │ ALT │     │     │
 *                             │Enter│Shift├─────┤ ├─────┤Shift│Space│
 *                             │>NAVI│     │Mod3 │ │Mod3 │     │>NAVI│
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */

// NEO_ keycodes: OS-Layout is neo2


[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,
        NEO_Y,      NEO_X,      NEO_V,      NEO_L,   NEO_C,   NEO_W,   KC_DELT,
        KC_TAB,     NEO_U,      NEO_I,      NEO_A,   NEO_E,   NEO_O,
        KC_TRNS,    NEO_UE,     NEO_OE,     NEO_AE,  NEO_P,   NEO_Z,   KC_TRNS,
        KC_TRNS,    NEO_CIRC,   NEO_GRV,    NEO_ACUT,NEO_L2_L,
                                                             KC_LCTL,KC_LGUI,
                                                                     KC_LALT,
                                             LT(NAVI,KC_ENT),KC_LSFT,NEO_L1_L,
        // right hand
        KC_F7,       KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_TRNS,
        KC_INS,      NEO_K,     NEO_H,     NEO_G,     NEO_F,     NEO_Q,     NEO_SS,
                     NEO_S,     NEO_N,     NEO_R,     NEO_T,     NEO_D,     NEO_Y,
        KC_TRNS,     NEO_B,     NEO_M,     NEO_COMM,  NEO_DOT,   NEO_J,     KC_TRNS,
                                NEO_L2_R,  NEO_ACUT,  NEO_GRV,   NEO_CIRC,  KC_TRNS,
                     KC_LGUI,  KC_LCTL,
                     KC_LALT,
                     NEO_L1_R,  KC_RSFT, LT(NAVI,KC_SPC)
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
