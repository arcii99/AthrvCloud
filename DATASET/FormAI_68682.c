//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    // User input
    printf("Welcome to the scientific calculator!\n");
    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter an operator (+, -, *, /, ^): ");
    operator = getchar();
    operator = getchar();
    
    // Calculation
    switch (operator) {
        case '+':
            printf("Enter another number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            printf("Enter another number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            printf("Enter another number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            printf("Enter another number: ");
            scanf("%lf", &num2);
            if (num2 == 0) {
                printf("Error: division by zero\n");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        case '^':
            printf("Enter exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}