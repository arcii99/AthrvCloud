//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

void sanitize_input(char* input);

int main()
{
    char input[MAX_INPUT_SIZE];
    printf("Please enter your sensitive information: ");
    fgets(input, MAX_INPUT_SIZE, stdin); //get user input including whitespace
    sanitize_input(input);
    printf("Your sanitized input is: %s\n", input);

    return 0;
}

void sanitize_input(char* input)
{
    // Remove newline character if present
    if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Loop through each character in input
    for (int i = 0; i < strlen(input); i++) {
        // If character is a digit or letter, continue
        if (isdigit(input[i]) || isalpha(input[i])) {
            continue;
        }
        // Otherwise, replace character with an asterisk
        input[i] = '*';
    }
}