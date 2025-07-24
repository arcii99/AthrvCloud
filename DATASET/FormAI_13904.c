//FormAI DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

// function to parse C syntax
void parseSyntax(char input[]) {
    int length = strlen(input);
    int parens = 0, braces = 0, brackets = 0;

    for(int i=0; i<length; i++) {
        if(input[i] == '(') {
            parens++;
        }
        else if(input[i] == ')') {
            parens--;
        }
        else if(input[i] == '{') {
            braces++;
        }
        else if(input[i] == '}') {
            braces--;
        }
        else if(input[i] == '[') {
            brackets++;
        }
        else if(input[i] == ']') {
            brackets--;
        }
    }

    if(parens == 0 && braces == 0 && brackets == 0) {
        printf("The C syntax is correct\n");
    }
    else if(parens > 0) {
        printf("Error: There are %d open parentheses\n", parens);
    }
    else if(parens < 0) {
        printf("Error: There are %d extra closing parentheses\n", -parens);
    }
    else if(braces > 0) {
        printf("Error: There are %d open braces\n", braces);
    }
    else if(braces < 0) {
        printf("Error: There are %d extra closing braces\n", -braces);
    }
    else if(brackets > 0) {
        printf("Error: There are %d open brackets\n", brackets);
    }
    else if(brackets < 0) {
        printf("Error: There are %d extra closing brackets\n", -brackets);
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a C syntax for parsing: ");
    fgets(input, sizeof(input), stdin);

    // remove newline character
    input[strcspn(input, "\n")] = 0;

    parseSyntax(input);

    return 0;
}