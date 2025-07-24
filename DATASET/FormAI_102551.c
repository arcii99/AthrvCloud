//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12

char generateRandomChar() {
    int randNum = rand() % 3;
    char randChar;

    switch (randNum) {
        case 0:
            randChar = rand() % 26 + 'a';
            break;
        case 1:
            randChar = rand() % 26 + 'A';
            break;
        case 2:
            randChar = rand() % 10 + '0';
            break;
    }

    return randChar;
}

int main() {
    srand(time(NULL));

    char password[PASSWORD_LENGTH + 1];
    memset(password, 0, PASSWORD_LENGTH + 1);

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomChar();
    }

    printf("Your secure medieval-style password is: %s", password);

    return 0;
}