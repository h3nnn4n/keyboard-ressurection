#if !defined(__LOOP_H)
#define __LOOP_H

#include "WProgram.h"
#include "usb_keyboard.h"

void loop();
void reset_keys();
void reset_keyboard();
int key_is_modifier(int);
int key_is_media(int);
int shift_layer();
int get_key(int, int, int);

// Defined in usb_keyboard.c, as part of the teensy libs
int usb_keyboard_send();
int usb_keymedia_send();

extern uint8_t keyboard_keys[6];
extern uint8_t keyboard_modifier_keys;
extern uint16_t keymedia_consumer_keys[4];

#endif // __LOOP_H
