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

            if (key_status)
            {
                const int new_key = key_map[n_rows - j - 1][i];

                if (new_key == KEY_NOP) {
                  sprintf(buffer, "i: %4d j: %4d j2: %4d  -- KEY_NOP\r", i, j, n_rows - j - 1);
                  int size = strlen(buffer);
                  usb_serial_write(buffer, size);
                  continue;
                }

                keyboard_keys[active_keys] = new_key;
                active_keys++;

                sprintf(buffer, "i: %4d j: %4d j2: %4d\r", i, j, n_rows - j - 1);
                int size = strlen(buffer);
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
