#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};



#define DUAL_FUNC_0 LT(13, KC_F14)
#define DUAL_FUNC_1 LT(6, KC_F5)
#define DUAL_FUNC_2 LT(7, KC_7)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    DUAL_FUNC_0,    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           DUAL_FUNC_1,    DUAL_FUNC_2,    KC_8,           KC_9,           KC_0,           TT(3),          
    KC_TAB,         KC_J,           KC_D,           KC_U,           KC_A,           KC_X,                                           KC_P,           KC_H,           KC_L,           KC_M,           KC_W,           DE_SS,          
    MO(1),          MT(MOD_LSFT, KC_C),KC_T,           KC_I,           KC_E,           KC_O,                                           KC_B,           KC_N,           KC_R,           KC_S,           MT(MOD_RSFT, KC_G),KC_Q,           
    KC_LEFT_CTRL,   KC_F,           KC_V,           DE_UE,          DE_AE,          DE_OE,                                          DE_Y,           DE_Z,           KC_COMMA,       KC_DOT,         KC_K,           LALT(KC_LEFT_GUI),
                                                    MT(MOD_LALT, KC_SPACE),OSM(MOD_LGUI),                                  OSM(MOD_LGUI),  LT(2, KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    DE_LESS,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, DE_EURO,        DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_PARA,                                        DE_EXLM,        DE_LESS,        DE_MORE,        DE_EQL,         DE_AMPR,        DE_AT,          
    KC_TRANSPARENT, DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,                                        DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          RGB_VAD,        RGB_VAI,        DE_SLSH,        DE_ASTR,        DE_MINS,        TOGGLE_LAYER_COLOR,
    KC_TRANSPARENT, KC_PAGE_UP,     KC_BSPC,        KC_UP,          KC_DELETE,      KC_PGDN,                                        KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           DE_PLUS,        RGB_TOG,        
    KC_TRANSPARENT, KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,                                         DE_COLN,        KC_3,           KC_5,           KC_6,           KC_DOT,         RGB_MODE_FORWARD,
    KC_TRANSPARENT, KC_ESCAPE,      KC_TAB,         KC_INSERT,      KC_ENTER,       KC_PC_UNDO,                                     KC_0,           KC_1,           KC_2,           KC_3,           KC_COMMA,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_0,           KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_TRANSPARENT, KC_PSCR,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,                                KC_MEDIA_NEXT_TRACK,KC_MEDIA_PREV_TRACK
  ),
};


const uint16_t PROGMEM combo0[] = { DE_Y, MT(MOD_LALT, KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LALT, KC_SPACE), LT(2, KC_BSPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_ENTER),
    COMBO(combo1, KC_ENTER),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,255,255}, {232,255,255}, {215,255,255}, {200,255,255}, {183,255,255}, {172,255,255}, {0,255,255}, {232,255,255}, {215,255,255}, {200,255,255}, {183,255,255}, {172,255,255}, {0,255,255}, {232,255,255}, {215,255,255}, {200,255,255}, {183,255,255}, {172,255,255}, {0,255,255}, {232,255,255}, {215,255,255}, {200,255,255}, {183,255,255}, {172,255,255}, {172,255,255}, {183,159,190}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [1] = { {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141}, {131,244,141} },

    [2] = { {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {32,255,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {32,255,255}, {32,255,255}, {32,255,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {23,161,255}, {199,231,240}, {200,255,255}, {200,255,255}, {23,161,255}, {23,161,255}, {32,255,255}, {32,255,255}, {32,255,255}, {200,255,255}, {23,161,255}, {23,161,255}, {32,255,255}, {32,255,255}, {32,255,255}, {131,244,141}, {23,161,255}, {23,161,255}, {32,255,255}, {32,255,255}, {32,255,255}, {131,244,141}, {23,161,255}, {32,255,255}, {23,161,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ESCAPE);
        } else {
          unregister_code16(KC_ESCAPE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(KC_G));
        } else {
          unregister_code16(LCTL(KC_G));
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_6);
        } else {
          unregister_code16(KC_6);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DE_DLR);
        } else {
          unregister_code16(DE_DLR);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_7);
        } else {
          unregister_code16(KC_7);
        }
      } else {
        if (record->event.pressed) {
          register_code16(DE_EURO);
        } else {
          unregister_code16(DE_EURO);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
