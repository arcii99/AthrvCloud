//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
// Welcome to the C Syntax Parsing program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of input string
#define MAX_INPUT_SIZE 256

// Define accepted tokens
typedef enum {
    TOKEN_EMPTY,
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_L_BRACKET,
    TOKEN_R_BRACKET,
    TOKEN_ERROR
} token_type;

// Define a token struct
typedef struct {
    token_type type;
    char value[MAX_INPUT_SIZE];
} token;

// Define the main function
int main() {
    // Initialize input buffer
    char input[MAX_INPUT_SIZE];
    memset(input, 0, MAX_INPUT_SIZE);

    // Prompt user for input
    printf("Enter an arithmetic expression: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Initialize token buffer
    token tokens[MAX_INPUT_SIZE];
    memset(tokens, 0, sizeof(tokens));

    // Initialize token index
    int token_index = 0;

    // Parse input string
    for (int i = 0; i < strlen(input); i++) {
        char current_char = input[i];

        // Check for whitespace
        if (current_char == ' ') {
            continue;
        }

        // Parse integer or float
        if (isdigit(current_char) || current_char == '.') {
            token_type type = TOKEN_INT;
            char value[MAX_INPUT_SIZE];
            memset(value, 0, MAX_INPUT_SIZE);

            // Parse integer or float
            int value_index = 0;
            while (isdigit(input[i]) || input[i] == '.') {
                value[value_index] = input[i];
                i++;
                value_index++;
            }

            // Check for floating point
            if (strchr(value, '.') != NULL) {
                type = TOKEN_FLOAT;
            }

            // Add token to buffer
            strncpy(tokens[token_index].value, value, strlen(value));
            tokens[token_index].type = type;
            token_index++;

            // Continue to next iteration of loop
            continue;
        }

        // Parse operators and brackets
        switch (current_char) {
            case '+':
                tokens[token_index].type = TOKEN_PLUS;
                token_index++;
                break;
            case '-':
                tokens[token_index].type = TOKEN_MINUS;
                token_index++;
                break;
            case '*':
                tokens[token_index].type = TOKEN_MULTIPLY;
                token_index++;
                break;
            case '/':
                tokens[token_index].type = TOKEN_DIVIDE;
                token_index++;
                break;
            case '(':
                tokens[token_index].type = TOKEN_L_BRACKET;
                token_index++;
                break;
            case ')':
                tokens[token_index].type = TOKEN_R_BRACKET;
                token_index++;
                break;
            default:
                tokens[token_index].type = TOKEN_ERROR;
                token_index++;
                break;
        }
    }

    // Print out tokens
    printf("Parsed Tokens:\n");
    for (int i = 0; i < token_index; i++) {
        printf("[%d]: %s\n", i, tokens[i].value);
    }

    // Exit program
    return 0;
}