//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ATTEMPTS 3
#define MAX_INPUT_LENGTH 100

void generateRandomString(char *randomStr, int length) {
    time_t t;
    srand((unsigned) time(&t));

    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    for (i = 0; i < length; i++) {
        int index = rand() % (int) (strlen(charset));
        randomStr[i] = charset[index];
    }
    randomStr[i] = '\0';
}

int main() {
    int testLength = 10;
    char randomString[MAX_INPUT_LENGTH];
    generateRandomString(randomString, testLength);

    printf("Type the following string and hit enter:\n%s\n", randomString);

    char userInput[MAX_INPUT_LENGTH];
    fgets(userInput, MAX_INPUT_LENGTH, stdin);

    int attempts = 1;
    while (strcmp(userInput, randomString) != 0 && attempts < MAX_ATTEMPTS) {
        printf("\nIncorrect input, please try again. You have %d attempt(s) remaining.\n", MAX_ATTEMPTS - attempts);
        fgets(userInput, MAX_INPUT_LENGTH, stdin);
        attempts++;
    }

    if (strcmp(userInput, randomString) == 0) {
        printf("\nCongratulations, you typed the correct string!\n");
    } else {
        printf("\nSorry, you failed to type the correct string within the given attempts.\n");
    }

    return 0;
}