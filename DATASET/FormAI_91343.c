//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char* sanitizeInput(char* input) {
    char* sanitizedInput = malloc(sizeof(char) * strlen(input) + 1);
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (isalpha(c) || isdigit(c) || isspace(c)) {
            sanitizedInput[j++] = tolower(c);
        }
    }
    sanitizedInput[j] = '\0';
    return sanitizedInput;
}

int main() {
    char userInput[1000];
    printf("Enter your input: ");
    fgets(userInput, 1000, stdin);

    char* sanitizedInput = sanitizeInput(userInput);
    printf("Sanitized Input: %s", sanitizedInput);

    free(sanitizedInput);
    return 0;
}