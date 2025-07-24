//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator\n");

    // Display list of operations
    printf("Operation List:\n");
    printf("+       Addition\n");
    printf("-       Subtraction\n");
    printf("*       Multiplication\n");
    printf("/       Division\n");
    printf("^       Power\n");
    printf("sqrt    Square Root\n");
    printf("sin     Sine Function\n");
    printf("cos     Cosine Function\n");
    printf("tan     Tangent Function\n");
    printf("log     Natural Logarithm\n");

    // Obtain user input
    printf("Enter the desired operation: ");
    scanf("%c", &operator);

    // Perform operation based on user input
    switch(operator)
    {
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf(" %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf(" %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf(" %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 / num2;
            printf(" %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;

        case '^':
            printf("Enter the base number: ");
            scanf("%lf", &num1);
            printf("Enter the power: ");
            scanf("%lf", &num2);
            result = pow(num1, num2);
            printf(" %.2lf to the power of %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 's':
            printf("Enter a number to take the square root of: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf(" Square root of %.2lf = %.2lf\n", num1, result);
            break;

        case 'S':
            printf("Enter a number to take the sine of: ");
            scanf("%lf", &num1);
            result = sin(num1);
            printf(" Sine of %.2lf = %.2lf\n", num1, result);
            break;

        case 'c':
            printf("Enter a number to take the cosine of: ");
            scanf("%lf", &num1);
            result = cos(num1);
            printf(" Cosine of %.2lf = %.2lf\n", num1, result);
            break;

        case 't':
            printf("Enter a number to take the tangent of: ");
            scanf("%lf", &num1);
            result = tan(num1);
            printf(" Tangent of %.2lf = %.2lf\n", num1, result);
            break;

        case 'l':
            printf("Enter a number to take the natural logarithm of: ");
            scanf("%lf", &num1);
            result = log(num1);
            printf(" Natural Logarithm of %.2lf = %.2lf\n", num1, result);
            break;

        default:
            printf("Error: Invalid input.\n");
    }

    return 0;
}