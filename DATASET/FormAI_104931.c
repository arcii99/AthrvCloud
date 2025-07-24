//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeString(char *input);

int main() {
    char userInput[MAX_INPUT_LENGTH];

    printf("Enter your input: ");
    fgets(userInput, MAX_INPUT_LENGTH, stdin);

    // Remove any newline characters at the end of input
    if (userInput[strlen(userInput) - 1] == '\n') {
        userInput[strlen(userInput) - 1] = '\0';
    }

    sanitizeString(userInput);

    printf("Your sanitized input is: %s\n", userInput);

    return 0;
}

void sanitizeString(char *input) {
    int i, j = 0;
    char temp[MAX_INPUT_LENGTH];

    for (i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            temp[j] = input[i];
            j++;
        }
    }

    // Add null terminator to end of sanitized string
    temp[j] = '\0';

    // Copy sanitized string back into input string
    strcpy(input, temp);
}