//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// function to perform addition
double add(double a, double b) {
    return a + b;
}

// function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// function to perform division
double divide(double a, double b) {
    return a / b;
}

// function to perform power calculation
double power(double a, double b) {
    return pow(a, b);
}

// function to perform root calculation
double root(double a, double b) {
    return pow(a, 1 / b);
}

// function to perform logarithmic calculation
double logarithm(double a, double base) {
    return log(a) / log(base);
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        printf("Enter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power calculation\n");
        printf("6. Root calculation\n");
        printf("7. Logarithmic calculation\n");
        printf("8. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", add(num1, num2));
                break;

            case 2:
                printf("Enter two numbers to subtract:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", subtract(num1, num2));
                break;

            case 3:
                printf("Enter two numbers to multiply:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", multiply(num1, num2));
                break;

            case 4:
                printf("Enter two numbers to divide:\n");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Cannot divide by zero!\n");
                } else {
                    printf("Result: %lf\n", divide(num1, num2));
                }
                break;

            case 5:
                printf("Enter two numbers where first number is base and second number is exponent:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", power(num1, num2));
                break;

            case 6:
                printf("Enter two numbers where first number is value and second number is root:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", root(num1, num2));
                break;

            case 7:
                printf("Enter two numbers where first number is value and second number is base:\n");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", logarithm(num1, num2));
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}