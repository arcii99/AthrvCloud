//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

char *sanitize_input(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    char *sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}

char *sanitize_input(char *input) {
    char *sanitized = malloc(MAX_INPUT_LENGTH * sizeof(char));
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            sanitized[j] = toupper(input[i]);
            j++;
        }
    }
    return sanitized;
}