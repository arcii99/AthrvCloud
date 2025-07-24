//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
float natural_logarithm(float num);
float power(float num, float power);
float sine(float num);
float cosine(float num);
float tangent(float num);

// Main Program
int main()
{
    int choice;
    float num1, num2, result;

    printf("Welcome to my Scientific Calculator Implementation Program!\n\n");

    do {
        // Menu Display
        printf("Please choose from the following options:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Natural Logarithm\n");
        printf("6. Power\n");
        printf("7. Sine\n");
        printf("8. Cosine\n");
        printf("9. Tangent\n");
        printf("10. Exit\n\n");

        // User Input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Calculation and Display of Result
        switch (choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = addition(num1, num2);
                printf("The sum is: %.2f\n\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = subtraction(num1, num2);
                printf("The difference is: %.2f\n\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = multiplication(num1, num2);
                printf("The product is: %.2f\n\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = division(num1, num2);
                printf("The quotient is: %.2f\n\n", result);
                break;

            case 5:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = natural_logarithm(num1);
                printf("The natural logarithm is: %.2f\n\n", result);
                break;

            case 6:
                printf("Enter a number and its power: ");
                scanf("%f %f", &num1, &num2);
                result = power(num1, num2);
                printf("The result is: %.2f\n\n", result);
                break;

            case 7:
                printf("Enter a number in degrees: ");
                scanf("%f", &num1);
                result = sine(num1);
                printf("The sine value is: %.2f\n\n", result);
                break;

            case 8:
                printf("Enter a number in degrees: ");
                scanf("%f", &num1);
                result = cosine(num1);
                printf("The cosine value is: %.2f\n\n", result);
                break;

            case 9:
                printf("Enter a number in degrees: ");
                scanf("%f", &num1);
                result = tangent(num1);
                printf("The tangent value is: %.2f\n\n", result);
                break;

            case 10:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 10);

    return 0;
}

// Function Implementations
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
    if (num2 == 0)
    {
        printf("Division by zero error!\n");
        return 0;
    }
    else
    {
        return num1 / num2;
    }
}

float natural_logarithm(float num)
{
    return log(num);
}

float power(float num, float power)
{
    return pow(num, power);
}

float sine(float num)
{
    return sin(num * 3.14159 / 180);
}

float cosine(float num)
{
    return cos(num * 3.14159 / 180);
}

float tangent(float num)
{
    return tan(num * 3.14159 / 180);
}