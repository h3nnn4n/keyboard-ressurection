#include "keylayouts.h"

#include "config.h"

const int n_rows = N_ROWS;
const int n_columns = N_COLUMNS;
const int n_modifiers = N_MODIFIERS;

const int row_pins[N_ROWS] = { ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6 };
const int column_pins[N_COLUMNS] = {
    COLUMN_1  , COLUMN_2  , COLUMN_3  , COLUMN_4  , COLUMN_5  , COLUMN_6  ,
    COLUMN_7  , COLUMN_8  , COLUMN_9  , COLUMN_10 , COLUMN_11 , COLUMN_12 ,
    COLUMN_13 , COLUMN_14 , COLUMN_15 , COLUMN_16 , COLUMN_17 , COLUMN_18 ,
};

const int key_modifiers[] = {
  KEY_LEFT_SHIFT , KEY_RIGHT_SHIFT ,
  KEY_LEFT_CTRL  , KEY_RIGHT_CTRL  ,
  KEY_LEFT_ALT   , KEY_RIGHT_ALT   ,
  KEY_LEFT_GUI   ,
};

const int key_map[N_ROWS][N_COLUMNS] = {
/*         0              , 1            , 2            , 3      , 4      , 5      , 6         , 7      , 8      , 9         , 10            , 11             , 12              , 13            , 14              , 15             , 16             , 17               */
/* 0 */  { KEY_ESC        , NOP          , KEY_F1       , KEY_F2 , KEY_F3 , KEY_F4 , NOP       , KEY_F5 , KEY_F6 , KEY_F7    , KEY_F8        , KEY_F9         , KEY_F10         , KEY_F11       , KEY_F12         , NOP            , NOP            , NOP             }   ,
/* 1 */  { KEY_TILDE      , KEY_1        , KEY_2        , KEY_3  , KEY_4  , KEY_5  , KEY_6     , KEY_7  , KEY_8  , KEY_9     , KEY_0         , KEY_MINUS      , KEY_EQUAL       , NOP           , KEY_BACKSPACE   , NOP            , NOP            , NOP             }   ,
/* 2 */  { KEY_TAB        , KEY_Q        , KEY_W        , KEY_E  , KEY_R  , KEY_T  , KEY_Y     , KEY_U  , KEY_I  , KEY_O     , KEY_P         , KEY_LEFT_BRACE , KEY_RIGHT_BRACE , NOP           , KEY_BACKSLASH   , NOP            , NOP            , NOP             }   ,
/* 3 */  { KEY_ESC        , KEY_A        , KEY_S        , KEY_D  , KEY_F  , KEY_G  , KEY_H     , KEY_J  , KEY_K  , KEY_L     , KEY_SEMICOLON , KEY_QUOTE      , NOP             , NOP           , KEY_ENTER       , NOP            , NOP            , NOP             }   ,
/* 4 */  { KEY_LEFT_SHIFT , NOP          , KEY_Z        , KEY_X  , KEY_C  , KEY_V  , KEY_B     , KEY_N  , KEY_M  , KEY_COMMA , KEY_PERIOD    , KEY_SLASH      , NOP             , NOP           , KEY_RIGHT_SHIFT , NOP            , KEY_UP_ARROW   , NOP             }   ,
/* 5 */  { KEY_LEFT_CTRL  , KEY_LEFT_GUI , KEY_LEFT_ALT , NOP    , NOP    , NOP    , KEY_SPACE , NOP    , NOP    , NOP       , NOP           , NOP            , NOP             , NOP           , KEY_RIGHT_CTRL  , KEY_LEFT_ARROW , KEY_DOWN_ARROW , KEY_RIGHT_ARROW }
};
