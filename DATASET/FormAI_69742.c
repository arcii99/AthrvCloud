//FormAI DATASET v1.0 Category: Calculator ; Style: minimalist
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter a simple calculation (e.g. 5 + 3): ");
    scanf("%d %c %d", &num1, &operator, &num2);

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
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Cannot divide by zero.");
                return 0;
            }
            break;
        default:
            printf("Invalid operator.");
            return 0;
    }

    printf("%d %c %d = %d", num1, operator, num2, result);

    return 0;
}