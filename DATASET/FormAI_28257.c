//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function prototypes
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double exponentiation(double, double);
double factorial(double);

//Main function
int main()
{
    char operator;
    double num1, num2, result;
    printf("Welcome to my Scientific Calculator\n");
    printf("Enter an operator (+, -, *, /, ^, !): ");
    scanf("%c", &operator);

    switch(operator)
    {
        case '+':
            printf("Enter two numbers separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = addition(num1, num2);
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            break;

        case '-':
            printf("Enter two numbers separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtraction(num1, num2);
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            break;

        case '*':
            printf("Enter two numbers separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiplication(num1, num2);
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            break;

        case '/':
            printf("Enter two numbers separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = division(num1, num2);
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
            break;

        case '^':
            printf("Enter two numbers separated by a space: ");
            scanf("%lf %lf", &num1, &num2);
            result = exponentiation(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf", num1, num2, result);
            break;

        case '!':
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = factorial(num1);
            printf("%.2lf! = %.2lf", num1, result);
            break;

        default:
            printf("Invalid operator.");
    }
    return 0;
}

double addition(double num1, double num2)
{
    return num1 + num2;
}

double subtraction(double num1, double num2)
{
    return num1 - num2;
}

double multiplication(double num1, double num2)
{
    return num1 * num2;
}

double division(double num1, double num2)
{
    if(num2 == 0)
    {
        printf("Error! Division by zero.");
        exit(0);
    }
    return num1 / num2;
}

double exponentiation(double base, double exponent)
{
    return pow(base, exponent);
}

double factorial(double num)
{
    double result = 1;
    int i;

    if(num < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
        exit(0);
    }

    for(i = 1; i <= num; i++)
    {
        result *= i;
    }

    return result;
}