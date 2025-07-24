//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int is_valid_syntax(char* input);

int main() {
    char input[MAX_LEN];
    int valid_syntax = 0;

    printf("Enter C syntax to check for validity:\n");
    fgets(input, MAX_LEN, stdin);

    valid_syntax = is_valid_syntax(input);

    if (valid_syntax) {
        printf("Input is valid C syntax!\n");
    } else {
        printf("Input is not valid C syntax.\n");
    }

    return 0;
}

int is_valid_syntax(char* input) {
    int i = 0;
    int open_parens = 0;
    int closed_parens = 0;
    int open_braces = 0;
    int closed_braces = 0;
    int open_brackets = 0;
    int closed_brackets = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            open_parens++;
        } else if (input[i] == ')') {
            closed_parens++;
        } else if (input[i] == '{') {
            open_braces++;
        } else if (input[i] == '}') {
            closed_braces++;
        } else if (input[i] == '[') {
            open_brackets++;
        } else if (input[i] == ']') {
            closed_brackets++;
        }
    }

    if (open_parens != closed_parens || open_braces != closed_braces || open_brackets != closed_brackets) {
        return 0;
    } else {
        return 1;
    }
}