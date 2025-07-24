//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double root(double x);
double logarithm(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);
double arcsine(double x);
double arccosine(double x);
double arctangent(double x);
double degrees_to_radians(double x);
double radians_to_degrees(double x);

int main()
{
    double num1, num2;
    char operator;

    printf("Welcome to my Scientific Calculator!\n\n");

    printf("Please enter a number: ");
    scanf("%lf", &num1);
    printf("Please enter an operator (+, -, *, /, ^, r, l, s, c, t, a, b, n): ");
    scanf(" %c", &operator);

    // perform appropriate operation based on user input
    switch(operator) {
        case '+':
            printf("Please enter another number: ");
            scanf("%lf", &num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("Please enter another number: ");
            scanf("%lf", &num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("Please enter another number: ");
            scanf("%lf", &num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, multiply(num1, num2));
            break;
        case '/':
            printf("Please enter another number: ");
            scanf("%lf", &num2);
            if (num2 == 0) {
                printf("Error: Cannot divide by zero.\n");
            } else {
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, divide(num1, num2));
            }
            break;
        case '^':
            printf("Please enter the power: ");
            scanf("%lf", &num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, power(num1, num2));
            break;
        case 'r':
            printf("The square root of %.2lf = %.2lf\n", num1, root(num1));
            break;
        case 'l':
            printf("The natural logarithm of %.2lf = %.2lf\n", num1, logarithm(num1));
            break;
        case 's':
            printf("The sine of %.2lf degrees = %.2lf\n", num1, sine(num1));
            break;
        case 'c':
            printf("The cosine of %.2lf degrees = %.2lf\n", num1, cosine(num1));
            break;
        case 't':
            printf("The tangent of %.2lf degrees = %.2lf\n", num1, tangent(num1));
            break;
        case 'a':
            printf("The arcsine of %.2lf = %.2lf degrees\n", num1, arcsine(num1));
            break;
        case 'b':
            printf("The arccosine of %.2lf = %.2lf degrees\n", num1, arccosine(num1));
            break;
        case 'n':
            printf("%.2lf degrees = %.2lf radians\n", num1, degrees_to_radians(num1));
            break;
        default:
            printf("Error: Invalid operator.\n");
    }

    return 0;
}

// function to add two numbers
double add(double x, double y)
{
    return x + y;
}

// function to subtract two numbers
double subtract(double x, double y)
{
    return x - y;
}

// function to multiply two numbers
double multiply(double x, double y)
{
    return x * y;
}

// function to divide two numbers
double divide(double x, double y)
{
    return x / y;
}

// function to raise a number to a power
double power(double x, double y)
{
    return pow(x, y);
}

// function to find the square root of a number
double root(double x)
{
    return sqrt(x);
}

// function to find the natural logarithm of a number
double logarithm(double x)
{
    return log(x);
}

// function to find the sine of an angle in degrees
double sine(double x)
{
    double radians = x * M_PI / 180;
    return sin(radians);
}

// function to find the cosine of an angle in degrees
double cosine(double x)
{
    double radians = x * M_PI / 180;
    return cos(radians);
}

// function to find the tangent of an angle in degrees
double tangent(double x)
{
    double radians = x * M_PI / 180;
    return tan(radians);
}

// function to find the arcsine of a number
double arcsine(double x)
{
    double radians = asin(x);
    return radians * 180 / M_PI;
}

// function to find the arccosine of a number
double arccosine(double x)
{
    double radians = acos(x);
    return radians * 180 / M_PI;
}

// function to find the arctangent of a number
double arctangent(double x)
{
    double radians = atan(x);
    return radians * 180 / M_PI;
}

// function to convert degrees to radians
double degrees_to_radians(double x)
{
    return x * M_PI / 180;
}

// function to convert radians to degrees
double radians_to_degrees(double x)
{
    return x * 180 / M_PI;
}