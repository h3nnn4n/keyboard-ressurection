#include "WProgram.h"

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
    pinMode(13, OUTPUT);
}

void loop()
{
    // TODO: Make the linter happy
    // TODO: Fix KEY_* type to suppress warnings
    keyboard_keys[0] = KEY_A;
    usb_keyboard_send();

    delay(5);

    keyboard_keys[0] = 0;
    usb_keyboard_send();

    digitalWriteFast(13, HIGH);
    delay(500);

    digitalWriteFast(13, LOW);
    delay(500);
}
