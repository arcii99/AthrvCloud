//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int num1, num2;
    float result;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %.2f", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %.2f", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %.2f", num1, num2, result);
            break;
        case '/':
            result = (float)num1 / num2;
            printf("%d / %d = %.2f", num1, num2, result);
            break;
        default:
            printf("Invalid operator");
    }

    return 0;
}