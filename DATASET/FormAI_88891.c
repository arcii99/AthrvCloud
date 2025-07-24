//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    char operator;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator\n");

    printf("Enter operator (+, -, *, /, sin, cos, tan, log, exp): ");
    scanf("%c", &operator);

    switch(operator) {
        case '+':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("Result: %lf\n", result);
            break;
        case '-':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("Result: %lf\n", result);
            break;
        case '*':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("Result: %lf\n", result);
            break;
        case '/':
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            if(num2 != 0) {
                result = num1 / num2;
                printf("Result: %lf\n", result);
            }
            else {
                printf("Error: Division by zero\n");
            }
            break;
        case 's':
        case 'S':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * PI / 180);
            printf("Result: %lf\n", result);
            break;
        case 'c':
        case 'C':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * PI / 180);
            printf("Result: %lf\n", result);
            break;
        case 't':
        case 'T':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = tan(num1 * PI / 180);
            printf("Result: %lf\n", result);
            break;
        case 'l':
        case 'L':
            printf("Enter number: ");
            scanf("%lf", &num1);
            if(num1 > 0) {
                result = log(num1);
                printf("Result: %lf\n", result);
            }
            else {
                printf("Error: Logarithm of non-positive number\n");
            }
            break;
        case 'e':
        case 'E':
            printf("Enter exponent: ");
            scanf("%lf", &num1);
            result = exp(num1);
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    return 0;
}