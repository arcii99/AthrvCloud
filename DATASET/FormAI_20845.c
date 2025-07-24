//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0) {
        printf("Error: cannot divide by zero\n");
        return 0;
    }
    return a / b;
}

double power(double a, double b)
{
    return pow(a, b);
}

double square(double a)
{
    return pow(a, 2);
}

double cube(double a)
{
    return pow(a, 3);
}

double absolute(double a)
{
    return abs(a);
}

int main()
{
    int choice;
    double num1, num2, result;

    printf("Select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("5. Power\n6. Square\n7. Cube\n8. Absolute\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 5:
            printf("Enter the base and the exponent:\n");
            scanf("%lf %lf", &num1, &num2);
            result = power(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 6:
            printf("Enter a number to square:\n");
            scanf("%lf", &num1);
            result = square(num1);
            printf("The result is: %lf\n", result);
            break;
        case 7:
            printf("Enter a number to cube:\n");
            scanf("%lf", &num1);
            result = cube(num1);
            printf("The result is: %lf\n", result);
            break;
        case 8:
            printf("Enter a number to find the absolute value of:\n");
            scanf("%lf", &num1);
            result = absolute(num1);
            printf("The result is: %lf\n", result);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}