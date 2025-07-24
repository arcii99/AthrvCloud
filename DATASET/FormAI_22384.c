//FormAI DATASET v1.0 Category: Syntax parsing ; Style: automated
#include <stdio.h>

// Function to check if a character is a valid letter or digit
int is_valid_char(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

int main() {
    char input[100];
    int i = 0;
    int state = 0;

    printf("Enter an expression: ");
    fgets(input, 100, stdin);

    while (input[i] != '\0') {
        switch(state) {
            case 0: // Initial state
                if (is_valid_char(input[i])) {
                    state = 1; // Go to the identifier state
                } else if (input[i] == '+' || input[i] == '-') {
                    state = 2; // Go to the operator state
                } else if (input[i] == ' ' || input[i] == '\n') {
                    state = 0; // Stay in the initial state (ignore whitespace)
                } else {
                    printf("Syntax error: unexpected character '%c'\n", input[i]);
                    return 1;
                }
                break;
            case 1: // Identifier state
                if (is_valid_char(input[i])) {
                    state = 1; // Stay in the identifier state
                } else if (input[i] == '+' || input[i] == '-') {
                    state = 2; // Go to the operator state
                } else if (input[i] == ' ' || input[i] == '\n') {
                    state = 0; // Go back to the initial state
                } else {
                    printf("Syntax error: unexpected character '%c'\n", input[i]);
                    return 1;
                }
                break;
            case 2: // Operator state
                if (is_valid_char(input[i])) {
                    state = 1; // Go back to the identifier state
                } else if (input[i] == ' ' || input[i] == '\n') {
                    state = 0; // Go back to the initial state
                } else {
                    printf("Syntax error: unexpected character '%c'\n", input[i]);
                    return 1;
                }
                break;
        }
        i++;
    }

    printf("Syntax check successful!\n");
    return 0;
}