//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

char* sanitizeInput(char *input);

int main() {
    char input[MAX_LENGTH];
    printf("Enter your input: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // removes newline character from input

    char *sanitizedInput = sanitizeInput(input);
    printf("Sanitized input: %s\n", sanitizedInput);
    free(sanitizedInput); // free dynamically allocated memory

    return 0;
}

char* sanitizeInput(char *input) {
    char *sanitizedInput = malloc(MAX_LENGTH);
    int i, j = 0;

    for(i = 0; input[i] != '\0'; ++i) {
        if(isalnum(input[i])) { // checks if character is alphanumeric
            sanitizedInput[j++] = tolower(input[i]); // converts to lowercase and adds to sanitized input
        }
    }
    sanitizedInput[j] = '\0'; // adds null terminator to sanitized input

    return sanitizedInput;
}