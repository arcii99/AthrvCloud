//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's create a calculator program!
    printf("Welcome to your ultimate calculator!\n");
    int num1, num2, result;
    char operator;

    printf("Please enter your first number: \n");
    scanf("%d", &num1);
    printf("Please enter your operator (+, -, *, /): \n");
    scanf(" %c", &operator);
    printf("Please enter your second number: \n");
    scanf("%d", &num2);

    if (operator == '+') { // Addition operation
        result = num1 + num2;
    } else if (operator == '-') { // Subtraction operation
        result = num1 - num2;
    } else if (operator == '*') { // Multiplication operation
        result = num1 * num2;
    } else if (operator == '/') { // Division operation
        if (num2 == 0) { // Handle division by zero error
            printf("Error: Division by zero not allowed!\n");
            exit(0);
        }
        result = num1 / num2;
    } else { // Handle invalid operator error
        printf("Error: Invalid operator entered!\n");
        exit(0);
    }

    printf("The result of %d %c %d = %d.\n", num1, operator, num2, result);
    printf("Thank you for using our calculator. Have a nice day!\n");

    return 0;
}