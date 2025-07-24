//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declarations
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
float power(float a, float b);
float square_root(float a);
float absolute(float a);
float logarithm(float a);
void print_menu();

// Main Function
int main()
{
    // Variable Declarations
    int choice;
    float num1, num2, result;

    do
    {
        // Display Menu and Get User's Choice
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the Selected Operation
        switch(choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2f\n", result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2f\n", result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2f\n", result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = divide(num1, num2);
                printf("Result: %.2f\n", result);
                break;

            case 5:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = power(num1, 2);
                printf("Result: %.2f\n", result);
                break;

            case 6:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = square_root(num1);
                printf("Result: %.2f\n", result);
                break;

            case 7:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = absolute(num1);
                printf("Result: %.2f\n", result);
                break;
            
            case 8:
                printf("Enter a number: ");
                scanf("%f", &num1);
                result = logarithm(num1);
                printf("Result: %.2f\n", result);
                break;

            case 9:
                printf("Exiting Program...\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice...Please Try Again.\n");
                break;
        }

    } while(choice != 9);

    return 0;
}

// Function Definitions
void print_menu()
{
    printf("\nMenu\n====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("8. Logarithm\n");
    printf("9. Quit\n");
}

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    if(b == 0)
    {
        printf("Error: Division by Zero\n");
        return 0;
    }
    else
    {
        return a / b;
    }
}

float power(float a, float b)
{
    return pow(a, b);
}

float square_root(float a)
{
    if(a < 0)
    {
        printf("Error: Square Root of Negative Number\n");
        return 0;
    }
    else
    {
        return sqrt(a);
    }
}

float absolute(float a)
{
    return fabs(a);
}

float logarithm(float a)
{
    if(a <= 0)
    {
        printf("Error: Logarithm of Non-Positive Number\n");
        return 0;
    }
    else
    {
        return log10(a);
    }
}