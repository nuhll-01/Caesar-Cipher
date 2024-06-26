#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_COUNT 3
#define MAX_TEXT_LENGTH 1024
#define MIN_KEY_SIZE 0
#define MAX_KEY_SIZE 25
#define TRUE 1
#define ENCRYPTION "-e"
#define DECRYPTION "-d"
#define EXIT "exit\n"

char* encrypt(int key, char str[]);
char* decrypt(int key, char str[]);
int findLength(char str[]);