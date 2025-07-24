//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH], sanitized_input[MAX_INPUT_LENGTH];
    int i, count = 0;

    printf("Enter input (max length %d): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);

    /* sanitize input */
    for (i = 0; i < MAX_INPUT_LENGTH && input[i] != '\n'; i++) {
        if (isalnum(input[i])) {
            sanitized_input[count++] = input[i];
        }
    }
    sanitized_input[count] = '\0';

    printf("Sanitized input: %s", sanitized_input);

    return 0;
}