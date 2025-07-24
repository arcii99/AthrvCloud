//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototype for functions
void add();
void subtract();
void multiply();
void divide();
void square();
void square_root();
void power();
void factorial();

int main()
{
    int choice;
    while (1)
    {
        printf ("Scientific Calculator Menu\n");
        printf ("---------------------------\n");
        printf ("1. Addition\n");
        printf ("2. Subtraction\n");
        printf ("3. Multiplication\n");
        printf ("4. Division\n");
        printf ("5. Square\n");
        printf ("6. Square Root\n");
        printf ("7. Power\n");
        printf ("8. Factorial\n");
        printf ("9. Exit\n");
        printf ("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                square();
                break;
            case 6:
                square_root();
                break;
            case 7:
                power();
                break;
            case 8:
                factorial();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void add()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 + num2;
    printf("Result: %.2f\n", result);
}

void subtract()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 - num2;
    printf("Result: %.2f\n", result);
}

void multiply()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 * num2;
    printf("Result: %.2f\n", result);
}

void divide()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    if (num2 == 0)
    {
        printf("Error: Division by zero\n");
    }
    else
    {
        result = num1 / num2;
        printf("Result: %.2f\n", result);
    }
}

void square()
{
    float num, result;
    printf("Enter a number: ");
    scanf("%f", &num);
    result = num * num;
    printf("Result: %.2f\n", result);
}

void square_root()
{
    float num, result;
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num < 0)
    {
        printf("Error: Invalid input\n");
    }
    else
    {
        result = sqrt(num);
        printf("Result: %.2f\n", result);
    }
}

void power()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = pow(num1, num2);
    printf("Result: %.2f\n", result);
}

void factorial()
{
    int num, i;
    unsigned long long result = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Error: Invalid input\n");
    }
    else
    {
        for (i = 1; i <= num; i++)
        {
            result *= i;
        }
        printf("Result: %llu\n", result);
    }
}