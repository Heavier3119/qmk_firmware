#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// 
//
//

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 4


enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y |||  F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I |||  D  |   H  |   T  |   N  |   S  |ENTER |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X |||  B  |   M  |   W  |   V  |   Z  | DEL  |
 * |------+------+------+------+------+-----|||-----+------+------+------+------+------|
 * | Ctrl | GUI  |ADJUST| ALT  |Lower |Space|||Space|Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_DEL, \
  KC_LCTL,  KC_LGUI, ADJUST, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F7  |  F8  |  F9  |      |     ||   /  |   7  |   8  |   9  |  -   |      |
 * |------+------+------+------+------+-----||------+------+------+------+------+------|
 * |      |  F4  |  F5  |  F6  |      |     ||   *  |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+-----||------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |      |     ||      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+-----||------+------+------+------+------+------|
 * |      |      |      |      |~LOWER|     ||  0   |~RAISE| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV, KC_F7, KC_F8,   KC_F9, KC_NO,  KC_NO,          KC_SLSH, KC_7,  KC_8,     KC_9,   KC_MINS, KC_NO, \
  KC_NO, KC_F4, KC_F5,   KC_F6, KC_NO,  KC_NO,           KC_ASTR, KC_4,  KC_5 ,    KC_6,   KC_PLUS, KC_NO, \
  KC_NO,  KC_F1, KC_F2,   KC_F3, KC_NO,  KC_NO,          KC_NO,   KC_1,  KC_2,     KC_3,   KC_NO,   KC_NO, \
  KC_NO,  KC_NO, ADJUST, KC_NO, LOWER,KC_NO,          KC_0  ,RAISE, KC_MNXT,  KC_VOLD,KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   &  |  *   |   _  |   (  |  )   |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   $  |  %   |   ^  | [ ({)| ] (})|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   !  |  @   |   #  | / (?)| \ (|)|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |ADJUST|      |~LOWER|     |||     |~RAISE|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_NO, KC_NO, KC_AMPERSAND, KC_ASTERISK, KC_UNDS, KC_LEFT_PAREN,       KC_RIGHT_PAREN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO, KC_NO, KC_DOLLAR,     KC_PERCENT, KC_CIRCUMFLEX,   KC_LBRACKET,    KC_RBRACKET,   KC_NO,   KC_NO, KC_NO,  KC_NO, KC_NO, \
  KC_NO, KC_NO; KC_EXLM,            KC_AT, KC_NUHS,   KC_SLASH,               KC_BSLASH,  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO, KC_NO, ADJUST,             KC_NO, LOWER, KC_NO,                          KC_NO, RAISE, KC_NO, KC_NO, KC_NO, KC_NO \
),
  // KC_UNDERSCORE is left shift and - to get'_'

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |MSACCL|RESET |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |C+A+D |SNOOZE|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |M$ PWR|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |ADJUST|      |~LOWER|      |      |~RAISE|      |      |      |L. PWR|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_ACCEL0, RESET, \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(LCTL(KC_DEL)), KC_SYSTEM_SLEEP, \
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PWR, \
  KC_NO, KC_NO, ADJUST, KC_NO, LOWER, KC_NO, KC_NO, RAISE, KC_NO, KC_NO, KC_NO, KC_POWER \
)
//KC_POWER is for Linux, KC_PWR is for Microsoft, KC_SYSTEM_SLEEP is universal,
//RESET is a reset to the keyboard, and KC_MS_ACCEL0 sets mouse acceleration to zero. 

// LALT(LCTL(KC_DEL)) GIVES left control, alt and del.

};



void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) 
  {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
