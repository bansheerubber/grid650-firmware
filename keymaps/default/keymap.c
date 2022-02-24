/* Copyright 2020 grid
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

// #define LED_DEBUG

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

//keymap for test
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         KC_1,       KC_2,       MO(_FN),
//         KC_4,       KC_5,       KC_6, 
//         KC_7,       KC_8,       KC_9,
//         KC_A,       KC_B,       KC_C,
//         OUT_USB,    OUT_BT,       KC_F
//     )
//     // [_FN] = LAYOUT(
//     //     QMKBEST, QMKURL,  _______,
//     //         RESET,    XXXXXXX
//     // )
// };



enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR,
  LED_BLE,
  BLE_PWR_OFF,
  BLE_PWR_ON,
  BLE_DFU,
  BREATHING,
  ON,
  RED,
  BLUE,
  ORANGE
};

enum LED_STAT {
  NONE,
  IGNORE,
  RED_BLINK,
  WHITE_BREATHING,
  WHITE_ON,  
  BLE_ON,
  ORANGE_ON
};

void set_status_led(enum LED_STAT led_stat);
void set_led_real(enum LED_STAT bluetooth_stat, enum LED_STAT user_stat);

// BLE keymap for user
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, KC_GRV, KC_BSPC,    KC_BSPC,
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,KC_BSLS,KC_DEL,    KC_GRV,     
        KC_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,KC_ENT, KC_PGUP,
        KC_LSFT,    KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,KC_UP,  KC_PGDN,
        KC_LCTL,    KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,  KC_NO,  MO(_FN),KC_RALT,KC_RCTL,    KC_LEFT,KC_DOWN,KC_RGHT,
        KC_F1,      KC_F2,  KC_F3,  KC_F4
    ),
    [_FN] = LAYOUT(
        KC_GRV,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12, KC_F13  ,KC_DEL,     KC_DEL,
        BLE_DFU,    KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,_______,OUT_USB,_______,_______,_______,_______,    _______,_______,_______,    KC_PSCR,
        _______,    KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,OUT_AUTO,_______,_______,_______,_______,_______,   _______,_______,KC_HOME,
        _______,    _______,_______,_______,_______,_______,OUT_BT,  _______,_______,_______,_______,_______,   _______,KC_VOLU,KC_END,
        _______,    _______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,   KC_MPRV,KC_VOLD,KC_MNXT,
        _______,    _______,_______,_______        
    )
};

//keymap for test
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         RESET,    BLE_PWR_OFF,   BLE_PWR_ON,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, KC_GRV, KC_BSPC,    KC_BSPC,
//         OUT_USB,    OUT_AUTO,  OUT_BT,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,KC_BSLS,KC_PGUP,    KC_DEL,     
//         KC_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,KC_ENT, KC_PGDN,
//         KC_LSFT,    KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,KC_UP,  KC_PSCR,
//         BLE_DFU,    KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,  KC_NO,  KC_RALT,KC_RCTL,MO(_FN),    KC_LEFT,KC_DOWN,KC_RGHT
//     )
//     // ,
//     // [_FN] = LAYOUT(
//     //     KC_GRV,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12, _______,KC_DEL,     KC_DEL,
//     //     _______,    KC_BTN1,KC_MS_U,KC_BTN2,_______,_______,_______,OUT_USB,BL_TOGG,BL_BRTG, _______,_______, LED_BLE,_______,KC_HOME,    KC_BSPC,
//     //     KC_MS_L,    KC_MS_D,KC_MS_R,_______,_______,_______,OUT_AUTO,_______,_______,_______,_______,_______,   _______,_______,KC_END,
//     //     _______,    _______,_______,_______,_______,_______,OUT_BT,  _______,_______,_______,_______,_______,   _______,KC_VOLU,KC_INS,
//     //     _______,    _______,_______,_______,_______,_______,_______, _______,_______,_______,KC_MPRV,KC_VOLD,   KC_MNXT,_______,_______        
//     // )
// };

//led debug keymap
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         RESET,    BLE_PWR_OFF,   BLE_PWR_ON,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL, KC_GRV, KC_BSPC,    KC_BSPC,
//         OUT_USB,    OUT_AUTO,  OUT_BT,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,KC_BSLS,KC_PGUP,    KC_DEL,     
//         KC_CAPS,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,KC_ENT, KC_PGDN,
//         BREATHING,    ON,RED,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,KC_UP,  KC_PSCR,
//         BLE_DFU,    ORANGE,BLUE,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,  KC_NO,  KC_RALT,KC_RCTL,MO(_FN),    KC_LEFT,KC_DOWN,KC_RGHT
//     )
// };





// uint8_t white_led = 1;
uint8_t orange_led = 1;
uint8_t red_led = 1;
uint8_t ble_led = 1;
bool lalt_home_modifier = false;
bool tab_key = false;
uint8_t alt_tab_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BLE_PWR_OFF:
        if (record->event.pressed) {
            
            //BLE_PWR(PD5) LOW
            PORTD &= ~(1<<5);

            //BLE_OE(PD2) HIGH
            PORTD |= (1<<2);

            //DFU_MCU(PC6) HIGH
            // PORTC |= 1 << 6;   //set high
            
        } else {
            // Do something else when release
        }
            return true;      
        case BLE_PWR_ON:
        if (record->event.pressed) {
            
            //BLE_PWR(PD5) HIGH
            // PORTD &= ~(1<<5);
            PORTD |= (1<<5);

            //BLE_OE(PD2) LOW
            // PORTD |= (1<<2);
            PORTD &= ~(1<<2);

            //DFU_MCU(PC6) HIGH
            // PORTC |= 1 << 6;   //set high
                
        } else {
            // Do something else when release
        }
            return true;         
        case BLE_DFU:
        if (record->event.pressed) {
            //DFU_MCU(PC6) HIGH
            PORTC |= 1 << 6;   //set high
              
        } else {
            // Do something else when release
            //DFU_MCU(PC6) LOW
            PORTC &= ~(1 << 6);   //set high
        }
            return true; 
        // case KC_ENTER:
        //     // Play a tone when enter is pressed
        //     if (record->event.pressed) {
        //         PLAY_NOTE_ARRAY(tone_qwerty);
        //     }
        //     return true; // Let QMK send the enter press/release events

        case KC_LALT: {
            if (record->event.pressed) {
                lalt_home_modifier = true;
            }
            else {
                lalt_home_modifier = false;
            }

            if(alt_tab_state != 0) {
                unregister_code(KC_LALT);
            }

            return false;
        }

        case KC_RIGHT: {
            if (lalt_home_modifier && record->event.pressed) {
                tap_code16(KC_END);
                return false;
            }
            return true;
        }

        case KC_LEFT: {
            if (lalt_home_modifier && record->event.pressed) {
                tap_code16(KC_HOME);
                return false;
            }
            return true;
        }

        case KC_TAB: {
            if (record->event.pressed) {
                tab_key = true;

                if(lalt_home_modifier && (alt_tab_state == 0 || alt_tab_state == 2)) {
                    register_code(KC_LALT);
                    alt_tab_state = 1;
                }
            }
            else {
                tab_key = false;

                if(alt_tab_state == 1) { // go into state 2
                    alt_tab_state = 2;
                }
            }

            return true;
        }

        // alt keybinds that we want to keep
        case KC_0:
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9: {
            if (lalt_home_modifier && record->event.pressed) {
                register_code(KC_LALT);
                tap_code16(keycode);
                unregister_code(KC_LALT);
                return false;
            }
            return true;
        }

        default:
            return true; // Process all other keycodes normally
    }
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
