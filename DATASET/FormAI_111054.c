//FormAI DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two numbers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to divide two numbers
int divide(int num1, int num2) {
    return num1 / num2;
}

// Main function
int main() {
    int choice, num1, num2, result;

    // Display the menu to the user
    printf("*** Welcome to the C Browser Plugin Example Program ***\n");
    printf("Please select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get the input from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform the selected operation
    switch(choice) {
        case 1:
            result = add(num1, num2);
            printf("The sum of %d and %d is %d\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("The difference between %d and %d is %d\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("The product of %d and %d is %d\n", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("The quotient of %d and %d is %d\n", num1, num2, result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}