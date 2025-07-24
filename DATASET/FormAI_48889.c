//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// The maximum length of the secure password
#define MAX_LEN 25

// The minimum length of the secure password
#define MIN_LEN 8

// The total number of allowed characters
#define TOT_CHARS 94

// The array containing the allowed characters
char allowedChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                       'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                       'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
                       'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                       'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                       'y', 'z', ' ', '!', '"', '#', '$', '%', '&', '\'',
                       '(', ')', '*', '+', ',', '-', '.', '/', ':', ';',
                       '<', '=', '>', '?', '@', '[', '\\', ']', '^', '_',
                       '`', '{', '|', '}', '~'};

// Function to generate a secure password
void generatePassword(char *password) {
    srand(time(NULL));
    int len = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
    bool symbol = false, digit = false, upper = false, lower = false, space = false;

    for (int i = 0; i < len; i++) {
        int index = rand() % TOT_CHARS;
        password[i] = allowedChars[index];

        if (password[i] >= '0' && password[i] <= '9') {
            digit = true;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = true;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower = true;
        } else if (password[i] == ' ') {
            space = true;
        } else {
            symbol = true;
        }
    }

    if (!symbol) {
        password[rand() % len] = allowedChars[rand() % 31 + 62];
    }

    if (!digit) {
        password[rand() % len] = allowedChars[rand() % 10];
    }

    if (!upper) {
        password[rand() % len] = allowedChars[rand() % 26 + 10];
    }

    if (!lower) {
        password[rand() % len] = allowedChars[rand() % 26 + 36];
    }

    if (!space) {
        password[rand() % len] = ' ';
    }

    password[len] = '\0';
}

int main() {
    char password[MAX_LEN + 1];
    generatePassword(password);
    printf("Your secure password is: %s\n", password);
    return 0;
}