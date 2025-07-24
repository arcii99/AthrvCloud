//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double power(double, double);
double factorial(double);

int main() {
    double num1, num2, result;
    int choice;

    // display menu
    printf("Scientific Calculator\n");
    printf("---------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Factorial\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // check input and get operands
    if (choice >= 1 && choice <= 4) {
        printf("Enter two operands: ");
        scanf("%lf %lf", &num1, &num2);
    } else if (choice == 5) {
        printf("Enter a base: ");
        scanf("%lf", &num1);
        printf("Enter an exponent: ");
        scanf("%lf", &num2);
    } else if (choice == 6) {
        printf("Enter a number: ");
        scanf("%lf", &num1);
    } else {
        printf("Invalid choice\n");
        exit(0);
    }

    // perform calculation based on user's choice
    switch (choice) {
        case 1:
            result = addition(num1, num2);
            break;
        case 2:
            result = subtraction(num1, num2);
            break;
        case 3:
            result = multiplication(num1, num2);
            break;
        case 4:
            result = division(num1, num2);
            break;
        case 5:
            result = power(num1, num2);
            break;
        case 6:
            result = factorial(num1);
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }

    // display result
    printf("Result: %lf\n", result);

    return 0;
}

// function definitions
double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        printf("Cannot divide by zero\n");
        exit(0);
    }
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double factorial(double n) {
    if (n < 0) {
        printf("Factorial of negative number is undefined\n");
        exit(0);
    }
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}