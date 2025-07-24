//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate addition
double add(double a, double b) {
    return a + b;
}

// Function to calculate subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to calculate multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to calculate division
double divide(double a, double b) {
    return a / b;
}

// Function to calculate square root
double sqroot(double a) {
    return sqrt(a);
}

// Function to calculate power
double power(double a, double b) {
    return pow(a, b);
}

// Function to calculate exponential
double exponential(double a) {
    return exp(a);
}

// Function to calculate logarithm
double logarithm(double a) {
    return log(a);
}

int main() {
    double a, b, result;
    int choice;

    printf("\nWelcome to the Scientific Calculator!");
    printf("\nSelect an operation from the following options:");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Square Root");
    printf("\n6. Power");
    printf("\n7. Exponential");
    printf("\n8. Logarithm\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter two numbers:\n");
            scanf("%lf %lf", &a, &b);
            result = add(a,b);
            printf("\nResult: %lf\n", result);
            break;
        case 2:
            printf("\nEnter two numbers:\n");
            scanf("%lf %lf", &a, &b);
            result = subtract(a,b);
            printf("\nResult: %lf\n", result);
            break;
        case 3:
            printf("\nEnter two numbers:\n");
            scanf("%lf %lf", &a, &b);
            result = multiply(a,b);
            printf("\nResult: %lf\n", result);
            break;
        case 4:
            printf("\nEnter two numbers:\n");
            scanf("%lf %lf", &a, &b);
            result = divide(a,b);
            printf("\nResult: %lf\n", result);
            break;
        case 5:
            printf("\nEnter a number:\n");
            scanf("%lf", &a);
            result = sqroot(a);
            printf("\nResult: %lf\n", result);
            break;
        case 6:
            printf("\nEnter two numbers:\n");
            scanf("%lf %lf", &a, &b);
            result = power(a,b);
            printf("\nResult: %lf\n", result);
            break;
        case 7:
            printf("\nEnter a number:\n");
            scanf("%lf", &a);
            result = exponential(a);
            printf("\nResult: %lf\n", result);
            break;
        case 8:
            printf("\nEnter a number:\n");
            scanf("%lf", &a);
            result = logarithm(a);
            printf("\nResult: %lf\n", result);
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }

    return 0;
}