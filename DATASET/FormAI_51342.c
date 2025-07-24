//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <math.h>

/*Function Prototypes*/
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double factorial(double);
double sine(double);
double cosine(double);
double tangent(double);

int main()
{
    char operator;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator\n");
    printf("Please enter an operator (+, -, *, /, ^, !, sin, cos, tan): ");
    scanf("%c", &operator);

    switch (operator)
    {
    case '+':
        printf("Enter two numbers to add: ");
        scanf("%lf %lf", &num1, &num2);
        result = add(num1, num2);
        break;

    case '-':
        printf("Enter two numbers to subtract: ");
        scanf("%lf %lf", &num1, &num2);
        result = subtract(num1, num2);
        break;

    case '*':
        printf("Enter two numbers to multiply: ");
        scanf("%lf %lf", &num1, &num2);
        result = multiply(num1, num2);
        break;

    case '/':
        printf("Enter two numbers to divide: ");
        scanf("%lf %lf", &num1, &num2);
        result = divide(num1, num2);
        break;

    case '^':
        printf("Enter a number and its exponent: ");
        scanf("%lf %lf", &num1, &num2);
        result = power(num1, num2);
        break;

    case '!':
        printf("Enter a number to find its factorial: ");
        scanf("%lf", &num1);
        result = factorial(num1);
        break;

    case 's':
        printf("Enter an angle in degrees: ");
        scanf("%lf", &num1);
        result = sine(num1);
        break;

    case 'c':
        printf("Enter an angle in degrees: ");
        scanf("%lf", &num1);
        result = cosine(num1);
        break;

    case 't':
        printf("Enter an angle in degrees: ");
        scanf("%lf", &num1);
        result = tangent(num1);
        break;

    default:
        printf("Error! Operator is not valid\n");
        return 1;
    }

    printf("Result: %lf\n", result);

    return 0;
}

/*Functions*/
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
    return num1 / num2;
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

double factorial(double num)
{
    int i;
    double result = 1;

    for (i = 1; i <= num; i++)
    {
        result *= i;
    }

    return result;
}

double sine(double num)
{
    return sin(num * M_PI / 180);
}

double cosine(double num)
{
    return cos(num * M_PI / 180);
}

double tangent(double num)
{
    return tan(num * M_PI / 180);
}