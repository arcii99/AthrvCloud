//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMenu();
double getNumber();
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double root(double x);
double absolute(double x);
double factorial(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);

int main()
{
    int choice;
    double x, y, result;

    do
    {
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                x = getNumber();
                y = getNumber();
                result = add(x, y);
                printf("Result: %.2lf\n", result);
                break;

            case 2:
                x = getNumber();
                y = getNumber();
                result = subtract(x, y);
                printf("Result: %.2lf\n", result);
                break;

            case 3:
                x = getNumber();
                y = getNumber();
                result = multiply(x, y);
                printf("Result: %.2lf\n", result);
                break;

            case 4:
                x = getNumber();
                y = getNumber();
                result = divide(x, y);
                printf("Result: %.2lf\n", result);
                break;

            case 5:
                x = getNumber();
                y = getNumber();
                result = power(x, y);
                printf("Result: %.2lf\n", result);
                break;

            case 6:
                x = getNumber();
                result = root(x);
                printf("Result: %.2lf\n", result);
                break;

            case 7:
                x = getNumber();
                result = absolute(x);
                printf("Result: %.2lf\n", result);
                break;

            case 8:
                x = getNumber();
                result = factorial(x);
                printf("Result: %.2lf\n", result);
                break;

            case 9:
                x = getNumber();
                result = sine(x);
                printf("Result: %.2lf\n", result);
                break;

            case 10:
                x = getNumber();
                result = cosine(x);
                printf("Result: %.2lf\n", result);
                break;

            case 11:
                x = getNumber();
                result = tangent(x);
                printf("Result: %.2lf\n", result);
                break;

            case 12:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid input\n");
                break;
        }

    } while (1);

    return 0;
}

void printMenu()
{
    printf("\n");
    printf("Scientific Calculator\n");
    printf("----------------------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Root\n");
    printf("7. Absolute\n");
    printf("8. Factorial\n");
    printf("9. Sine\n");
    printf("10. Cosine\n");
    printf("11. Tangent\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
}

double getNumber()
{
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    return num;
}

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
    if (y == 0)
    {
        printf("Error: Division by zero\n");
        exit(1);
    }

    return x / y;
}

double power(double x, double y)
{
    return pow(x, y);
}

double root(double x)
{
    return sqrt(x);
}

double absolute(double x)
{
    return fabs(x);
}

double factorial(double x)
{
    int i;
    double fact = 1;
    if (x < 0)
    {
        printf("Error: Factorial of negative number\n");
        exit(1);
    }
    
    for (i = 1; i <= x; i++)
    {
        fact *= i;
    }

    return fact;
}

double sine(double x)
{
    return sin(x);
}

double cosine(double x)
{
    return cos(x);
}

double tangent(double x)
{
    if (cos(x) == 0)
    {
        printf("Error: Tangent undefined\n");
        exit(1);
    }

    return tan(x);
}