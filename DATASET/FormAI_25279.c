//FormAI DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 50
#define MAX_STRING_LENGTH 1000

typedef enum {
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    LITERAL,
    PUNCTUATION,
    END_OF_FILE
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

Token getNextToken(char* buffer);
void printToken(Token token);

int main(void) {
    char input[MAX_STRING_LENGTH] = "int main() { return 0; }";
    Token token;

    char buffer[MAX_TOKEN_LENGTH];
    memset(buffer, 0, MAX_TOKEN_LENGTH);

    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            i++;
            continue;
        }
        if (input[i] == ';' || input[i] == '{' || input[i] == '}' || input[i] == '(' || input[i] == ')' || input[i] == ',') {
            if (j > 0) {
                token = getNextToken(buffer);
                printToken(token);
                memset(buffer, 0, MAX_TOKEN_LENGTH);
                j = 0;
            }
            token.type = PUNCTUATION;
            token.value[0] = input[i];
            token.value[1] = '\0';
            printToken(token);
            i++;
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '>' || input[i] == '<' || input[i] == '=') {
            if (j > 0) {
                token = getNextToken(buffer);
                printToken(token);
                memset(buffer, 0, MAX_TOKEN_LENGTH);
                j = 0;
            }
            if (input[i + 1] == '=') {
                token.type = OPERATOR;
                token.value[0] = input[i];
                token.value[1] = '=';
                token.value[2] = '\0';
                printToken(token);
                i += 2;
            }
            else {
                token.type = OPERATOR;
                token.value[0] = input[i];
                token.value[1] = '\0';
                printToken(token);
                i++;
            }
        }
        else {
            buffer[j++] = input[i++];
        }
    }

    if (j > 0) {
        token = getNextToken(buffer);
        printToken(token);
    }

    token.type = END_OF_FILE;
    printToken(token);

    return 0;
}

Token getNextToken(char* buffer) {
    Token token;
    memset(&token, 0, sizeof(Token));

    if (strcmp(buffer, "int") == 0 || strcmp(buffer, "float") == 0 || strcmp(buffer, "double") == 0) {
        token.type = KEYWORD;
        strcpy(token.value, buffer);
    }
    else if (strcmp(buffer, "if") == 0 || strcmp(buffer, "while") == 0 || strcmp(buffer, "for") == 0) {
        token.type = KEYWORD;
        strcpy(token.value, buffer);
    }
    else if (strcmp(buffer, "+") == 0 || strcmp(buffer, "-") == 0 || strcmp(buffer, "*") == 0 ||
             strcmp(buffer, "/") == 0 || strcmp(buffer, "%") == 0 || strcmp(buffer, ">") == 0 ||
             strcmp(buffer, "<") == 0 || strcmp(buffer, ">=") == 0 || strcmp(buffer, "<=") == 0 ||
             strcmp(buffer, "==") == 0 || strcmp(buffer, "!=") == 0) {
        token.type = OPERATOR;
        strcpy(token.value, buffer);
    }
    else {
        token.type = IDENTIFIER;
        strcpy(token.value, buffer);
    }

    return token;
}

void printToken(Token token) {
    switch (token.type) {
        case KEYWORD:
            printf("Keyword: %s\n", token.value);
            break;
        case IDENTIFIER:
            printf("Identifier: %s\n", token.value);
            break;
        case OPERATOR:
            printf("Operator: %s\n", token.value);
            break;
        case LITERAL:
            printf("Literal: %s\n", token.value);
            break;
        case PUNCTUATION:
            printf("Punctuation: %s\n", token.value);
            break;
        case END_OF_FILE:
            printf("End of File\n");
            break;
        default:
            printf("Unknown Token\n");
            break;
    }
}