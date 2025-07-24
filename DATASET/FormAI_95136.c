//FormAI DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_TOKEN_LENGTH 64

typedef enum {
    TOKEN_NONE,
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATION,
    TOKEN_LITERAL,
    TOKEN_COMMENT
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

Token getNextToken(FILE* fp) {
    Token token = {TOKEN_NONE, ""};
    char buffer[MAX_BUFFER_SIZE] = {0};
    char c;
    int i, j;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            token.type = TOKEN_COMMENT;
            return token;
        }
        else if (isspace(c)) {
            continue;
        }
        else if (isalpha(c)) {
            i = 0;
            buffer[i++] = c;
            while (isalnum(c = fgetc(fp))) {
                buffer[i++] = c;
            }
            buffer[i] = '\0';
            ungetc(c, fp);
            if (strcmp(buffer, "char") == 0 || strcmp(buffer, "double") == 0 || strcmp(buffer, "float") == 0 ||
                strcmp(buffer, "int") == 0 || strcmp(buffer, "long") == 0 || strcmp(buffer, "short") == 0 ||
                strcmp(buffer, "signed") == 0 || strcmp(buffer, "unsigned") == 0 || strcmp(buffer, "void") == 0) {
                token.type = TOKEN_KEYWORD;
                strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
                return token;
            }
            else {
                token.type = TOKEN_IDENTIFIER;
                strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
                return token;
            }
        }
        else if (isdigit(c)) {
            i = 0;
            buffer[i++] = c;
            while (isdigit(c = fgetc(fp))) {
                buffer[i++] = c;
            }
            buffer[i] = '\0';
            ungetc(c, fp);
            token.type = TOKEN_LITERAL;
            strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
            return token;
        }
        else if (c == '\'' || c == '\"') {
            i = 0;
            buffer[i++] = c;
            while ((c = fgetc(fp)) != EOF) {
                buffer[i++] = c;
                if (c == '\\' && (c = fgetc(fp)) != EOF) {
                    buffer[i++] = c;
                }
                else if (c == '\'' || c == '\"') {
                    break;
                }
            }
            buffer[i] = '\0';
            token.type = TOKEN_LITERAL;
            strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
            return token;
        }
        else if (c == '/') {
            i = 0;
            if ((c = fgetc(fp)) == '*') {
                buffer[i++] = '/';
                buffer[i++] = '*';
                while ((c = fgetc(fp)) != EOF) {
                    buffer[i++] = c;
                    if (c == '*' && (c = fgetc(fp)) == '/') {
                        buffer[i++] = c;
                        break;
                    }
                }
                buffer[i] = '\0';
                token.type = TOKEN_COMMENT;
                strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
                return token;
            }
            else if (c == '/') {
                buffer[i++] = '/';
                while ((c = fgetc(fp)) != EOF) {
                    buffer[i++] = c;
                    if (c == '\n') {
                        break;
                    }
                }
                buffer[i] = '\0';
                token.type = TOKEN_COMMENT;
                strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
                return token;
            }
            else {
                ungetc(c, fp);
                token.type = TOKEN_OPERATOR;
                token.value[0] = '/';
                return token;
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' ||
                 c == '<' || c == '>' || c == '=' || c == '&' || c == '|' || c == '^') {
            i = 0;
            buffer[i++] = c;
            if ((c = fgetc(fp)) == '=') {
                buffer[i++] = c;
            }
            else {
                ungetc(c, fp);
            }
            buffer[i] = '\0';
            token.type = TOKEN_OPERATOR;
            strncpy(token.value, buffer, MAX_TOKEN_LENGTH);
            return token;
        }
        else if (c == '.' || c == ',' || c == ';' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {
            token.type = TOKEN_PUNCTUATION;
            token.value[0] = c;
            return token;
        }
        else {
            token.type = TOKEN_NONE;
            return token;
        }
    }

    return token;
}

void skipStatement(FILE* fp) {
    Token token;
    while ((token = getNextToken(fp)).type != TOKEN_NONE) {
        if (token.type == TOKEN_PUNCTUATION && token.value[0] == ';') {
            break;
        }
    }
}

void parseDeclaration(FILE* fp, Token typeToken) {
    Token token;

    while ((token = getNextToken(fp)).type != TOKEN_NONE) {
        if (token.type == TOKEN_IDENTIFIER) {
            printf("%s %s;\n", typeToken.value, token.value);
        }
        else if (token.type == TOKEN_OPERATOR && token.value[0] == '=') {
            printf("%s %s", typeToken.value, token.value);
            skipStatement(fp);
        }
        else if (token.type == TOKEN_PUNCTUATION && token.value[0] == ',') {
            continue;
        }
        else if (token.type == TOKEN_PUNCTUATION && token.value[0] == ';') {
            break;
        }
    }
}

void parseFunction(FILE* fp, Token returnToken) {
    Token token;

    while ((token = getNextToken(fp)).type != TOKEN_NONE) {
        if (token.type == TOKEN_IDENTIFIER) {
            printf("%s %s(", returnToken.value, token.value);
            while ((token = getNextToken(fp)).type != TOKEN_NONE) {
                if (token.type == TOKEN_PUNCTUATION && token.value[0] == ')') {
                    printf(") {\n");
                    skipStatement(fp);
                    printf("}\n\n");
                    return;
                }
                else if (token.type == TOKEN_KEYWORD) {
                    parseDeclaration(fp, token);
                }
                else if (token.type == TOKEN_IDENTIFIER) {
                    printf("%s, ", token.value);
                }
                else if (token.type == TOKEN_PUNCTUATION && token.value[0] == ',') {
                    continue;
                }
            }
        }
        else if (token.type == TOKEN_PUNCTUATION && token.value[0] == ';') {
            break;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    Token token;
    while ((token = getNextToken(fp)).type != TOKEN_NONE) {
        if (token.type == TOKEN_KEYWORD) {
            if (strcmp(token.value, "int") == 0 || strcmp(token.value, "char") == 0 ||
                strcmp(token.value, "double") == 0 || strcmp(token.value, "float") == 0 ||
                strcmp(token.value, "long") == 0 || strcmp(token.value, "short") == 0 ||
                strcmp(token.value, "signed") == 0 || strcmp(token.value, "unsigned") == 0 || strcmp(token.value, "void") == 0) {
                parseDeclaration(fp, token);
            }
            else if (strcmp(token.value, "return") == 0) {
                skipStatement(fp);
            }
            else if (strcmp(token.value, "if") == 0 || strcmp(token.value, "for") == 0 ||
                     strcmp(token.value, "while") == 0 || strcmp(token.value, "do") == 0 ||
                     strcmp(token.value, "switch") == 0) {
                skipStatement(fp);
            }
        }
        else if (token.type == TOKEN_IDENTIFIER) {
            Token nextToken = getNextToken(fp);
            if (nextToken.type == TOKEN_PUNCTUATION && nextToken.value[0] == '(') {
                parseFunction(fp, token);
            }
            else if (nextToken.type == TOKEN_PUNCTUATION && nextToken.value[0] == '=') {
                printf("%s %s", token.value, nextToken.value);
                skipStatement(fp);
            }
        }
    }

    fclose(fp);
    return 0;
}