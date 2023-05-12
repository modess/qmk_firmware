#include QMK_KEYBOARD_H

// Layers
enum ferris_layers {
  _ALPHA,
  _NAV,
  _SYM,
  _NUM,
  _FUNC,
};

// Modifiers
#define KC_SPM1 LT(1, KC_SPC)
#define KC_BSM2 LT(2, KC_BSPC)
#define KC_ESM3 LT(3, KC_ESC)
#define KC_ENM4 LT(4, KC_ENTER)

#define KC_MA LSFT_T(KC_A)
#define KC_MR GUI_T(KC_R)
#define KC_MS LALT_T(KC_S)
#define KC_MT LCTL_T(KC_T)

#define KC_MN LCTL_T(KC_N)
#define KC_ME LALT_T(KC_E)
#define KC_MI GUI_T(KC_I)
#define KC_MO RSFT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
  KC_Q  , KC_W  , KC_F  , KC_P    , KC_B    ,     KC_J    , KC_L    , KC_U   , KC_Y    , KC_SCLN,
  KC_MA , KC_MR , KC_MS , KC_MT   , KC_G    ,     KC_M    , KC_MN   , KC_ME  , KC_MI   , KC_MO  ,
  KC_Z  , KC_X  , KC_C  , KC_D    , KC_V    ,     KC_K    , KC_H    , KC_TAB , KC_LBRC , KC_QUOT,
                          KC_ESM3 , KC_SPM1 ,     KC_BSM2 , KC_ENM4
),

[_NAV] = LAYOUT(
  KC_NO   , KC_MUTE        , KC_VOLD         , KC_VOLU         , KC_NO ,     KC_NO     , KC_HOME         , KC_UP           , KC_END          , KC_INS         ,
  KC_LSFT , GUI_T(KC_MPRV) , LALT_T(KC_MPLY) , LCTL_T(KC_MNXT) , KC_NO ,     KC_NO     , RCTL_T(KC_LEFT) , LALT_T(KC_DOWN) , GUI_T(KC_RIGHT) , RSFT_T(KC_PGUP),
  KC_NO   , KC_NO          , KC_NO           , KC_NO           , KC_NO ,     KC_NO     , CW_TOGG         , KC_CAPS         , KC_NO           , KC_PGDN        ,
                                               KC_NO           , KC_NO ,     KC_DELETE , KC_NO
),

[_SYM] = LAYOUT(
  LSFT(KC_5) , KC_MINS    , KC_NUBS    , LSFT(KC_DOT) , RALT(KC_RBRC) ,     LSFT(KC_NUHS) , LSFT(KC_COMM) , LSFT(KC_NUBS) , LSFT(KC_SLSH) , RALT(KC_2)   ,
  RALT(KC_8) , RALT(KC_7) , LSFT(KC_8) , RALT(KC_4)   , LSFT(KC_EQL)  ,     LSFT(KC_0)    , KC_SLSH       , LSFT(KC_9)    , RALT(KC_0)    , RALT(KC_9)   ,
  LSFT(KC_1) , LSFT(KC_6) , LSFT(KC_7) , KC_NUHS      , RALT(KC_NUBS) ,     KC_NO         , LSFT(KC_2)    , RALT(KC_MINS) , LSFT(KC_3)    , LSFT(KC_MINS),
                                         KC_DOT       , KC_COMM       ,     KC_NO         , KC_NO
),

[_NUM] = LAYOUT(
  KC_NO        , KC_NO       , KC_NO        , KC_NO        , KC_NO  ,     KC_NO   , KC_7  , KC_8 , KC_9 , KC_NO,
  LSFT_T(KC_1) , GUI_T(KC_2) , LALT_T(KC_3) , LCTL_T(KC_4) , KC_NO  ,     KC_NO   , KC_4  , KC_5 , KC_6 , KC_0 ,
  KC_NO        , KC_NO       , KC_NO        , KC_NO        , KC_NO  ,     KC_NO   , KC_1  , KC_2 , KC_3 , KC_NO,
                                              TO(0)        , KC_SPC ,     KC_BSPC , KC_NO
),

[_FUNC] = LAYOUT(
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,     KC_NO , KC_F7 , KC_F8 , KC_F9 , KC_F11 ,
  KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , KC_NO ,     KC_NO  , KC_F4, KC_F5 , KC_F6 , KC_F10,
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,     KC_NO  , KC_F1  , KC_F2 , KC_F3 , KC_F12 ,
                                KC_NO   , KC_NO ,     KC_NO  , KC_NO
)
};

// Combos
const uint16_t PROGMEM reset_combo[] = {KC_J, KC_SCLN, COMBO_END};
const uint16_t PROGMEM num_layer_combo[] = {KC_ESM3, KC_ENM4, COMBO_END};

const uint16_t PROGMEM tab_combo[] = {KC_SPM1, KC_BSM2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(reset_combo, QK_BOOT),
  COMBO(num_layer_combo, TO(3)),
  COMBO(tab_combo, KC_TAB),
};
