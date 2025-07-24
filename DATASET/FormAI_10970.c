//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declarations
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double factorial(double x);
double root(double x, double y);
void menu();

int main()
{
    menu();
    return 0;
}

// Function Definitions

// Add
double add(double x, double y)
{
    return x + y;
}

// Subtract
double subtract(double x, double y)
{
    return x - y;
}

// Multiply
double multiply(double x, double y)
{
    return x * y;
}

// Divide
double divide(double x, double y)
{
    if(y == 0)
    {
        printf("Invalid operation! Division by 0 is not allowed.\n");
        exit(0);
    }
    return x / y;
}

// Power
double power(double x, double y)
{
    return pow(x, y);
}

// Factorial
double factorial(double x)
{
    if(x < 0)
    {
        printf("Invalid operation! Factorial of negative numbers is not allowed.\n");
        exit(0);
    }
    double fact = 1;
    for(int i = 2; i <= x; i++)
    {
        fact *= i;
    }
    return fact;
}

// Root
double root(double x, double y)
{
    if(x < 0 && fmod(y, 2) == 0)
    {
        printf("Invalid operation! Negative numbers do not have even roots.\n");
        exit(0);
    }
    return pow(x, (1 / y));
}

// Menu
void menu()
{
    double num1, num2, result;
    int choice;
    printf("Welcome to C Scientific Calculator!\n");
    printf("-----------------------------------\n");
    printf("Operations available:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Factorial\n");
    printf("7. Root\n");
    printf("-----------------------------------\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("Result = %lf\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result = %lf\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result = %lf\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("Result = %lf\n", result);
            break;
        case 5:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("Result = %lf\n", result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = factorial(num1);
            printf("Result = %lf\n", result);
            break;
        case 7:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = root(num1, num2);
            printf("Result = %lf\n", result);
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }
}