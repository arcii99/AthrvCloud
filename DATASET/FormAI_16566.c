//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000 // Maximum length for user input

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get input from user

    // Remove trailing newline character from input
    int input_length = strlen(input);
    if (input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
    }

    // Remove leading and trailing whitespaces from input
    char *trimmed_input = input;
    int i = 0, j = strlen(trimmed_input) - 1;
    while (isspace(trimmed_input[i])) {
        i++;
    }
    while (j > i && isspace(trimmed_input[j])) {
        trimmed_input[j--] = '\0';
    }
    trimmed_input += i;

    // Check if input contains any invalid characters
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_=+[]{};:'\"\\|,<.>/? ";
    for (int i = 0; i < strlen(trimmed_input); i++) {
        if (!strchr(allowed_chars, trimmed_input[i])) {
            printf("Invalid character found: %c", trimmed_input[i]);
            return 1;
        }
    }

    // Print sanitized input
    printf("Sanitized input: %s", trimmed_input);
    return 0;
}