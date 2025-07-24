//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to sanitize the input string
void sanitizeInput(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {
            input[i] = '_';
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter the input string (maximum %d characters allowed): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Sanitize input string
    sanitizeInput(input);

    // Print sanitized input string
    printf("Sanitized input string: %s\n", input);

    return 0;
}