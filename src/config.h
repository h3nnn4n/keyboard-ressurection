#if !defined(__CONFIG_H)
#define __CONFIG_H

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

#define N_ROWS 6
#define N_COLUMNS 18
#define N_MODIFIERS 7
#define N_MEDIA 7

#define KEY_BUFFER_SIZE 6
#define N_MEDIA_BUFFER_SIZE 4

#define NOP -1

// Fake key used as layer switching key
#define KEY_NINJA -2

// how much we wait before scanning the keyboard matrix
#define POOLING_DELAY 10

// how much we wait between turning a column off and turning the next one on
// for scanning this being set as zero causes some ghosting (a key is pressed
// and another one comes with it)
#define COLUMN_POOLING_DELAY 1

#define LED_PIN 13

extern const int column_pins[];
extern const int row_pins[];
extern const int n_columns;
extern const int n_rows;
extern const int key_modifiers[];
extern const int key_media[];
extern const int key_map[N_ROWS][N_COLUMNS];
extern const int key_layer_2[N_ROWS][N_COLUMNS];

#endif // __CONFIG_H
