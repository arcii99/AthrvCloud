//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50

// Function to sanitize the user input
char* sanitize_input(char* input) {
    int length = strlen(input);
    char* sanitized_input = (char*)malloc(sizeof(char) * (length + 1)); // Allocate memory for the new sanitized string

    // Copy over only valid characters to the sanitized string
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (isalnum(input[i])) {
            sanitized_input[index++] = input[i];
        }
    }
    sanitized_input[index] = '\0'; // Add null terminator to the end of the sanitized string

    return sanitized_input;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a string to sanitize: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character from the end of input

    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);

    free(sanitized_input); // Free the memory allocated for the sanitized string

    return 0;
}