//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declaration of Functions
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double num1, double num2);
double square_root(double num);
double absolute_value(double num);

int main()
{
    int option;
    double num1, num2, result;

    printf("Welcome to our romantic scientific calculator!\n");

    // Get user input
    printf("Please enter the first number: ");
    scanf("%lf", &num1);

    printf("Please enter the second number: ");
    scanf("%lf", &num2);

    // Display available operations
    printf("\nAvailable operations: \n"
           "1. Add\n"
           "2. Subtract\n"
           "3. Multiply\n"
           "4. Divide\n"
           "5. Power\n"
           "6. Square Root\n"
           "7. Absolute Value\n"
           "Please enter your choice: ");

    scanf("%d", &option);

    // Perform respective operation based on user's choice
    switch(option)
    {
        case 1:
            result = add(num1, num2);
            printf("The sum of %lf and %lf is %lf. Love is like addition, you add happiness to my life and it multiplies.\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("The difference of %lf and %lf is %lf. You may subtract me from your heart, but you will always remain in mine.\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("The product of %lf and %lf is %lf. Our love multiplies everyday as we spend time together.\n", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("The quotient of %lf and %lf is %lf. You divide my sorrows and multiply my joys.\n", num1, num2, result);
            break;
        case 5:
            result = power(num1, num2);
            printf("%lf raised to the power of %lf is %lf. Our love has the power to conquer every obstacle thrown our way.\n", num1, num2, result);
            break;
        case 6:
            result = square_root(num1);
            printf("The square root of %lf is %lf. You are the missing piece that makes me whole and complete.\n", num1, result);
            break;
        case 7:
            result = absolute_value(num1);
            printf("The absolute value of %lf is %lf. Our love is absolute and knows no bounds.\n", num1, result);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
    }

    return 0;
}

// Function Definitions
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
    if(num2 == 0)
    {
        printf("Error: Cannot divide by zero. Please try again with a different number.\n");
        exit(0);
    }

    return num1 / num2;
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

double square_root(double num)
{
    if(num < 0)
    {
        printf("Error: Cannot calculate square root of a negative number. Please try again with a positive number.\n");
        exit(0);
    }

    return sqrt(num);
}

double absolute_value(double num)
{
    return fabs(num);
}