//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 20

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double square_root(double);
double factorial(double);
void print_menu();
void process_input(char[]);
void reset_calculator();

// Global variables
double memory = 0;

int main() {
    char input[MAX_DIGITS];

    print_menu();

    while (1) {
        printf("\nEnter your choice: ");
        fgets(input, MAX_DIGITS, stdin);

        process_input(input);
    }

    return 0;
}

// Function to print the scientific calculator menu
void print_menu() {
    printf("Welcome to the Scientific Calculator!\n");
    printf("1- Add\n");
    printf("2- Subtract\n");
    printf("3- Multiply\n");
    printf("4- Divide\n");
    printf("5- Power\n");
    printf("6- Square Root\n");
    printf("7- Factorial\n");
    printf("8- Memory Store\n");
    printf("9- Memory Recall\n");
    printf("10- Memory Clear\n");
    printf("11- Reset Calculator\n");
    printf("0- Exit\n");
}

// Function to process user menu choice
void process_input(char input[]) {
    double num1, num2, result;
    int choice;

    // Convert input to integer
    sscanf(input, "%d", &choice);

    switch (choice) {
        case 0:
            printf("\nThank you for using the Scientific Calculator!\n");
            exit(0);
        case 1:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 2:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 3:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 4:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 5:
            printf("Enter the base: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            result = power(num1, num2);
            printf("The result is: %lf\n", result);
            break;
        case 6:
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = square_root(num1);
            printf("The result is: %lf\n", result);
            break;
        case 7:
            printf("Enter the number: ");
            scanf("%lf", &num1);
            result = factorial(num1);
            printf("The result is: %lf\n", result);
            break;
        case 8:
            printf("Enter the number to store: ");
            scanf("%lf", &memory);
            printf("Value %lf has been stored in memory.\n", memory);
            break;
        case 9:
            printf("The value in memory is: %lf\n", memory);
            break;
        case 10:
            memory = 0;
            printf("Memory has been cleared.\n");
            break;
        case 11:
            reset_calculator();
            printf("Calculator has been reset.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
    // Flush input buffer
    fflush(stdin);
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

// Function to calculate power of a number
double power(double base, double exponent) {
    return pow(base, exponent);
}

// Function to calculate square root of a number
double square_root(double num) {
    return sqrt(num);
}

// Function to calculate factorial of a number using recursion
double factorial(double num) {
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

// Function to reset the calculator
void reset_calculator() {
    memory = 0;
}