//FormAI DATASET v1.0 Category: Error handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input. Program terminated.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input. Program terminated.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter operator (+,-,*,/): ");
    scanf(" %c", &operator);

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
                printf("Error: Division by zero. Program terminated.\n");
                exit(EXIT_FAILURE);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator. Program terminated.\n");
            exit(EXIT_FAILURE);
    }

    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}