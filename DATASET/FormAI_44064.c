//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function prototypes
void add();
void subtract();
void multiply();
void divide();
void power();
void square_root();
void absolute_value();

int main()
{
    int choice;
    printf("Welcome to the Happy Calculator! Here all your calculations will be joyful!\n");

    while(1)
    {
        printf("\nSelect a mathematical operation:\n");
        printf("\n1. Addition");
        printf("\n2. Subtraction");
        printf("\n3. Multiplication");
        printf("\n4. Division");
        printf("\n5. Power of a Number");
        printf("\n6. Square Root");
        printf("\n7. Absolute Value");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
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
                power();
                break;
            case 6:
                square_root();
                break;
            case 7:
                absolute_value();
                break;

            default:
                printf("Invalid choice! Please try again.");
                break;
        }
    }
    return 0;
}

//function to perform addition
void add()
{
    double num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = num1 + num2;
    printf("\nResult: %.2lf\n", result);
    printf("Addition is joyful!\n");
}

//function to perform subtraction
void subtract()
{
    double num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = num1 - num2;
    printf("\nResult: %.2lf\n", result);
    printf("Subtraction is a happy journey!\n");
}

//function to perform multiplication
void multiply()
{
    double num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    result = num1 * num2;
    printf("\nResult: %.2lf\n", result);
    printf("Multiplication brings a lot of joy!\n");
}

//function to perform division
void divide()
{
    double num1, num2, result;
    printf("\nEnter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    if(num2 == 0)
    {
        printf("\nCannot divide by zero. Please try again.\n");
        return;
    }
    result = num1/num2;
    printf("\nResult: %.2lf\n", result);
    printf("Division spreads happiness!\n");
}

//function to perform power
void power()
{
    double num1, num2, result;
    printf("\nEnter the number: ");
    scanf("%lf", &num1);

    printf("Enter the power: ");
    scanf("%lf", &num2);

    result = pow(num1, num2);
    printf("\nResult: %.2lf\n", result);
    printf("Power is a joyful experience!\n");
}

//function to perform square root
void square_root()
{
    double num, result;
    printf("\nEnter the number: ");
    scanf("%lf", &num);

    if(num < 0)
    {
        printf("\nCannot find square root of negative numbers. Please try again.\n");
        return;
    }
    result = sqrt(num);
    printf("\nResult: %.2lf\n", result);
    printf("Square root is a happy ending!\n");
}

//function to perform absolute value
void absolute_value()
{
    double num, result;
    printf("\nEnter the number: ");
    scanf("%lf", &num);

    result = abs(num);
    printf("\nResult: %.2lf\n", result);
    printf("Absolute value is a happy place!\n");
}