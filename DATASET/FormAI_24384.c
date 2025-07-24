//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 50

void sanitizeInput(char* input);
void clearBuffer();

int main() {
    char userInput[MAX_INPUT_LENGTH];

    printf("Enter a string: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(userInput);

    printf("Sanitized Input: %s\n", userInput);

    return 0;
}

void sanitizeInput(char* input) {
    // Remove any trailing newline characters
    size_t len = strlen(input);
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }

    char sanitizedInput[MAX_INPUT_LENGTH];
    int i = 0;
    int index = 0;
    bool ignoreSpace = false;

    // Remove leading whitespace
    while (isspace(input[i])) {
        i++;
    }

    // Sanitize input
    while (input[i] != '\0' && index < MAX_INPUT_LENGTH-1) {
        if (!isalnum(input[i])) {
            // Ignore consecutive spaces or non-alphanumeric characters
            if (ignoreSpace) {
                i++;
                continue;
            }

            // Replace non-alphanumeric characters with a space
            sanitizedInput[index] = ' ';
            ignoreSpace = true;
        } else {
            // Convert all alphanumeric characters to lowercase
            sanitizedInput[index] = tolower(input[i]);
            ignoreSpace = false;
        }

        i++;
        index++;
    }

    // Remove trailing whitespace
    while (index > 0 && isspace(sanitizedInput[index-1])) {
        index--;
    }

    // Null-terminate the sanitized input string
    sanitizedInput[index] = '\0';

    // Copy the sanitized input string back to the original input buffer
    strncpy(input, sanitizedInput, MAX_INPUT_LENGTH);
}

void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Discard the input buffer
    }
}