//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a token
typedef struct Token {
    char* type;
    char* value;
} Token;

// Define a function to create a new token
Token* newToken(char* type, char* value) {
    Token* token = malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

// Define a function to tokenize a C program string
Token** tokenize(char* program) {
    Token** tokens = malloc(sizeof(Token*) * strlen(program));
    int numTokens = 0;

    // Define the keywords and operators to look for
    char* keywords[10] = {"int", "char", "float", "double", "if", "else", "for", "while", "break", "return"};
    char* operators[6] = {";", "{", "}", "(", ")", ","};

    // Start tokenizing the program
    char* tokenType = NULL;
    char* tokenValue = NULL;
    while (*program) {
        if (*program == ' ' || *program == '\n' || *program == '\r' || *program == '\t') {
            // Skip whitespace characters
        } else if (*program >= '0' && *program <= '9') {
            // Tokenize numbers
            tokenType = "number";
            tokenValue = malloc(sizeof(char) * strlen(program));
            int i = 0;
            while (*program >= '0' && *program <= '9') {
                tokenValue[i++] = *program++;
            }
            tokenValue[i] = '\0';
        } else if ((*program >= 'a' && *program <= 'z') || (*program >= 'A' && *program <= 'Z')) {
            // Tokenize keywords and variable names
            tokenType = "identifier";
            tokenValue = malloc(sizeof(char) * strlen(program));
            int i = 0;
            while ((*program >= 'a' && *program <= 'z') || (*program >= 'A' && *program <= 'Z')) {
                tokenValue[i++] = *program++;
            }
            tokenValue[i] = '\0';

            // Check if the token is a keyword
            for (int j = 0; j < 10; j++) {
                if (strcmp(tokenValue, keywords[j]) == 0) {
                    tokenType = "keyword";
                    break;
                }
            }
        } else {
            // Tokenize operators
            tokenType = "operator";
            tokenValue = malloc(sizeof(char) * 2);
            tokenValue[0] = *program++;
            tokenValue[1] = '\0';
            
            // Check if the token is a multi-character operator
            if ((*program == '<' || *program == '>' || *program == '=') && *(program + 1) == '=') {
                tokenValue[1] = *++program;
                tokenValue[2] = '\0';
            }
        }

        // Create a new token
        tokens[numTokens++] = newToken(tokenType, tokenValue);
    }
    tokens[numTokens] = NULL;

    return tokens;
}

// Define a function to print out the tokens
void printTokens(Token** tokens) {
    for (int i = 0; tokens[i]; i++) {
        printf("{type: %s, value: %s}\n", tokens[i]->type, tokens[i]->value);
    }
}

int main() {
    char* program = "int main() {\nint x = 1;\nif (x == 1) {\nprintf(\"Hello, world!\\n\");\n}\nreturn 0;\n}";
    Token** tokens = tokenize(program);
    printTokens(tokens);
    return 0;
}