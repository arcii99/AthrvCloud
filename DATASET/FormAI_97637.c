//FormAI DATASET v1.0 Category: Syntax parsing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Token types
enum {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LPAREN,
    RPAREN,
    END,
};

// Structure for tokens
typedef struct token {
    int type;           // Token type
    int value;          // Token value (only applicable for NUMBER type)
} token;

// Structure for the parser
typedef struct parser {
    const char* input;  // Input string
    token current;      // Current token
    int pos;            // Current position in input string
} parser;

// Function to initialize the parser
void parser_init(parser* p, const char* input) {
    p->input = input;
    p->pos = 0;
    p->current.type = -1;
    p->current.value = 0;
}

// Function to get the next token from the input
void parser_next_token(parser* p) {
    // Skip whitespace
    while (isspace(p->input[p->pos])) {
        p->pos++;
    }

    // Check for end of input
    if (p->input[p->pos] == '\0') {
        p->current.type = END;
        p->current.value = 0;
        return;
    }

    // Check for operators and parentheses
    switch (p->input[p->pos]) {
        case '+':
            p->current.type = PLUS;
            p->current.value = 0;
            p->pos++;
            break;
        case '-':
            p->current.type = MINUS;
            p->current.value = 0;
            p->pos++;
            break;
        case '*':
            p->current.type = MULTIPLY;
            p->current.value = 0;
            p->pos++;
            break;
        case '/':
            p->current.type = DIVIDE;
            p->current.value = 0;
            p->pos++;
            break;
        case '(':
            p->current.type = LPAREN;
            p->current.value = 0;
            p->pos++;
            break;
        case ')':
            p->current.type = RPAREN;
            p->current.value = 0;
            p->pos++;
            break;
        default:
            // Check for number
            if (isdigit(p->input[p->pos])) {
                int value = 0;
                while (isdigit(p->input[p->pos])) {
                    value = value * 10 + (p->input[p->pos] - '0');
                    p->pos++;
                }
                p->current.type = NUMBER;
                p->current.value = value;
            } else {
                // Invalid character
                printf("Invalid character '%c' found\n", p->input[p->pos]);
                exit(1);
            }
            break;
    }
}

// Function to parse expressions
int parse_expr(parser* p);

// Function to parse factors
int parse_factor(parser* p) {
    int value;

    if (p->current.type == NUMBER) {
        // Number
        value = p->current.value;
        parser_next_token(p);
    } else if (p->current.type == LPAREN) {
        // Parenthesized expression
        parser_next_token(p);
        value = parse_expr(p);
        if (p->current.type != RPAREN) {
            printf("')' expected\n");
            exit(1);
        }
        parser_next_token(p);
    } else {
        // Invalid token
        printf("Number or '(' expected\n");
        exit(1);
    }

    return value;
}

// Function to parse terms
int parse_term(parser* p) {
    int value = parse_factor(p);

    while (p->current.type == MULTIPLY || p->current.type == DIVIDE) {
        // Operator
        if (p->current.type == MULTIPLY) {
            parser_next_token(p);
            value *= parse_factor(p);
        } else {
            parser_next_token(p);
            value /= parse_factor(p);
        }
    }

    return value;
}

// Function to parse expressions
int parse_expr(parser* p) {
    int value = parse_term(p);

    while (p->current.type == PLUS || p->current.type == MINUS) {
        // Operator
        if (p->current.type == PLUS) {
            parser_next_token(p);
            value += parse_term(p);
        } else {
            parser_next_token(p);
            value -= parse_term(p);
        }
    }

    return value;
}

int main() {
    // Test inputs
    const char* inputs[] = {
        "2+3*4",
        "2*3+4",
        "10/2-4",
        "5+()",
        "2*(3+4))"
    };

    // Parse inputs
    size_t num_inputs = sizeof(inputs) / sizeof(inputs[0]);
    for (size_t i = 0; i < num_inputs; i++) {
        parser p;
        parser_init(&p, inputs[i]);
        parser_next_token(&p);
        int result = parse_expr(&p);
        if (p.current.type != END) {
            printf("Unexpected token\n");
            exit(1);
        }
        printf("%s = %d\n", inputs[i], result);
    }

    return 0;
}