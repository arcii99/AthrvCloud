//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void addition();
void subtraction();
void multiplication();
void division();
void power();
void square_root();
void absolute_value();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
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
            power();
            break;
        case 6:
            square_root();
            break;
        case 7:
            absolute_value();
            break;
        default:
            printf("Invalid choice.\n");
            menu();
    }
}

void addition()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 + num2;
    printf("Result: %lf\n", result);
}

void subtraction()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 - num2;
    printf("Result: %lf\n", result);
}

void multiplication()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf("Result: %lf\n", result);
}

void division()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    if(num2 == 0)
    {
        printf("Error: Division by zero.\n");
        division();
    }
    else
    {
        result = num1 / num2;
        printf("Result: %lf\n", result);
    }
}

void power()
{
    double num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    result = pow(num1, num2);
    printf("Result: %lf\n", result);
}

void square_root()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);
    result = sqrt(num);
    printf("Result: %lf\n", result);
}

void absolute_value()
{
    double num, result;
    printf("Enter a number: ");
    scanf("%lf", &num);
    result = fabs(num);
    printf("Result: %lf\n", result);
}