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
    [0] = LAYOUT_rgb_martix_vaxis(
                   KC_ENT,
        KC_Q,   KC_R,   KC_U,   KC_P,
        KC_A,                   KC_L
    ),
    [1] = LAYOUT_rgb_martix_vaxis(
                   TO(2),
        RM_VALD,   RM_VALU,   RM_SPDD,   RM_SPDU,
        RM_TOGG,                   RM_NEXT
    ),
    [2] = LAYOUT_rgb_martix_vaxis(
                   TO(0),
        RM_HUED,   RM_HUEU,   RM_SATD,   RM_SATU,
        RM_TOGG,                   RM_NEXT
    )
};

static int axis_val0 = 0;
static int axis_val1 = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            if(axis_val0 == 127){
                axis_val0 = -128;
            }
            else{
                axis_val0++;
            }
        } else {
            if(axis_val0 == -128){
                axis_val0 = 127;
            }
            else{
                axis_val0--;
            }
        }
        joystick_set_axis(0,axis_val0);
    } else if (index == 1) {
        if (clockwise) {
            if(axis_val1 == 127){
                axis_val1 = -128;
            }
            else{
                axis_val1++;
            }
        } else {
            if(axis_val1 == -128){
                axis_val1 = 127;
            }
            else{
                axis_val1--;
            }
        }
        joystick_set_axis(1,axis_val1);
    }
    return false;
};

const uint16_t PROGMEM L1_switch[] = {KC_Q, KC_P, KC_ENT};
combo_t key_combos[] = {
    COMBO(L1_switch, TG(1))
};