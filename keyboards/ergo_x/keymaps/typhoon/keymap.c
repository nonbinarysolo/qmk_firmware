#include QMK_KEYBOARD_H
#include "version.h"


#include "keymap_us_international.h"
#include "keymap_icelandic.h"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  GCAP,
  GREC,
  SSHOT
};

enum tap_dance_codes {
  LANG_SWAP,      // WIN when tapped, WIN+SPACE when double-tapped
  LDESK,          // Go to left desktop
  RDESK,          // Go to right desktop
  CAPSW           // Double-tap Caps Lock to do Caps Word
};

tap_dance_action_t tap_dance_actions[] = {
        [LANG_SWAP] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_SPACE)), //ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [LDESK] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, LCTL(LGUI(KC_LEFT))),
        [RDESK] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, LCTL(LGUI(KC_RIGHT))),
        //[CAPSW] = ACTION_TAP_DANCE_DOUBLE(KC_CAPS, QK_CAPS_WORD_TOGGLE)
        [CAPSW] = ACTION_TAP_DANCE_DOUBLE(CW_TOGG, KC_CAPS)
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                      KC_H,       KC_P,       KC_O,       KC_I,       KC_U,       KC_Y,       KC_BSPC,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                      TT(2),      KC_T,       KC_R,       KC_E,       KC_W,       KC_Q,       KC_TAB,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                              KC_G,       KC_F,       KC_D,       KC_S,       KC_A,       KC_LSFT,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                      TT(1),      KC_B,       KC_V,       KC_C,       KC_X,       KC_Z,       KC_LCTL,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                                          KC_M,       KC_N,       KC_L,       KC_K,       KC_J,
                                                                                            KC_NO,      KC_NO,          KC_END,         KC_HOME,
                                                                                                        KC_NO,          KC_LALT,
                                                                            KC_NO,          KC_NO,      KC_NO,          TD(LANG_SWAP),  KC_ENT,     KC_SPC
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      KC_DELETE,      KC_5,           KC_4,           KC_3,           KC_2,           KC_1,           KC_TRNS,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      TT(2),          KC_0,           KC_9,           KC_8,           KC_7,           KC_6,           KC_TRNS,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                  KC_RPRN,        KC_LPRN,        KC_SLASH,       KC_QUOTE,       KC_SCLN,        KC_TRNS,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      KC_TRNS,        KC_RBRC,        KC_LBRC,        KC_BSLS,        KC_DOT,         KC_COMMA,       MOD_LCTL,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                              AS_TOGG,        KC_EQUAL,       KC_MINUS,       KC_GRAVE,       KC_CAPS,
                                                                                            KC_NO,      KC_NO,          KC_PGDN,        KC_PGUP,
                                                                                                        KC_NO,          KC_LALT,
                                                                            KC_NO,          KC_NO,      KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      KC_ESC,         KC_F5,          KC_F4,          KC_F3,          KC_F2,          KC_F1,          LGUI(KC_L),
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      KC_TRNS,        KC_F10,         KC_F9,          KC_F8,          KC_F7,          KC_F6,          KC_MAIL,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                  KC_MUTE,        KC_UP,          SSHOT,          GCAP,           KC_NO,          KC_CALC,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      TO(1),          TD(RDESK),      KC_DOWN,        TD(LDESK),      GREC,           QK_BOOT,        KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                                              KC_F15,         KC_F14,         KC_F13,         KC_F12,         KC_F11,
                                                                                            KC_NO,      KC_NO,          KC_MNXT,        KC_MPRV,
                                                                                                        KC_NO,          KC_MPLY,
                                                                            KC_NO,          KC_NO,      KC_NO,          KC_LGUI,        KC_VOLU,        KC_VOLD
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	 
    case GCAP:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RGUI(SS_TAP(X_G))));
    }
    break;
    case GREC:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RGUI(SS_TAP(X_R))));
    }
    break;
    case SSHOT:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
    }
    break;
  }
  return true;
}

//uint32_t layer_state_set_user(uint32_t state) {
layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};


void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
        ergodox_right_led_3_on();
    } else {
        // Do something when Caps Word deactivates.
        ergodox_right_led_3_off();
    }
}