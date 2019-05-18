#if !defined(__LOOP_H)
#define __LOOP_H

#include "WProgram.h"

void loop();
void reset_keys();
void reset_keyboard();
int usb_keyboard_send();

extern uint8_t keyboard_keys[6];

#endif // __LOOP_H
