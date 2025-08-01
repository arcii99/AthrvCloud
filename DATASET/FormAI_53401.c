//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char operator;
    double num1, num2, result;

    printf("Enter an operator (+,-,*,/): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(operator)
    {
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
            result = num1 / num2;
            break;

        default:
            printf("Error: Invalid Operator.");
            return 0;
    }

    printf("Result: %lf", result);
    return 0;
}