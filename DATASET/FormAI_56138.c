//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int num1, num2, result;
    char op;

    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        fprintf(stderr, "Error: Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the operation (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) {
        fprintf(stderr, "Error: Invalid input!\n");
        exit(EXIT_FAILURE);
    }

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
            if (num2 == 0) {
                fprintf(stderr, "Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
            result = num1 / num2;
            break;
        default:
            fprintf(stderr, "Error: Invalid operation!\n");
            exit(EXIT_FAILURE);
    }

    printf("The result is: %d\n", result);

    return 0;
}