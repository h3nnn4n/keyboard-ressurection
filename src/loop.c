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

                if (new_key == NOP) {
                  sprintf(buffer, "i: %4d j: %4d j2: %4d  -- NOP\r", i, j, n_rows - j - 1);
                  int size = strlen(buffer);
                  usb_serial_write(buffer, size);
                  continue;
                }

                if (key_is_modifier(new_key)) {
                  keyboard_modifier_keys |= new_key;
                } else {
                  keyboard_keys[active_keys] = new_key;
                  active_keys++;
                }

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

    delay(POOLING_DELAY);
}

int key_is_modifier(int key)
{
    for (size_t i = 0; i < 6; i++)
    {
        if (key_modifiers[i] == key) {
            return 1;
        }
    }

    return 0;
}

void reset_keys()
{
    for (size_t i = 0; i < 6; i++)
    {
        keyboard_keys[i] = 0;
    }

    keyboard_modifier_keys = 0;
}
