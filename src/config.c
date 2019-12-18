#include "keylayouts.h"

#define ROW_1 31
#define ROW_2 33
#define ROW_3 27
#define ROW_4 26
#define ROW_5 32
#define ROW_6 28

#define COLUMN_1 0
#define COLUMN_2 1
#define COLUMN_3 2
#define COLUMN_4 3
#define COLUMN_5 4
#define COLUMN_6 5
#define COLUMN_7 6
#define COLUMN_8 7
#define COLUMN_9 8
#define COLUMN_10 9
#define COLUMN_11 10
#define COLUMN_12 11
#define COLUMN_13 12
#define COLUMN_14 14
#define COLUMN_15 15
#define COLUMN_16 16
#define COLUMN_17 17
#define COLUMN_18 18

const int row_pins[] = {ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6};
const int column_pins[] = {
    COLUMN_1, COLUMN_2, COLUMN_3, COLUMN_4, COLUMN_5, COLUMN_6, COLUMN_7,
    COLUMN_8, COLUMN_9, COLUMN_10, COLUMN_11, COLUMN_12, COLUMN_13,
    COLUMN_14, COLUMN_15, COLUMN_16, COLUMN_17, COLUMN_18};
const int n_rows = 6;
const int n_columns = 18;

const int key_map[] = {KEY_ESC, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_A, KEY_A, KEY_A, KEY_A, KEY_A, KEY_A, KEY_A, KEY_A, KEY_A, KEY_A};
