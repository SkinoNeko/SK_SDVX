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
    [0] = LAYOUT_rgb_martix(
                KC_ENT,
        KC_Q,   KC_R,   KC_U,   KC_P,
        KC_A,                   KC_L
    ),
    [1] = LAYOUT_rgb_martix(
                   TG(1),
        RM_VALD,   RM_VALU,   RM_SPDD,   RM_SPDU,
        RM_TOGG,                   RM_NEXT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4)},
    [1] = { ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)}
};
#endif

const uint16_t PROGMEM L1_switch[] = {KC_Q, KC_P, KC_ENT};
combo_t key_combos[] = {
    COMBO(L1_switch, TG(1))
};