//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitizeInput(char *input) {
    int i, j = 0;
    char sanitized_input[MAX_INPUT_LENGTH];
    for (i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            sanitized_input[j++] = input[i];
        }
        if (j == MAX_INPUT_LENGTH - 1) { // ensure the output won't be too long
            break;
        }
    }
    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sanitizeInput(input);

    printf("Sanitized input: %s", input);

    return 0;
}