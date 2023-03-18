/* 
 * Author: Morteza Shoeibi <mortezashoeibi77@gmail.com>
 * File: main.ino
 * Description:
        This is an "Arduino ATmega32u4" board program. 
        It downloads the following file and set it as
        The connected device wallpaper.
        https://github.com/MortezaShoeibi/Arduino-Scripts/blob/master/assets/sunglasses-in-the-dark.jpg
 * Notes:
        This works only on win10
*/


#include <Keyboard.h>

#define RELEASE_KEYS 100 // milliseconds


void setup() {
    // initialize control over the keyboard
    Keyboard.begin();
}

void loop() {
    delay(3000);
    // open run
    Keyboard.press(KEY_RIGHT_GUI);
    Keyboard.press('r');
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(1000);
    // type and hit enter
    // NOTE: change the link to your photo
    Keyboard.println("chrome https://github.com/MortezaShoeibi/Arduino-Scripts/blob/master/assets/sunglasses-in-the-dark.jpg");
    delay(4000);
    // save the image
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('s');
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(2000);
    Keyboard.println("%USERPROFILE%\\sunglasses-in-the-dark.jpg");
    delay(2000);
    // close window
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('w');
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(3000);
    // open paint
    Keyboard.press(KEY_LEFT_GUI);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(2000);
    Keyboard.println("paint");
    delay(5000);
    // open image in paint
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('o');
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(3000);
    Keyboard.println("%USERPROFILE%\\sunglasses-in-the-dark.jpg");
    delay(4000);
    // set as wallpaper
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('f');
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(3000);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_TAB);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    delay(500);
    Keyboard.press(KEY_RETURN);
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    // close paint
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('w');
    delay(RELEASE_KEYS);
    Keyboard.releaseAll();
    while(1);
}
