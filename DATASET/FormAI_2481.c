//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
void add();
void subtract();
void multiply();
void divide();
void power();
void sin_func();
void cos_func();
void tan_func();
void log_func();
void sqrt_func();
void clear();

int main()
{
    int choice;
    do
    {
        printf("Scientific Calculator\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Sin\n");
        printf("7. Cos\n");
        printf("8. Tan\n");
        printf("9. Log\n");
        printf("10. Square Root\n");
        printf("11. Clear\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
                sin_func();
                break;
            case 7:
                cos_func();
                break;
            case 8:
                tan_func();
                break;
            case 9:
                log_func();
                break;
            case 10:
                sqrt_func();
                break;
            case 11:
                clear();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while(choice != 0);
    return 0;
}

void add()
{
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Result: %d\n", num1 + num2);
}

void subtract()
{
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Result: %d\n", num1 - num2);
}

void multiply()
{
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Result: %d\n", num1 * num2);
}

void divide()
{
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Result: %d\n", num1 / num2);
}

void power()
{
    int num1, num2;
    printf("Enter base: ");
    scanf("%d", &num1);
    printf("Enter exponent: ");
    scanf("%d", &num2);
    printf("Result: %f\n", pow(num1, num2));
}

void sin_func()
{
    float num;
    printf("Enter angle in degrees: ");
    scanf("%f", &num);
    printf("Result: %f\n", sin(num * M_PI / 180));
}

void cos_func()
{
    float num;
    printf("Enter angle in degrees: ");
    scanf("%f", &num);
    printf("Result: %f\n", cos(num * M_PI / 180));
}

void tan_func()
{
    float num;
    printf("Enter angle in degrees: ");
    scanf("%f", &num);
    printf("Result: %f\n", tan(num * M_PI / 180));
}

void log_func()
{
    float num;
    printf("Enter number: ");
    scanf("%f", &num);
    printf("Result: %f\n", log10(num));
}

void sqrt_func()
{
    float num;
    printf("Enter number: ");
    scanf("%f", &num);
    printf("Result: %f\n", sqrt(num));
}

void clear()
{
    system("clear");
}