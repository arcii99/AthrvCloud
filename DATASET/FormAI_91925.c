//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void power();
void squareRoot();

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\nWelcome to the scientific calculator\n");
        printf("1. Addition \n");
        printf("2. Subtraction \n");
        printf("3. Multiplication \n");
        printf("4. Division \n");
        printf("5. Power \n");
        printf("6. Square root \n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                power();
                break;
            case 6:
                squareRoot();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void add()
{
    double num1, num2, result;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = num1 + num2;

    printf("The result of the addition is: %lf\n", result);
}

void subtract()
{
    double num1, num2, result;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = num1 - num2;

    printf("The result of the subtraction is: %lf\n", result);
}

void multiply()
{
    double num1, num2, result;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = num1 * num2;

    printf("The result of the multiplication is: %lf\n", result);
}

void divide()
{
    double num1, num2, result;

    printf("Enter the dividend: ");
    scanf("%lf", &num1);

    printf("Enter the divisor: ");
    scanf("%lf", &num2);

    if (num2 == 0)
    {
        printf("Division by zero is not allowed.\n");
        return;
    }

    result = num1 / num2;

    printf("The result of the division is: %lf\n", result);
}

void power()
{
    double num1, num2, result;

    printf("Enter the base: ");
    scanf("%lf", &num1);

    printf("Enter the exponent: ");
    scanf("%lf", &num2);

    result = pow(num1, num2);

    printf("The result of the power function is: %lf\n", result);
}

void squareRoot()
{
    double num, result;

    printf("Enter the number to calculate the square root of: ");
    scanf("%lf", &num);

    if (num < 0)
    {
        printf("Square root of a negative number is not defined.\n");
        return;
    }

    result = sqrt(num);

    printf("The square root of %lf is %lf\n", num, result);
}