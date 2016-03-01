#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_german.h"
#include "keymap_extras/keymap_neo2.h"

#define BASE 0 // default layer, based on Neo2 OS-Layout
#define SHFT 1 // Shift layer
#define DEDE 2
#define PROG 3 // Coding symbols, like (){}<>[]_=-:;'"%+`
#define NAVI 4 // Cursor keys (left) and num-block (right)
//		MDIA   // Keyboard-Mouse + Media-keys (Play,Pause,etc.)
#define LOGR 5 // lowercase greek letters
#define UPGR 6 // uppercase greek letters
#define MATH 7 // mathematical symbols, like ⇔ℝℚ

//#define SYMB 1 // symbols
//#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: lowercase-letters layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   x  |   v  |   l  |   c  |   w  |  Del |           |  Ins |   k  |   h  |   g  |   f  |   q  |    ß   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Bcksp |   u  |   i  |   a  |   e  |   o  |------|           |------|   s  |   n  |   r  |   t  |   d  |    y   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ü  |   ö  |   ä  |   p  |   z  |      |           |      |   b  |   m  |   ,  |   .  |   j  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   ^  |   `  |   ´  | Mod4 |                                       | Mod4 |   ´  |   `  |   ^  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ctrl | Super|       | Super| Ctrl |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |  Alt |       |  Alt |      |      |
 *                                 | Enter| Shift|------|       |------| Shift| Space|
 *                                 |  Nav |      | Mod3 |       | Mod3 |      |  Nav |
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
        KC_ESC,     NEO_1,      NEO_2,      NEO_3,   NEO_4,   NEO_5,   KC_TRNS,
        KC_TAB,     NEO_X,      NEO_V,      NEO_L,   NEO_C,   NEO_W,   KC_DELT,
        KC_BSPC,    NEO_U,      NEO_I,      NEO_A,   NEO_E,   NEO_O,
        KC_TRNS,    NEO_UE,     NEO_OE,     NEO_AE,  NEO_P,   NEO_Z,   KC_TRNS,
        KC_TRNS,    NEO_CIRC,   NEO_GRV,    NEO_ACUT,NEO_L2_L,
                                                             KC_LCTL,KC_LGUI,
                                                                     KC_LALT,
                                             LT(NAVI,KC_ENT),KC_LSFT,NEO_L1_L,
        // right hand
        KC_TRNS,     NEO_6,     NEO_7,     NEO_8,     NEO_9,     NEO_0,     NEO_MINS,
        KC_INS,      NEO_K,     NEO_H,     NEO_G,     NEO_F,     NEO_Q,     NEO_SS,
                     NEO_S,     NEO_N,     NEO_R,     NEO_T,     NEO_D,     NEO_Y,
        KC_TRNS,     NEO_B,     NEO_M,     NEO_COMM,  NEO_DOT,   NEO_J,     KC_TRNS,
                                NEO_L2_R,  NEO_ACUT,  NEO_GRV,   NEO_CIRC,  KC_TRNS,
                     KC_LGUI,  KC_LCTL,
                     KC_LALT,
                     NEO_L1_R,  KC_RSFT, LT(NAVI,KC_SPC)
    ),

/* Keymap 1: uppercase-letters layer (shift-layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   X  |   V  |   L  |   C  |   W  |      |           |      |   K  |   H  |   G  |   F  |   Q  |   S(ß) |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |    Y   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Ü  |   Ö  |   Ä  |   P  |   Z  |      |           |      |   B  |   M  |   ;  |   :  |   J  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
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

// [SHFT] = KEYMAP(  // layer 1 : uppercase letters
//         // left hand
//         KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//         KC_TRNS,       S(NEO_X),     S(NEO_V),    S(NEO_L),    S(NEO_C),    S(NEO_W),    KC_TRNS,
//         KC_TRNS,       S(NEO_U),     S(NEO_I),    S(NEO_A),    S(NEO_E),    S(NEO_O),
//         KC_TRNS,       S(NEO_UE),    S(NEO_OE),   S(NEO_AE),   S(NEO_P),    S(NEO_Z),    KC_TRNS,
//         KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
//                                                             KC_TRNS,    KC_TRNS,
//                                                                         KC_TRNS,
//                                                 KC_TRNS,    KC_TRNS,    KC_TRNS,
//         // right hand
//         KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
//         KC_TRNS,     S(NEO_K),    S(NEO_H),    S(NEO_G),    S(NEO_F),    S(NEO_Q),    S(NEO_SS),
//                      S(NEO_S),    S(NEO_N),    S(NEO_R),    S(NEO_T),    S(NEO_D),    S(NEO_Y),
//         KC_TRNS,     S(NEO_B),    S(NEO_M),    S(NEO_COMM), S(NEO_DOT),  S(NEO_J),    KC_TRNS,
//                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//                      KC_TRNS,  KC_TRNS,
//                      KC_TRNS,
//                      KC_TRNS,  KC_TRNS,  KC_TRNS
//         ),

[DEDE] = KEYMAP(  // Neo letters with Qwertz Keycodes
        // left hand
        KC_ESC,     KC_1,       KC_2,       KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TAB,     DE_X,      DE_V,      DE_L,   DE_C,   DE_W,   KC_DELT,
        KC_BSPC,    DE_U,      DE_I,      DE_A,   DE_E,   DE_O,
        KC_TRNS,    DE_UE,     DE_OE,     DE_AE,  DE_P,   DE_Z,   KC_TRNS,
        KC_ESC,    KC_TRNS,    KC_TRNS,    KC_TRNS,MO(PROG),
                                                            MO(PROG),KC_LGUI,
                                                                     KC_LALT,
                                             LT(NAVI,KC_ENT),KC_LSFT,KC_LCTL,
        // right hand
        KC_TRNS,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
        KC_TRNS,     DE_K,     DE_H,     DE_G,     DE_F,     DE_Q,     DE_SS,
                     DE_S,     DE_N,     DE_R,     DE_T,     DE_D,     DE_Y,
        KC_TRNS,     DE_B,     DE_M,     DE_COMM,  DE_DOT,   DE_J,     KC_TRNS,
                               MO(PROG),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                     KC_LGUI,  MO(PROG),
                     KC_LALT,
                     KC_LCTL,  MO(SHFT), LT(NAVI,KC_SPC)
    ),


/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^    |   1  |   2  |   3  |   4  |   5  | Play |           | Next |   6  |   7  |   8  |   9  |   0  |   ß    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Del   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L2  |   Z  |   U  |   I  |   O  |   P  |   Ü    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |  Ä/L2  |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |-/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | </L1 |#/Ctrl|   ´  |   -  |   +  |                                       | Right| Down |  Up  | Left | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
// [QWRZ] = KEYMAP(  // QWERTZ (german standard) characters with QWERTZ keycodes
//         // left hand
//         KC_CIRC,         KC_1,           KC_2,     KC_3,     KC_4,     KC_5,   KC_MPLY,
//         KC_DELT,         DE_Q,           DE_W,     DE_E,     DE_R,     DE_T,   TG(1),
//         KC_CAPS,         DE_A,           DE_S,     DE_D,     DE_F,     DE_G,
//         KC_LSFT,         DE_Y,           DE_X,     DE_C,     DE_V,     DE_B,   ALL_T(KC_NO),
//         LT(SYMB,DE_LESS),CTL_T(DE_HASH), DE_ACUT,  DE_MINS,  DE_PLUS,
//                                                ALT_T(KC_APP), KC_LGUI,
//                                                               KC_HOME,
//                                                KC_SPC,KC_BSPC,KC_END,
//         // right hand
//         KC_MNXT,     KC_6,   KC_7,    KC_8,    KC_9,   KC_0,             KC_MINS,
//         TG(2),       DE_Z,   DE_U,    DE_I,    DE_O,   DE_P,             DE_UE,
//                      DE_H,   DE_J,    DE_K,    DE_L,   DE_OE,            LT(MDIA,DE_AE),
//         MEH_T(KC_NO),DE_N,   DE_M,    KC_COMM, KC_DOT, CTL_T(DE_MINS),   KC_RSFT,
//                              KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,          KC_FN1,
//         KC_LALT,CTL_T(KC_ESC),
//         KC_PGUP,
//         KC_PGDN,KC_TAB, KC_ENT
//     ),

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
       KC_TRNS, KC_TRNS, KC_TRNS
       ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Bcksp|  Up  |  Del |      |      |           |      |      |   7  |   8  |   9  |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Right|  End |------|           |------|      |   4  |   5  |   6  |   ,  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Esc |      |      | Enter|      |      |           |      |      |   1  |   2  |   3  |   .  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Navigation Keys + Numpad
[NAVI] = KEYMAP(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BSPC, KC_UP,   KC_DELT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
       KC_TRNS, KC_ESC,  KC_TRNS, KC_TRNS, KC_ENT,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS,  KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_F12,
                 KC_TRNS, KC_4,    KC_5,    KC_6,    KC_COMM, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_TRNS,
                          KC_0,    KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
       ),

//[MATH] = KEYMAP(

//),

};

const uint16_t PROGMEM fn_actions[] = {
//     [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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
		case SHFT:
			ergodox_right_led_1_on();
			break;
        case NAVI:
            ergodox_right_led_3_on();
            break;
        case PROG:
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
