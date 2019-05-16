#include "WProgram.h"

void reset_keyboard();
int usb_keyboard_send();

const int column_pins[] = {10, 11, 12};
const int row_pins[] = {14, 15, 16};
const int n_columns = 3;
const int n_rows = 3;

const int key_map[] = {KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I};

extern "C" int main(void)
{
    setup();

    while (1)
    {
        loop();
    }
}

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
        pinMode(row_pins[i], INPUT_PULLUP);
    }
}

void loop()
{
    reset_keys();
    int active_keys = 0;

    for (size_t i = 0; i < n_columns; i++)
    {
        digitalWrite(column_pins[i], HIGH);

        for (size_t j = 0; j < n_rows; j++)
        {
            int key_status = !digitalRead(row_pins[j]);
            int key_index = i * n_columns + j;

            if (key_status)
            {
                keyboard_keys[active_keys] = key_map[key_index];
                active_keys++;
            }
        }

        digitalWrite(column_pins[i], LOW);
    }

    if (active_keys > 0)
    {
        digitalWriteFast(13, HIGH);
    }
    else
    {
        digitalWriteFast(13, LOW);
    }

    usb_keyboard_send();
}

void reset_keys()
{
    for (size_t i = 0; i < 6; i++)
    {
        keyboard_keys[i] = 0;
    }
}
