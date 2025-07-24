//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitizeInput(char* userInput);

int main() {

    char userInput[MAX_INPUT_LENGTH];
    printf("Enter input: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);

    char* sanitizedInput = sanitizeInput(userInput);
    printf("Sanitized input: %s", sanitizedInput);

    return 0;
}

char* sanitizeInput(char* userInput) {
    char* sanitizedInput = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int i = 0;
    int j = 0;

    // Loop through each character in the user input
    while (userInput[i]) {
        // If the character is alphanumeric, append it to the sanitized input
        if (isalnum(userInput[i])) {
            sanitizedInput[j] = userInput[i];
            j++;
        }
        i++;
    }

    // Add null terminator at the end
    sanitizedInput[j] = '\0';

    return sanitizedInput;
}