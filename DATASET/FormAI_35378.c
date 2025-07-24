//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform addition
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to perform subtraction
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to perform multiplication
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to perform division
double divide(double num1, double num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("ERROR: Divide by zero\n");
        return 0;
    }
}

// Function to perform square root
double squareRoot(double num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        printf("ERROR: Invalid input\n");
        return 0;
    }
}

// Function to perform power
double power(double num, int exponent) {
    return pow(num, exponent);
}

int main() {
    int choice, exponent;
    double num1, num2;

    printf("***** Scientific Calculator *****\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root\n");
    printf("6. Power\n");
    printf("7. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", add(num1, num2));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", subtract(num1, num2));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", multiply(num1, num2));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %.2lf\n", divide(num1, num2));
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Result: %.2lf\n", squareRoot(num1));
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                printf("Result: %.2lf\n", power(num1, exponent));
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}