//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function prototypes
void parseSyntax(char *input);

// main function
int main(void) {
    char input[100];

    printf("Please input a C expression to parse: ");
    fgets(input, 100, stdin);

    // remove newline character from input string
    input[strcspn(input, "\n")] = '\0';

    printf("Parsing input expression: %s\n", input);
    parseSyntax(input);

    return 0;
}

// function to parse C syntax
void parseSyntax(char *input) {
    int i = 0;

    // loop through input string and check for syntax errors
    while (input[i] != '\0') {
        if (input[i] == '(') {
            if (input[i+1] == ')') {
                printf("Syntax Error: Empty brackets\n");
                return;
            }
        }
        else if (!isdigit(input[i]) && !isalpha(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '(' && input[i] != ')') {
            printf("Syntax Error: Invalid character '%c'\n", input[i]);
            return;
        }
        i++;
    }

    printf("Syntax is correct\n");
}