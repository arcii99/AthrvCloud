//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
#include<stdio.h>

int main() {
    printf("Welcome to the happy C Syntax parsing program!\n");
    printf("We can't wait to parse your happy C code!\n");

    char code[1000];
    printf("Enter your happy C code here:\n");
    fgets(code, sizeof(code), stdin);

    int i = 0;
    int open_parenthesis = 0, close_parenthesis = 0;
    int open_curly = 0, close_curly = 0;
    int open_bracket = 0, close_bracket = 0;

    while (code[i] != '\0') {
        if (code[i] == '(') {
            open_parenthesis++;
        } else if (code[i] == ')') {
            close_parenthesis++;
        } else if (code[i] == '{') {
            open_curly++;
        } else if (code[i] == '}') {
            close_curly++;
        } else if (code[i] == '[') {
            open_bracket++;
        } else if (code[i] == ']') {
            close_bracket++;
        }

        i++;
    }

    if (open_parenthesis == close_parenthesis && open_curly == close_curly && open_bracket == close_bracket) {
        printf("Your happy C code is syntactically correct!\n");
    } else {
        printf("Your happy C code has a syntax error!\n");
    }

    printf("Thank you for parsing your happy C code with us!\n");
    return 0;
}