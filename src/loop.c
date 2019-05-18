#include "WProgram.h"
#include "config.h"
#include "setup.h"
#include "loop.h"

void loop()
{
    reset_keys();
    int active_keys = 0;

    for (size_t i = 0; i < n_columns; i++)
    {
        digitalWrite(column_pins[i], HIGH);

        for (size_t j = 0; j < n_rows; j++)
        {
            int key_status = digitalRead(row_pins[j]);
            int key_index = i * n_columns + j;

            if (key_status)
            {
                keyboard_keys[active_keys] = KEY_A; // key_map[key_index];
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

    delay(10);
}

void reset_keys()
{
    for (size_t i = 0; i < 6; i++)
    {
        keyboard_keys[i] = 0;
    }
}
