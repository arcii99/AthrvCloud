//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void sanitize(char input[]) {
    int i, j = 0;
    char sanitized_input[MAX_INPUT_LENGTH];

    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i]) && j < MAX_INPUT_LENGTH - 1) {
            sanitized_input[j] = tolower(input[i]);
            j++;
        } else if (isdigit(input[i]) && j < MAX_INPUT_LENGTH - 1) {
            sanitized_input[j] = input[i];
            j++;
        }
    }

    sanitized_input[j] = '\0';
    strcpy(input, sanitized_input);
}

int main() {
    char user_input[MAX_INPUT_LENGTH];

    printf("Please enter a string to sanitize: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    // Remove trailing newline character
    user_input[strlen(user_input) - 1] = '\0';

    sanitize(user_input);

    printf("\nSanitized string: %s\n", user_input);

    return 0;
}