/* 
 * Author: Morteza Shoeibi <mortezashoeibi77@gmail.com>
 * File: main.ino
 * Description:
        This is an "Arduino ATmega32u4" board program.
 * Note: 
        This script works only on win10
*/


#include <Keyboard.h>

#define RELEASE_KEYS 100 // milliseconds

// press and release a key
void press1key(int _key) {
    Keyboard.press(_key);
    delay(RELEASE_KEYS);
    Keyboard.release(_key);
}

// press and release two keys
void press2keys(int _1key, int _2key) {
    Keyboard.press(_1key);
    Keyboard.press(_2key);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
}



// main functions

void setup() {
    // initialize control over the keyboard
    Keyboard.begin();
}

void loop() {
    delay(5000);
    // open run
    press2keys(KEY_LEFT_GUL, 'r');
    delay(500);

    while(1);
}
