#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_LCBR_RCBR = SAFE_RANGE, // { / }
    KC_LBRC_RBRC,              // [ / ]
    KC_LPRN_RPRN,              // ( / )
    KC_LT_GT,                  // < / >
    KC_QUOT_DQUO,              // ' / "
    KC_BSLS_PIPE,              // \ / |
    KC_COMM_SCLN,              // , / ;
    KC_DOT_COLN,               // . / :
    KC_SLSH_QUES               // / / ?
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t timer;

    switch (keycode) {
        case KC_LCBR_RCBR:
            if (record->event.pressed) timer = timer_read();
            else tap_code16(timer_elapsed(timer) < TAPPING_TERM ? S(KC_LBRC) : S(KC_RBRC));
            return false;

        case KC_LBRC_RBRC:
            if (record->event.pressed) timer = timer_read();
            else tap_code(timer_elapsed(timer) < TAPPING_TERM ? KC_LBRC : KC_RBRC);
            return false;

        case KC_LPRN_RPRN:
            if (record->event.pressed) timer = timer_read();
            else tap_code16(timer_elapsed(timer) < TAPPING_TERM ? S(KC_9) : S(KC_0));
            return false;

        case KC_LT_GT:
            if (record->event.pressed) timer = timer_read();
            else tap_code16(timer_elapsed(timer) < TAPPING_TERM ? S(KC_COMMA) : S(KC_DOT));
            return false;

        case KC_QUOT_DQUO:
            if (record->event.pressed) timer = timer_read();
            else tap_code16(timer_elapsed(timer) < TAPPING_TERM ? KC_QUOT : S(KC_QUOT));
            return false;

        case KC_BSLS_PIPE:
            if (record->event.pressed) timer = timer_read();
            else tap_code16(timer_elapsed(timer) < TAPPING_TERM ? KC_BSLS : S(KC_BSLS));
            return false;

        case KC_COMM_SCLN:
            if (record->event.pressed) timer = timer_read();
            else tap_code(timer_elapsed(timer) < TAPPING_TERM ? KC_COMM : KC_SCLN);
            return false;

        case KC_DOT_COLN:
            if (record->event.pressed) timer = timer_read();
            else tap_code(timer_elapsed(timer) < TAPPING_TERM ? KC_DOT : S(KC_SCLN));
            return false;

        case KC_SLSH_QUES:
            if (record->event.pressed) timer = timer_read();
            else tap_code16(timer_elapsed(timer) < TAPPING_TERM ? KC_SLSH : S(KC_SLSH));
            return false;
    }
    return true;
}

// Puedes ajustar esto si quieres otro valor para TAPPING_TERM
// #define TAPPING_TERM 175 en tu config.h

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_H, KC_J, KC_K, KC_L, KC_SCLN, LCTL_T(KC_ENT),
        TO(2), KC_RBRC, KC_N, KC_M, KC_COMM_SCLN, KC_DOT_COLN, KC_SLSH_QUES, KC_RSFT,
        TO(1), KC_SPC, KC_RALT, KC_RGUI, KC_APP
    ),

   // Layer 1 - Símbolos optimizado
    [1] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
        KC_LPRN_RPRN, KC_LBRC_RBRC,KC_LCBR_RCBR ,KC_DEL  ,KC_MINS , KC_EQL,
        TO(0),   KC_PLUS, KC_UNDS, KC_ASTR, KC_TILD, KC_CIRC, KC_BSLS_PIPE, KC_QUES,
        TO(0),   KC_DOT,  KC_COMM, KC_COLN, KC_SCLN
    ),
    

    [2] = LAYOUT(
        KC_PGUP, KC_HOME, KC_UP, KC_END, KC_VOLU, KC_MUTE,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_BSPC,
        TO(0), KC_TRNS, KC_PAUS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, QK_BOOT,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [3] = LAYOUT(
        KC_MPRV, KC_MSTP, KC_MPLY, KC_VOLU, KC_VOLD, KC_MUTE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
