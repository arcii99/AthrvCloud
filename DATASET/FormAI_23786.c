//FormAI DATASET v1.0 Category: Scientific ; Style: brave
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Brave Scientific Calculator!\n");

    double num1, num2, result;
    char operation;

    printf("Please enter a mathematical operation (+, -, *, / or ^): ");
    scanf(" %c", &operation);

    printf("Please enter the first number: ");
    scanf("%lf", &num1);

    printf("Please enter the second number: ");
    scanf("%lf", &num2);

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("The result is: %lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result is: %lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result is: %lf\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %lf\n", result);
            }
            break;
        case '^':
            result = pow(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        default:
            printf("Error: Invalid operation selected.\n");
    }

    printf("Thank you for using the Brave Scientific Calculator!\n");

    return 0;
}