//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double factorial(double x);
double sin_func(double x);
double cos_func(double x);
double tan_func(double x);

int main()
{
    int choice;
    double x, y, result;

    while (1)
    {
        printf("Welcome to the Scientific Calculator\n");
        printf("Select an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Power (x^y)\n");
        printf("6. Factorial (!)\n");
        printf("7. Sine (sin x)\n");
        printf("8. Cosine (cos x)\n");
        printf("9. Tangent (tan x)\n");
        printf("10. Exit\n");

        scanf("%d", &choice);

        if (choice == 10)
        {
            break;
        }

        if (choice >= 1 && choice <= 5)
        {
            printf("Enter the first number: ");
            scanf("%lf", &x);
            printf("Enter the second number: ");
            scanf("%lf", &y);
        }
        else if (choice >= 6 && choice <= 9)
        {
            printf("Enter the number: ");
            scanf("%lf", &x);
        }

        switch (choice)
        {
            case 1:
                result = add(x, y);
                printf("Result: %lf\n", result);
                break;
            case 2:
                result = subtract(x, y);
                printf("Result: %lf\n", result);
                break;
            case 3:
                result = multiply(x, y);
                printf("Result: %lf\n", result);
                break;
            case 4:
                result = divide(x, y);
                printf("Result: %lf\n", result);
                break;
            case 5:
                result = power(x, y);
                printf("Result: %lf\n", result);
                break;
            case 6:
                result = factorial(x);
                printf("Result: %lf\n", result);
                break;
            case 7:
                result = sin_func(x);
                printf("Result: %lf\n", result);
                break;
            case 8:
                result = cos_func(x);
                printf("Result: %lf\n", result);
                break;
            case 9:
                result = tan_func(x);
                printf("Result: %lf\n", result);
                break;
            default:
                printf("Wrong Input!\n");
        }

        printf("\n");
    }

    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double subtract(double x, double y)
{
    return x - y;
}

double multiply(double x, double y)
{
    return x * y;
}

double divide(double x, double y)
{
    return x / y;
}

double power(double x, double y)
{
    return pow(x, y);
}

double factorial(double x)
{
    int i;
    double result = 1;
    for (i = 1; i <= (int) x; i++)
    {
        result *= i;
    }
    return result;
}

double sin_func(double x)
{
    return sin(x);
}

double cos_func(double x)
{
    return cos(x);
}

double tan_func(double x)
{
    return tan(x);
}