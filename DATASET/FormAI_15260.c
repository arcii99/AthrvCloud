//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include<stdio.h>
#include<math.h>

//function definitions
int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int power(int a, int b);
float square_root(int a);
float absolute_value(int a);

int main()
{
    int choice, a, b;
    float result;

    printf("Welcome to C Scientific Calculator Implementation\n");
    printf("Please select an operation from the following list:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter two numbers to add: ");
            scanf("%d %d", &a, &b);
            result = addition(a, b);
            printf("%d + %d = %.2f", a, b, result);
            break;

        case 2:
            printf("Enter two numbers to subtract: ");
            scanf("%d %d", &a, &b);
            result = subtraction(a, b);
            printf("%d - %d = %.2f", a, b, result);
            break;

        case 3:
            printf("Enter two numbers to multiply: ");
            scanf("%d %d", &a, &b);
            result = multiplication(a, b);
            printf("%d x %d = %.2f", a, b, result);
            break;

        case 4:
            printf("Enter two numbers to divide: ");
            scanf("%d %d", &a, &b);
            result = division(a, b);
            printf("%d / %d = %.2f", a, b, result);
            break;

        case 5:
            printf("Enter a number and its power: ");
            scanf("%d %d", &a, &b);
            result = power(a, b);
            printf("%d^%d = %.2f", a, b, result);
            break;

        case 6:
            printf("Enter a number to find its square root: ");
            scanf("%d", &a);
            result = square_root(a);
            printf("√%d = %.2f", a, result);
            break;

        case 7:
            printf("Enter a number to find its absolute value: ");
            scanf("%d", &a);
            result = absolute_value(a);
            printf("|%d| = %.2f", a, result);
            break;

        default:
            printf("Error: Invalid Choice!");
    }

    return 0;
}

//function implementations
int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if(b==0)
    {
        printf("Error: Division by zero\n");
        return 0;
    }
    else
    {
        return (float)a/b;
    }
}

int power(int a, int b)
{
    return pow(a, b);
}

float square_root(int a)
{
    return sqrt(a);
}

float absolute_value(int a)
{
    return fabs(a);
}