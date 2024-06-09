#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define KC_SPM1 LT(1, KC_SPC)
#define KC_BSM2 LT(2, KC_BSPC)
#define KC_ESM3 LT(3, KC_TAB)
#define KC_ENM4 LT(4, KC_ESC)

#define KC_MA LSFT_T(KC_A)
#define KC_MR GUI_T(KC_R)
#define KC_MS LALT_T(KC_S)
#define KC_MT LCTL_T(KC_T)

#define KC_MN LCTL_T(KC_N)
#define KC_ME LALT_T(KC_E)
#define KC_MI GUI_T(KC_I)
#define KC_MO RSFT_T(KC_O)

// Combos
const uint16_t PROGMEM reset_right_combo[] = {KC_J, KC_SCLN, COMBO_END};
const uint16_t PROGMEM reset_left_combo[] = {KC_B, KC_Z, COMBO_END};
const uint16_t PROGMEM num_layer_combo[] = {KC_ESM3, KC_Q, COMBO_END};

combo_t key_combos[] = {
  COMBO(reset_right_combo, QK_BOOT), // J + Ö = reset (right)
  COMBO(reset_left_combo, QK_BOOT),  // B + Z = reset (left)
  COMBO(num_layer_combo, TO(3)),     // Tab + Q = num layer
};

// Tap dance
enum {
    TD_PC,
    TD_ST,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(SE_PERC, SE_CIRC), // % | ^
    [TD_ST] = ACTION_TAP_DANCE_DOUBLE(SE_ASTR, SE_TILD), // * | ~
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Alpha
    |----+----+----+-----+-----|      |-----+-----+----+----+----|
    | Q  | W  | F  | P   | B   |      | J   | L   | U  | Y  |    |
    | A  | R  | S  | T   | G   |      | M   | N   | E  | I  | O  |
    | Z  | X  | C  | D   | V   |      | K   | H   | Å  | Ä  | Ö  |
    |----+----+----| Tab | Spc |      | Bsp | Esc |----+----+----+
                   |-----+-----|      |-----+-----|
    */
    [0] = LAYOUT_split_3x5_2(
        KC_Q  , KC_W        , KC_F        , KC_P    , KC_B        , KC_J    , KC_L    , KC_U    , KC_Y    , KC_NO  ,
        KC_MA , KC_MR       , KC_MS       , KC_MT   , KC_G        , KC_M    , KC_MN   , KC_ME   , KC_MI   , KC_MO  ,
        KC_Z  , LT(0,KC_X)  , LT(0,KC_C)  , KC_D    , LT(0,KC_V)  , KC_K    , KC_H    , KC_LBRC , KC_QUOT     , KC_SCLN,
                                KC_ESM3 , KC_SPM1 ,     KC_BSM2 , KC_ENM4
    ),

    /* Nav
    |----+----+----+-----+-----|      |-----+-----+----+----+----|
    |    | 🔇 | 🔈 | 🔊  |     |      | ⏫  | ↩️   |    | ↪️  |    |
    |    | ⏮️  | ⏯️  | ⏭️   |     |      |     | H   | J  | K  | L  |
    |    |    |    |     |     |      | ⏬  | ⬅️   | ⬇️  | ⬆️  | ➡️  |
    |----+----+----|     |     |      | Ent | Del |----+----+----+
                   |-----+-----|      |-----+-----|
    */
    [1] = LAYOUT_split_3x5_2(
        KC_NO   , KC_MUTE        , KC_VOLD         , KC_VOLU         , KC_NO ,     KC_PGUP     , KC_HOME         , KC_NO           , KC_END          , KC_NO         ,
        KC_LSFT , GUI_T(KC_MPRV) , LALT_T(KC_MPLY) , LCTL_T(KC_MNXT) , KC_NO ,     KC_NO     , KC_H , KC_J , KC_K , KC_L,
        KC_NO   , KC_NO          , KC_NO           , KC_NO           , KC_NO ,     KC_PGDN     , KC_LEFT         , KC_DOWN         , KC_UP           , KC_RIGHT        ,
                                                     KC_NO           , KC_NO ,     KC_ENTER  , KC_DELETE
    ),

    /* Sym
    |----+----+----+-----+-----|      |-----+-----+----+----+----|
    | ü  | +  | <  | :   | %\^ |      | *\~ | ;   | >  | _  | #  |
    | [  | {  | (  | $   | `   |      | =   | -   | )  | }  | ]  |
    | !  | &  | /  | '   | |   |      | '   | "   | \  | @  | ?  |
    |----+----+----| ,   | .   |      |     |     |----+----+----+
                   |-----+-----|      |-----+-----|
    */
    [2] = LAYOUT_split_3x5_2(
        KC_RBRC   , KC_MINS    , KC_NUBS    , LSFT(KC_DOT) , TD(TD_PC) ,     TD(TD_ST)  , LSFT(KC_COMM) , LSFT(KC_NUBS) , LSFT(KC_SLSH) , LSFT(KC_3)   ,
        RALT(KC_8), RALT(KC_7) , LSFT(KC_8) , RALT(KC_4)   , LSFT(KC_EQL)  ,     LSFT(KC_0)    , KC_SLSH       , LSFT(KC_9)    , RALT(KC_0)    , RALT(KC_9)   ,
        LSFT(KC_1) , LSFT(KC_6) , LSFT(KC_7) , KC_NUHS      , RALT(KC_NUBS) ,     KC_EQL        , LSFT(KC_2)    , RALT(KC_MINS) , RALT(KC_2)    , LSFT(KC_MINS),
                                               KC_COMM      , KC_DOT        ,     KC_NO         , KC_NO
    ),

    /* Num/anki
    |----+----+----+-----+-----|      |-----+-----+----+----+----|
    |    |    |    |     |     |      |     | 7   | 8  | 9  |    |
    | 1  | 2  | 3  | 4   |     |      |     | 4   | 5  | 6  | 0  |
    |    |    |    |     |     |      |     | 1   | 2  | 3  |    |
    |----+----+----| L0  |     |      |     |     |----+----+----+
                   |-----+-----|      |-----+-----|
    */
    [3] = LAYOUT_split_3x5_2(
        KC_NO        , KC_NO       , KC_NO        , KC_NO        , KC_NO  ,     KC_NO   , KC_7  , KC_8 , KC_9 , KC_NO,
        LSFT_T(KC_1) , GUI_T(KC_2) , LALT_T(KC_3) , LCTL_T(KC_4) , KC_NO  ,     KC_NO   , KC_4  , KC_5 , KC_6 , KC_0 ,
        KC_NO        , KC_NO       , KC_NO        , KC_NO        , KC_NO  ,     KC_NO   , KC_1  , KC_2 , KC_3 , KC_NO,
                                                    TO(0)        , KC_SPC ,     KC_BSPC , KC_NO
    ),

    /* Func
    |----+----+----+-----+-----|      |-----+-----+----+----+-----|
    |    |    |    |     |     |      |     | F7  | F8 | F9 | F11 |
    |    |    |    |     |     |      |     | F4  | F5 | F6 | F10 |
    |    |    |    |     |     |      |     | F1  | F2 | F3 | F12 |
    |----+----+----|     |     |      |     |     |----+----+-----+
                   |-----+-----|      |-----+-----|
    */
    [4] = LAYOUT_split_3x5_2(
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,     KC_NO  , KC_F7 , KC_F8 , KC_F9 , KC_F11 ,
        KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , KC_NO ,     KC_NO  , KC_F4 , KC_F5 , KC_F6 , KC_F10,
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,     KC_NO  , KC_F1 , KC_F2 , KC_F3 , KC_F12 ,
                                      KC_NO   , KC_NO ,     KC_NO  , KC_NO
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

