#include "WProgram.h"

#include "config.h"

void reset_keys();
void reset_keyboard();
int usb_keyboard_send();

extern uint8_t keyboard_keys[6];

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
