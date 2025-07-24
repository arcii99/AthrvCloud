//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants for PI and E
#define PI 3.14159265358979323846
#define E 2.71828182845904523536

// function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double sine(double);
double cosine(double);
double tangent(double);
double arcSine(double);
double arcCosine(double);
double arcTangent(double);

int main()
{
    // declare variables
    int option;
    double num1, num2, result;

    // print welcome message and list of operations
    printf("Welcome to our Scientific Calculator!\n");
    printf("Choose an operation from the following:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Arcsine\n");
    printf("11. Arccosine\n");
    printf("12. Arctangent\n");

    // get user input for operation
    printf("Enter the operation number: ");
    scanf("%d", &option);

    // perform operation based on user input
    switch(option)
    {
        case 1:
            // addition operation
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            // subtraction operation
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            // multiplication operation
            printf("Enter the first number: ");
            scanf("%lf", &num1);
            printf("Enter the second number: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            // division operation
            printf("Enter the numerator: ");
            scanf("%lf", &num1);
            printf("Enter the denominator: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 5:
            // power operation
            printf("Enter the base: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 6:
            // square root operation
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = squareRoot(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 7:
            // sine operation
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            result = sine(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 8:
            // cosine operation
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            result = cosine(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 9:
            // tangent operation
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            result = tangent(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 10:
            // arcsine operation
            printf("Enter the value of sin(x): ");
            scanf("%lf", &num1);
            result = arcSine(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 11:
            // arccosine operation
            printf("Enter the value of cos(x): ");
            scanf("%lf", &num1);
            result = arcCosine(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 12:
            // arctangent operation
            printf("Enter the value of tan(x): ");
            scanf("%lf", &num1);
            result = arcTangent(num1);
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("Invalid option selected.\n");
    }

    return 0;
}

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
        printf("Error: Division by zero.\n");
        exit(EXIT_FAILURE);
    }
    return num1 / num2;
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

double squareRoot(double num1)
{
    if(num1 < 0)
    {
        printf("Error: Negative number.\n");
        exit(EXIT_FAILURE);
    }
    return sqrt(num1);
}

double sine(double num1)
{
    return sin(num1);
}

double cosine(double num1)
{
    return cos(num1);
}

double tangent(double num1)
{
    return tan(num1);
}

double arcSine(double num1)
{
    if(num1 > 1 || num1 < -1)
    {
        printf("Error: Invalid value.\n");
        exit(EXIT_FAILURE);
    }
    return asin(num1);
}

double arcCosine(double num1)
{
    if(num1 > 1 || num1 < -1)
    {
        printf("Error: Invalid value.\n");
        exit(EXIT_FAILURE);
    }
    return acos(num1);
}

double arcTangent(double num1)
{
    return atan(num1);
}