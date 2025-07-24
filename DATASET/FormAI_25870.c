//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main(void) {
    double num1, num2, result = 0;
    char operator;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the operator (+, -, *, /, ^): ");
    scanf(" %c", &operator);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch(operator) {
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
        case '^':
            result = pow(num1, num2);
            break;
        default:
            printf("Invalid operator.");
            return 0;
    }

    printf("Result: %lf", result);
    return 0;
}