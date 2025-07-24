//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <math.h>

// Function prototypes
int addition(int x, int y);
int subtraction(int x, int y);
int multiplication(int x, int y);
int division(int x, int y);
double power(double x, double y);
double squareroot(double x);

// Main function
int main() {
    int choice, num1, num2;
    double num3, result;

    // Display menu
    printf("Welcome to My Calculator\n");
    printf("Select the operation you want to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n");
    printf("Enter your choice: ");

    // Read user choice
    scanf("%d", &choice);

    // Switch case to perform operation based on user choice
    switch (choice) {
        case 1: // Addition
            printf("Enter two integer numbers to add: ");
            scanf("%d%d", &num1, &num2);
            result = addition(num1, num2);
            printf("The result is %lf\n", result);
            break;

        case 2: // Subtraction
            printf("Enter two integer numbers to subtract: ");
            scanf("%d%d", &num1, &num2);
            result = subtraction(num1, num2);
            printf("The result is %lf\n", result);
            break;

        case 3: // Multiplication
            printf("Enter two integer numbers to multiply: ");
            scanf("%d%d", &num1, &num2);
            result = multiplication(num1, num2);
            printf("The result is %lf\n", result);
            break;

        case 4: // Division
            printf("Enter two integer numbers to divide: ");
            scanf("%d%d", &num1, &num2);
            result = division(num1, num2);
            printf("The result is %lf\n", result);
            break;

        case 5: // Power
            printf("Enter two double numbers to raise power: ");
            scanf("%lf%lf", &num3, &num3);
            result = power(num3, num3);
            printf("The result is %lf\n", result);
            break;

        case 6: // Square root
            printf("Enter a double number to find square root: ");
            scanf("%lf", &num3);
            result = squareroot(num3);
            printf("The result is %lf\n", result);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

// Function to perform addition
int addition(int x, int y) {
    return x + y;
}

// Function to perform subtraction
int subtraction(int x, int y) {
    return x - y;
}

// Function to perform multiplication
int multiplication(int x, int y) {
    return x * y;
}

// Function to perform division
int division(int x, int y) {
    return x / y;
}

// Function to perform power
double power(double x, double y) {
    return pow(x, y);
}

// Function to find square root
double squareroot(double x) {
    if (x >= 0) {
        return sqrt(x);
    } else {
        printf("Error: Cannot find square root of negative number\n");
        return 0.0;
    }
}