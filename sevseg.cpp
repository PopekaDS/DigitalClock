// Sevseg, by Al Sweigart
// A seven-segment number display module, used by the Countdown and Digital
// Clock programs.
// This code is available at https://nostarch.com/big-book-small-python-programming
// #64 SEVEN-SEGMENT DISPLAY MODULE

/*

A labeled seven-segment display, with each segment labeled A to G:
 __A__
|     |    Each digit in a seven-segment display:
F     B     __       __   __        __   __  __   __   __
|__G__|    |  |   |  __|  __| |__| |__  |__    | |__| |__|
|     |    |__|   | |__   __|    |  __| |__|   | |__|  __|
E     C
|__D__|

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getSevSegStr(std::string number, std::string& up, std::string& middle, std::string& down, int minWidth = 0, std::string between = " ") {

    while (number.size() < minWidth) {
        number = "0" + number;
    }
    
    vector <string> rows = { "", "", "" };
    
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] == '.') { // Render the decimal point.
            rows[0] += " ";
            rows[1] += " ";
            rows[2] += ".";
            continue; // Skip the space in between digits.
        } else if (number[i] == '-') { // Render the negative sign :
            rows[0] += "    ";
            rows[1] += " __ ";
            rows[2] += "    ";
        } else if (number[i] == '0') { // Render the 0.
            rows[0] += " __ ";
            rows[1] += "|  |";
            rows[2] += "|__|";
        } else if (number[i] == '1') { // Render the 1.
            rows[0] += "    ";
            rows[1] += "   |";
            rows[2] += "   |";
        } else if (number[i] == '2') { // Render the 2.
            rows[0] += " __ ";
            rows[1] += " __|";
            rows[2] += "|__ ";
        } else if (number[i] == '3') { // Render the 3.
            rows[0] += " __ ";
            rows[1] += " __|";
            rows[2] += " __|";
        } else if (number[i] == '4') { // Render the 4.
            rows[0] += "    ";
            rows[1] += "|__|";
            rows[2] += "   |";
        } else if (number[i] == '5') { // Render the 5.
            rows[0] += " __ ";
            rows[1] += "|__ ";
            rows[2] += " __|";
        } else if (number[i] == '6') { // Render the 6.
            rows[0] += " __ ";
            rows[1] += "|__ ";
            rows[2] += "|__|";
        } else if (number[i] == '7') { // Render the 7.
            rows[0] += " __ ";
            rows[1] += "   |";
            rows[2] += "   |";
        } else if (number[i] == '8') { // Render the 8.
            rows[0] += " __ ";
            rows[1] += "|__|";
            rows[2] += "|__|";
        } else if (number[i] == '9') { // Render the 9.
            rows[0] += " __ ";
            rows[1] += "|__|";
            rows[2] += " __|";
        }
        
        // Add a space(for the space in between numerals) if this
        // isn't the last numeral and the decimal point isn't next:
        if (i != number.size() - 1 && number[i + 1] != '.') {
            rows[0] += " ";
            rows[1] += " ";
            rows[2] += " ";
        }
    }
    
    up = up + rows[0] + "   ";
    middle = middle + rows[1] + " " + between + " ";
    down = down + rows[2] + " " + between + " ";
}
