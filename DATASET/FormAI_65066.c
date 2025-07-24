//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to sanitize user input and remove any special characters
void sanitizeInput(char inputString[], int maxLength) {
    int i;
    for (i = 0; i < maxLength; i++) {
        if (inputString[i] == '\n') {
            inputString[i] = '\0';
            break;
        }
        if (inputString[i] < 32 || inputString[i] > 126) {
            inputString[i] = '_'; // Replace special character with underscore
        }
    }
}

int main() {
    char userInput[MAX_STRING_LENGTH];
    printf("Enter a string of up to %d characters: ", MAX_STRING_LENGTH);
    fgets(userInput, MAX_STRING_LENGTH, stdin);

    sanitizeInput(userInput, MAX_STRING_LENGTH);

    printf("Sanitized input: %s\n", userInput);

    return 0;
}