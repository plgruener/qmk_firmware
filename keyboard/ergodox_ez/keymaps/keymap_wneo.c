#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SHFT 1 // Shift layer
#define PROG 2 // Coding symbols, like (){}<>[]_=-:;'"%+`
#define NAVI 3 // Cursor keys (left) and num-block (right)
#define LOGR 4 // lowercase greek letters
#define UPGR 5 // uppercase greek letters
#define MATH 6 // mathematical symbols, like ⇔ℝℚ

//#define SYMB 1 // symbols
//#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: lowercase-letters layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   x  |   v  |   l  |   c  |   w  |  Del |           | Bcksp|   k  |   h  |   g  |   f  |   q  |    ß   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Esc  |   u  |   i  |   a  |   e  |   o  |------|           |------|   s  |   n  |   r  |   t  |   d  |    y   |
 * |--------+------+------+------+------+------| Comp |           | Enter|------+------+------+------+------+--------|
 * |  Space |   ü  |   ö  |   ä  |   p  |   z  |      |           |      |   b  |   m  |   ,  |   .  |   j  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | greek|      |      |      |                                       |      |      |      | greek|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prog | Super|       | Super| Prog |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |  Alt |       |  Alt |      |      |
 *                                 | Enter| Shift|------|       |------| Shift| Space|
 *                                 |  Nav |      | Ctrl |       | Ctrl |      |  Nav |
 *                                 `--------------------'       `--------------------'
 *  Super=Gui (Win/Linux) or Cmd (Mac) ?
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

// Use DE_ keycodes: assume the OS- base layout is german

//TODO thumb-key modifier
//TODO top-row keys

[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_TRNS,       KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TAB,        DE_X,         DE_V,   DE_L,   DE_R,   DE_W,   KC_TRNS,
        KC_ESC,        DE_U,         DE_I,   DE_A,   DE_E,   DE_O,
        KC_SPC,        DE_UE,        DE_OE,  DE_AE,  DE_P,   DE_Z,   KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,
                                                             KC_TRNS,KC_TRNS,
                                                                     KC_TRNS,
                                                     KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,     DE_K,     DE_H,     DE_G,     DE_F,     DE_Q,     DE_SS,
                     DE_S,     DE_N,     DE_R,     DE_T,     DE_D,     DE_Y,
        KC_TRNS,     DE_B,     DE_M,     DE_COMM,  DE_DOT,   DE_J,     KC_TRNS,
                               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                     KC_TRNS,  KC_TRNS,
                     KC_TRNS,
                     KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

/* Keymap 1: uppercase-letters layer (shift-layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   X  |   V  |   L  |   C  |   W  |  Del |           | Bcksp|   K  |   H  |   G  |   F  |   Q  |   S(ß) |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Esc  |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |    Y   |
 * |--------+------+------+------+------+------| Comp |           | Enter|------+------+------+------+------+--------|
 * |  Space |   Ü  |   Ö  |   Ä  |   P  |   Z  |      |           |      |   B  |   M  |   ;  |   :  |   J  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |Sgreek|      |      |      |                                       |      |      |      |Sgreek|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Prog | Super|       | Super| Prog |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |  Alt |       |  Alt |      |      |
 *                                 | Enter| Shift|------|       |------| Shift| Space|
 *                                 |  Nav |      | Ctrl |       | Ctrl |      |  Nav |
 *                                 `--------------------'       `--------------------'
 *  Super=Gui (Win/Linux) or Cmd (Mac) ?
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*


[SHFT] = KEYMAP(  // layer 1 : uppercase letters
        // left hand
        KC_TRNS,       KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TAB,        S(DE_X),     S(DE_V),    S(DE_L),    S(DE_R),    S(DE_W),    KC_TRNS,
        KC_ESC,        S(DE_U),     S(DE_I),    S(DE_A),    S(DE_E),    S(DE_O),
        KC_SPC,        S(DE_UE),    S(DE_OE),   S(DE_AE),   S(DE_P),    S(DE_Z),    KC_TRNS,
        KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                            KC_TRNS,    KC_TRNS,
                                                                        KC_TRNS,
                                                KC_TRNS,    KC_TRNS,    KC_TRNS,
        // right hand
        KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,     S(DE_K),     S(DE_H),     S(DE_G),     S(DE_F),     S(DE_Q),     S(DE_SS),
                     S(DE_S),     S(DE_N),     S(DE_R),     S(DE_T),     S(DE_D),     S(DE_Y),
        KC_TRNS,     S(DE_B),     S(DE_M),     S(DE_COMM),  S(DE_DOT),   S(DE_J),     KC_TRNS,
                               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                     KC_TRNS,  KC_TRNS,
                     KC_TRNS,
                     KC_TRNS,  KC_TRNS,  KC_TRNS
        ),

/* Keymap 2: Programming Symbols Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   …  |   _  |   [  |   ]  |   ^  |      |           |      |   !  |   <  |   >  |   =  |   &  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   \  |   /  |   {  |   }  |   *  |------|           |------|   ?  |   (  |   )  |   -  |   :  |    @   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   |  |   ~  |   `  |      |           |      |   +  |   %  |   "  |   '  |   ;  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

// PROGRAMMING SYMBOLS
[PROG] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC,KC_TRNS,//TODO DE_CIRC == ^ ?! //TODO Ellipsis …
       KC_TRNS,DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,
       KC_TRNS,DE_HASH,DE_DLR, DE_PIPE,DE_TILD,DE_GRV,KC_TRNS,//TODO DE_GRV == ~ ?!
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, DE_EXLM,DE_LESS,DE_MORE,DE_EQL, DE_AMPR,KC_F12,	//DONE
                DE_QST, DE_LPRN,DE_RPRN,DE_MINS,DE_COLN,DE_AT,	//DONE
       KC_TRNS, DE_PLUS,DE_PERC,DE_DQOT,DE_QUOT,DE_SCLN,KC_TRNS,//DONE
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,//?
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNSaaaaaaa
       ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NAVI] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
       ),

[MATH] = KEYMAP(

),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
/* Keymap empty (template for copying)
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