//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 100

void clearBuffer() {
    while (getchar() != '\n');
}

int main() {
    char expr[MAX_LENGTH], op;
    double num1, num2, result;

    printf("Enter an expression: ");
    fgets(expr, MAX_LENGTH, stdin);

    // Remove excess newline character if present
    if (expr[strlen(expr) - 1] == '\n')
        expr[strlen(expr) - 1] = '\0';

    // Parse operands and operators
    sscanf(expr, "%lf %c %lf", &num1, &op, &num2);

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        case '%':
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = fmod(num1, num2);
                printf("Result: %.2f\n", result);
            }
            break;
        case '^':
            result = pow(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}