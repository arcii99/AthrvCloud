//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <math.h>

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);

int main()
{
    int choice;
    double num1, num2;

    printf("Welcome to the Scientific Calculator!\n\n");

    do {
        // Display menu
        printf("Menu:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Exit\n\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // Check if choice is valid
        if (choice < 1 || choice > 6) {
            printf("\nInvalid choice. Please enter a number from 1 to 6.\n\n");
            continue;
        }

        // Ask for two numbers
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Perform operation based on choice
        switch (choice) {
            case 1:
                printf("\nResult: %lf\n\n", add(num1, num2));
                break;
            case 2:
                printf("\nResult: %lf\n\n", subtract(num1, num2));
                break;
            case 3:
                printf("\nResult: %lf\n\n", multiply(num1, num2));
                break;
            case 4:
                // Check for division by zero
                if (num2 == 0) {
                    printf("\nError: division by zero.\n\n");
                    continue;
                }
                printf("\nResult: %lf\n\n", divide(num1, num2));
                break;
            case 5:
                printf("\nResult: %lf\n\n", power(num1, num2));
                break;
        }
    } while (choice != 6);

    printf("Thank you for using the Scientific Calculator!\n");

    return 0;
}

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    return num1 / num2;
}

// Function to raise num1 to the power of num2
double power(double num1, double num2) {
    return pow(num1, num2);
}