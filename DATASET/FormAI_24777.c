//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >='a' && c <= 'z');
}

bool is_numeric(char c) {
    return (c >= '0' && c <= '9');
}

bool is_valid_character(char c) {
    return is_alpha(c) || is_numeric(c);
}

void sanitize_input(char input[], int length) {
    for (int i = 0; i < length; i++) {
        if (!is_valid_character(input[i])) {
            input[i] = '_';
        }
    }
}

void get_user_input(char input[], int max_length) {
    printf("Enter input (alphabets and numbers only): ");
    fgets(input, max_length, stdin);
    int length = strlen(input);
    input[length-1] = '\0'; // remove newline character
    sanitize_input(input, length-1);
}

int main() {
    char input[MAX_LENGTH];
    get_user_input(input, MAX_LENGTH);
    printf("Clean input is: %s\n", input);
    return 0;
}