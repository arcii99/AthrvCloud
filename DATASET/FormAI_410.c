//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mathematical
// This program implements a manual C syntax parser to evaluate a mathematical expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_EXPR_SIZE 100 // Maximum size of expression the program can handle

// Function declarations
int parse_expression(char* expr, int start_idx, int end_idx);
int parse_term(char* expr, int start_idx, int end_idx);
int parse_factor(char* expr, int start_idx, int end_idx);
int get_priority(char operator);

int main() {
    char expr[MAX_EXPR_SIZE];
    printf("Enter the mathematical expression: ");
    scanf("%[^\n]%*c", expr);
    int result = parse_expression(expr, 0, strlen(expr) - 1);
    printf("Result: %d\n", result);
    return 0;
}

// Function to parse an expression
int parse_expression(char* expr, int start_idx, int end_idx) {
    int num1 = parse_term(expr, start_idx, end_idx);
    char operator;
    int num2;
    int i = start_idx + 1;
    while (i <= end_idx) {
        operator = expr[i];
        if (operator == '+' || operator == '-') {
            num2 = parse_term(expr, i + 1, end_idx);
            if (operator == '+') {
                num1 += num2;
            } else {
                num1 -= num2;
            }
        }
        i++;
    }
    return num1;
}

// Function to parse a term
int parse_term(char* expr, int start_idx, int end_idx) {
    int num1 = parse_factor(expr, start_idx, end_idx);
    char operator;
    int num2;
    int i = start_idx + 1;
    while (i <= end_idx) {
        operator = expr[i];
        if (operator == '*' || operator == '/') {
            num2 = parse_factor(expr, i + 1, end_idx);
            if (operator == '*') {
                num1 *= num2;
            } else {
                num1 /= num2;
            }
        }
        i++;
    }
    return num1;
}

// Function to parse a factor
int parse_factor(char* expr, int start_idx, int end_idx) {
    if (expr[start_idx] == '(' && expr[end_idx] == ')') {
        return parse_expression(expr, start_idx + 1, end_idx - 1);
    }
    int num = 0;
    int i = start_idx;
    while (i <= end_idx && isdigit(expr[i])) {
        num = num * 10 + (expr[i] - '0');
        i++;
    }
    return num;
}

// Function to get the priority of an operator
int get_priority(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else {
        return 0;
    }
}