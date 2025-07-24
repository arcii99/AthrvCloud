//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256

void sanitize_input(char* input) {
    char *p = input;
    while (*input) {
        if (*input != '\n' && *input != '\r' && *input != '\t') {
            if (*input >= 'a' && *input <= 'z') {
                *p++ = *input - 32;
            } else {
                *p++ = *input;
            }
        }
        input++;
    }
    *p = '\0';
}

int main() {

    char input[MAX_INPUT_SIZE];
    printf("Enter your input: ");

    if (fgets(input, MAX_INPUT_SIZE, stdin)) {
        sanitize_input(input);
        printf("Sanitized input: %s", input);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}