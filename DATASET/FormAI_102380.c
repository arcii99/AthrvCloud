//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Cyberpunk User Input Sanitizer!\n");

    char input[256];
    char sanitized[256];
    int length;

    printf("Please enter your input:\n");
    fgets(input, sizeof(input), stdin);

    length = strlen(input);

    for (int i = 0; i < length; i++) {
        if (input[i] == '<' || input[i] == '>') {
            sanitized[i] = '*';
        } else if (input[i] == '(' || input[i] == ')') {
            sanitized[i] = '+';
        } else if (input[i] == '{' || input[i] == '}') {
            sanitized[i] = '-';
        } else if (input[i] == '[' || input[i] == ']') {
            sanitized[i] = '/';
        } else if (input[i] == '\'') {
            sanitized[i] = '\"';
        } else if (input[i] == '\"') {
            sanitized[i] = '\'';
        } else if (input[i] == '.') {
            sanitized[i] = ',';
        } else if (input[i] == '_') {
            sanitized[i] = '|';
        } else if (input[i] == '/') {
            sanitized[i] = '\\';
        } else {
            sanitized[i] = input[i];
        }
    }

    printf("\nOriginal input: %s", input);
    printf("Sanitized input: %s", sanitized);

    printf("\nThank you for using the Cyberpunk User Input Sanitizer!\n");
    return 0;
}