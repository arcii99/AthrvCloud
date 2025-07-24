//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double square_root(double);
double sine(double);
double cosine(double);
double tangent(double);
double arcsine(double);
double arccosine(double);
double arctangent(double);
double log_10(double);
double log_e(double);
double absolute(double);
double factorial(double);

// main function
int main()
{
    // variables
    int choice = 0;
    double num1, num2, result;

    // menu
    printf("Scientific Calculator\n");
    printf("---------------------\n");
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
    printf("13. Logarithm (base 10)\n");
    printf("14. Natural Logarithm (base e)\n");
    printf("15. Absolute Value\n");
    printf("16. Factorial\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 5:
            printf("Enter base number and exponent: ");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("Result: %lf\n", result);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = square_root(num1);
            printf("Result: %lf\n", result);
            break;

        case 7:
            printf("Enter an angle in radians: ");
            scanf("%lf", &num1);
            result = sine(num1);
            printf("Result: %lf\n", result);
            break;

        case 8:
            printf("Enter an angle in radians: ");
            scanf("%lf", &num1);
            result = cosine(num1);
            printf("Result: %lf\n", result);
            break;

        case 9:
            printf("Enter an angle in radians: ");
            scanf("%lf", &num1);
            result = tangent(num1);
            printf("Result: %lf\n", result);
            break;

        case 10:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = arcsine(num1);
            printf("Result: %lf\n", result);
            break;

        case 11:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = arccosine(num1);
            printf("Result: %lf\n", result);
            break;

        case 12:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = arctangent(num1);
            printf("Result: %lf\n", result);
            break;

        case 13:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = log_10(num1);
            printf("Result: %lf\n", result);
            break;

        case 14:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = log_e(num1);
            printf("Result: %lf\n", result);
            break;

        case 15:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = absolute(num1);
            printf("Result: %lf\n", result);
            break;

        case 16:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = factorial(num1);
            printf("Result: %lf\n", result);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

// function definitions
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

double power(double a, double b)
{
    return pow(a, b);
}

double square_root(double a)
{
    return sqrt(a);
}

double sine(double a)
{
    return sin(a);
}

double cosine(double a)
{
    return cos(a);
}

double tangent(double a)
{
    return tan(a);
}

double arcsine(double a)
{
    return asin(a);
}

double arccosine(double a)
{
    return acos(a);
}

double arctangent(double a)
{
    return atan(a);
}

double log_10(double a)
{
    return log10(a);
}

double log_e(double a)
{
    return log(a);
}

double absolute(double a)
{
    return fabs(a);
}

double factorial(double a)
{
    double result = 1;

    for(int i = 1; i <= a; i++)
    {
        result *= i;
    }

    return result;
}