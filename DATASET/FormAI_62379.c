//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Function declarations
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double square_root(double);
double factorial(double);
double sin_in_degrees(double);
double cos_in_degrees(double);
double tan_in_degrees(double);

int main() {
    double operand1, operand2, result;
    char operator;

    printf("Welcome to the UltraPrecise Scientific Calculator\n");
    printf("Please enter your expression with spaces in between: ");
    scanf("%lf %c %lf", &operand1, &operator, &operand2);

    switch (operator) {
        case '+':
            result = add(operand1, operand2);
            printf("Result: %.15lf\n", result);
            break;
        
        case '-':
            result = subtract(operand1, operand2);
            printf("Result: %.15lf\n", result);
            break;
        
        case '*':
            result = multiply(operand1, operand2);
            printf("Result: %.15lf\n", result);
            break;
        
        case '/':
            result = divide(operand1, operand2);
            if (result == INFINITY) {
                printf("Cannot divide by zero.\n");
            } else {
                printf("Result: %.15lf\n", result);
            }
            break;

        case '^':
            result = power(operand1, operand2);
            printf("Result: %.15lf\n", result);
            break;

        default:
            printf("Invalid operator.\n");
            exit(EXIT_FAILURE);
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
    if (num2 == 0) {
        return INFINITY;
    } else {
        return num1 / num2;
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double square_root(double num) {
    return sqrt(num);
}

double factorial(double num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

double sin_in_degrees(double angle) {
    double radian = angle * PI / 180;
    return sin(radian);
}

double cos_in_degrees(double angle) {
    double radian = angle * PI / 180;
    return cos(radian);
}

double tan_in_degrees(double angle) {
    double radian = angle * PI / 180;
    return tan(radian);
}