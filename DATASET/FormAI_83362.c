//FormAI DATASET v1.0 Category: Calculator ; Style: relaxed
#include <stdio.h>

// Function to get the operation input from the user
char getOperator() {
    char operator;
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);
    return operator;
}

int main() {
    // Declare variables
    int num1, num2;
    char operator;

    // Get input from the user
    printf("Enter first number: ");
    scanf("%d", &num1);

    operator = getOperator();

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform calculation based on the input operator
    switch (operator) {
        case '+':
            printf("Result: %d + %d = %d\n", num1, num2, num1+num2);
            break;
        case '-':
            printf("Result: %d - %d = %d\n", num1, num2, num1-num2);
            break;
        case '*':
            printf("Result: %d * %d = %d\n", num1, num2, num1*num2);
            break;
        case '/':
            printf("Result: %d / %d = %d\n", num1, num2, num1/num2);
            break;
        default:
            printf("Invalid operator. Please try again.\n");
            break;
    }

    return 0;
}