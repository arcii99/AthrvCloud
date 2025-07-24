//FormAI DATASET v1.0 Category: Syntax parsing ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

// function prototypes
void check_syntax(char input[MAX_INPUT_SIZE]);

int main(void) {
    char input[MAX_INPUT_SIZE];

    printf("Enter your C syntax code here:\n>> ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    check_syntax(input);

    return 0;
}

void check_syntax(char input[MAX_INPUT_SIZE]) {
    int len = strlen(input);
    int line_count = 1;
    bool in_single_comment = false;
    bool in_multi_comment = false;
    bool in_quotes = false;
    bool in_char = false;
    char last_char = '\0';

    for (int i = 0; i < len; i++) {
        char c = input[i];

        if (c == '\n') {
            line_count++;
        }

        if (in_multi_comment && c == '/' && last_char == '*') {
            in_multi_comment = false;
        }

        if (in_single_comment || in_multi_comment) {
            continue;
        }

        if (c == '/' && last_char == '/') { // single line comment
            in_single_comment = true;
            continue;
        }

        if (c == '*' && last_char == '/') { // multi-line comment
            in_multi_comment = true;
            continue;
        }

        if (c == '"' && last_char != '\\') { // string
            in_quotes = !in_quotes;
        }

        if (c == '\'' && !in_quotes) { // char
            if (!in_char) {
                in_char = true;
            } else {
                in_char = false;
            }
        }

        if (!in_char && !in_quotes) {
            if (c == '{' || c == '(' || c == '[') {
                printf("Line %d: Opening bracket '%c' found\n", line_count, c);
            } else if (c == '}' || c == ')' || c == ']') {
                printf("Line %d: Closing bracket '%c' found\n", line_count, c);
            } else if (c == ';') {
                printf("Line %d: Semicolon found\n", line_count);
            } else if (c == ':') {
                printf("Line %d: Colon found\n", line_count);
            }
        }

        last_char = c;
    }

    if (in_single_comment) {
        printf("Missing closing single line comment at line %d\n", line_count);
    }

    if (in_multi_comment) {
        printf("Missing closing multi-line comment at line %d\n", line_count);
    }

    if (in_char) {
        printf("Missing closing single quote at line %d\n", line_count);
    }

    if (in_quotes) {
        printf("Missing closing double quotes at line %d\n", line_count);
    }
}