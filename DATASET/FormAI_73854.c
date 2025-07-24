//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to sanitize user input
void sanitizeInput(char *input) {
    char sanitizedInput[MAX_LENGTH];
    int index = 0;

    for (int i = 0; i < strlen(input); i++) {
        // If the character is alphanumeric, add it to the sanitized input
        if (isalnum(input[i])) {
            sanitizedInput[index++] = input[i];
        }
    }

    // Add null terminator and copy the sanitized input to the original input buffer
    sanitizedInput[index] = '\0';
    strcpy(input, sanitizedInput);
}

int main() {
    char userInput[MAX_LENGTH];

    printf("Enter some text: ");
    fgets(userInput, MAX_LENGTH, stdin);

    // Remove the newline character from the input buffer
    userInput[strcspn(userInput, "\n")] = '\0';

    // Sanitize the user input
    sanitizeInput(userInput);

    printf("Sanitized User Input: %s\n", userInput);

    return 0;
}