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
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
};

enum tap_dance_codes {
  LANG_SWAP,            // WIN when tapped, WIN+SPACE when double-tapped
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                      KC_H,       KC_P,       KC_O,       KC_I,       KC_U,       KC_Y,       KC_BSPACE,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                      TT(2),      KC_T,       KC_R,       KC_E,       KC_W,       KC_Q,       KC_TAB,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                              KC_G,       KC_F,       KC_D,       KC_S,       KC_A,       KC_LSHIFT,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                      TT(1),      KC_B,       KC_V,       KC_C,       KC_X,       KC_Z,       KC_LCTRL,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                                          KC_M,       KC_N,       KC_L,       KC_K,       KC_J,
                                                                                            KC_NO,      KC_NO,          KC_END,         KC_HOME,
                                                                                                        KC_NO,          KC_LALT,
                                                                            KC_NO,          KC_NO,      KC_NO,          TD(LANG_SWAP),    KC_ENTER,   KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      KC_DELETE,      KC_5,           KC_4,           KC_3,           KC_2,           KC_1,           KC_TRANSPARENT,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      TT(2),          KC_0,           KC_9,           KC_8,           KC_7,           KC_6,           KC_TRANSPARENT,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                  KC_RPRN,        KC_LPRN,        KC_SLASH,       KC_QUOTE,       KC_SCOLON,      KC_TRANSPARENT,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                      KC_TRANSPARENT, KC_RBRACKET,    KC_LBRACKET,    KC_BSLASH,      KC_DOT,         KC_COMMA,       MOD_LCTL,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                                                                                                        KC_ASTG,        KC_EQUAL,       KC_MINUS,       KC_GRAVE,       KC_CAPSLOCK,
                                                                                        KC_NO,      KC_NO,              KC_PGDOWN,      KC_PGUP,
                                                                                                                        KC_LALT,        KC_LALT,
                                                                            KC_NO,      KC_NO,      KC_NO,              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    LGUI(KC_L),     KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_ESCAPE,                                      KC_ESCAPE,      KC_F5,          KC_F4,          KC_F3,          KC_F2,          KC_F1,          LGUI(KC_L),
    KC_MAIL,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F10,         KC_F9,          KC_F8,          KC_F7,          KC_F6,          KC_CALCULATOR,
    KC_LSHIFT,      TO(3),          ST_MACRO_0,     LGUI(LSFT(KC_S)),KC_UP,          KC_AUDIO_MUTE,                                                                  KC_AUDIO_MUTE,  KC_UP,          LGUI(LSFT(KC_S)),ST_MACRO_2,     TO(3),          KC_LSHIFT,
    KC_CALCULATOR,  RESET,    ST_MACRO_1,     KC_LEFT,        KC_DOWN,        KC_RIGHT,       TO(1),                                          TO(1),          KC_RIGHT,       KC_DOWN,        KC_LEFT,        ST_MACRO_3,     RESET,    KC_MAIL,
    KC_F11,         KC_F12,         KC_F13,         KC_F14,         KC_F15,                                                                                                         KC_F15,         KC_F14,         KC_F13,         KC_F12,         KC_F11,
                                                                                                    KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK,
                                                                                                                    KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PLAY_PAUSE,
                                                                                    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_LGUI,        KC_LGUI,        KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_BSPACE,      KC_TRANSPARENT, KC_KP_MINUS,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_DELETE,                                      KC_DELETE,      KC_KP_9,        KC_KP_8,        KC_KP_7,        KC_KP_MINUS,    KC_TRANSPARENT, KC_BSPACE,
    KC_TAB,         KC_TRANSPARENT, KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,                                     KC_KP_PLUS,     KC_KP_6,        KC_KP_5,        KC_KP_4,        KC_KP_ASTERISK, KC_TRANSPARENT, KC_TAB,
    KC_TRANSPARENT, TO(0),          KC_KP_SLASH,    KC_KP_1,        KC_KP_2,        KC_KP_3,                                                                        KC_KP_3,        KC_KP_2,        KC_KP_1,        KC_KP_SLASH,    TO(0),          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_DOT,      KC_KP_0,        KC_TRANSPARENT, KC_KP_ENTER,                                    KC_KP_ENTER,    KC_TRANSPARENT, KC_KP_0,        KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    LGUI(LCTL(KC_LALT)),KC_NUMLOCK,     KC_NUMLOCK,     LGUI(LCTL(KC_LALT)),
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	 
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RGUI(SS_TAP(X_G))));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RGUI(SS_TAP(X_R))));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RGUI(SS_TAP(X_G))));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_RGUI(SS_TAP(X_R))));

    }
    break;
	
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_2) ));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_4) ));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_2) ));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_4) ));

    }
    break;
	
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
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

/*
static tap dance_state[2];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LALT);
        tap_code16(KC_LALT);
        tap_code16(KC_LALT);
    }
    if(state->count > 3) {
        tap_code16(KC_LALT);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LALT); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_LALT); register_code16(KC_LALT); break;
        case DOUBLE_HOLD: layer_on(4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LALT); register_code16(KC_LALT);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LALT); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_LALT); break;
        case DOUBLE_HOLD: layer_off(4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LALT); break;
    }
    dance_state[1].step = 0;
}
*/

qk_tap_dance_action_t tap_dance_actions[] = {
        [LANG_SWAP] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, LGUI(KC_SPACE)), //ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

