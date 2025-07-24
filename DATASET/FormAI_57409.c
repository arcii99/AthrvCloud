//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Recursive Scientific Calculator Implementation */

int calculate(char op, int num1, int num2);

int main() {

    char operator;
    int num1, num2, result;

    printf("Please enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    printf("\nPlease enter the first number: ");
    scanf("%d", &num1);

    printf("\nPlease enter the second number: ");
    scanf("%d", &num2);

    result = calculate(operator, num1, num2);

    printf("\nThe result is: %d\n", result);

    return 0;
}


int calculate(char op, int num1, int num2) {

    int result;

    switch (op) {

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

        case '^':
            result = (int) pow(num1,num2);
            break;

        default:
            printf("Invalid Operator!\n");
            exit(1);
    }

    return result;
}