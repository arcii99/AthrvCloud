//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if(b == 0) {
        printf("Invalid Operation: Cannot divide by zero.\n");
        exit(0);
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

double factorial(double a) {
    if(a < 0) {
        printf("Invalid Operation: Cannot take factorial of a negative number.\n");
        exit(0);
    }
    double fact = 1;
    for(int i = 1; i <= a; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    printf("Welcome to the Scientific Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Factorial\n");

    int choice;
    double a, b;
    double result;

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the two numbers to be added: ");
            scanf("%lf %lf", &a, &b);
            result = add(a, b);
            printf("Result: %lf\n", result);
            break;
        case 2:
            printf("Enter the two numbers to be subtracted (a - b): ");
            scanf("%lf %lf", &a, &b);
            result = subtract(a, b);
            printf("Result: %lf\n", result);
            break;
        case 3:
            printf("Enter the two numbers to be multiplied: ");
            scanf("%lf %lf", &a, &b);
            result = multiply(a, b);
            printf("Result: %lf\n", result);
            break;
        case 4:
            printf("Enter the two numbers to be divided (a / b): ");
            scanf("%lf %lf", &a, &b);
            result = divide(a, b);
            printf("Result: %lf\n", result);
            break;
        case 5:
            printf("Enter the two numbers (a ^ b): ");
            scanf("%lf %lf", &a, &b);
            result = power(a, b);
            printf("Result: %lf\n", result);
            break;
        case 6:
            printf("Enter the number to find the factorial of: ");
            scanf("%lf", &a);
            result = factorial(a);
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}