//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the calculator program!\n\n");
    printf("Please enter your first number: ");
    scanf("%d", &num1);

    printf("Please enter your second number: ");
    scanf("%d", &num2);

    printf("Please enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The result of %d + %d is: %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The result of %d - %d is: %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The result of %d * %d is: %d\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            }
            else {
                result = num1 / num2;
                printf("The result of %d / %d is: %d\n", num1, num2, result);
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    printf("\nThank you for using the calculator program!");

    return 0;
}