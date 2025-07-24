//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /, ^): \n");
    scanf("%c", &operator);

    printf("Enter two operands: \n");
    scanf("%lf %lf", &num1, &num2);

    switch(operator) {
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
            if(num2 == 0) {
                printf("Error: Division by zero.\n");
                exit(0);
            } else {
                result = num1 / num2;
            }
            break;

        case '^':
            result = pow(num1, num2);
            break;

        default:
            printf("Error: Invalid operator.\n");
            exit(0);
    }

    printf("Result: %lf \n", result);
    return 0;
}