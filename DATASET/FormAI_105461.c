//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

bool is_alpha_numeric(char c) {
    return isalnum(c);
}

bool is_valid_input(char c) {
    return is_alpha_numeric(c) || isspace(c) || ispunct(c);
}

char* sanitize_input(char* input) {
    int length = strlen(input);
    char* sanitized_input = malloc(length + 1);
    int index = 0;

    for(int i = 0; i < length; i++) {
        char current_char = input[i];
        bool is_valid = is_valid_input(current_char);
        if(is_valid) {
            sanitized_input[index++] = current_char;
        }
    }

    sanitized_input[index] = '\0';
    return sanitized_input;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter your text: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    char* sanitized_input = sanitize_input(input);
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    return 0;
}