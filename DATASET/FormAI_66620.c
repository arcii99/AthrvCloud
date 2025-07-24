//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100 // maximum length of user input string

char* sanitizeInput(char* userInput) {
    char* cleanInput = (char*) malloc((MAX_INPUT_LENGTH + 1) * sizeof(char)); // allocate memory for clean input string
    int i, j;
    for (i = 0, j = 0; i < strlen(userInput); i++) {
        if (isalnum(userInput[i])) { // if character is alphanumeric
            cleanInput[j++] = tolower(userInput[i]); // add lowercase character to clean input string
        }
    }
    cleanInput[j] = '\0'; // add null character to end of clean input string
    return cleanInput;
}

int main() {
    char userInput[MAX_INPUT_LENGTH + 1]; // allocate memory for user input string
    printf("Please enter a sentence: ");
    fgets(userInput, MAX_INPUT_LENGTH + 1, stdin); // get user input from console
    char* cleanInput = sanitizeInput(userInput);
    printf("Cleaned Input: %s\n", cleanInput);
    free(cleanInput); // free memory used by clean input string
    return 0;
}