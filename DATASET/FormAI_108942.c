//FormAI DATASET v1.0 Category: Arithmetic ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Cannot divide by zero!");
                exit(0);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator");
            exit(0);
    }

    printf("%.2lf %c %.2lf = %.2lf", num1, operator, num2, result);

    return 0;
}