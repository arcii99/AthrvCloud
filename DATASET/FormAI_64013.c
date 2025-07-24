//FormAI DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%d", &num2);

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
                printf("Error: Cannot divide by zero.\n");
                return 0;
            } else {
                result = num1 / num2;
                break;
            }
        default:
            printf("Error: Invalid operator.\n");
            return 0;
    }

    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}