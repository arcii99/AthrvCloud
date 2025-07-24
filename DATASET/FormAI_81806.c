//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the exciting Calculator Program!\n");
    printf("Are you ready to do some calculations?\n");

    // Declare variables
    int num1, num2, result;
    char operator;

    // Get input from user
    printf("Enter your first number: ");
    scanf("%d", &num1);
    printf("Enter your second number: ");
    scanf("%d", &num2);

    // Get operation from user
    printf("Enter the operation you would like to perform (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform calculation based on operator
    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Cannot divide by zero!\n");
                return 1;
            } else {
                result = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, result);
                break;
            }
        default:
            printf("Invalid operation entered!\n");
            return 1;
    }

    printf("Thanks for using the exciting Calculator Program! Come back soon.\n");

    return 0;
}