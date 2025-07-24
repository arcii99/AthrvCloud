//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main(void) {
    char password[PASSWORD_LENGTH + 1] = {'\0'};

    const char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*";

    const int num_lowercase_letters = sizeof(lowercase_letters) / sizeof(lowercase_letters[0]) - 1;
    const int num_uppercase_letters = sizeof(uppercase_letters) / sizeof(uppercase_letters[0]) - 1;
    const int num_digits = sizeof(digits) / sizeof(digits[0]) - 1;
    const int num_symbols = sizeof(symbols) / sizeof(symbols[0]) - 1;

    srand(time(NULL));

    int i = 0;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int category = rand() % 4;
        switch (category) {
            case 0:
                password[i] = lowercase_letters[rand() % num_lowercase_letters];
                break;
            case 1:
                password[i] = uppercase_letters[rand() % num_uppercase_letters];
                break;
            case 2:
                password[i] = digits[rand() % num_digits];
                break;
            case 3:
                password[i] = symbols[rand() % num_symbols];
                break;
        }
    }

    printf("Your new password is: %s\n", password);

    return 0;
}