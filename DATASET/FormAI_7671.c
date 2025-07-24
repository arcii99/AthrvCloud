//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* token_type;
    char* literal;
} Token;

Token* tokens;
int token_index = 0;
char* input;

void tokenize(char* input) {
    tokens = (Token*) malloc(strlen(input) * sizeof(Token));
    int index = 0;

    while (input[index] != '\0') {
        if (input[index] == '(') {
            tokens[token_index].token_type = "LPAREN";
            tokens[token_index].literal = "(";
            token_index++;
        } else if (input[index] == ')') {
            tokens[token_index].token_type = "RPAREN";
            tokens[token_index].literal = ")";
            token_index++;
        }
        index++;
    }

    tokens[token_index].token_type = "EOF";
    tokens[token_index].literal = "";
}

void program() {
    if (strcmp(tokens[token_index].token_type, "LPAREN") == 0) {
        printf("%s\n", tokens[token_index].literal);
        token_index++;
        program();
    } else if (strcmp(tokens[token_index].token_type, "RPAREN") == 0) {
        printf("%s\n", tokens[token_index].literal);
        token_index++;
        program();
    } else if (strcmp(tokens[token_index].token_type, "EOF") == 0) {
        printf("%s\n", tokens[token_index].literal);
        exit(0);
    } else {
        printf("Unexpected token: %s\n", tokens[token_index].token_type);
        exit(1);
    }
}

int main() {
    input = "(foo (bar) hello world)";
    tokenize(input);
    program();
}