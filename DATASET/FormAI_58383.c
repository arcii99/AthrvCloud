//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double absolute(double a);
double power(double a, double b);
double squareRoot(double a);
double logBase10(double a);

int main()
{
    int option;
    double num1, num2, result;
    
    do {
        /* Show menu */
        printf("\nScientific calculator\n\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Absolute value\n");
        printf("6. Power\n");
        printf("7. Square root\n");
        printf("8. Log base 10\n");
        printf("0. Exit\n");
        
        /* Get user input */
        printf("\nEnter option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("\nResult: %lf\n", result);
                break;
            case 2:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("\nResult: %lf\n", result);
                break;
            case 3:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("\nResult: %lf\n", result);
                break;
            case 4:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("\nResult: %lf\n", result);
                break;
            case 5:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = absolute(num1);
                printf("\nResult: %lf\n", result);
                break;
            case 6:
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("\nResult: %lf\n", result);
                break;
            case 7:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("\nResult: %lf\n", result);
                break;
            case 8:
                printf("\nEnter a number: ");
                scanf("%lf", &num1);
                result = logBase10(num1);
                printf("\nResult: %lf\n", result);
                break;
            case 0:
                printf("\nExiting calculator...\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
                break;
        }
    } while (option != 0);
    
    return 0;
}

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

double absolute(double a)
{
    return fabs(a);
}

double power(double a, double b)
{
    return pow(a, b);
}

double squareRoot(double a)
{
    return sqrt(a);
}

double logBase10(double a)
{
    return log10(a);
}