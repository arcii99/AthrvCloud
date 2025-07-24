//FormAI DATASET v1.0 Category: Scientific ; Style: imaginative
#include <stdio.h>

int main() {
    printf("Welcome to the Imaginative C Scientific example program!\n\n");

    float num1, num2;
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers separated by a space: ");
    scanf("%f %f", &num1, &num2);

    switch (operator) {
        case '+':
            printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Cannot divide by zero");
            } else {
                printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Error: Invalid operator");
    }

    printf("\n\nThanks for using the Imaginative C Scientific example program! Keep exploring the vast world of C programming!");

    return 0;
}