#include "keylayouts.h"

#include "config.h"

const int row_pins[] = {ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6};
const int column_pins[] = {
    COLUMN_1, COLUMN_2, COLUMN_3, COLUMN_4, COLUMN_5, COLUMN_6, COLUMN_7,
    COLUMN_8, COLUMN_9, COLUMN_10, COLUMN_11, COLUMN_12, COLUMN_13,
    COLUMN_14, COLUMN_15, COLUMN_16, COLUMN_17, COLUMN_18};
const int n_rows = N_ROWS;
const int n_columns = N_COLUMNS;

const int key_row_remap[N_ROWS] = {5, 4, 3, 2, 1, 0};

const int key_map[N_ROWS][N_COLUMNS] = {
/*         0       , 1       , 2       , 3       , 4       , 5       , 6       , 7         , 8       , 9       , 10      , 11      , 12      , 13      , 14            , 15      , 16      , 17 */
/* 0 */  { KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP   , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP       , KEY_NOP , KEY_NOP , KEY_NOP  } ,
/* 1 */  { KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP   , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_BACKSPACE , KEY_NOP , KEY_NOP , KEY_NOP  } ,
/* 2 */  { KEY_NOP , KEY_Q   , KEY_W   , KEY_E   , KEY_R   , KEY_T   , KEY_Y   , KEY_U     , KEY_I   , KEY_O   , KEY_P   , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP       , KEY_NOP , KEY_NOP , KEY_NOP  } ,
/* 3 */  { KEY_ESC , KEY_A   , KEY_S   , KEY_D   , KEY_F   , KEY_G   , KEY_H   , KEY_J     , KEY_K   , KEY_L   , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_ENTER     , KEY_NOP , KEY_NOP , KEY_NOP  } ,
/* 4 */  { KEY_NOP , KEY_NOP , KEY_Z   , KEY_X   , KEY_C   , KEY_V   , KEY_B   , KEY_N     , KEY_M   , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP       , KEY_NOP , KEY_NOP , KEY_NOP  } ,
/* 5 */  { KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_SPACE , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP , KEY_NOP       , KEY_NOP , KEY_NOP , KEY_NOP  }
};
