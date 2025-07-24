//FormAI DATASET v1.0 Category: Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Brave Calculator\n");
    printf("Enter two numbers to perform an operation on them:\n");

    double num1, num2;
    char operator;
    printf("First number: ");
    scanf("%lf", &num1);
    printf("Operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Second number: ");
    scanf("%lf", &num2);

    double result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: cannot divide by zero\n");
                exit(0);
            } else {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            }
            break;
        default:
            printf("Error: invalid operator entered\n");
            exit(0);
    }
    printf("Thank you for using the Brave Calculator\n");
    return 0;
}