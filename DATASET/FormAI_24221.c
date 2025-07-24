//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double addition(double x, double y);
double subtraction(double x, double y);
double multiplication(double x, double y);
double division(double x, double y);
double power(double x, double y);
double square_root(double x);
double factorial(double x);

int main()
{
    int choice;
    double x, y, result;

    // Print menu
    printf("Scientific Calculator Implementation\n");
    printf("-----------------------------------\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Factorial\n");
    printf("Enter your choice: ");

    // Get input from user
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > 7)
    {
        printf("Invalid choice.\n");
        return 0;
    }

    // Get numbers from user
    printf("Enter first number: ");
    scanf("%lf", &x);

    if (choice != 6 && choice != 7)
    {
        printf("Enter second number: ");
        scanf("%lf", &y);
    }

    // Calculate result based on choice
    switch (choice)
    {
        case 1:
            result = addition(x, y);
            printf("%.2lf + %.2lf = %.2lf\n", x, y, result);
            break;
        case 2:
            result = subtraction(x, y);
            printf("%.2lf - %.2lf = %.2lf\n", x, y, result);
            break;
        case 3:
            result = multiplication(x, y);
            printf("%.2lf * %.2lf = %.2lf\n", x, y, result);
            break;
        case 4:
            if (y == 0)
            {
                printf("Cannot divide by zero.\n");
                return 0;
            }
            result = division(x, y);
            printf("%.2lf / %.2lf = %.2lf\n", x, y, result);
            break;
        case 5:
            result = power(x, y);
            printf("%.2lf ^ %.2lf = %.2lf\n", x, y, result);
            break;
        case 6:
            if (x < 0)
            {
                printf("Cannot calculate square root of negative number.\n");
                return 0;
            }
            result = square_root(x);
            printf("Square root of %.2lf = %.2lf\n", x, result);
            break;
        case 7:
            if (x < 0)
            {
                printf("Cannot calculate factorial of negative number.\n");
                return 0;
            }
            result = factorial(x);
            printf("%.2lf! = %.2lf\n", x, result);
            break;
    }

    return 0;
}

// Function definitions
double addition(double x, double y)
{
    return x + y;
}

double subtraction(double x, double y)
{
    return x - y;
}

double multiplication(double x, double y)
{
    return x * y;
}

double division(double x, double y)
{
    return x / y;
}

double power(double x, double y)
{
    return pow(x, y);
}

double square_root(double x)
{
    return sqrt(x);
}

double factorial(double x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}