/*
 * Author: Morteza Shoeibi <mortezashoeibi77@gmail.com>
 * File: main.ino
 * Description:
		This is an "Arduino ATmega32u4" board program.
        It opens a  fake windows seven update  window,
        And maximizes it.
 * Notes:
		This works only on win7
*/

#include <Keyboard.h>

#define RELEASE_KEYS 100 // milliseconds

void setup() {
	// initialize control over the keyboard
	Keyboard.begin();
}

void loop() {
	delay(5000);
	// open run
	Keyboard.press(KEY_RIGHT_GUI);
	Keyboard.press('r');
	delay(RELEASE_KEYS);
	Keyboard.releaseAll();
	delay(1000);
	// type and hit enter
	Keyboard.println("chrome https://fakeupdate.net/win7/");
	delay(500);
	Keyboard.press(KEY_F11);
	delay(RELEASE_KEYS);
	Keyboard.release(KEY_F11);
	while (1);
}
