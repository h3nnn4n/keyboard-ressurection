#if !defined(__LOOP_H)
#define __LOOP_H

#include "WProgram.h"

void loop();
void reset_keys();
void reset_keyboard();
int usb_keyboard_send();
int key_is_modifier(int);

extern uint8_t keyboard_keys[6];
extern uint8_t keyboard_modifier_keys;

#endif // __LOOP_H
