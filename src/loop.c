#include "usb_serial.h"
#include "WProgram.h"
#include "stdio.h"

#include "config.h"
#include "setup.h"
#include "loop.h"

void loop()
{
    reset_keys();
    int active_keys = 0;
    char buffer[256];

    for (size_t i = 0; i < n_columns; i++)
    {
        digitalWrite(column_pins[i], HIGH);

        for (size_t j = 0; j < n_rows; j++)
        {
            int key_status = digitalRead(row_pins[j]);
            int key_index = i * n_columns + j;

            if (key_status)
            {
                keyboard_keys[active_keys] = key_map[0];
                active_keys++;

                sprintf(buffer, "%4d %4d %4d\n", i, j, key_index);
                int size = 15;
                usb_serial_write(buffer, size);
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
