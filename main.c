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

Verify the value of the given key.

key - key given by the user

*/
static void check_key_range(int key) {
    // check if the key is not within the given range
    if (!(key >= MIN_KEY_SIZE) || !(key <= MAX_KEY_SIZE)) {
        puts("The key must be within the range of 0 through 25.");
        printf("%s\n %s\n %s", "Usage:", "To encrypt: ./main -e <shift>", "To decrypt: ./main -d <shift>");
        exit(1);
    }
}

/*

check if the program has terminated.

str[MAX_TEXT_LENGTH] - text given by the user (maximum size of 1024 characters)

*/
static void is_terminated(char str[MAX_TEXT_LENGTH]) {
    if (strcmp(str, EXIT) == 0) {
        puts("Program Terminated.");
        exit(0);
    }
}

/*

Display the encrypted message to the user.

*p_str - the pointer to the character array
str_length -  the length of the character array

*/
static void print_encrypted_text(char *p_str, int str_length) {
    printf("%s","Encrypted text: ");
    for (int i = 0; i < str_length; i++) {
        printf("%c", *(p_str + i));
    }
}

/*

Display the decrypted message to the user.

*p_str - the pointer to the character array
str_length -  the length of the character array

*/
static void print_decrypted_text(char *p_str, int str_length) {
    printf("%s","Decrypted text: ");
    for (int i = 0; i < str_length; i++) {
        printf("%c", *(p_str + i));
    }
}

/*

The driver function.

argc - the number of arguments in the command line
*argv - a string representation of the command line arguments

*/
int main(int argc, char *argv[]) {
    char str[MAX_TEXT_LENGTH];
    char* p_str = str;
    
    // check if the key is NULL
    if (argv[2] == NULL) {
        printf("%s\n %s\n %s", "Usage:", "To encrypt: ./main -e <shift>", "To decrypt: ./main -d <shift>");
        exit(1);
    }

    int key = atoi(argv[2]);

    // check if the argument count is correct
    if (argc != ARG_COUNT) {
        printf("%s\n%s%d%s%d.\n", "Incorrect number of arguments. ", "Requires ", ARG_COUNT, " Given ", argc);
        exit(1);
    }

    // check if the key is a non-integer value
    if (key == 0) {
        puts("Invalid key value.");
        printf("%s\n %s\n %s", "Usage:", "To encrypt: ./main -e <shift>", "To decrypt: ./main -d <shift>");
        exit(1);
    }

    check_key_range(key);

    // check if the argument is an encryption flag
    if (strcmp(argv[1], ENCRYPTION) == 0) {
        while (TRUE) {
            printf("%s", "Enter a text: ");
            fgets(str, MAX_TEXT_LENGTH, stdin);
            
            is_terminated(str);

            p_str = encrypt(key, str); 
            
            print_encrypted_text(p_str, findLength(str));
        }
    }

    // check if the argument is a decryption flag
    if (strcmp(argv[1], DECRYPTION) == 0) {
        while (TRUE) {
            printf("%s", "Enter a text: ");
            fgets(str, MAX_TEXT_LENGTH, stdin);
            
            is_terminated(str);
            
            p_str = decrypt(key, str); 
            
            print_decrypted_text(p_str, findLength(str));
        }
    }

    return 0;
}
