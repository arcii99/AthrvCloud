//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);
    printf("Enter first operand: ");
    scanf("%lf", &num1);
    printf("Enter second operand: ");
    scanf("%lf", &num2);

    switch(operator) {
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
                printf("Error: Cannot divide by zero\n");
                exit(0);
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;

        case '^':
            result = pow(num1, num2);
            printf("%.2lf raised to the power of %.2lf = %.2lf\n", num1, num2, result);
            break;

        default:
            printf("Error: Invalid operator entered\n");
            exit(0);
    }

    return 0;
}