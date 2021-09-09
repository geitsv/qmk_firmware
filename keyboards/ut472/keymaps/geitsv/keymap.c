#include QMK_KEYBOARD_H

/* Custom Designed Mod Keycodes (swap in code depending on OS in use)
 
 ROCKET == SEND_STRING("=>")
 
 UNDO_Mac == SEND_STRING(SS_RGUI(z))
 CUT_Mac == SEND_STRING(SS_RGUI(x))
 COPY_Mac == SEND_STRING(SS_RGUI(c))
 PASTE_Mac == SEND_STRING(SS_RGUI(v))

 UNDO_Linux == SEND_STRING(SS_RCTL(z))
 CUT_Linux == SEND_STRING(SS_RCTL(x))
 COPY_Linux == SEND_STRING(SS_RCTL(c))
 PASTE_Linux == SEND_STRING(SS_RCTL(v))
 */

enum custom_keycodes {
    ROCKET = SAFE_RANGE,
	UNDO_Mac,
	CUT_Mac,
	COPY_Mac,
	PASTE_Mac,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ROCKET:
        if (record->event.pressed) {
            // when keycode ROCKET is pressed
            SEND_STRING("=>");
        } else {
            // when keycode ROCKET is released
        }
        break;

    case UNDO_Mac:
        if (record->event.pressed) {
            // when keycode UNDO_Mac is pressed
            SEND_STRING(SS_RGUI(z));
        } else {
            // when keycode UNDO_Mac is released
        }
        break;

    case CUT_Mac:
        if (record->event.pressed) {
            SEND_STRING(SS_RGUI(x));
        } else {
        }
        break;

    case COPY_Mac:
        if (record->event.pressed) {
            SEND_STRING(SS_RGUI(c));
        } else {
        }
        break;

    case PASTE_Mac:
        if (record->event.pressed) {
            SEND_STRING(SS_RGUI(v));
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), OSM(MOD_LCTL), TT(3), OSM(MOD_LALT), OSM(MOD_LGUI), MO(1), KC_SPC, MO(2), OSM(MOD_RGUI), OSM(MOD_RALT), KC_CAPSLOCK, OSM(MOD_RCTL)),
	[1] = LAYOUT(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_7, KC_8, KC_9, KC_BSLS, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_LBRC, KC_RBRC, KC_4, KC_5, KC_6, KC_QUOT, KC_TRNS, KC_TRNS, KC_PERC, KC_CIRC, KC_UNDS, KC_PEQL, KC_AMPR, KC_0, KC_1, KC_2, KC_3, ROCKET, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_ESC, KC_F9, KC_F10, KC_F11, KC_F12, KC_PGUP, KC_PSCR, KC_NO, KC_UP, KC_NO, KC_HOME, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_PGDN, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, UNDO_Mac, CUT_Mac, COPY_Mac, KC_NO, PASTE_Mac, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_ESC, KC_NO, KC_NO, RGB_HUD, RGB_HUI, RGB_MOD, KC_MSTP, KC_MRWD, KC_MFFD, KC_NO, KC_NO, KC_PWR, KC_TRNS, RGB_SPD, RGB_SPI, RGB_VAD, RGB_VAI, RGB_TOG, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, RGB_RMOD, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP)
};
