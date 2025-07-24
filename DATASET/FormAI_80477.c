//FormAI DATASET v1.0 Category: Digital signal processing ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

// Function to calculate the sum of two numbers
int sum(int a, int b) {
    return a + b;
}

// Function to calculate the difference of two numbers
int diff(int a, int b) {
    return a - b;
}

// Function to calculate the product of two numbers
int product(int a, int b) {
    return a * b;
}

// Function to calculate the quotient of two numbers
int quotient(int a, int b) {
    return a / b;
}

void main() {
    int choice, num1, num2, result;

    // Displaying the menu to user
    printf("Choose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");

    scanf("%d", &choice);

    // Getting inputs from user
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Performing the chosen operation
    switch(choice) {
        case 1: // Addition
            result = sum(num1, num2);
            printf("Result: %d", result);
            break;
        case 2: // Subtraction
            result = diff(num1, num2);
            printf("Result: %d", result);
            break;
        case 3: // Multiplication
            result = product(num1, num2);
            printf("Result: %d", result);
            break;
        case 4: // Division
            result = quotient(num1, num2);
            printf("Result: %d", result);
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}