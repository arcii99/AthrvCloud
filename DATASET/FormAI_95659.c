//FormAI DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int num1, num2;
    float result;
    char operator;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %.2f", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %.2f", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %.2f", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Cannot divide by zero");
            } else {
                result = (float) num1 / num2;
                printf("%d / %d = %.2f", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operator");
            break;
    }

    return 0;
}