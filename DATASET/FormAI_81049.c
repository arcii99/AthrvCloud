//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This is a User Input Sanitizer program that removes any invalid characters from user input and converts
 * it to lowercase. The program also ensures that the input is not longer than 100 characters.
 */

int main() {
    char input[101];    // User input buffer
    char sanitized[101];    // Sanitized input buffer
    int i;

    printf("Enter your input: ");
    fgets(input, 101, stdin);   // Get user input
    fflush(stdin);

    // Remove invalid characters and convert to lowercase
    for (i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            sanitized[i] = tolower(input[i]);
        }
    }

    // If length of sanitized input is longer than 100 characters, terminate program
    if (strlen(sanitized) > 100) {
        printf("Input too long. Terminating program.");
        return 1;
    }

    // Print sanitized input
    printf("Sanitized input: %s", sanitized);

    return 0;
}