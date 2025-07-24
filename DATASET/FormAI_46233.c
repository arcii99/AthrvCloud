//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    int i, j;

    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    for (i = 0, j = 0; i < strlen(input); i++) {
        // Check if character is alphanumeric
        if (isalnum(input[i])) {
            // Sanitize uppercase characters
            if (isupper(input[i])) {
                input[j++] = tolower(input[i]);
            } else {
                input[j++] = input[i];
            }
        }
        // Check for spaces and hyphens
        else if (input[i] == ' ' || input[i] == '-') {
            input[j++] = '_';
        }
    }

    // Insert null character at end of sanitized input
    input[j] = '\0';

    printf("Sanitized input: %s\n", input);

    return 0;
}