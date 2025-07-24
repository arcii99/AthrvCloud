//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef enum {
    INT,
    FLOAT,
    CHAR,
    BOOL,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LESSTHAN,
    GREATERTHAN,
    EQUALTO,
    NOTEQUALTO,
    AND,
    OR,
    ASSIGNMENT,
    SEMICOLON,
    LEFTPAREN,
    RIGHTPAREN,
    LEFTBRACE,
    RIGHTBRACE,
    KEYWORD,
    IDENTIFIER,
    ERROR
} Token_Type;

typedef struct {
    Token_Type type;
    char value[MAX_TOKEN_LEN];
} Token;

Token tokens[MAX_TOKENS];
int totalTokens;

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isKeyword(char *str) {
    return strcmp(str, "int") == 0 || strcmp(str, "float") == 0 || strcmp(str, "char") == 0 || strcmp(str, "bool") == 0;
}

void lex(char *input) {
    int i = 0;
    while (input[i] != '\0') {
        char c = input[i];

        if (c == '+') {
            tokens[totalTokens].type = PLUS;
            strcpy(tokens[totalTokens].value, "+");
            totalTokens++;
        }
        else if (c == '-') {
            tokens[totalTokens].type = MINUS;
            strcpy(tokens[totalTokens].value, "-");
            totalTokens++;
        }
        else if (c == '*') {
            tokens[totalTokens].type = MUL;
            strcpy(tokens[totalTokens].value, "*");
            totalTokens++;
        }
        else if (c == '/') {
            tokens[totalTokens].type = DIV;
            strcpy(tokens[totalTokens].value, "/");
            totalTokens++;
        }
        else if (c == '<') {
            tokens[totalTokens].type = LESSTHAN;
            strcpy(tokens[totalTokens].value, "<");
            totalTokens++;
        }
        else if (c == '>') {
            tokens[totalTokens].type = GREATERTHAN;
            strcpy(tokens[totalTokens].value, ">");
            totalTokens++;
        }
        else if (c == '=') {
            if (input[i+1] == '=') {
                tokens[totalTokens].type = EQUALTO;
                strcpy(tokens[totalTokens].value, "==");
                totalTokens++;
                i++;
            }
            else {
                tokens[totalTokens].type = ASSIGNMENT;
                strcpy(tokens[totalTokens].value, "=");
                totalTokens++;
            }
        }
        else if (c == '!') {
            if (input[i+1] == '=') {
                tokens[totalTokens].type = NOTEQUALTO;
                strcpy(tokens[totalTokens].value, "!=");
                totalTokens++;
                i++;
            }
            else {
                tokens[totalTokens].type = ERROR;
                strcpy(tokens[totalTokens].value, "Error: Invalid Token !");
                totalTokens++;
            }
        }
        else if (c == '&' && input[i+1] == '&') {
            tokens[totalTokens].type = AND;
            strcpy(tokens[totalTokens].value, "&&");
            totalTokens++;
            i++;
        }
        else if (c == '|' && input[i+1] == '|') {
            tokens[totalTokens].type = OR;
            strcpy(tokens[totalTokens].value, "||");
            totalTokens++;
            i++;
        }
        else if (c == ';') {
            tokens[totalTokens].type = SEMICOLON;
            strcpy(tokens[totalTokens].value, ";");
            totalTokens++;
        }
        else if (c == '(') {
            tokens[totalTokens].type = LEFTPAREN;
            strcpy(tokens[totalTokens].value, "(");
            totalTokens++;
        }
        else if (c == ')') {
            tokens[totalTokens].type = RIGHTPAREN;
            strcpy(tokens[totalTokens].value, ")");
            totalTokens++;
        }
        else if (c == '{') {
            tokens[totalTokens].type = LEFTBRACE;
            strcpy(tokens[totalTokens].value, "{");
            totalTokens++;
        }
        else if (c == '}') {
            tokens[totalTokens].type = RIGHTBRACE;
            strcpy(tokens[totalTokens].value, "}");
            totalTokens++;
        }
        else if (isDigit(c)) {
            int j = i;
            while (isDigit(input[j])) {
                j++;
            }
            if (input[j] == '.') {
                j++;
                while (isDigit(input[j])) {
                    j++;
                }
                tokens[totalTokens].type = FLOAT;
            }
            else {
                tokens[totalTokens].type = INT;
            }
            memcpy(tokens[totalTokens].value, &input[i], j-i);
            tokens[totalTokens].value[j-i] = '\0';
            totalTokens++;
            i = j-1;
        }
        else if (isLetter(c)) {
            int j = i;
            while (isLetter(input[j]) || isDigit(input[j])) {
                j++;
            }
            int len = j-i;
            char tokenStr[MAX_TOKEN_LEN];
            memcpy(tokenStr, &input[i], len);
            tokenStr[len] = '\0';
            if (isKeyword(tokenStr)) {
                tokens[totalTokens].type = KEYWORD;
            }
            else {
                tokens[totalTokens].type = IDENTIFIER;
            }
            strcpy(tokens[totalTokens].value, tokenStr);
            totalTokens++;
            i = j-1;
        }
        i++;
    }
}

void parse() {
    for (int i = 0; i < totalTokens; i++) {
        Token currentToken = tokens[i];
        switch(currentToken.type) {
            case INT:
                printf("INT: %s\n", currentToken.value);
                break;
            case FLOAT:
                printf("FLOAT: %s\n", currentToken.value);
                break;
            case CHAR:
                printf("CHAR: %s\n", currentToken.value);
                break;
            case BOOL:
                printf("BOOL: %s\n", currentToken.value);
                break;
            case PLUS:
                printf("PLUS\n");
                break;
            case MINUS:
                printf("MINUS\n");
                break;
            case MUL:
                printf("MUL\n");
                break;
            case DIV:
                printf("DIV\n");
                break;
            case LESSTHAN:
                printf("LESSTHAN\n");
                break;
            case GREATERTHAN:
                printf("GREATERTHAN\n");
                break;
            case EQUALTO:
                printf("EQUALTO\n");
                break;
            case NOTEQUALTO:
                printf("NOTEQUALTO\n");
                break;
            case AND:
                printf("AND\n");
                break;
            case OR:
                printf("OR\n");
                break;
            case ASSIGNMENT:
                printf("ASSIGNMENT\n");
                break;
            case SEMICOLON:
                printf("SEMICOLON\n");
                break;
            case LEFTPAREN:
                printf("LEFTPAREN\n");
                break;
            case RIGHTPAREN:
                printf("RIGHTPAREN\n");
                break;
            case LEFTBRACE:
                printf("LEFTBRACE\n");
                break;
            case RIGHTBRACE:
                printf("RIGHTBRACE\n");
                break;
            case KEYWORD:
                printf("KEYWORD: %s\n", currentToken.value);
                break;
            case IDENTIFIER:
                printf("IDENTIFIER: %s\n", currentToken.value);
                break;
            case ERROR:
                printf("%s\n", currentToken.value);
                break;
        }
    }
}

int main() {
    char input[] = "int x; float y; x = 10; y = 3.14; if (x > y) { printf(\"x is greater than y\"); } else { printf(\"y is greater than x\"); }";
    lex(input);
    parse();
    return 0;
}