//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
/**************************************************************
 * scientific_calculator.c
 * 
 * A simple scientific calculator implementation in C,
 * inspired by the Linux kernel programming style of Linus Torvalds.
 *
 * Author: [Your Name]
 * Email: [Your Email]
 * License: [Your License]
 **************************************************************/

#include <stdio.h>
#include <math.h>

// Define constants for mathematical operations
#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'
#define POWER '^'
#define SQRT 's'
#define LOG 'l'
#define EXP 'e'

// Function prototypes
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
double power(double x, double y);
double square_root(double x);
double logarithm(double x);
double exponential(double x);

// The main function
int main() {
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^, s, l, e): ");
    scanf("%c", &operator);

    // Check if the operator is square root, logarithm, or exponential
    if(operator == SQRT || operator == LOG || operator == EXP) {
        printf("Enter the number: ");
        scanf("%lf", &num1);

        // Perform the corresponding operation based on the operator
        switch(operator) {
            case SQRT:
                result = square_root(num1);
                printf("The square root of %lf is %lf.\n", num1, result);
                break;
            case LOG:
                result = logarithm(num1);
                printf("The natural logarithm of %lf is %lf.\n", num1, result);
                break;
            case EXP:
                result = exponential(num1);
                printf("The exponential of %lf is %lf.\n", num1, result);
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }
    }
    // If the operator is addition, subtraction, multiplication, division, or power
    else {
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);

        // Perform the corresponding mathematical operation based on the operator
        switch(operator) {
            case ADDITION:
                result = add(num1, num2);
                printf("%lf + %lf = %lf\n", num1, num2, result);
                break;
            case SUBTRACTION:
                result = subtract(num1, num2);
                printf("%lf - %lf = %lf\n", num1, num2, result);
                break;
            case MULTIPLICATION:
                result = multiply(num1, num2);
                printf("%lf * %lf = %lf\n", num1, num2, result);
                break;
            case DIVISION:
                result = divide(num1, num2);
                printf("%lf / %lf = %lf\n", num1, num2, result);
                break;
            case POWER:
                result = power(num1, num2);
                printf("%lf ^ %lf = %lf\n", num1, num2, result);
                break;
            default:
                printf("Invalid operator.\n");
                break;
        }
    }

    return 0;
}

// Function definitions

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    return x / y;
}

double power(double x, double y) {
    return pow(x, y);
}

double square_root(double x) {
    return sqrt(x);
}

double logarithm(double x) {
    return log(x);
}

double exponential(double x) {
    return exp(x);
}