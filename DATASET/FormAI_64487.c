//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void menu();
void addition();
void subtraction();
void multiplication();
void division();
void power();
void square_root();
void absolute_value();

int main() {
    menu();
    return 0;
}

// Function to display menu options
void menu() {
    int choice;
    printf("Welcome to the Brave Scientific Calculator!\n\n");
    printf("Select an operation below:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Absolute Value\n");
    printf("8. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            power();
            break;
        case 6:
            square_root();
            break;
        case 7:
            absolute_value();
            break;
        case 8:
            printf("Thanks for using the Brave Scientific Calculator!");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 8.");
            menu();
            break;
    }
}

// Function to add two numbers
void addition() {
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    float result = num1 + num2;
    printf("Result: %.2f", result);
    menu();
}

// Function to subtract two numbers
void subtraction() {
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    float result = num1 - num2;
    printf("Result: %.2f", result);
    menu();
}

// Function to multiply two numbers
void multiplication() {
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    float result = num1 * num2;
    printf("Result: %.2f", result);
    menu();
}

// Function to divide two numbers
void division() {
    float num1, num2;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    if (num2 == 0) {
        printf("Cannot divide by zero!");
    } else {
        float result = num1 / num2;
        printf("Result: %.2f", result);
    }
    menu();
}

// Function to calculate power of a number
void power() {
    float base, exponent;
    printf("Enter base number: ");
    scanf("%f", &base);
    printf("Enter exponent: ");
    scanf("%f", &exponent);
    float result = pow(base, exponent);
    printf("Result: %.2f", result);
    menu();
}

// Function to calculate square root of a number
void square_root() {
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num < 0) {
        printf("Cannot calculate square root of a negative number!");
    } else {
        float result = sqrt(num);
        printf("Result: %.2f", result);
    }
    menu();
}

// Function to calculate absolute value of a number
void absolute_value() {
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);
    float result = abs(num);
    printf("Result: %.2f", result);
    menu();
}