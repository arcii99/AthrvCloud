//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Welcome to the User Input Sanitizer!\n");
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitizeInput(input);
    printf("Your sanitized input is: %s", input);
    return 0;
}

void sanitizeInput(char *input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (iscntrl(input[i])) {
            input[i] = ' ';
        } else if (islower(input[i])) {
            input[i] = toupper(input[i]);
        } else if (ispunct(input[i])) {
            input[i] = ' ';
        }
    }
}