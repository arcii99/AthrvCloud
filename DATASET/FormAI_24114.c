//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'
#define MODULUS '%'
#define POWER '^'
#define LOGARITHM 'l'

float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
float modulus(float num1, float num2);
float power(float num1, float num2);
float logarithm(float num);

int main()
{
    char operator;
    float num1, num2, result;

    printf("Enter an operator (+, -, *, /, %%, ^, l): ");
    scanf("%c", &operator);

    switch (operator)
    {
        case ADDITION:
            printf("Enter two numbers to add: ");
            scanf("%f %f", &num1, &num2);
            result = addition(num1, num2);
            printf("%.2f + %.2f = %.2f", num1, num2, result);
            break;

        case SUBTRACTION:
            printf("Enter two numbers to subtract: ");
            scanf("%f %f", &num1, &num2);
            result = subtraction(num1, num2);
            printf("%.2f - %.2f = %.2f", num1, num2, result);
            break;

        case MULTIPLICATION:
            printf("Enter two numbers to multiply: ");
            scanf("%f %f", &num1, &num2);
            result = multiplication(num1, num2);
            printf("%.2f * %.2f = %.2f", num1, num2, result);
            break;

        case DIVISION:
            printf("Enter two numbers to divide: ");
            scanf("%f %f", &num1, &num2);
            result = division(num1, num2);
            printf("%.2f / %.2f = %.2f", num1, num2, result);
            break;

        case MODULUS:
            printf("Enter two numbers to get modulus: ");
            scanf("%f %f", &num1, &num2);
            result = modulus(num1, num2);
            printf("%.2f %% %.2f = %.2f", num1, num2, result);
            break;

        case POWER:
            printf("Enter a number and its power: ");
            scanf("%f %f", &num1, &num2);
            result = power(num1, num2);
            printf("%.2f ^ %.2f = %.2f", num1, num2, result);
            break;

        case LOGARITHM:
            printf("Enter a number to get its logarithm: ");
            scanf("%f", &num1);
            result = logarithm(num1);
            printf("log(%.2f) = %.2f", num1, result);
            break;

        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}

float addition(float num1, float num2)
{
    return num1 + num2;
}

float subtraction(float num1, float num2)
{
    return num1 - num2;
}

float multiplication(float num1, float num2)
{
    return num1 * num2;
}

float division(float num1, float num2)
{
    return num1 / num2;
}

float modulus(float num1, float num2)
{
    return fmod(num1, num2);
}

float power(float num1, float num2)
{
    return pow(num1, num2);
}

float logarithm(float num)
{
    return log(num);
}