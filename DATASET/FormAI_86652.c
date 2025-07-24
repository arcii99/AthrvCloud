//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Please enter a string of text to be sanitized: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(input);

    printf("Sanitized input: %s", input);

    return 0;
}

void sanitizeInput(char *input) {
    int i, j;
    char sanitized_input[MAX_INPUT_LENGTH];

    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            sanitized_input[j++] = input[i];
        }
    }
    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
}