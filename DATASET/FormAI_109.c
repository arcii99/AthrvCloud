//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void displayMenu();
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double power(double num1, double num2);
double squareRoot(double num);
double absolute(double num);
double factorial(double num);
double logarithm(double num);

int main()
{
    int choice;
    double num1, num2, result;

    do
    {
        // Display menu
        displayMenu();

        // Get user choice
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        // Perform corresponding operation
        switch(choice)
        {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = addition(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 2:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtraction(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 3:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiplication(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 4:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = division(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 5:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("\nResult: %lf\n", result);
                break;

            case 6:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = absolute(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 8:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = factorial(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 9:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = logarithm(num1);
                printf("\nResult: %lf\n", result);
                break;

            case 10:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while(choice != 10);

    return 0;
}

// Function to display menu
void displayMenu()
{
    printf("\n---------------------------------------------\n");
    printf("          C Scientific Calculator\n");
    printf("---------------------------------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Absolute\n");
    printf("8. Factorial\n");
    printf("9. Logarithm\n");
    printf("10. Exit\n");
    printf("---------------------------------------------\n");
}

// Function to perform addition
double addition(double num1, double num2)
{
    return num1 + num2;
}

// Function to perform subtraction
double subtraction(double num1, double num2)
{
    return num1 - num2;
}

// Function to perform multiplication
double multiplication(double num1, double num2)
{
    return num1 * num2;
}

// Function to perform division
double division(double num1, double num2)
{
    if(num2 == 0)
    {
        printf("\nError! Division by zero.\n");
        exit(0);
    }
    else
    {
        return num1 / num2;
    }
}

// Function to calculate power
double power(double num1, double num2)
{
    return pow(num1, num2);
}

// Function to calculate square root
double squareRoot(double num)
{
    if(num < 0)
    {
        printf("\nError! Square root of negative number.\n");
        exit(0);
    }
    else
    {
        return sqrt(num);
    }
}

// Function to calculate absolute value
double absolute(double num)
{
    return abs(num);
}

// Function to calculate factorial
double factorial(double num)
{
    if(num < 0)
    {
        printf("\nError! Factorial of negative number.\n");
        exit(0);
    }
    else if(num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

// Function to calculate logarithm with base 10
double logarithm(double num)
{
    if(num <= 0)
    {
        printf("\nError! Logarithm of non-positive number.\n");
        exit(0);
    }
    else
    {
        return log10(num);
    }
}