//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define functions
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double factorial(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);

int main()
{
    // Define variables
    int option;
    double num1, num2, result;

    printf("-------------------------\n");
    printf("MIND-BENDING CALCULATOR\n");
    printf("-------------------------\n\n");

    // Display menu
    printf("Please select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Factorial\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");

    printf("\nOption: ");
    scanf("%d", &option);

    // Check for valid option
    if (option < 1 || option > 9)
    {
        printf("Invalid option. Please try again.\n");
        return 0;
    }

    printf("Enter first number: ");
    scanf("%lf", &num1);

    // Perform calculations based on option chosen
    switch (option)
    {
        case 1:
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 2:
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 3:
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 4:
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 5:
            printf("Enter power: ");
            scanf("%lf", &num2);
            result = power(num1, num2);
            printf("Result: %.2f\n", result);
            break;
        case 6:
            result = factorial(num1);
            printf("Result: %.2f\n", result);
            break;
        case 7:
            result = sine(num1);
            printf("Result: %.2f\n", result);
            break;
        case 8:
            result = cosine(num1);
            printf("Result: %.2f\n", result);
            break;
        case 9:
            result = tangent(num1);
            printf("Result: %.2f\n", result);
            break;
    }

    return 0;
}

// Function to add two numbers
double add(double x, double y)
{
    return x + y;
}

// Function to subtract two numbers
double subtract(double x, double y)
{
    return x - y;
}

// Function to multiply two numbers
double multiply(double x, double y)
{
    return x * y;
}

// Function to divide two numbers
double divide(double x, double y)
{
    if (y == 0)
    {
        printf("Cannot divide by zero. Please try again.\n");
        exit(0);
    }

    return x / y;
}

// Function to calculate power of a number
double power(double x, double y)
{
    return pow(x, y);
}

// Function to calculate factorial of a number
double factorial(double x)
{
    if (x < 0)
    {
        printf("Cannot calculate factorial of a negative number. Please try again.\n");
        exit(0);
    }
    else if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}

// Function to calculate sine of a number
double sine(double x)
{
    return sin(x);
}

// Function to calculate cosine of a number
double cosine(double x)
{
    return cos(x);
}

// Function to calculate tangent of a number
double tangent(double x)
{
    return tan(x);
}