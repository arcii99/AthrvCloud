//FormAI DATASET v1.0 Category: Syntax parsing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TOKEN_LENGTH 100

typedef enum {
    INTEGER,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LPAREN,
    RPAREN,
    END_OF_FILE
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

typedef struct {
    char *input;
    int position;
} InputBuffer;

InputBuffer *new_input_buffer(const char *input) {
    InputBuffer *buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    buffer->input = (char*)malloc(strlen(input) + 1);
    strcpy(buffer->input, input);
    buffer->position = 0;
    return buffer;
}

char input_buffer_next_char(InputBuffer *buffer) {
    char c = buffer->input[buffer->position];
    buffer->position++;
    return c;
}

Token get_next_token(InputBuffer *buffer) {
    char c;
    Token token = { END_OF_FILE, 0 };
    bool is_integer = false;
    char integer_buffer[MAX_TOKEN_LENGTH];
    int integer_buffer_index = 0;

    while ((c = input_buffer_next_char(buffer)) != '\0') {
        if (isspace(c)) {
            continue;
        } else if (isdigit(c)) {
            is_integer = true;
            integer_buffer[integer_buffer_index] = c;
            integer_buffer_index++;
        } else if (c == '+') {
            token.type = PLUS;
            break;
        } else if (c == '-') {
            token.type = MINUS;
            break;
        } else if (c == '*') {
            token.type = MUL;
            break;
        } else if (c == '/') {
            token.type = DIV;
            break;
        } else if (c == '(') {
            token.type = LPAREN;
            break;
        } else if (c == ')') {
            token.type = RPAREN;
            break;
        }
    }

    if (is_integer) {
        token.type = INTEGER;
        integer_buffer[integer_buffer_index] = '\0';
        token.value = atoi(integer_buffer);
    }

    return token;
}

int parse_expr();
int parse_term();
int parse_factor();
int parse_integer_token(Token token);

InputBuffer *input_buffer;
Token current_token;

void init_parser(const char *input) {
    input_buffer = new_input_buffer(input);
    current_token = get_next_token(input_buffer);
}

void advance() {
    current_token = get_next_token(input_buffer);
}

void error() {
    printf("Error parsing input!\n");
    exit(-1);
}

int parse_expr() {
    int result = parse_term();

    while (current_token.type == PLUS || current_token.type == MINUS) {
        if (current_token.type == PLUS) {
            advance();
            result += parse_term();
        } else if (current_token.type == MINUS) {
            advance();
            result -= parse_term();
        }
    }

    return result;
}

int parse_term() {
    int result = parse_factor();

    while (current_token.type == MUL || current_token.type == DIV) {
        if (current_token.type == MUL) {
            advance();
            result *= parse_factor();
        } else if (current_token.type == DIV) {
            advance();
            result /= parse_factor();
        }
    }

    return result;
}

int parse_factor() {
    Token token = current_token;

    if (token.type == INTEGER) {
        advance();
        return parse_integer_token(token);
    } else if (token.type == LPAREN) {
        advance();
        int result = parse_expr();
        if (current_token.type == RPAREN) {
            advance();
        } else {
            error();
        }
        return result;
    } else {
        error();
    }
}

int parse_integer_token(Token token) {
    return token.value;
}

int main() {
    const char *input = "2 + 3 * (10 / 5)";

    init_parser(input);

    int result = parse_expr();

    printf("Result: %d\n", result);

    return 0;
}