//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double base, double exponent);
double squareRoot(double num);

int main() {
    int choice;
    double num1, num2, result;
    printf("Welcome to the Scientific Calculator Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("Result: %lf", result);
            break;
        case 2:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("Result: %lf", result);
            break;
        case 3:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("Result: %lf", result);
            break;
        case 4:
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("Result: %lf", result);
            break;
        case 5:
            printf("Enter base number: ");
            scanf("%lf", &num1);
            printf("Enter exponent number: ");
            scanf("%lf", &num2);
            result = power(num1, num2);
            printf("Result: %lf", result);
            break;
        case 6:
            printf("Enter number: ");
            scanf("%lf", &num1);
            result = squareRoot(num1);
            printf("Result: %lf", result);
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.");
    }

    return 0;
}

double add(double num1, double num2) {
    return num1 + num2;
}

double subtract(double num1, double num2) {
    return num1 - num2;
}

double multiply(double num1, double num2) {
    return num1 * num2;
}

double divide(double num1, double num2) {
    return num1 / num2;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double num) {
    return sqrt(num);
}