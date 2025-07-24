//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

char* generatePassword() {
    const char alphaNumeric[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int length = strlen(alphaNumeric);
    char* password = malloc(PASSWORD_LENGTH + 1);

    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = alphaNumeric[rand() % length];
    }

    password[PASSWORD_LENGTH] = '\0';

    return password;
}

int containsUpperCase(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int containsLowerCase(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int containsNumber(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char* password = generatePassword();

    while (!(containsUpperCase(password) && containsLowerCase(password) && containsNumber(password))) {
        free(password);
        password = generatePassword();
    }

    printf("Your shiny new password is: %s\n", password);

    free(password);
    return 0;
}