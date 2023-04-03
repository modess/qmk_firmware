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
#define KC_SPM3 LT(3, KC_SPC)
#define KC_BSM4 LT(4, KC_BSPC)

#define KC_MA LSFT_T(KC_A)
#define KC_MR GUI_T(KC_R)
#define KC_MS LALT_T(KC_S)
#define KC_MT LCTL_T(KC_T)

#define KC_MN LCTL_T(KC_N)
#define KC_ME LALT_T(KC_E)
#define KC_MI GUI_T(KC_I)
#define KC_MO RSFT_T(KC_O)

// Macros
enum custom_keycodes {
    TILDE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TILDE:
        if (record->event.pressed) {
            SEND_STRING("]");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
//    ┌────┬────┬────┬────────┬──────┐   ┌──────┬────────┬────┬─────┬─────┐
//    │ q  │ w  │ f  │   p    │  b   │   │  j   │   l    │ u  │  y  │ del │
//    ├────┼────┼────┼────────┼──────┤   ├──────┼────────┼────┼─────┼─────┤
//    │ mA │ mR │ mS │   mT   │  g   │   │  m   │   mN   │ mE │ mI  │ mO  │
//    ├────┼────┼────┼────────┼──────┤   ├──────┼────────┼────┼─────┼─────┤
//    │ z  │ x  │ c  │   d    │  v   │   │  k   │   h    │ [  │ "'" │  ;  │
//    └────┴────┴────┼────────┼──────┤   ├──────┼────────┼────┴─────┴─────┘
//                   │ OSL(1) │ sPM3 │   │ bSM4 │ OSL(2) │                 
//                   └────────┴──────┘   └──────┴────────┘                 
  KC_Q  , KC_W  , KC_F  , KC_P   , KC_B    ,     KC_J    , KC_L   , KC_U    , KC_Y    , KC_DELETE,
  KC_MA , KC_MR , KC_MS , KC_MT  , KC_G    ,     KC_M    , KC_MN  , KC_ME   , KC_MI   , KC_MO    ,
  KC_Z  , KC_X  , KC_C  , KC_D   , KC_V    ,     KC_K    , KC_H   , KC_LBRC , KC_QUOT , KC_SCLN  ,
                          OSL(1) , KC_SPM3 ,     KC_BSM4 , OSL(2)                                
),

[_NAV] = LAYOUT(
//    ┌──────┬─────────────┬──────────────┬──────────────┬────┐   ┌────┬──────────────┬──────────────┬─────────────┬──────────────┐
//    │  no  │    mute     │     vold     │     volu     │ no │   │ no │     home     │      up      │     end     │     ins      │
//    ├──────┼─────────────┼──────────────┼──────────────┼────┤   ├────┼──────────────┼──────────────┼─────────────┼──────────────┤
//    │ lsft │ GUI_T(mprv) │ LALT_T(mply) │ LCTL_T(mnxt) │ no │   │ no │ RCTL_T(left) │ LALT_T(down) │ GUI_T(rght) │ RSFT_T(pgup) │
//    ├──────┼─────────────┼──────────────┼──────────────┼────┤   ├────┼──────────────┼──────────────┼─────────────┼──────────────┤
//    │  no  │     no      │     caps     │   CW_TOGG    │ no │   │ no │     ent      │     esc      │     tab     │     pgdn     │
//    └──────┴─────────────┴──────────────┼──────────────┼────┤   ├────┼──────────────┼──────────────┴─────────────┴──────────────┘
//                                        │      no      │ no │   │ no │      no      │                                            
//                                        └──────────────┴────┘   └────┴──────────────┘                                            
  KC_NO   , KC_MUTE        , KC_VOLD         , KC_VOLU         , KC_NO ,     KC_NO , KC_HOME         , KC_UP           , KC_END          , KC_INS         ,
  KC_LSFT , GUI_T(KC_MPRV) , LALT_T(KC_MPLY) , LCTL_T(KC_MNXT) , KC_NO ,     KC_NO , RCTL_T(KC_LEFT) , LALT_T(KC_DOWN) , GUI_T(KC_RIGHT) , RSFT_T(KC_PGUP),
  KC_NO   , KC_NO          , KC_CAPS         , CW_TOGG         , KC_NO ,     KC_NO , KC_ENTER        , KC_ESC          , KC_TAB          , KC_PGDN        ,
                                               KC_NO           , KC_NO ,     KC_NO , KC_NO                                                                
),

[_SYM] = LAYOUT(
//    ┌─────────┬─────────┬─────────┬─────────┬────────────┐   ┌─────────────┬─────────┬────────────┬─────────┬─────────┐
//    │ LSFT(5) │    -    │  iso\   │ LSFT(.) │  RALT(])   │   │ LSFT(iso--) │ LSFT(,) │ LSFT(iso\) │ LSFT(/) │ RALT(2) │
//    ├─────────┼─────────┼─────────┼─────────┼────────────┤   ├─────────────┼─────────┼────────────┼─────────┼─────────┤
//    │ RALT(8) │ RALT(7) │ LSFT(8) │ RALT(4) │  LSFT(=)   │   │   LSFT(0)   │    /    │  LSFT(9)   │ RALT(0) │ RALT(9) │
//    ├─────────┼─────────┼─────────┼─────────┼────────────┤   ├─────────────┼─────────┼────────────┼─────────┼─────────┤
//    │ LSFT(1) │ LSFT(6) │ LSFT(7) │  iso--  │ RALT(iso\) │   │     no      │ LSFT(2) │  RALT(-)   │ LSFT(3) │ LSFT(-) │
//    └─────────┴─────────┴─────────┼─────────┼────────────┤   ├─────────────┼─────────┼────────────┴─────────┴─────────┘
//                                  │    .    │     ,      │   │     no      │   no    │                                 
//                                  └─────────┴────────────┘   └─────────────┴─────────┘                                 
  LSFT(KC_5) , KC_MINS    , KC_NUBS    , LSFT(KC_DOT) , RALT(KC_RBRC) ,     LSFT(KC_NUHS) , LSFT(KC_COMM) , LSFT(KC_NUBS) , LSFT(KC_SLSH) , RALT(KC_2)   ,
  RALT(KC_8) , RALT(KC_7) , LSFT(KC_8) , RALT(KC_4)   , LSFT(KC_EQL)  ,     LSFT(KC_0)    , KC_SLSH       , LSFT(KC_9)    , RALT(KC_0)    , RALT(KC_9)   ,
  LSFT(KC_1) , LSFT(KC_6) , LSFT(KC_7) , KC_NUHS      , RALT(KC_NUBS) ,     KC_NO         , LSFT(KC_2)    , RALT(KC_MINS) , LSFT(KC_3)    , LSFT(KC_MINS),
                                         KC_DOT       , KC_COMM       ,     KC_NO         , KC_NO                                                        
),

[_NUM] = LAYOUT(
//    ┌───────────┬──────────┬───────────┬───────────┬─────┐   ┌────┬────┬───┬───┬────┐
//    │    no     │    no    │    no     │    no     │ no  │   │ no │ 7  │ 8 │ 9 │ no │
//    ├───────────┼──────────┼───────────┼───────────┼─────┤   ├────┼────┼───┼───┼────┤
//    │ LSFT_T(1) │ GUI_T(2) │ LALT_T(3) │ LCTL_T(4) │ no  │   │ no │ 4  │ 5 │ 6 │ 0  │
//    ├───────────┼──────────┼───────────┼───────────┼─────┤   ├────┼────┼───┼───┼────┤
//    │    no     │    no    │    no     │    no     │ no  │   │ no │ 1  │ 2 │ 3 │ no │
//    └───────────┴──────────┴───────────┼───────────┼─────┤   ├────┼────┼───┴───┴────┘
//                                       │   TO(0)   │ spc │   │ no │ no │             
//                                       └───────────┴─────┘   └────┴────┘             
  KC_NO        , KC_NO       , KC_NO        , KC_NO        , KC_NO  ,     KC_NO , KC_7  , KC_8 , KC_9 , KC_NO,
  LSFT_T(KC_1) , GUI_T(KC_2) , LALT_T(KC_3) , LCTL_T(KC_4) , KC_NO  ,     KC_NO , KC_4  , KC_5 , KC_6 , KC_0 ,
  KC_NO        , KC_NO       , KC_NO        , KC_NO        , KC_NO  ,     KC_NO , KC_1  , KC_2 , KC_3 , KC_NO,
                                              TO(0)        , KC_SPC ,     KC_NO , KC_NO                      
),

[_FUNC] = LAYOUT(
//    ┌──────┬──────┬──────┬───────┬────┐   ┌─────┬─────┬────┬────┬─────┐
//    │  no  │  no  │  no  │  no   │ no │   │ f11 │ f12 │ no │ no │ no  │
//    ├──────┼──────┼──────┼───────┼────┤   ├─────┼─────┼────┼────┼─────┤
//    │ lsft │ lgui │ lalt │ lctl  │ no │   │ f6  │ f7  │ f8 │ f9 │ f10 │
//    ├──────┼──────┼──────┼───────┼────┤   ├─────┼─────┼────┼────┼─────┤
//    │  no  │  no  │  no  │  no   │ no │   │ f1  │ f2  │ f3 │ f4 │ f5  │
//    └──────┴──────┴──────┼───────┼────┤   ├─────┼─────┼────┴────┴─────┘
//                         │ TO(0) │ no │   │ no  │ no  │                
//                         └───────┴────┘   └─────┴─────┘                
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,     KC_F11 , KC_F12 , KC_NO , KC_NO , KC_NO ,
  KC_LSFT , KC_LGUI , KC_LALT , KC_LCTL , KC_NO ,     KC_F6  , KC_F7  , KC_F8 , KC_F9 , KC_F10,
  KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,     KC_F1  , KC_F2  , KC_F3 , KC_F4 , KC_F5 ,
                                TO(0)   , KC_NO ,     KC_NO  , KC_NO                          
)
};

// Combos
const uint16_t PROGMEM reset_combo[] = {MO(1), KC_SPM3, KC_BSM4, OSL(2), COMBO_END};
const uint16_t PROGMEM num_layer_combo[] = {KC_SPM3, KC_BSM4, COMBO_END};

const uint16_t PROGMEM enter_combo[] = {KC_SPM3, KC_MT, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_SPM3, KC_MS, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_SPM3, KC_MR, COMBO_END};

const uint16_t PROGMEM dot_combo[] = {KC_BSM4, KC_ME, COMBO_END};
const uint16_t PROGMEM comma_combo[] = {KC_BSM4, KC_MN, COMBO_END};
const uint16_t PROGMEM question_mark_combo[] = {KC_BSM4, KC_MI, COMBO_END};
const uint16_t PROGMEM exclamation_mark_combo[] = {KC_BSM4, KC_MO, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_BSM4, KC_U, COMBO_END};
const uint16_t PROGMEM colon_combo[] = {KC_BSM4, KC_L, COMBO_END};
const uint16_t PROGMEM semicolon_combo[] = {KC_BSM4, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(reset_combo, QK_BOOT),
  COMBO(num_layer_combo, TO(3)),

  COMBO(enter_combo, KC_ENTER),
  COMBO(escape_combo, KC_ESCAPE),
  COMBO(tab_combo, KC_ESCAPE),

  COMBO(dot_combo, KC_DOT),
  COMBO(comma_combo, KC_COMM),
  COMBO(question_mark_combo, LSFT(KC_MINS)),
  COMBO(exclamation_mark_combo, LSFT(KC_1)),
  COMBO(slash_combo, LSFT(KC_7)),
  COMBO(colon_combo, LSFT(KC_DOT)),
  COMBO(semicolon_combo, LSFT(KC_COMM)),
};
