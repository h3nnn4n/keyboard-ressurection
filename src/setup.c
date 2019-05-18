#include "WProgram.h"
#include "config.h"
#include "loop.h"

void setup()
{
    // Used for the LED. Just a simple heartbeat
    pinMode(13, OUTPUT);

    // Column scan pins
    for (size_t i = 0; i < n_columns; i++)
    {
        pinMode(column_pins[i], OUTPUT);
    }

    // Row scan pins
    for (size_t i = 0; i < n_rows; i++)
    {
        pinMode(row_pins[i], INPUT_PULLDOWN);
    }

    reset_keys();
}