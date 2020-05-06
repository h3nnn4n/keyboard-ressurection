#ifdef __SERIAL_DEBUG
#include "usb_serial.h"
#endif

#include "WProgram.h"
#include "stdio.h"

#include "config.h"
#include "setup.h"
#include "loop.h"

void loop() {
    reset_keys();
    int active_keys = 0;
    int key_status = 0;
    int layer = 0;

#ifdef __SERIAL_DEBUG
    char buffer[256];
#endif

    layer = shift_layer();

    /*if (layer == 1) {*/
        /*digitalWriteFast(LED_PIN, HIGH);*/
    /*} else {*/
        /*digitalWriteFast(LED_PIN, LOW);*/
    /*}*/

    for (size_t i = 0; i < N_COLUMNS; i++) {
        digitalWrite(column_pins[i], HIGH);
        delay(COLUMN_POOLING_DELAY);

        for (size_t j = 0; j < N_ROWS; j++) {
            key_status = digitalRead(row_pins[j]);

            if (key_status) {
                const int new_key = get_key(layer, N_ROWS - j - 1, i);

                if (new_key == NOP) {
#ifdef __SERIAL_DEBUG
                  sprintf(buffer, "i: %4d j: %4d j2: %4d  -- NOP\n\r", i, j, N_ROWS - j - 1);
                  int size = strlen(buffer);
                  usb_serial_write(buffer, size);
#endif
                  continue;
                }

                if (key_is_modifier(new_key)) {
                  keyboard_modifier_keys |= new_key;
                } else if (key_is_media(new_key)) {
                  // Lets assume we will never press two or more media key simutaneously
                  keymedia_consumer_keys[0] = new_key;
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
    }

    if (active_keys > 0) {
        digitalWriteFast(LED_PIN, HIGH);
    } else {
        digitalWriteFast(LED_PIN, LOW);
    }

    /*usb_keymedia_send();*/
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

int key_is_media(int key) {
    for (size_t i = 0; i < N_MEDIA; i++) {
        if (key_media[i] == key) {
            return 1;
        }
    }

    return 0;
}

void reset_keys() {
    for (size_t i = 0; i < KEY_BUFFER_SIZE; i++) {
        keyboard_keys[i] = 0;
    }

    for (size_t i = 0; i < N_MEDIA_BUFFER_SIZE; i++) {
        keymedia_consumer_keys[i] = 0;
    }

    keyboard_modifier_keys = 0;
}

int shift_layer() {
    digitalWrite(column_pins[11], HIGH);

    int key_status = digitalRead(row_pins[0]);

    digitalWrite(column_pins[11], LOW);

    return key_status;
}

int get_key(int layer, int row_index, int column_index) {
    if (layer == 1) {
        return key_layer_2[row_index][column_index];
    }

    return key_map[row_index][column_index];
}
