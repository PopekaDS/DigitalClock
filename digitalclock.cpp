/*
try:
    while True:  # Main program loop.

except KeyboardInterrupt:
    print('Digital Clock, by Al Sweigart al@inventwithpython.com')
    sys.exit()  # When Ctrl-C is pressed, end the program.

*/

// Digital Clock, by Al Sweigart al@inventwithpython.com
// Displays a digital clock of the current time with a seven - segment
// More info at https ://en.wikipedia.org/wiki/Seven-segment_display
// Requires sevseg.py to be in the same folder.
// This code is available at https ://nostarch.com/big-book-small-python-programming

#include <iostream>
#include <string>
#include <ctime>
#include "sevseg.h"
#include "windows.h"
using namespace std;

int main() {
    while (true) { // Main program loop.
        // Clear the screen by printing several newlines:
        for (int i = 0; i < 60; ++i)
            cout << '\n';

        // Get the current time from the computer's clock:
        time_t now = time(0);
        tm* ltm = localtime(&now);

        // % 12 so we use a 12-hour clock, not 24:
        string hours = to_string(ltm->tm_hour % 12);
        if (hours == "0") {
            hours = "12"; // 12-hour clocks show 12:00, not 00:00.
        }
        string minutes = to_string(ltm->tm_min);
        string seconds = to_string(ltm->tm_sec);

        // Get the digit strings from the sevseg module:
        string up = "", middle = "", down = "";
        getSevSegStr(hours, up, middle, down, 2, "*");
        getSevSegStr(minutes, up, middle, down, 2, "*");
        getSevSegStr(seconds, up, middle, down, 2);

        // Display the digits:
        cout << up << '\n';
        cout << middle << '\n';
        cout << down << '\n';
        cout << "\nPress Ctrl-C to quit.\n";
        Sleep(1000);
    }

    return 0;
}

// Добавить обработку нажатия Ctrl + C
// Добавить решение проблемы localtime