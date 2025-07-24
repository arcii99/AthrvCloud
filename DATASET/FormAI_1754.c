//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: realistic
#include <stdio.h>
#include <math.h>

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double absolute(double);

int main() {
    double num1, num2;
    int choice;

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Select an operation: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Absolute\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf", add(num1, num2));
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf", subtract(num1, num2));
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf", multiply(num1, num2));
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf", divide(num1, num2));
            break;
        case 5:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf", power(num1, num2));
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Result: %.2lf", squareRoot(num1));
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            printf("Result: %.2lf", absolute(num1));
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}

// Function to add two numbers
double add(double x, double y) {
    return x + y;
}

// Function to subtract two numbers
double subtract(double x, double y) {
    return x - y;
}

// Function to multiply two numbers
double multiply(double x, double y) {
    return x * y;
}

// Function to divide two numbers
double divide(double x, double y) {
    return x / y;
}

// Function to calculate the power of a number
double power(double x, double y) {
    return pow(x, y);
}

// Function to calculate the square root of a number
double squareRoot(double x) {
    return sqrt(x);
}

// Function to calculate the absolute value of a number
double absolute(double x) {
    return fabs(x);
}