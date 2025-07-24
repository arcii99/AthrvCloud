//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

void generatePassword(char *password) {
    srand(time(NULL));
    const char *possibleChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{};:',.<>/?";
    int numPossibleChars = strlen(possibleChars);
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int randomIndex = rand() % numPossibleChars;
        password[i] = possibleChars[randomIndex];
    }
    password[PASSWORD_LENGTH] = '\0';
}

int main() {

    char password[PASSWORD_LENGTH + 1];
    generatePassword(password);

    printf("Your secure password is: %s\n", password);

    return 0;
}