//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

// function to check if character is an operator
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// function to parse the expression
void parse_expression(char* expression) {
    int length = strlen(expression);
    int i = 0;
    while(i < length) {
        if(isdigit(expression[i])) {
            printf("Constant: ");
            while(i < length && isdigit(expression[i])) {
                printf("%c", expression[i]);
                i++;
            }
            printf("\n");
        } else if(is_operator(expression[i])) {
            printf("Operator: %c\n", expression[i]);
            i++;
        } else if(expression[i] == '(') {
            printf("Left Parenthesis\n");
            i++;
        } else if(expression[i] == ')') {
            printf("Right Parenthesis\n");
            i++;
        } else if(expression[i] == ' ') {
            i++;
        } else {
            printf("Invalid Input\n");
            exit(0);
        }
    }
}

// main function
int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);
    parse_expression(expression);
    return 0;
}