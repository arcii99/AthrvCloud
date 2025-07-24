//FormAI DATASET v1.0 Category: Calculator ; Style: lively
#include <stdio.h>

int main() {
    printf("Welcome to the Lively Calculator!\n");
    printf("Enter an operation (+, -, *, /): ");

    char operation;
    scanf("%c", &operation);

    printf("Enter the first number: ");
    double num1;
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    double num2;
    scanf("%lf", &num2);

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero\n");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        default:
            printf("Unknown operation: %c\n", operation);
            break;
    }

    printf("Thank you for using the Lively Calculator!\n");

    return 0;
}