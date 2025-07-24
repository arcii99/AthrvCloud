//FormAI DATASET v1.0 Category: Scientific ; Style: relaxed
#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("Enter a mathematical operation (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

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
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator!");
            return 0;
    }

    printf("Result of %.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0;
}