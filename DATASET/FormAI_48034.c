//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int menu();
void addition();
void subtraction();
void multiplication();
void division();
void sine();
void cosine();
void tangent();
void arcsine();
void arccosine();
void arctangent();
void square();
void squareRoot();
void power();
void factorial();
void logarithm();
void naturalLogarithm();

int main()
{
    int choice;
    printf("Welcome to my calculator program!\n");

    do
    {
        choice = menu();

        switch (choice)
        {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                sine();
                break;
            case 6:
                cosine();
                break;
            case 7:
                tangent();
                break;
            case 8:
                arcsine();
                break;
            case 9:
                arccosine();
                break;
            case 10:
                arctangent();
                break;
            case 11:
                square();
                break;
            case 12:
                squareRoot();
                break;
            case 13:
                power();
                break;
            case 14:
                factorial();
                break;
            case 15:
                logarithm();
                break;
            case 16:
                naturalLogarithm();
                break;
            case 17:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 17);

    return 0;
}

int menu()
{
    int choice;

    printf("\n---MENU---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Arcsine\n");
    printf("9. Arccosine\n");
    printf("10. Arctangent\n");
    printf("11. Square\n");
    printf("12. Square Root\n");
    printf("13. Power\n");
    printf("14. Factorial\n");
    printf("15. Logarithm\n");
    printf("16. Natural Logarithm\n");
    printf("17. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void addition()
{
    double num1, num2, result;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 + num2;

    printf("Result: %lf\n", result);
}

void subtraction()
{
    double num1, num2, result;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 - num2;

    printf("Result: %lf\n", result);
}

void multiplication()
{
    double num1, num2, result;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    result = num1 * num2;

    printf("Result: %lf\n", result);
}

void division()
{
    double num1, num2, result;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    if (num2 == 0)
    {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }

    result = num1 / num2;

    printf("Result: %lf\n", result);
}

void sine()
{
    double degree, radians, result;

    printf("Enter degree: ");
    scanf("%lf", &degree);

    radians = degree * PI / 180;

    result = sin(radians);

    printf("Result: %lf\n", result);
}

void cosine()
{
    double degree, radians, result;

    printf("Enter degree: ");
    scanf("%lf", &degree);

    radians = degree * PI / 180;

    result = cos(radians);

    printf("Result: %lf\n", result);
}

void tangent()
{
    double degree, radians, result;

    printf("Enter degree: ");
    scanf("%lf", &degree);

    radians = degree * PI / 180;

    result = tan(radians);

    printf("Result: %lf\n", result);
}

void arcsine()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    if (num < -1 || num > 1)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    result = asin(num) * 180 / PI;

    printf("Result: %lf\n", result);
}

void arccosine()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    if (num < -1 || num > 1)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    result = acos(num) * 180 / PI;

    printf("Result: %lf\n", result);
}

void arctangent()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    result = atan(num) * 180 / PI;

    printf("Result: %lf\n", result);
}

void square()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    result = num * num;

    printf("Result: %lf\n", result);
}

void squareRoot()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    if (num < 0)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    result = sqrt(num);

    printf("Result: %lf\n", result);
}

void power()
{
    double base, exponent, result;

    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%lf", &exponent);

    result = pow(base, exponent);

    printf("Result: %lf\n", result);
}

void factorial()
{
    int num, i;
    double result = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    for (i = 1; i <= num; i++)
    {
        result = result * i;
    }

    printf("Result: %lf\n", result);
}

void logarithm()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    if (num <= 0)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    result = log10(num);

    printf("Result: %lf\n", result);
}

void naturalLogarithm()
{
    double num, result;

    printf("Enter number: ");
    scanf("%lf", &num);

    if (num <= 0)
    {
        printf("Error: Invalid input.\n");
        return;
    }

    result = log(num);

    printf("Result: %lf\n", result);
}