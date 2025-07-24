//FormAI DATASET v1.0 Category: Calculator ; Style: recursive
#include <stdio.h>

int main()
{
    int choice;
    do
    {
        printf("Choose an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Exit\n");
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
                modulus();
                break;
            case 6:
                power();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose between 1-7.\n");
                break;
        }
    } while(choice != 7);

    return 0;
}

void add()
{
    int a, b;
    printf("Enter two numbers to add: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a + b);
    return;
}

void subtract()
{
    int a, b;
    printf("Enter two numbers to subtract: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a - b);
    return;
}

void multiply()
{
    int a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a * b);
    return;
}

void divide()
{
    int a, b;
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &a, &b);
    if(b == 0)
    {
        printf("Cannot divide by zero.\n");
        return;
    }
    printf("Result: %d\n", a / b);
    return;
}

void modulus()
{
    int a, b;
    printf("Enter two numbers to find modulus: ");
    scanf("%d %d", &a, &b);
    printf("Result: %d\n", a % b);
    return;
}

void power()
{
    int base, exponent;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    printf("Result: %d\n", recursive_power(base, exponent));
    return;
}

int recursive_power(int base, int exponent)
{
    if(exponent == 0)
        return 1;
    else if(exponent == 1)
        return base;
    else
        return base * recursive_power(base, exponent - 1);
}