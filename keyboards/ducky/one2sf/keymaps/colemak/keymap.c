#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_all(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, KC_END, KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
	[1] = LAYOUT_all(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_NO, KC_INS, KC_TRNS, KC_UP, KC_PAUS, KC_PGUP, KC_HOME, KC_PSCR, KC_TRNS, KC_PGUP, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_NO, KC_SCRL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_TRNS, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_WREF, KC_TRNS, RGB_TOG, RGB_MOD, KC_TRNS, TG(2), KC_TRNS, KC_RPRN, KC_MPRV, KC_TRNS, KC_MNXT),
	[2] = LAYOUT_all(QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_INT1, KC_INT3, KC_BSPC, KC_DEL, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Z, KC_SCLN, KC_LBRC, KC_RBRC, KC_EQL, KC_HOME, KC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_NUHS, KC_ENT, KC_END, KC_LSFT, KC_Y, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_NUBS, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_TRNS, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


rgb_config_t user_config;

void keyboard_post_init_user(void) {
  // Call the keymap level matrix init.

  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();

  // Set default layer, if enabled
  if (user_config.enable) {
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_CYAN);
    rgb_matrix_mode_noeeprom(1);
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.enable = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
  rgb_matrix_enable(); // Enable RGB by default
 // Enable RGB by default
  rgb_matrix_sethsv(HSV_CYAN);  // Set it to CYAN by default
  rgb_matrix_mode(1); // set to solid by default
}

layer_state_t layer_state_set_user(layer_state_t state) {

  switch(biton32(state)) {
  case 0:
    // Blue
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    break;
  case 1:
    // Red
    rgb_matrix_enable_noeeprom();	
    rgb_matrix_sethsv_noeeprom(HSV_RED);
    break;
  case 2:
    // Blue
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
    break;
  default:
    // White
    //Read RGB Light State
    user_config.raw = eeconfig_read_user();
    //If enabled, set white
    if (user_config.enable) {
		rgb_matrix_sethsv_noeeprom(HSV_WHITE);
	} else { //Otherwise go back to disabled
		rgb_matrix_disable_noeeprom();
	}
    break;
}
return state;
}



