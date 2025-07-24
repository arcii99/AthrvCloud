//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: secure
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char* input);

int main() {
    printf("Enter your input: ");
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Sanitized input: %s\n", input);
    return 0;
}

void sanitizeInput(char* input) {
    int i;
    int len = strlen(input);
    int sanitizedIndex = 0;
    char sanitizedInput[MAX_INPUT_LENGTH];
    for (i = 0; i < len; i++) {
        char c = input[i];
        if (isalnum(c)) {
            sanitizedInput[sanitizedIndex] = c;
            sanitizedIndex++;
        }
    }
    if (sanitizedIndex == 0) {
        // If all characters are invalid, replace input with empty string
        input[0] = '\0';
    } else {
        // Ensure null termination of sanitizedInput to copy back to input
        sanitizedInput[sanitizedIndex] = '\0';
        strncpy(input, sanitizedInput, MAX_INPUT_LENGTH);
    }
}