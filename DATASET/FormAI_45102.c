//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <math.h>

/* Define constants */
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define SQUARE 5
#define SQUARE_ROOT 6
#define POWER 7

/* Function prototypes */
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double square(double);
double square_root(double);
double power(double, double);
int get_choice(void);

/* Main function */
int main(void)
{
    /* Declare variables */
    double num1, num2, result;
    int choice;

    /* Get user input */
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    /* Ask user to choose operation */
    choice = get_choice();

    /* Perform operation based on user choice */
    switch(choice)
    {
        case ADDITION:
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case SUBTRACTION:
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case MULTIPLICATION:
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case DIVISION:
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        case SQUARE:
            result = square(num1);
            printf("Result: %.2lf\n", result);
            break;

        case SQUARE_ROOT:
            result = square_root(num1);
            printf("Result: %.2lf\n", result);
            break;

        case POWER:
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}

/* Function to perform addition */
double add(double num1, double num2)
{
    return num1 + num2;
}

/* Function to perform subtraction */
double subtract(double num1, double num2)
{
    return num1 - num2;
}

/* Function to perform multiplication */
double multiply(double num1, double num2)
{
    return num1 * num2;
}

/* Function to perform division */
double divide(double num1, double num2)
{
    return num1 / num2;
}

/* Function to perform square */
double square(double num)
{
    return num * num;
}

/* Function to perform square root */
double square_root(double num)
{
    return sqrt(num);
}

/* Function to perform power */
double power(double base, double exponent)
{
    return pow(base, exponent);
}

/* Function to get user choice */
int get_choice(void)
{
    int choice;

    printf("\nChoose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Square root\n");
    printf("7. Power\n");

    scanf("%d", &choice);

    return choice;
}