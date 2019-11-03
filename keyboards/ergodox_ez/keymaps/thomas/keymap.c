#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define BASE 0 // default layer
//#define MED 1 // symbols
//#define NAV 2 // media keys
//#define NUM 3 // media keys


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  QMK_BEST,
  EMAX_REPL,   
  EMAX_RECTKILL,
  EMAX_RECTYANK,
  EMAX_RKTKR,
  PY_CMT,
  LG_THOMAS,
  TABELLEN,
  SPSS_LABS,
  R_ASSIGN,
  SPSS_FILT_FREQ
};

//Tap Dance Declarations
enum {
      CT_SCAPS = 0,
      CT_KLAM,
      CT_EKLAM,
      CT_CKLAM,
      CT_TITERM,
      CT_PIPES,
      CT_HASHD,
      CT_DOPPEL,
      CT_PERCAND,
      CT_SLASHS,
      CT_MARKS,
      CT_TUET,
      CT_ATERIX,
      CT_KOMMA,
      CT_PUNKT
};

//Tap Dance functions

// Klammern
void dance_klam_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_8);
  } else {
    register_code (KC_RSFT);
    register_code (KC_9);
  }
}
void dance_klam_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_8);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_9);
  }
}

// eckige Klammern
void dance_eklam_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RALT);
    register_code (KC_8);
  } else {
    register_code (KC_RALT);
    register_code (KC_9);
  }
}
void dance_eklam_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RALT);
    unregister_code (KC_8);
  } else {
    unregister_code (KC_RALT);
    unregister_code (KC_9);
  }
}

// curly Klammern
void dance_cklam_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RALT);
    register_code (KC_7);
  } else {
    register_code (KC_RALT);
    register_code (KC_0);
  }
}
void dance_cklam_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RALT);
    unregister_code (KC_7);
  } else {
    unregister_code (KC_RALT);
    unregister_code (KC_0);
  }
}

//// Tilde + Terminal (F1)
//void dance_titerm_finished (qk_tap_dance_state_t *state, void *user_data) {
  //  if (state->count == 1) {
    //    register_code (KC_RALT);
    //    register_code (KC_RBRC);
    //  } else {
    //    register_code (KC_RALT);
    //    register_code (KC_F1);
    //  }
  //}
//void dance_titerm_reset (qk_tap_dance_state_t *state, void *user_data) {
  //  if (state->count == 1) {
    //    unregister_code (KC_RALT);
    //    unregister_code (KC_RBRC);
    //  } else {
    //    unregister_code (KC_RALT);
    //    unregister_code (KC_F1);
    //  }
  //}
// Tilde + Terminal (F1)
void dance_titerm_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_F1);
  } if (state->count == 2) {
    register_code (KC_RALT);
    register_code (KC_RBRC);
  } else {
    register_code (KC_RALT);
    register_code (KC_NONUS_BSLASH);
  }
}
void dance_titerm_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_F1);
  } if (state->count == 2) {
    unregister_code (KC_RALT);
    unregister_code (KC_RBRC);
  } else {
    unregister_code (KC_RALT);
    unregister_code (KC_NONUS_BSLASH);    
  }
}
// Pipes (nicht mehr verwendet)
void dance_pipes_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_NONUS_BSLASH);
  } if (state->count == 2) {
    register_code (KC_LSFT);
    register_code (KC_NONUS_BSLASH);
  } else {
    register_code (KC_RALT);
    register_code (KC_NONUS_BSLASH);
  }
}
void dance_pipes_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_NONUS_BSLASH);
  } if (state->count == 2) {
    unregister_code (KC_LSFT);
    unregister_code (KC_NONUS_BSLASH);
  } else {
    unregister_code (KC_RALT);
    unregister_code (KC_NONUS_BSLASH);
  }
}

// Hash + Dollar
void dance_hashd_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_BSLASH);
  } else {
    register_code (KC_RSFT);
    register_code (KC_4);
  }
}
void dance_hashd_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_BSLASH);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_4);
  }
}

// Doppelpunkt und Semikolon
void dance_doppel_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_DOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_COMMA);
  }
}
void dance_doppel_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_DOT);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_COMMA);
  }
}

// Prozent und und
void dance_percand_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_5);
  } else {
    register_code (KC_RSFT);
    register_code (KC_6);
  }
}
void dance_percand_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_5);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_6);
  }
}

// Slash und Backsalash
void dance_slashs_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_7);
  } else {
    register_code (KC_RALT);
    register_code (KC_MINUS);
  }
}
void dance_slashs_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_7);
  } else {
    unregister_code (KC_RALT);
    unregister_code (KC_MINUS);
  }
}

// Ausrufe und Fragezeichen
void dance_marks_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_1);
  } else {
    register_code (KC_RSFT);
    register_code (KC_MINUS);
  }
}
void dance_marks_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_1);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_MINUS);
  }
}

// Apostroph und Tütelchen
void dance_tuet_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);  
    register_code (KC_2);     
  } else {                    
    register_code (KC_LSFT);  
    register_code (KC_BSLASH);
  }
}
void dance_tuet_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LSFT);
    unregister_code (KC_2);     
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_BSLASH);
  }
}

// Asterisk und @
void dance_aterix_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LSFT);  
    register_code (KC_RBRACKET);
  } else {                    
    register_code (KC_RALT);  
    register_code (KC_Q);     
  }
}
void dance_aterix_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LSFT);
    unregister_code (KC_RBRACKET);
  } else {
    unregister_code (KC_RALT);
    unregister_code (KC_Q);     
  }
}


// komma mit und ohne leerzeichen (nicht mehr verwendet)
void dance_komma_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_COMMA);  
  } else {                    
    register_code (KC_COMMA);     
    register_code (KC_SPACE);  
  }
}
void dance_komma_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_COMMA);
  } else {
    unregister_code (KC_COMMA);
    unregister_code (KC_SPACE);     
  }
}
// punkt mit und ohne leerzeichen (nicht mehr verwendet)
void dance_punkt_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_DOT);  
  } else {                    
    register_code (KC_DOT);     
    register_code (KC_SPACE);  
  }
}
void dance_punkt_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_DOT);
  } else {
    unregister_code (KC_DOT);
    unregister_code (KC_SPACE);     
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for SZett, twice for Caps Lock
  [CT_SCAPS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_CAPS),
  [CT_KLAM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_klam_finished, dance_klam_reset),
  [CT_EKLAM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_eklam_finished, dance_eklam_reset),
  [CT_CKLAM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cklam_finished, dance_cklam_reset),
  [CT_TITERM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_titerm_finished, dance_titerm_reset),
  [CT_PIPES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_pipes_finished, dance_pipes_reset),
  [CT_HASHD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_hashd_finished, dance_hashd_reset),
  [CT_DOPPEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_doppel_finished, dance_doppel_reset),
  [CT_PERCAND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_percand_finished, dance_percand_reset),
  [CT_SLASHS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_slashs_finished, dance_slashs_reset),
  [CT_MARKS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_marks_finished, dance_marks_reset),
  [CT_TUET] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_tuet_finished, dance_tuet_reset),
  [CT_ATERIX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_aterix_finished, dance_aterix_reset),
  [CT_KOMMA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_komma_finished, dance_komma_reset),
  [CT_PUNKT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_punkt_finished, dance_punkt_reset)
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   @  |  " ' |  ( ) |  [ ] |  { } |layers|           |      | % ²& |   *  | / ²\ |   =  | ! ²? |  AltF4 |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  | back |           |  #   |   Z  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------| spac |           |      |------+------+------+------+------+--------|
 * |  CAPS  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  uml | enter  |
 * |--------+------+------+------+------+------| del  |           |      |------+------+------+------+------+--------|  
 * |L_Shift |   Y  |   X  |   C  |   V  |   B  |      |           | menu |   N  |   M  |  up  |  ~   |  |   |R_Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctl ^°|Alt ´`| Mous | Fun  | Num  |                                       | left | down |right |AltG  |RCrl  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |  ,   |  .   |
 *                                 |space | tab  |------|       |------|      |      |
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 * emacs leader meh 
 */

                                                              
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
                        
// left hand
KC_ESC,          RALT(KC_Q),      TD(CT_TUET),  TD(CT_KLAM), TD(CT_EKLAM), TD(CT_CKLAM), TT(7),
KC_TAB,          KC_Q,            KC_W,         GUI_T(KC_E), ALL_T(KC_R),  KC_T,         KC_BSPACE,
KC_CAPS,         KC_A,            KC_S,         ALT_T(KC_D), CTL_T(KC_F),  KC_G,
KC_LSHIFT,       KC_Z,            KC_X,         KC_C,        MEH_T(KC_V),  KC_B,         KC_DELETE,
CTL_T(KC_GRAVE), GUI_T(KC_EQUAL), TT(3),        TT(2),       TT(1),

XXXXXXX,         XXXXXXX,
KC_HOME,
KC_SPACE,        KC_TAB,   KC_END,


// right handTD(CT_ATERIX)TD(CT_DOPPEL)
XXXXXXX,       TD(CT_PERCAND), LSFT(KC_RBRACKET), TD(CT_SLASHS), LSFT(KC_0),      TD(CT_MARKS),          LALT(KC_F4),
KC_BSLASH,       KC_Y,           ALL_T(KC_U),       GUI_T(KC_I),   KC_O,            KC_P,                  XXXXXXX,
               KC_H,           CTL_T(KC_J),       ALT_T(KC_K),   KC_L,            OSL(2),                KC_ENTER,
KC_APP,        KC_N,           MEH_T(KC_M),       KC_UP,         RALT(KC_RBRC),   RALT(KC_NONUS_BSLASH), KC_RSHIFT,
                               KC_LEFT,           KC_DOWN,       KC_RGHT,         KC_RALT,               KC_RCTRL,

XXXXXXX,      XXXXXXX,
KC_PGUP,
KC_PGDOWN,    KC_COMMA,       KC_DOT
),







/* Keymap 1: Numpad 
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |   *  |   /  |  =   |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |  $   |  <-  |   7  |   8  |  9   |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|  >   |   4  |   5  |  6   |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |  <   |   1  |   2  |  3   |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |  .   |  ,   |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  -   |  +   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */


[1] = LAYOUT_ergodox(

        // left hand                       
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, XXXXXXX,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
TO(0),          KC_TRANSPARENT, TO(3),          TO(2),          TO(0),

KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT,
KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,


        // right hand
XXXXXXX,        XXXXXXX,               LSFT(KC_RBRACKET), RSFT(KC_7),      LSFT(KC_0),      XXXXXXX,        XXXXXXX,
LSFT(KC_4),     R_ASSIGN,              KC_7,              KC_8,            KC_9,            KC_TRANSPARENT, KC_TRANSPARENT,
                LSFT(KC_NONUS_BSLASH), KC_4,              KC_5,            KC_6,            XXXXXXX,        KC_TRANSPARENT,
XXXXXXX,        KC_NONUS_BSLASH,       KC_1,              KC_2,            KC_3,            KC_TRANSPARENT, KC_TRANSPARENT,
                                       KC_0,              KC_DOT,          KC_COMMA,        KC_TRANSPARENT, KC_TRANSPARENT,

KC_TRANSPARENT, KC_TRANSPARENT,
KC_TRANSPARENT,
KC_TRANSPARENT, KC_SLASH, KC_RBRACKET
),




/* Keymap 2: Function keys
 *
 * ,-------------------------------------------------.           ,--------------------------------------------------.
 * |         | F1  | F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | power  |
 * |---------+-----+-----+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |     |     |      |      |      |      |           |      |      |   Ü  |      |   Ö  |      | sleep  |
 * |---------+-----+-----+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  Ä  |  ß  |      |      |      |------|           |------|      |      |      |      |      | wake   |
 * |---------+-----+-----+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | L Shift |     |     |      |      |      |      |           |      |      |PrtScn|Scroll|PausBr|      | R Shift|
 * `---------+-----+-----+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |     |     |      |      |                                       |insert|      |      |      |      |
 *   `---------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[2] = LAYOUT_ergodox(

        // left hand                       
XXXXXXX,   KC_F1,    KC_F2,     KC_F3,      KC_F4,     KC_F5,     KC_F6,
XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
XXXXXXX,   KC_QUOTE, KC_MINUS,  XXXXXXX,    XXXXXXX,   XXXXXXX,
KC_LSHIFT, XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,
TO(0),     XXXXXXX,  TO(3),     TO(0),      TO(1),

XXXXXXX,    XXXXXXX,
XXXXXXX,
XXXXXXX,    XXXXXXX,   XXXXXXX,


        // right hand
KC_F7,   KC_F8,   KC_F9,       KC_F10,  KC_F11,    KC_F12,  KC_SYSTEM_POWER,
XXXXXXX, XXXXXXX, KC_LBRACKET, XXXXXXX, KC_SCOLON, XXXXXXX, KC_SYSTEM_SLEEP,
         XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,   XXXXXXX, KC_SYSTEM_WAKE,
XXXXXXX, XXXXXXX, KC_PSCR,     KC_SLCK, KC_PAUS,   XXXXXXX, XXXXXXX,
                  KC_INS,      XXXXXXX, XXXXXXX,   XXXXXXX, KC_RSHIFT,

XXXXXXX,   XXXXXXX,
XXXXXXX,
XXXXXXX,   XXXXXXX,   XXXXXXX
), 



/* Keymap 3: Media + Mouse
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |mclick|      |      | play   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      | paste|      |      |           |      |      |      |  up  |      |      | stop   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |  cut | copy |      |------|           |------|scrup | left | down |right |      | vol +  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |scrdwn|      |      |      |      | vol -  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |rclick|      |      |prv tr|nex tr|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |lclick|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[3] = LAYOUT_ergodox( // layer 1 : Media + Mouse

        // left hand                       
XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX,
XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,     LCTL(KC_V),  XXXXXXX,   XXXXXXX,
XXXXXXX,    XXXXXXX,   XXXXXXX,   LCTL(KC_X),  LCTL(KC_C),  XXXXXXX,
XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX,
TO(0),      XXXXXXX,   TO(0),     TO(2),       TO(1),

                                   XXXXXXX,    XXXXXXX,
                                               XXXXXXX,
                       XXXXXXX,    XXXXXXX,    XXXXXXX,


        // right hand
XXXXXXX,    XXXXXXX,        XXXXXXX,           KC_MS_BTN3,      XXXXXXX,         XXXXXXX,              KC_MEDIA_PLAY_PAUSE,
XXXXXXX,    XXXXXXX,        XXXXXXX,           KC_MS_UP,        XXXXXXX,         XXXXXXX,              KC_MEDIA_STOP,
            KC_MS_WH_UP,    KC_MS_LEFT,        KC_MS_DOWN,      KC_MS_RIGHT,     XXXXXXX,              KC_AUDIO_VOL_UP,
XXXXXXX,    KC_MS_WH_DOWN,  XXXXXXX,           KC_WWW_REFRESH,  XXXXXXX,         XXXXXXX,              KC_AUDIO_VOL_DOWN,
                            KC_MS_BTN2,        XXXXXXX,         XXXXXXX,         KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,

XXXXXXX,    XXXXXXX,
KC_PGUP,
KC_PGDOWN,  XXXXXXX,    KC_MS_BTN1
),





/* Keymap 4: Programming Layer 
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |pycomt|      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[4] = LAYOUT_ergodox(

        // left hand                     
XXXXXXX, XXXXXXX,        XXXXXXX, TO(6),   TO(5),   TO(0),   TO(0),
XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, SPSS_FILT_FREQ, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
TO(0),   XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX,


XXXXXXX, XXXXXXX,
XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX,


        // right hand
PY_CMT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, SPSS_LABS, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,

XXXXXXX, XXXXXXX,
XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX
), 






/* Keymap 6: gaming layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  ' " |  # $ |  ( ) |  [ ] |  { } |layers|           | : ²; | % ²& | * ²@ | / ²\ |   =  | ! ²? |  ²CAPS |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  | back |           |   +  |   Z  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------| spac |           |      |------+------+------+------+------+--------|
 * | enter  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |      | enter  |
 * |--------+------+------+------+------+------| del  |           |   -  |------+------+------+------+------+--------|  
 * |L_Shift |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  up  |   ~  | <> | |R_Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Ctl ^°|Alt ´`| Mous | Fun  | Num  |                                       | left | down |right |AltG  |RCrl  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | emacs|      |       |      |emacs |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |  ,   |  .   |
 *                                 |space | meh  |------|       |------| meh  |emacs |
 *                                 |      |      | End  |       | PgDn |      |leader|
 *                                 `--------------------'       `--------------------'
 */

                                                              
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[5] = LAYOUT_ergodox(  // layer 0 : default
                        
        // left hand
KC_ESC,          TD(CT_TUET),     TD(CT_HASHD), TO(6),       TO(0),        TO(4),        TO(0),
KC_TAB,          KC_Q,            KC_W,         KC_E,        KC_R,         KC_T,         KC_BSPACE,
KC_TRANSPARENT,  KC_A,            KC_S,         KC_D,        KC_F,         KC_G,
KC_LSHIFT,       KC_Z,            KC_X,         KC_C,        KC_V,         KC_B,         KC_DELETE,
KC_LCTRL,        KC_LGUI,         TT(3),        TT(2),       TT(1),

KC_APP,          XXXXXXX,
KC_HOME,
KC_SPACE,        MEH_T(KC_COMMA), KC_END,


// right hand
TD(CT_DOPPEL), TD(CT_PERCAND), TD(CT_ATERIX), TD(CT_SLASHS), LSFT(KC_0),    TD(CT_MARKS), KC_CAPS,
KC_RBRACKET,   KC_Y,           KC_U,          KC_I,          KC_O,          KC_P,         XXXXXXX,
               KC_H,           KC_J,          KC_K,          KC_L,          OSL(2),       KC_ENTER,
KC_SLASH,      KC_N,           KC_M,          KC_UP,         TD(CT_TITERM), TD(CT_PIPES), KC_RSHIFT,
                               KC_LEFT,       KC_DOWN,       KC_RGHT,       KC_RALT,      KC_RCTRL,

XXXXXXX,      KC_APP,
KC_PGUP,
KC_PGDOWN,    TD(CT_KOMMA),       TD(CT_PUNKT)
),



/* Keymap 7: ???
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[6] = LAYOUT_ergodox(

        // left hand                     
XXXXXXX, XXXXXXX, XXXXXXX, TO(0),   TO(5),   TO(4),   TO(0),
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,


XXXXXXX, XXXXXXX,
XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX,


        // right hand
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

XXXXXXX, XXXXXXX,
XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX
), 


/* Keymap 7: switch + rgb
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[7] = LAYOUT_ergodox(

        // left hand                     
XXXXXXX, XXXXXXX, XXXXXXX, TO(6),          TO(5),   TO(4),    TO(0),
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TABELLEN, LG_THOMAS,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,  XXXXXXX,
TO(0),   XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,


XXXXXXX, XXXXXXX,
XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX,


        // right hand
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, RGB_VAI, RGB_HUI, RGB_SAI,   XXXXXXX, XXXXXXX,
                  RGB_VAD, RGB_HUD, RGB_SAD,   XXXXXXX, XXXXXXX,

RGB_MODE_PLAIN, XXXXXXX,
RGB_MOD,
RGB_RMOD, RGB_TOG, RGB_TOG
), 




};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(2)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    // CUSTOM MACROS
    case QMK_BEST:
      if (record->event.pressed) {
        SEND_STRING("QMK is the best thing ever!");
      }
      return false;
      break;
    case EMAX_RECTKILL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("x")"rk"); // emacs rectangle kill
      }
      return false;
      break;
    case EMAX_RECTYANK:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("x")"rz"); // emacs rectangle yank
      }
      return false;
      break;
    case EMAX_RKTKR:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("x")"r"SS_LALT("w")); // emacs rectangle kill to kill ring
      }
      return false;
      break;
    case EMAX_REPL:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("%"));
      }
      return false;
      break;
    // Python Comment
    case PY_CMT:
      if (record->event.pressed) {
        SEND_STRING("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        SEND_STRING("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" SS_TAP(X_ENTER));
        SEND_STRING("\\\\\\" SS_TAP(X_ENTER));
        SEND_STRING("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        SEND_STRING("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" SS_TAP(X_UP) SS_TAP(X_SPACE));
      }
      return false;
      break;
    // LG, THOMAS
    case LG_THOMAS:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING("LG, Thomas");
      }
      return false;
      break;
    // TABELLEN IM ANHANG
    case TABELLEN:
      if (record->event.pressed) {
        SEND_STRING("Hez hez,"SS_TAP(X_ENTER));
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING("Die Tabellenb'nder sind im Anhang."SS_TAP(X_ENTER));
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING("LG, Thomas");
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
    // spss-filter-freq
    case SPSS_FILT_FREQ:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING("temporarz."SS_TAP(X_ENTER));
        SEND_STRING("select if ."SS_TAP(X_ENTER));
        SEND_STRING("fre .");
        SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
	layer_invert(0);
      }
      return false;
      break;
    // spss-labs
    case SPSS_LABS:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER));
        SEND_STRING("var lab  ''."SS_TAP(X_ENTER));
        SEND_STRING("val lab "SS_TAP(X_ENTER));
        SEND_STRING("1 ''"SS_TAP(X_ENTER));
	SEND_STRING("2 ''"SS_TAP(X_ENTER));
	SEND_STRING(".");
        SEND_STRING(SS_TAP(X_LEFT) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
	layer_invert(0);
      }
      return false;
      break;
    // R Zuweisung
    case R_ASSIGN:
      if (record->event.pressed) {
	SEND_STRING(" ");
	SEND_STRING(SS_TAP(X_NONUS_BSLASH) SS_TAP(X_SLASH));
	SEND_STRING(" ");	
	layer_invert(0);
      }
      return false;
      break;
            
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};




// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};



// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();        
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
