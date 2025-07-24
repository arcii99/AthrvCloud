//FormAI DATASET v1.0 Category: Scientific ; Style: portable
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

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
            if (num2 == 0) {
                printf("Error: Cannot divide by zero");
                return 0;
            } else {
                result = num1 / num2;
            }
            break;

        default:
            printf("Invalid operator selected");
            return 0;
    }

    printf("Result: %d %c %d = %d", num1, operator, num2, result);
    return 0;
}