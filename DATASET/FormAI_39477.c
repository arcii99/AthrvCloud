//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void addition();
void subtraction();
void multiplication();
void division();
void power();
void modular();
void factorial();
void sine();
void cosine();
void tangent();

int main()
{
    int choice;

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Modular\n");
    printf("7. Factorial\n");
    printf("8. Sine\n");
    printf("9. Cosine\n");
    printf("10. Tangent\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1: addition(); break;
        case 2: subtraction(); break;
        case 3: multiplication(); break;
        case 4: division(); break;
        case 5: power(); break;
        case 6: modular(); break;
        case 7: factorial(); break;
        case 8: sine(); break;
        case 9: cosine(); break;
        case 10: tangent(); break;
        default: printf("Invalid choice! Try again.");
    }
}

void addition()
{
    double num1, num2, sum;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    sum = num1 + num2;
    printf("Sum = %.2lf", sum);
}

void subtraction()
{
    double num1, num2, diff;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    diff = num1 - num2;
    printf("Difference = %.2lf", diff);
}

void multiplication()
{
    double num1, num2, product;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    product = num1 * num2;
    printf("Product = %.2lf", product);
}

void division()
{
    double num1, num2, quotient;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    if(num2 == 0)
    {
        printf("Error! Cannot divide by zero.");
        exit(0);
    }

    quotient = num1 / num2;
    printf("Quotient = %.2lf", quotient);
}

void power()
{
    double num, exp, result;
    printf("Enter number: ");
    scanf("%lf", &num);
    printf("Enter exponent: ");
    scanf("%lf", &exp);
    result = pow(num, exp);
    printf("Result = %.2lf", result);
}

void modular()
{
    int num1, num2, result;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    if(num2 == 0)
    {
        printf("Error! Cannot perform modular division with zero.");
        exit(0);
    }

    result = num1 % num2;
    printf("Result = %d", result);
}

void factorial()
{
    int num, i;
    unsigned long long fact = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
        exit(0);
    }

    for(i = 1; i <= num; ++i)
    {
        fact *= i;
    }

    printf("Factorial of %d = %llu", num, fact);
}

void sine()
{
    double angle, result;
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    result = sin(angle * M_PI / 180);
    printf("Sine of %.2lf degrees = %.2lf", angle, result);
}

void cosine()
{
    double angle, result;
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    result = cos(angle * M_PI / 180);
    printf("Cosine of %.2lf degrees = %.2lf", angle, result);
}

void tangent()
{
    double angle, result;
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    result = tan(angle * M_PI / 180);
    printf("Tangent of %.2lf degrees = %.2lf", angle, result);
}