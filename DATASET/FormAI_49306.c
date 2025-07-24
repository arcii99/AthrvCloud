//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 // Maximum string length

void sanitizeInput(char inputString[], char sanitizedString[]);

int main() {
    char inputString[MAX_SIZE];
    char sanitizedString[MAX_SIZE];

    // Get user input
    printf("Enter input string: ");
    fgets(inputString, MAX_SIZE, stdin);

    // Remove trailing newline character from input string
    inputString[strcspn(inputString, "\n")] = 0;

    // Sanitize user input
    sanitizeInput(inputString, sanitizedString);

    // Print sanitized input
    printf("Sanitized input: %s\n", sanitizedString);

    return 0;
}

// Sanitize user input by removing non-alphanumeric characters and converting to lowercase
void sanitizeInput(char inputString[], char sanitizedString[]) {
    int i, j;

    for (i = 0, j = 0; i < strlen(inputString); i++) {
        if (isalnum(inputString[i])) { // Keep alphanumeric characters
            sanitizedString[j] = tolower(inputString[i]); // Convert to lowercase
            j++;
        }
    }

    sanitizedString[j] = '\0'; // Add terminating null character
}