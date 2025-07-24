//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char op;

    printf("Enter two numbers: ");
    if(scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Invalid input. Enter two integers separated by a space.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter an operator (+, -, *, /): ");
    if(scanf(" %c", &op) != 1) {
        fprintf(stderr, "Invalid input. Enter one operator (+, -, *, /).\n");
        exit(EXIT_FAILURE);
    }

    switch(op) {
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
                fprintf(stderr, "Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            result = num1 / num2;
            break;
        default:
            fprintf(stderr, "Error: Invalid operator (+, -, *, /).\n");
            exit(EXIT_FAILURE);
    }

    printf("The result is %d.\n", result);

    return 0;
}