//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

void sanitize_input(char *input);

int main() {
    char user_input[MAX_INPUT_LENGTH];

    printf("Enter your name: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(user_input);
    printf("Hello, %s!\n", user_input);

    printf("Enter a number: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(user_input);
    int num = atoi(user_input);
    printf("You entered %d.\n", num);

    printf("Enter a search term: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(user_input);
    printf("Searching for '%s'...\n", user_input);

    return 0;
}

void sanitize_input(char *input) {
    int length = strlen(input);

    // Remove trailing newline character
    if (input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }

    // Remove any characters that are not alphanumeric or space
    int i, j;
    for (i = 0, j = 0; i < length; i++) {
        if (isalnum(input[i]) || isspace(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}