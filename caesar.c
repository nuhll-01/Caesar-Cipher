/*************************************************************************************
*                                                                                    *
* Author: Erick Chavez                                                               *
* Created: June 22, 2024                                                             *
*                                                                                    *
* A program that utilizes the Caesar Cipher algorithm for plain-text                 *
* encryption and decryption.                                                         *
*                                                                                    *
* References/Citations:                                                              *
*   - https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html               *
*   - https://stackoverflow.com/questions/66213496/understanding-fgets-function-in-c *
*   - https://www.geeksforgeeks.org/fgets-gets-c-language/                           *
*   - https://stackoverflow.com/questions/40605075/how-to-compare-2-character-arrays *
*   - https://stackoverflow.com/questions/15485179/how-to-check-if-c-string-is-empty *
*   - https://www.calculatorsoup.com/calculators/math/modulo-calculator.php          *
**************************************************************************************/

#include "caesar.h"

/*

Return the cipher key.

ciph_key - the key for encryption and decryption 


*/
static int get_key(int ciph_key) {
    int encryption_key =  ciph_key;
    return encryption_key;
}

/*

Finds and returns the length of a given character array.

str[] - the given character array to iterate through.
*/
int findLength(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}

/*

Encrypt a given character array using the Caesar Cipher algorithm.

key - N number of times to shift the character values. (right-shift)
str[] - the given character array to cipher. 

returns an encrypted character array.

*/
char* encrypt(int key, char str[]) {

    // Iterate through the character array
    for (int i = 0; i < findLength(str); i++) {

        /* 

        Enabling this line of code below will omit the ASCII Code 10 from the output.
        It's up to you (the programmer) to determine whether or not you need the functionality.

        if (str[i] == 10) { continue; }

        */

        // Determine if we're in the valid range to shift characters
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            
            // Shift N number of times
            str[i] = str[i] + get_key(key);

            // Wrap around if within the specified range
            if (str[i] > 90 && str[i] < 97) {
                int difference = str[i] - 90;
                str[i] = difference + (145 % 80) - 1;
            }

            // Handle integer overflow
            if (str[i] < 0) {
                int x = str[i] + 127;
                x = x + 127;
                x = (x - 25) + 1;
                str[i] = x;
            }

            // Wrap around if we exceed 122
            if (str[i] > 122) {
                int y = str[i] - 122;
                str[i] = y + (197 % 100) - 1;
            }
        }
    }
    
    return str;
}

/*

Decrypt a given character array using the Caesar Cipher algorithm.

key - N number of times to shift the character values. (left-shift)
str[] - the given character array to decipher. 

returns an decrypted character array.

*/
char* decrypt(int key, char str[]) { 
    
    // Iterate through the character array
    for (int i = 0; i < findLength(str); i++) {

        // Determine if we're in the valid range to shift characters
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {

            // Shift N number of times (this time we go backwards)
            str[i] = str[i] - get_key(key);

            // wrap around if we're between the specified range 
            if (str[i] > 90 && str[i] < 97) {
                int difference = str[i] - 97;
                str[i] = (247 % 125);
                str[i] = (str[i] + difference) + 1;
            }

            // wrap around if we're in the specified range
            if (str[i] > 0 && str[i] < 65) { 
                int x = str[i] - 65;
                str[i] = (90 % 160);
                str[i] = (str[i] + x) + 1;
            }
        }
    }

    return str;
}
