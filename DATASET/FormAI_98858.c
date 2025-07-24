//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>

int main() {
    printf("Hello, welcome to the arithmetic calculator!\n\n");

    int num1, num2;
    char operator;

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("Please enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Please enter the second number: ");
    scanf("%d", &num2);

    int result;
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d", num1, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Cannot divide by 0");
            } else {
                result = num1 / num2;
                printf("%d / %d = %d", num1, num2, result);
            }
            break;
        default:
            printf("Error: Please enter a valid operator (+, -, *, /)");
            break;
    }

    return 0;
}