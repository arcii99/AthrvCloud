//FormAI DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100  // max length for an identifier or a constant

// structure to hold a token
typedef struct token {
    char type[MAX_LEN];  // type of the token ("Identifier", "Keyword", "Constant", etc.)
    char value[MAX_LEN];  // value of the token (e.g. for an identifier, its actual name)
} token;

// function to check if a character c is an operator
int is_operator(char c) {
    char operators[] = "+-*/%<>=&|^!";  // list of operators
    for (int i = 0; i < strlen(operators); i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

// function to check if a character c is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// function to check if a character c is a whitespace character
int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

// function to get the next token from input string gs
token get_next_token(char gs[]) {
    token t;
    int i = 0;
    int j = 0;
    char c;

    // skip over whitespace
    while (is_whitespace(gs[i])) {
        i++;
    }

    c = gs[i];

    // identifier or keyword
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
        while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_') {
            t.value[j++] = c;
            c = gs[++i];
        }
        t.value[j] = '\0';

        if (!strcmp(t.value, "if") || !strcmp(t.value, "else") || !strcmp(t.value, "while") || !strcmp(t.value, "for")) {
            strcpy(t.type, "Keyword");
        } else {
            strcpy(t.type, "Identifier");
        }
    }

    // constant
    else if (is_digit(c)) {
        while (is_digit(c)) {
            t.value[j++] = c;
            c = gs[++i];
        }
        t.value[j] = '\0';
        strcpy(t.type, "Constant");
    }

    // operator
    else if (is_operator(c)) {
        while (is_operator(c)) {
            t.value[j++] = c;
            c = gs[++i];
        }
        t.value[j] = '\0';
        strcpy(t.type, "Operator");
    }

    // single-character tokens
    else {
        t.value[j++] = c;
        t.value[j] = '\0';

        switch (c) {
            case '(':
            case ')':
            case '{':
            case '}':
            case ';':
            case ',':
                strcpy(t.type, "Symbol");
                break;
            default:
                strcpy(t.type, "Unknown");
                break;
        }
        i++;
    }

    return t;
}

int main() {
    char gs[MAX_LEN];
    token t;

    printf("Enter a C syntax to parse: ");

    fgets(gs, MAX_LEN, stdin);

    while (1) {
        t = get_next_token(gs);

        if (!strcmp(t.value, "")) {
            break;
        }

        printf("%s: %s\n", t.type, t.value);
    }

    return 0;
}