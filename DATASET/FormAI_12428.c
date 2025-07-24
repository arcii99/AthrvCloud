//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to print the menu and get the user's choice
int getMenuChoice() {
    int choice;
    printf("\nSelect an operation:\n");
    printf("1) Addition (+)\n");
    printf("2) Subtraction (-)\n");
    printf("3) Multiplication (*)\n");
    printf("4) Division (/)\n");
    printf("5) Power (x^y)\n");
    printf("6) Square Root (√x)\n");
    printf("7) Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get the inputs from the user and calculate the result
double performOperation(int choice) {
    double num1, num2;
    switch (choice) {
        case 1:
            printf("\nEnter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            return num1 + num2;
        case 2:
            printf("\nEnter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            return num1 - num2;
        case 3:
            printf("\nEnter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            return num1 * num2;
        case 4:
            printf("\nEnter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 == 0) {
                printf("Error: Division by zero is undefined\n");
                return 0;
            }
            return num1 / num2;
        case 5:
            printf("\nEnter two numbers to calculate power: ");
            scanf("%lf %lf", &num1, &num2);
            return pow(num1, num2);
        case 6:
            printf("\nEnter a number to calculate square root: ");
            scanf("%lf", &num1);
            if (num1 < 0) {
                printf("Error: Square root of a negative number is undefined\n");
                return 0;
            }
            return sqrt(num1);
        default:
            printf("Invalid choice\n");
            return 0;
    }
}

// Main function to run the program
int main() {
    printf("\nWelcome to the secure scientific calculator program\n");

    int choice;
    do {
        choice = getMenuChoice();
        if (choice != 7) {
            double result = performOperation(choice);
            printf("Result: %lf\n", result);
        }
    } while (choice != 7);

    printf("\nThank you for using the secure scientific calculator program\n");
    return 0;
}