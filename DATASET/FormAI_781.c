//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("Welcome to the calculator program!\n");
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: division by zero!\n");
            } else {
                result = num1 / num2;
                printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            }
            break;
        default:
            printf("Error: unknown operator!");
            break;
    }

    return 0;
}