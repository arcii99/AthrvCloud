//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

char* sanitize_input(char* input);

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}

char* sanitize_input(char* input) {
    char* sanitized_input = malloc(MAX_INPUT_LENGTH);
    int sanitized_index = 0;
    for (int i = 0; i < strlen(input); i++) {
        char current_char = input[i];
        if (isalpha(current_char) || isdigit(current_char) || isspace(current_char)) {
            sanitized_input[sanitized_index] = current_char;
            sanitized_index++;
        }
    }
    sanitized_input[sanitized_index] = '\0';
    return sanitized_input;
}