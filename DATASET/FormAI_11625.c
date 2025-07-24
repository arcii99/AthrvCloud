//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

/**
 * A function to sanitize user input by removing any non-alphanumeric characters
 * and replacing them with spaces.
 */
void sanitize_input(char *input) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }
    }
}

/* main function */
int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* sanitize user input */
    sanitize_input(input);

    printf("Sanitized input: %s\n", input);

    return 0;
}