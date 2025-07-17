#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *           ┌───────┐
     *           │ START │
     * ┌──────┬──┴───┬───┴──┬──────┐
     * │ BT-A │ BT-B │ BT-C │ BT-D │
     * └──┬───┴──┬───┴───┬──┴───┬──┘
     *    │ FX-L │       │ FX-R │
     *    └──────┘       └──────┘
     */
    [0] = LAYOUT_basic(
                KC_ENT,
        KC_Q,   KC_R,   KC_U,   KC_P,
        KC_A,                   KC_L
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4)}
};
#endif