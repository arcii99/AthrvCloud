//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <math.h>

int main() {
    char operation;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator\n\n");

    printf("Enter operation (+, -, *, /, ^, sin, cos, tan, log): ");
    scanf("%c", &operation);

    switch(operation) {
        case '+':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '^':
            printf("Enter base: ");
            scanf("%lf", &num1);
            printf("Enter exponent: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 's':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * M_PI / 180);
            printf("sin(%.2lf) = %.2lf\n", num1, result);
            break;

        case 'c':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * M_PI / 180);
            printf("cos(%.2lf) = %.2lf\n", num1, result);
            break;

        case 't':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * M_PI / 180);
            printf("tan(%.2lf) = %.2lf\n", num1, result);
            break;

        case 'l':
            printf("Enter number: ");
            scanf("%lf", &num1);
            result = log10(num1);
            printf("log(%.2lf) = %.2lf\n", num1, result);
            break;

        default:
            printf("Invalid operation. Please enter a valid operation.\n");
    }

    return 0;
}