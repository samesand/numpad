/* Copyright 2018 Yiancar
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

// Tap Dance declarations
enum {
    TD_L_BRCKT,
    TD_R_BRCKT,
    TD_ESC,
    TD_LAYER
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_L_BRCKT] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_9), KC_LBRC),
    [TD_R_BRCKT] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_0), KC_RBRC),
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, LSFT(LWIN(KC_J))),
    [TD_LAYER] = ACTION_TAP_DANCE_DOUBLE(MO(1), TO(1))
};


enum custom_keycodes {
    KC_LT12 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_basic(
    KC_Q,           KC_W,       KC_F,       KC_P,       KC_B,       TD(TD_L_BRCKT),
    KC_A,           KC_R,       KC_S,       KC_T,       KC_G,       KC_LEFT,
    KC_Z,           KC_X,       KC_C,       KC_D,       KC_V,       LALT_T(KC_QUOTE),
                                            KC_LCTL,    KC_SPC,     KC_LSFT,

    TD(TD_R_BRCKT), KC_J,       KC_L,       KC_U,       KC_Y,       KC_ESC,
    KC_RIGHT,       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,
    LGUI_T(KC_EQL), KC_K,       KC_H,       KC_DOT,     KC_COMM,    KC_DOWN,
    KC_BSPC,        KC_ENT,     KC_LT12
    ),

[1] = LAYOUT_basic(
    KC_F1,          KC_F2,        KC_F3,          KC_F4,      KC_F5,          KC_F6,
    KC_0,           KC_1,         KC_2,           KC_3,       KC_4,           LSFT(KC_LBRC),
    KC_Z,           KC_GRV,       LSFT(KC_BSLS),  KC_BSLS,    KC_SCLN,        LSFT(KC_COMM),
                                                  KC_LCTL,    KC_SPC,         KC_LSFT,
    KC_F7,          KC_F8,        KC_F9,          KC_F10,     KC_F11,         KC_F12,
    LSFT(KC_RBRC),  KC_5,         KC_6,           KC_7,       KC_8,           KC_9,
    LSFT(KC_DOT),   LSFT(KC_GRV), LSFT(KC_SLSH),  KC_SLSH,    LSFT(KC_SCLN),  KC_DOWN,
    KC_BSPC,        KC_ENT,       TO(0)
    ),

};

void keyboard_post_init_user(void) {
    rgblight_setrgb_range(0,0,0,0,7);
}


/*RGB LEDS*/
bool led_update_user(led_t led_state) {
    led_state = host_keyboard_led_state();
    if (led_state.num_lock) {  //if caps lock is on
        rgblight_setrgb_range(0,20,20,0,7);
    } else {
        rgblight_setrgb_range(0,0,0,0,7);
    }
    return true;
}


// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
uint16_t lt12_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        break;
        }
    
    case KC_LT12:
        {                                  
        if(record->event.pressed){
            lt12_timer = timer_read();
            layer_on(1);
            } else {
                layer_off(1);
                if (timer_elapsed(lt12_timer) < TAPPING_TERM) {  
                    layer_invert(1);
                    }
            }
        break;
        }

    }
    return true;
};
