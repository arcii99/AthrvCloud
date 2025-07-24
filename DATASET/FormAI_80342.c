//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double absoluteValue(double);

// main function
int main()
{
    int choice;
    double num1, num2, result;

    printf("+------------------+\n");
    printf("|  CALCULATOR 3000  |\n");
    printf("+------------------+\n");

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("\n");
    printf("Select the operation to perform: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power Function\n");
    printf("6. Square Root Function\n");
    printf("7. Absolute Value Function\n");
    printf("8. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            result = add(num1, num2);
            break;
        case 2:
            result = subtract(num1, num2);
            break;
        case 3:
            result = multiply(num1, num2);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Error: Division by zero.\n");
                return 0;
            }
            result = divide(num1, num2);
            break;
        case 5:
            result = power(num1, num2);
            break;
        case 6:
            result = squareRoot(num1);
            break;
        case 7:
            result = absoluteValue(num1);
            break;
        case 8:
            printf("Thank you for using CALCULATOR 3000!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            return 0;
    }

    printf("\nThe result is: %lf\n", result);

    return 0;
}

// function definitions
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

double squareRoot(double x)
{
    return sqrt(x);
}

double absoluteValue(double x)
{
    return fabs(x);
}