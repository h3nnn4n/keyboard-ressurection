#include "usb_serial.h"
#include "WProgram.h"
#include "stdio.h"

#include "config.h"
#include "setup.h"
#include "loop.h"

void loop() {
    reset_keys();
    int active_keys = 0;

#ifdef __SERIAL_DEBUG
    char buffer[256];
#endif

    for (size_t i = 0; i < n_columns; i++) {
        digitalWrite(column_pins[i], HIGH);

        for (size_t j = 0; j < n_rows; j++) {
            int key_status = digitalRead(row_pins[j]);

            if (key_status) {
                const int new_key = key_map[n_rows - j - 1][i];

                if (new_key == NOP) {
#ifdef __SERIAL_DEBUG
                  sprintf(buffer, "i: %4d j: %4d j2: %4d  -- NOP\n\r", i, j, n_rows - j - 1);
                  int size = strlen(buffer);
                  usb_serial_write(buffer, size);
#endif
                  continue;
                }

                if (key_is_modifier(new_key)) {
                  keyboard_modifier_keys |= new_key;
                } else {
                  keyboard_keys[active_keys] = new_key;
                  active_keys++;
                }

#ifdef __SERIAL_DEBUG
                sprintf(buffer, "i: %4d j: %4d j2: %4d\n\r", i, j, n_rows - j - 1);
                int size = strlen(buffer);
                usb_serial_write(buffer, size);
#endif
            }
        }

        digitalWrite(column_pins[i], LOW);

        if (i + 1 < n_columns) {
          delay(COLUMN_POOLING_DELAY);
        }
    }

    if (active_keys > 0) {
        digitalWriteFast(LED_PIN, HIGH);
    } else {
        digitalWriteFast(LED_PIN, LOW);
    }

    usb_keyboard_send();

    delay(POOLING_DELAY);
}

int key_is_modifier(int key) {
    for (size_t i = 0; i < N_MODIFIERS; i++) {
        if (key_modifiers[i] == key) {
            return 1;
        }
    }

    return 0;
}

void reset_keys() {
    for (size_t i = 0; i < KEY_BUFFER_SIZE; i++) {
        keyboard_keys[i] = 0;
    }

    keyboard_modifier_keys = 0;
}
