//FormAI DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

// Function to check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is whitespace
int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to parse an expression
double parseExpr(char *expr) {
    int len = strlen(expr);
    int i;
    int parenCount = 0;
    int parenIndex = -1;
    char op;
    int opIndex = -1;
    double left = 0.0;
    double right = 0.0;

    // Find the last operator in the expression that isn't enclosed in parentheses
    for (i = len - 1; i >= 0; i--) {
        char c = expr[i];

        if (c == '(') {
            parenCount--;
        } else if (c == ')') {
            parenCount++;
        } else if (parenCount == 0 && isOperator(c)) {
            op = c;
            opIndex = i;
            break;
        }
    }

    // If there is an operator, parse the left and right operands
    if (opIndex != -1) {
        left = parseExpr(expr);
        right = parseExpr(expr + opIndex + 1);

        switch (op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                return left / right;
            case '%':
                return (int) left % (int) right;
            case '^':
                return pow(left, right);
            default:
                return 0.0;
        }
    }

    // If there is no operator, the expression is either a number or an enclosed expression
    if (expr[0] == '(' && expr[len - 1] == ')') {
        expr[len - 1] = '\0';
        return parseExpr(expr + 1);
    } else {
        return atof(expr);
    }
}

int main() {
    char expr[MAX_EXPR_SIZE];
    printf("Enter an expression: ");
    fgets(expr, MAX_EXPR_SIZE, stdin);

    double result = parseExpr(expr);
    printf("Result: %g\n", result);

    return 0;
}