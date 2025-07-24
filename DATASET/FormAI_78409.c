//FormAI DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>

int main() {
    // declare variables
    int num1, num2;
    float result;
    char operator;

    // prompt user for input
    printf("Enter an arithmetic expression in the format num1 operator num2: ");
    scanf("%d %c %d", &num1, &operator, &num2);

    // perform calculation based on operator
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;

        case '/':
            if(num2 != 0) {
                result = (float) num1 / num2;
                printf("Result: %.2f\n", result);
            } else {
                printf("Error: Cannot divide by zero.\n");
            }
            break;

        case '%':
            result = num1 % num2;
            printf("Result: %.2f\n", result);
            break;

        default:
            printf("Error: Invalid operator.\n");
    }

    return 0;
}