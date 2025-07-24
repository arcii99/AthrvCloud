//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TOKEN_LEN 100

typedef enum {
    INT,
    FLOAT,
    STRING,
    BOOL,
    CHAR,
    IDENTIFIER,
    KEYWORD,
    PUNCTUATOR,
    END_OF_FILE,
    ERROR
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LEN];
} Token;

char curr_char = ' ';
Token curr_token;

bool is_keyword(char* str) {
    char* keywords[] = {"if", "else", "while", "for", "return", "void", "int", "float", "bool", "char", "string"};
    int num_keywords = 11;
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

Token get_next_token() {
    Token token;
    token.value[0] = '\0';
    while (isspace(curr_char)) {
        curr_char = getchar();
    }
    if (isalpha(curr_char)) {
        int i = 0;
        while (isalnum(curr_char)) {
            token.value[i] = curr_char;
            i++;
            curr_char = getchar();
        }
        token.type = is_keyword(token.value) ? KEYWORD : IDENTIFIER;
    } else if (isdigit(curr_char)) {
        int i = 0;
        while (isdigit(curr_char)) {
            token.value[i] = curr_char;
            i++;
            curr_char = getchar();
        }
        if (curr_char == '.') {
            token.type = FLOAT;
            token.value[i] = curr_char;
            i++;
            curr_char = getchar();
            while (isdigit(curr_char)) {
                token.value[i] = curr_char;
                i++;
                curr_char = getchar();
            }
        } else {
            token.type = INT;
        }
    } else if (curr_char == '\"') {
        int i = 0;
        curr_token.value[i] = curr_char;
        i++;
        curr_char = getchar();
        while (curr_char != '\"') {
            curr_token.value[i] = curr_char;
            i++;
            curr_char = getchar();
            if (curr_char == EOF) {
                curr_token.type = ERROR;
                return curr_token;
            }
        }
        curr_token.value[i] = curr_char;
        curr_token.type = STRING;
        curr_char = getchar();
    } else if (curr_char == '\'') {
        int i = 0;
        curr_token.value[i] = curr_char;
        i++;
        curr_char = getchar();
        curr_token.value[i] = curr_char;
        curr_token.type = CHAR;
        i++;
        curr_char = getchar();
        curr_token.value[i] = '\'';
        curr_token.value[i+1] = '\0';
        curr_char = getchar();
    } else if (curr_char == EOF) {
        curr_token.type = END_OF_FILE;
    } else {
        switch (curr_char) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '=':
            case '<':
            case '>':
            case '&':
            case '|':
            case '!':
            case '%':
            case ';':
            case ',':
            case '(':
            case ')':
            case '{':
            case '}':
                curr_token.value[0] = curr_char;
                curr_token.value[1] = '\0';
                curr_char = getchar();
                curr_token.type = PUNCTUATOR;
                break;
            default:
                curr_token.type = ERROR;
        }
    }
    return curr_token;
}

int main() {
    curr_token.type = ERROR;
    while (curr_token.type != END_OF_FILE) {
        curr_token = get_next_token();
        switch (curr_token.type) {
            case IDENTIFIER:
                printf("IDENTIFIER: %s\n", curr_token.value);
                break;
            case KEYWORD:
                printf("KEYWORD: %s\n", curr_token.value);
                break;
            case INT:
                printf("INT: %s\n", curr_token.value);
                break;
            case FLOAT:
                printf("FLOAT: %s\n", curr_token.value);
                break;
            case CHAR:
                printf("CHARACTER: %s\n", curr_token.value);
                break;
            case STRING:
                printf("STRING: %s\n", curr_token.value);
                break;
            case PUNCTUATOR:
                printf("PUNCTUATOR: %s\n", curr_token.value);
                break;
            case ERROR:
                printf("ERROR\n");
                break;
            default:
                printf("INVALID TOKEN\n");
        }
    }
    return 0;
}