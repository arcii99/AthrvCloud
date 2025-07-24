//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100 // Maximum length of user input

int main() {
    char input[MAX_INPUT_LENGTH]; // User input buffer
    int i;

    // Prompt user to enter some text
    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin); // Get user input

    // Remove any newline character from user input
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';

    // Sanitize user input by removing any non-alphanumeric characters
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) { // If character is not alphanumeric
            memmove(&input[i], &input[i + 1], strlen(input) - i); // Shift the rest of the string over
            i--; // Go back to check the character that was shifted over
        }
    }

    // Display sanitized input to user
    printf("Sanitized input: %s\n", input);

    return 0; // End program
}