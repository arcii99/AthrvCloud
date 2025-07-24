//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

bool is_valid_input(char c);
void sanitize_input(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    sanitize_input(input);
    
    printf("Your sanitized input is: %s\n", input);
    
    return 0;
}

bool is_valid_input(char c) {
    if (isalnum(c) || isspace(c)) {
        return true;
    }
    return false;
}

void sanitize_input(char *input) {
    char *current = input;
    
    while (*current != '\0') {
        if (!is_valid_input(*current)) {
            *current = ' ';
        }
        current++;
    }
}