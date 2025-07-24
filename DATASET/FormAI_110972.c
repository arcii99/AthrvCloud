//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate addition
double add(double num1, double num2)
{
    return num1 + num2;
}

// Function to calculate subtraction
double subtract(double num1, double num2)
{
    return num1 - num2;
}

// Function to calculate multiplication
double multiply(double num1, double num2)
{
    return num1 * num2;
}

// Function to calculate division
double divide(double num1, double num2)
{
    return num1 / num2;
}

// Function to calculate the power
double power(double base, double exponent)
{
    return pow(base, exponent);
}

// Function to calculate the square root
double square_root(double num)
{
    return sqrt(num);
}

// Function to calculate the sin value
double sine(double angle)
{
    return sin(angle * M_PI / 180.0);
}

// Function to calculate the cos value
double cosine(double angle)
{
    return cos(angle * M_PI / 180.0);
}

// Function to calculate the tangent value
double tangent(double angle)
{
    return tan(angle * M_PI / 180.0);
}

int main()
{
    double num1, num2, result;
    int operation;

    printf("Welcome to the Multiplayer Scientific Calculator!\n");

    while (1)
    {
        printf("\nEnter the first number: ");
        scanf("%lf", &num1);

        printf("Enter the second number: ");
        scanf("%lf", &num2);

        printf("Choose an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Sine\n8. Cosine\n9. Tangent\n0. Exit\n");

        scanf("%d", &operation);

        switch (operation)
        {
            case 1:
                result = add(num1, num2);
                printf("\nResult of %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = subtract(num1, num2);
                printf("\nResult of %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = multiply(num1, num2);
                printf("\nResult of %.2lf x %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                result = divide(num1, num2);
                printf("\nResult of %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 5:
                result = power(num1, num2);
                printf("\nResult of %.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 6:
                if (num1 < 0)
                {
                    printf("\nCannot calculate square root of a negative number!\n");
                    break;
                }
                result = square_root(num1);
                printf("\nSquare root of %.2lf = %.2lf\n", num1, result);
                break;

            case 7:
                result = sine(num1);
                printf("\nSine of %.2lf degrees = %.2lf\n", num1, result);
                break;

            case 8:
                result = cosine(num1);
                printf("\nCosine of %.2lf degrees = %.2lf\n", num1, result);
                break;

            case 9:
                result = tangent(num1);
                printf("\nTangent of %.2lf degrees = %.2lf\n", num1, result);
                break;

            case 0:
                printf("\nExiting the Multiplayer Scientific Calculator. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid operation selected. Please try again.\n");
                break;
        }
    }
    return 0;
}