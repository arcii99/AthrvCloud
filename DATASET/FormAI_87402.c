//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declarations
double calculate(double num1, double num2, char operator);

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to the Scientific Calculator!\n");

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the operator (+,-,*,/,^): ");
    scanf(" %c", &operator);

    if (operator == '^') {
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        result = calculate(num1, num2, operator);
    } else {
        num2 = 0;
        result = calculate(num1, num2, operator);
    }

    printf("Result: %.4lf\n", result);

    return 0;
}

double calculate(double num1, double num2, char operator) {
    double result;

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                exit(0);
            }
            result = num1 / num2;
            break;
        case '^':
            result = pow(num1, num2);
            break;
        default:
            printf("Error: Invalid operator entered\n");
            exit(0);
    }

    return result;
}