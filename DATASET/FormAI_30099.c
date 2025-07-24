//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_LENGTH 100

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
    if (b == 0) {
        printf("Error: Division by zero");
        exit(1);
    }
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double logarithm(double a) {
    if (a <= 0) {
        printf("Error: Logarithm of a non-positive number");
        exit(1);
    }
    return log(a);
}

double square_root(double a) {
    if (a < 0) {
        printf("Error: Square root of a negative number");
        exit(1);
    }
    return sqrt(a);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    double result = 0;
    printf("Welcome to the Ultra-Precise Scientific Calculator!\n\n");

    while (1) {
        printf("Please enter an equation (or 'q' to quit):\n");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        if (input[0] == 'q') {
            printf("Goodbye!\n");
            break;
        }
        double a, b;
        char operator;
        if (sscanf(input, "%lf %c %lf", &a, &operator, &b) != 3) {
            printf("Invalid input\n");
            continue;
        }
        switch (operator) {
            case '+':
                result = add(a, b);
                break;
            case '-':
                result = subtract(a, b);
                break;
            case '*':
                result = multiply(a, b);
                break;
            case '/':
                result = divide(a, b);
                break;
            case '^':
                result = power(a, b);
                break;
            case 'l':
                if (a == 'e' && b == 'n') {
                    result = logarithm(b);    
                } else {
                    printf("Invalid operator or incorrect number of operands\n");
                    continue;
                }
                break;
            case 's':
                if (a == 'q' && b == 'r') {
                    result = square_root(b);
                } else {
                    printf("Invalid operator or incorrect number of operands\n");
                    continue;
                }
                break;
            default:
                printf("Invalid operator or incorrect number of operands\n");
                continue;
        }
        printf("\nResult: %.10lf\n\n", result);
    }
    return 0;
}