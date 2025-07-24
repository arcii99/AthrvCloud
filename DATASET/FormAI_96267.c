//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: random
#include <stdio.h>
#include <math.h>

/* function declarations */
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);
float factorial(float);
float sin_func(float);
float cos_func(float);
float tan_func(float);
float sq_rt(float);

int main()
{
    int choice;
    float num1, num2, result;

    printf("\n Welcome to the C Scientific Calculator\n");
    printf(" -----------------------------\n");
    printf(" 1. Addition\n");
    printf(" 2. Subtraction\n");
    printf(" 3. Multiplication\n");
    printf(" 4. Division\n");
    printf(" 5. Power\n");
    printf(" 6. Factorial\n");
    printf(" 7. Sin\n");
    printf(" 8. Cos\n");
    printf(" 9. Tan\n");
    printf(" 10. Square Root\n");
    printf(" -----------------------------\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\n Enter number 1: ");
            scanf("%f", &num1);

            printf("\n Enter number 2: ");
            scanf("%f", &num2);

            result = add(num1, num2);
            printf("\n %.2f + %.2f = %.2f\n", num1, num2, result);
            break;

        case 2:
            printf("\n Enter number 1: ");
            scanf("%f", &num1);

            printf("\n Enter number 2: ");
            scanf("%f", &num2);

            result = subtract(num1, num2);
            printf("\n %.2f - %.2f = %.2f\n", num1, num2, result);
            break;

        case 3:
            printf("\n Enter number 1: ");
            scanf("%f", &num1);

            printf("\n Enter number 2: ");
            scanf("%f", &num2);

            result = multiply(num1, num2);
            printf("\n %.2f x %.2f = %.2f\n", num1, num2, result);
            break;

        case 4:
            printf("\n Enter number 1: ");
            scanf("%f", &num1);

            printf("\n Enter number 2: ");
            scanf("%f", &num2);

            result = divide(num1, num2);
            printf("\n %.2f / %.2f = %.2f\n", num1, num2, result);
            break;

        case 5:
            printf("\n Enter number: ");
            scanf("%f", &num1);

            printf("\n Enter power: ");
            scanf("%f", &num2);

            result = power(num1, num2);
            printf("\n %.2f ^ %.2f = %.2f\n", num1, num2, result);
            break;

        case 6:
            printf("\n Enter number: ");
            scanf("%f", &num1);

            result = factorial(num1);
            printf("\n Factorial of %.2f = %.2f\n", num1, result);
            break;

        case 7:
            printf("\n Enter angle in degrees: ");
            scanf("%f", &num1);

            result = sin_func(num1);
            printf("\n Sin(%.2f) = %.2f\n", num1, result);
            break;

        case 8:
            printf("\n Enter angle in degrees: ");
            scanf("%f", &num1);

            result = cos_func(num1);
            printf("\n Cos(%.2f) = %.2f\n", num1, result);
            break;

        case 9:
            printf("\n Enter angle in degrees: ");
            scanf("%f", &num1);

            result = tan_func(num1);
            printf("\n Tan(%.2f) = %.2f\n", num1, result);
            break;

        case 10:
            printf("\n Enter number: ");
            scanf("%f", &num1);

            result = sq_rt(num1);
            printf("\n Square root of %.2f = %.2f\n", num1, result);
            break;

        default:
            printf("\n Invalid choice! Please choose a number from 1-10. \n");
    }

    return 0;
}

float add(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}

float power(float num1, float num2)
{
    return pow(num1, num2);
}

float factorial(float num)
{
    float result = 1;

    for (int i = num; i > 0; i--)
    {
        result *= i;
    }

    return result;
}

float sin_func(float num)
{
    return sin(num * M_PI / 180);
}

float cos_func(float num)
{
    return cos(num * M_PI / 180);
}

float tan_func(float num)
{
    return tan(num * M_PI / 180);
}

float sq_rt(float num)
{
    return sqrt(num);
}