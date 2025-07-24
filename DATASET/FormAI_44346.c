//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition
float add(float x, float y) {
    return x + y;
}

// Function to perform subtraction
float subtract(float x, float y) {
    return x - y;
}

// Function to perform multiplication
float multiply(float x, float y) {
    return x * y;
}

// Function to perform division
float divide(float x, float y) {
    if (y == 0) {
        printf("Cannot divide by zero.");
        exit(0);
    }
    return x / y;
}

// Function to perform exponentiation
float power(float x, float y) {
    return pow(x, y);
}

// Function to perform logarithm
float logarithm(float x) {
    if (x <= 0) {
        printf("Input must be greater than zero.");
        exit(0);
    }
    return log(x);
}

// Function to display menu
void displayMenu() {
    printf("\nScientific Calculator");
    printf("\n---------------------");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Exponentiation");
    printf("\n6. Logarithm");
    printf("\n7. Exit");
}

int main() {
    float x, y, result;
    int choice;

    do {
        displayMenu();
        printf("\n\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%f %f", &x, &y);
                result = add(x, y);
                printf("%.2f + %.2f = %.2f\n", x, y, result);
                break;

            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%f %f", &x, &y);
                result = subtract(x, y);
                printf("%.2f - %.2f = %.2f\n", x, y, result);
                break;

            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%f %f", &x, &y);
                result = multiply(x, y);
                printf("%.2f * %.2f = %.2f\n", x, y, result);
                break;

            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%f %f", &x, &y);
                result = divide(x, y);
                printf("%.2f / %.2f = %.2f\n", x, y, result);
                break;

            case 5:
                printf("\nEnter two numbers to find the power: ");
                scanf("%f %f", &x, &y);
                result = power(x, y);
                printf("%.2f ^ %.2f = %.2f\n", x, y, result);
                break;

            case 6:
                printf("\nEnter a number to find the logarithm: ");
                scanf("%f", &x);
                result = logarithm(x);
                printf("log(%.2f) = %.2f\n", x, result);
                break;

            case 7:
                printf("\nThank you for using the scientific calculator.\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (1);

    return 0;
}