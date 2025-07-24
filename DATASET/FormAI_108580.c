//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Welcome to C Scientific Calculator\n");
    
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /, ^, s): ");
    scanf(" %c", &operator);

    if(operator == 's' || operator == 'S') {
        result = sin(num1);
        printf("Result: %lf", result);
        return 0;
    }

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %lf", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %lf", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %lf", result);
            break;

        case '/':
            result = num1 / num2;
            printf("Result: %lf", result);
            break;

        case '^':
            result = pow(num1, num2);
            printf("Result: %lf", result);
            break;

        default:
            printf("Invalid operator");
    }

    return 0;
}