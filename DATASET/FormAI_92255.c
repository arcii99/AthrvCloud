//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
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
    if (b == 0) {
        printf("ERROR: Division by zero\n");
        return 0;
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+':
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '^':
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("ERROR: Invalid operator\n");
    }

    return 0;
}