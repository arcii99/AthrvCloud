//FormAI DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_BUFFER_LENGTH 1000

typedef struct {
    char type[MAX_TOKEN_LENGTH];
    char value[MAX_TOKEN_LENGTH];
} Token;

typedef struct {
    char buffer[MAX_BUFFER_LENGTH];
    int position;
} Buffer;

Token nextToken(Buffer *);

void match(Buffer *, char *);

void parse_declaration(Buffer *);

void parse_assign_statement(Buffer *);

void parse_variable(Buffer *);

void parse_expression(Buffer *);

void parse_term(Buffer *);

int main(int argc, char *argv[]) {
    Buffer buffer;
    Token token;
    FILE *file;
    char *filename = argv[1];

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    if (fgets(buffer.buffer, MAX_BUFFER_LENGTH, file) == NULL) {
        printf("Cannot read from file %s\n", filename);
        exit(0);
    }

    buffer.position = 0;

    while (1) {
        token = nextToken(&buffer);

        if (strcmp(token.type, "IDENTIFIER") == 0) {
            parse_variable(&buffer);
        } else if (strcmp(token.type, "TYPE") == 0) {
            parse_declaration(&buffer);
        } else {
            printf("Syntax error on line: %d\n", buffer.position);
            exit(0);
        }

        if (buffer.position >= strlen(buffer.buffer)) {
            break;
        }
    }

    fclose(file);

    return 0;
}

Token nextToken(Buffer *buffer) {
    Token token;
    char current_token[MAX_TOKEN_LENGTH] = "";
    char current_char;
    int length;

    while (buffer->position < strlen(buffer->buffer)) {
        current_char = buffer->buffer[buffer->position];

        if (isspace(current_char)) {
            buffer->position++;
            continue;
        } else if (isalpha(current_char)) {
            length = 0;

            while (isalpha(current_char) || isdigit(current_char) || current_char == '_') {
                current_token[length++] = current_char;
                current_char = buffer->buffer[++buffer->position];
            }

            current_token[length] = '\0';
            strcpy(token.type, "IDENTIFIER");
            strcpy(token.value, current_token);

            return token;
        } else if (isdigit(current_char)) {
            length = 0;

            while (isdigit(current_char)) {
                current_token[length++] = current_char;
                current_char = buffer->buffer[++buffer->position];
            }

            current_token[length] = '\0';
            strcpy(token.type, "NUMBER");
            strcpy(token.value, current_token);

            return token;
        } else if (current_char == '=') {
            buffer->position++;
            strcpy(token.type, "ASSIGNMENT");
            strcpy(token.value, "=");

            return token;
        } else if (current_char == ';') {
            buffer->position++;
            strcpy(token.type, "SEMICOLON");
            strcpy(token.value, ";");

            return token;
        } else if (isupper(current_char)) {
            length = 0;

            while (isupper(current_char)) {
                current_token[length++] = current_char;
                current_char = buffer->buffer[++buffer->position];
            }

            current_token[length] = '\0';
            strcpy(token.type, "TYPE");
            strcpy(token.value, current_token);

            return token;
        } else {
            printf("Invalid character %c on line: %d\n", current_char, buffer->position);
            exit(0);
        }
    }

    strcpy(token.type, "END");
    strcpy(token.value, "");

    return token;
}

void match(Buffer *buffer, char *string) {
    Token token = nextToken(buffer);

    if (strcmp(token.value, string) != 0) {
        printf("Error: expected %s but got %s on line: %d\n", string, token.value, buffer->position);
        exit(0);
    }
}

void parse_declaration(Buffer *buffer) {
    match(buffer, "int"); // This can be configured to support other data types as well
    parse_variable(buffer);
    match(buffer, ";");
}

void parse_assign_statement(Buffer *buffer) {
    parse_variable(buffer);
    match(buffer, "=");
    parse_expression(buffer);
    match(buffer, ";");
}

void parse_variable(Buffer *buffer) {
    Token token = nextToken(buffer);

    if (strcmp(token.type, "IDENTIFIER") != 0) {
        printf("Error: expected identifier but got %s on line: %d\n", token.value, buffer->position);
        exit(0);
    }
}

void parse_expression(Buffer *buffer) {
    parse_term(buffer);

    while (1) {
        Token token = nextToken(buffer);

        if (strcmp(token.value, "+") == 0) {
            parse_term(buffer);
        } else if (strcmp(token.value, "-") == 0) {
            parse_term(buffer);
        } else {
            buffer->position--;
            break;
        }
    }
}

void parse_term(Buffer *buffer) {
    Token token = nextToken(buffer);

    if (strcmp(token.type, "NUMBER") == 0) {
        return;
    } else if (strcmp(token.type, "IDENTIFIER") == 0) {
        return;
    } else {
        printf("Error: expected numeric constant or identifier but got %s on line: %d\n", token.type, buffer->position);
        exit(0);
    }
}