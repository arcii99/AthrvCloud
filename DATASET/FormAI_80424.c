//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition
double add(double x, double y);

// Function to perform subtraction
double subtract(double x, double y);

// Function to perform multiplication
double multiply(double x, double y);

// Function to perform division
double divide(double x, double y);

// Function to perform modulus
int modulus(int x, int y);

// Function to perform factorial
int factorial(int n);

// Function to perform square root
double square_root(double n);

// Function to perform power
double power(double x, double y);

// Function to display menu
void display_menu();

int main()
{
    int choice, n;
    double x, y, result;
    
    do
    {
        // Display menu
        display_menu();
        
        // Take user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                // Addition
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = add(x, y);
                printf("Result: %lf\n", result);
                break;
                
            case 2:
                // Subtraction
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = subtract(x, y);
                printf("Result: %lf\n", result);
                break;
                
            case 3:
                // Multiplication
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = multiply(x, y);
                printf("Result: %lf\n", result);
                break;
                
            case 4:
                // Division
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = divide(x, y);
                printf("Result: %lf\n", result);
                break;
                
            case 5:
                // Modulus
                printf("\nEnter two numbers: ");
                scanf("%d %d", &n, &x);
                result = modulus(n, x);
                printf("Result: %d\n", result);
                break;
                
            case 6:
                // Factorial
                printf("\nEnter a number: ");
                scanf("%d", &n);
                result = factorial(n);
                printf("Result: %d\n", result);
                break;
                
            case 7:
                // Square root
                printf("\nEnter a number: ");
                scanf("%lf", &n);
                result = square_root(n);
                printf("Result: %lf\n", result);
                break;
                
            case 8:
                // Power
                printf("\nEnter two numbers: ");
                scanf("%lf %lf", &x, &y);
                result = power(x, y);
                printf("Result: %lf\n", result);
                break;
                
            case 9:
                // Exit program
                printf("\nExiting program...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    while (choice != 9);
    
    return 0;
}

// Function to perform addition
double add(double x, double y)
{
    return x + y;
}

// Function to perform subtraction
double subtract(double x, double y)
{
    return x - y;
}

// Function to perform multiplication
double multiply(double x, double y)
{
    return x * y;
}

// Function to perform division
double divide(double x, double y)
{
    return x / y;
}

// Function to perform modulus
int modulus(int x, int y)
{
    return x % y;
}

// Function to perform factorial
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

// Function to perform square root
double square_root(double n)
{
    return sqrt(n);
}

// Function to perform power
double power(double x, double y)
{
    return pow(x, y);
}

// Function to display menu
void display_menu()
{
    printf("\n*** Welcome to C Scientific Calculator ***\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Factorial\n");
    printf("7. Square Root\n");
    printf("8. Power\n");
    printf("9. Exit\n");
}