//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

// function to generate a random string of characters
char *generateRandomString(int length) {
    char *randomString = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        randomString[i] = (rand() % 26) + 'a';
    }
    randomString[length] = '\0';
    return randomString;
}

int main() {
    int charactersTyped = 0; // to keep track of number of characters typed
    int incorrectCharacters = 0; // to keep track of number of incorrect characters typed
    clock_t startTime, endTime; // to keep track of time taken to complete the test
    double timeTaken; // to store the time taken as a double value
    char *randomText = generateRandomString(MAX_STRING_LENGTH); // generate random string of characters
    printf("Type the following text as fast as you can:\n\n%s\n", randomText);
    startTime = clock(); // get the current time
    char inputText[MAX_STRING_LENGTH];
    fgets(inputText, MAX_STRING_LENGTH, stdin); // get user input
    endTime = clock(); // get the time after user input is received
    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC; // calculate time taken
    int i;
    for (i = 0; i < MAX_STRING_LENGTH; i++) {
        charactersTyped++;
        if (inputText[i] == '\0') {
            break; // get out of loop if end of string is reached
        }
        if (inputText[i] != randomText[i]) {
            incorrectCharacters++;
        }
    }
    printf("\nYou typed %d characters in %.2f seconds.\n", charactersTyped, timeTaken);
    int accuracy = (int)(((double)(charactersTyped - incorrectCharacters) / (double)charactersTyped) * 100); // calculate accuracy percentage
    printf("Accuracy: %d%%\n", accuracy);
    return 0;
}