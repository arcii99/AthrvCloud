//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double square_root(double x);
void display_menu();
double get_user_input();
int get_menu_choice();

int main()
{
    int choice;
    double num1, num2, result;
    
    do {
        // Display menu and get user choice
        display_menu();
        choice = get_menu_choice();
        
        // Get user input
        num1 = get_user_input();
        
        // If user chose square root, set num2 to 0
        if (choice == 6) {
            num2 = 0;
        } else {
            num2 = get_user_input();
        }
        
        // Perform calculation based on user choice
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                break;
            case 5:
                result = power(num1, num2);
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, result);
                break;
            case 6:
                result = square_root(num1);
                printf("sqrt(%.2f) = %.2f\n", num1, result);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);
    
    return 0;
}

// Function to add two numbers
double add(double x, double y)
{
    return x + y;
}

// Function to subtract two numbers
double subtract(double x, double y)
{
    return x - y;
}

// Function to multiply two numbers
double multiply(double x, double y)
{
    return x * y;
}

// Function to divide two numbers
double divide(double x, double y)
{
    return x / y;
}

// Function to calculate the power of a number
double power(double x, double y)
{
    return pow(x, y);
}

// Function to calculate the square root of a number
double square_root(double x)
{
    return sqrt(x);
}

// Function to display the calculator menu
void display_menu()
{
    printf("Calculator Menu\n");
    printf("--------------------------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square root\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to get user input
double get_user_input()
{
    double input;
    printf("Enter a number: ");
    scanf("%lf", &input);
    return input;
}

// Function to get user menu choice
int get_menu_choice()
{
    int choice;
    scanf("%d", &choice);
    return choice;
}