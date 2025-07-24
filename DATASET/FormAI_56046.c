//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>  // Standard Input and Output Library
#include <stdlib.h> // Standard Library
#include <math.h>   // Math Library

// Function Declarations
char get_user_choice();
void addition();
void subtraction();
void multiplication();
void division();
void square();
void cube();
void power();
void square_root();
void cube_root();
void logarithm();

int main() {
    char choice; // Initialize user choice variable
    printf("\nWelcome to our Scientific Calculator!\n");

    // Infinite while loop to display menu and perform calculations
    while(1) {
        choice = get_user_choice();

        // Execute corresponding function based on user choice
        switch(choice) {
            case 'A':
                addition();
                break;
            case 'S':
                subtraction();
                break;
            case 'M':
                multiplication();
                break;
            case 'D':
                division();
                break;
            case 'Q':
                square();
                break;
            case 'C':
                cube();
                break;
            case 'P':
                power();
                break;
            case 'R':
                square_root();
                break;
            case 'T':
                cube_root();
                break;
            case 'L':
                logarithm();
                break;
            case 'X':
                printf("\nThank you for using the calculator!\n");
                exit(0); // Gracefully terminate the program
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to get user choice in menu
char get_user_choice() {
    char choice;
    printf("\nPlease select an operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    printf("Q - Square\n");
    printf("C - Cube\n");
    printf("P - Power\n");
    printf("R - Square Root\n");
    printf("T - Cube Root\n");
    printf("L - Logarithm\n");
    printf("X - Exit\n");
    printf("Choice: ");
    scanf(" %c", &choice); // Get user choice from input
    return toupper(choice); // Convert user choice to uppercase and return
}

// Function to perform addition
void addition() {
    double num1, num2, result;
    printf("\nEnter two numbers to add:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);
    result = num1 + num2;
    printf("Result: %lf\n", result);
}

// Function to perform subtraction
void subtraction() {
    double num1, num2, result;
    printf("\nEnter two numbers to subtract:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);
    result = num1 - num2;
    printf("Result: %lf\n", result);
}

// Function to perform multiplication
void multiplication() {
    double num1, num2, result;
    printf("\nEnter two numbers to multiply:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);
    result = num1 * num2;
    printf("Result: %lf\n", result);
}

// Function to perform division
void division() {
    double num1, num2, result;
    printf("\nEnter two numbers to divide:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);

    // Check for division by zero
    if(num2 == 0) {
        printf("Error: Division by zero!\n");
        return;
    }

    result = num1 / num2;
    printf("Result: %lf\n", result);
}

// Function to find square of a number
void square() {
    double num, result;
    printf("\nEnter a number to find its square:\n");
    printf("Number: ");
    scanf("%lf", &num);
    result = pow(num, 2);
    printf("Result: %lf\n", result);
}

// Function to find cube of a number
void cube() {
    double num, result;
    printf("\nEnter a number to find its cube:\n");
    printf("Number: ");
    scanf("%lf", &num);
    result = pow(num, 3);
    printf("Result: %lf\n", result);
}

// Function to find power of a number
void power() {
    double num, exponent, result;
    printf("\nEnter a number and its exponent to find result:\n");
    printf("Number: ");
    scanf("%lf", &num);
    printf("Exponent: ");
    scanf("%lf", &exponent);
    result = pow(num, exponent);
    printf("Result: %lf\n", result);
}

// Function to find square root of a number
void square_root() {
    double num, result;
    printf("\nEnter a number to find its square root:\n");
    printf("Number: ");
    scanf("%lf", &num);

    // Check for negative numbers
    if(num < 0) {
        printf("Error: Cannot find square root of negative number!\n");
        return;
    }

    result = sqrt(num);
    printf("Result: %lf\n", result);
}

// Function to find cube root of a number
void cube_root() {
    double num, result;
    printf("\nEnter a number to find its cube root:\n");
    printf("Number: ");
    scanf("%lf", &num);
    result = cbrt(num);
    printf("Result: %lf\n", result);
}

// Function to find logarithm of a number
void logarithm() {
    double num, base, result;
    printf("\nEnter a number and its base to find result:\n");
    printf("Number: ");
    scanf("%lf", &num);
    printf("Base: ");
    scanf("%lf", &base);

    // Check for invalid base
    if(base <= 0 || base == 1) {
        printf("Error: Base must be greater than 0 and not equal to 1!\n");
        return;
    }

    result = log(num) / log(base);
    printf("Result: %lf\n", result);
}