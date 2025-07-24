//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check whether a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform arithmetic operations
double performOperation(char operator, double operand1, double operand2) {
    switch(operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
    }
}

// Function to evaluate the arithmetic expression
double evaluateExpression(char* expression) {
    int length = strlen(expression);
    // Stack to hold operands
    double stack[length];
    int top = -1;
    for (int i = 0; i < length; i++) {
        if (expression[i] == ' ') {
            continue;
        }
        else if (isdigit(expression[i])) {
            double operand = 0.0;
            int j = i;
            while (isdigit(expression[j])) {
                operand = operand * 10 + (expression[j] - '0');
                j++;
            }
            i = j - 1;
            stack[++top] = operand;
        }
        else if (isOperator(expression[i])) {
            double operand2 = stack[top--];
            double operand1 = stack[top--];
            double result = performOperation(expression[i], operand1, operand2);
            stack[++top] = result;
        }
    }
    return stack[top];
}

int main() {
    char expression[1000];
    printf("Enter an arithmetic expression:\n");
    fgets(expression, 1000, stdin);
    double result = evaluateExpression(expression);
    printf("Result: %lf\n", result);
    return 0;
}