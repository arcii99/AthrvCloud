//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

// function prototypes
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double base, double exponent);
double square_root(double num);

int main()
{
    int choice;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("------------------------------------\n");

    do
    {
        printf("Please choose an operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Sum = %.2lf\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Difference = %.2lf\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Product = %.2lf\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("Quotient = %.2lf\n", result);
                break;
            case 5:
                printf("Enter a number and its exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("%.2lf to the power of %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 6:
                printf("Enter a number to find its square root: ");
                scanf("%lf", &num1);
                result = square_root(num1);
                printf("Square root of %.2lf = %.2lf\n", num1, result);
                break;
            case 7:
                printf("Thank you for using the Scientific Calculator!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while(choice != 7);

    return 0;
}

// function definitions
double add(double num1, double num2)
{
    return num1 + num2;
}

double subtract(double num1, double num2)
{
    return num1 - num2;
}

double multiply(double num1, double num2)
{
    return num1 * num2;
}

double divide(double num1, double num2)
{
    while(num2 == 0)
    {
        printf("Division by zero is not allowed. Please enter a non-zero divisor: ");
        scanf("%lf", &num2);
    }
    return num1 / num2;
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double square_root(double num)
{
    while(num < 0)
    {
        printf("Square root of a negative number is not allowed. Please enter a non-negative number: ");
        scanf("%lf", &num);
    }
    return sqrt(num);
}