//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char operation;
    double num1, num2, result;

    printf("Enter an operation (+, -, *, /, ^, s): ");
    scanf("%c", &operation);

    // Addition Operation
    if (operation == '+')
    {
        printf("Enter two numbers to add: ");
        scanf("%lf %lf", &num1, &num2);
        result = num1 + num2;
        printf("Result: %lf\n", result);
    }
    // Subtraction Operation
    else if (operation == '-')
    {
        printf("Enter two numbers to subtract: ");
        scanf("%lf %lf", &num1, &num2);
        result = num1 - num2;
        printf("Result: %lf\n", result);
    }
    // Multiplication Operation
    else if (operation == '*')
    {
        printf("Enter two numbers to multiply: ");
        scanf("%lf %lf", &num1, &num2);
        result = num1 * num2;
        printf("Result: %lf\n", result);
    }
    // Division Operation
    else if (operation == '/')
    {
        printf("Enter two numbers to divide: ");
        scanf("%lf %lf", &num1, &num2);
        result = num1 / num2;
        printf("Result: %lf\n", result);
    }
    // Power Operation
    else if (operation == '^')
    {
        printf("Enter base number and power to calculate: ");
        scanf("%lf %lf", &num1, &num2);
        result = pow(num1, num2);
        printf("Result: %lf\n", result);
    }
    // Sine Operation
    else if (operation == 's')
    {
        printf("Enter an angle in degrees to calculate sine value: ");
        scanf("%lf", &num1);
        double radian = num1 * (M_PI/180);
        result = sin(radian);
        printf("Result: %lf\n", result);
    }
    // Invalid Operation
    else
    {
        printf("Invalid operation entered!\n");
    }

    return 0;
}