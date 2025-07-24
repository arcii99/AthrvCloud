//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
/* Welcome friends! Today we are going to take a dive into the world of C Arithmetic with a unique example program! Grab a snack and let's get started */

#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the C Arithmetic program!\n");

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("Please enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Please enter the second number: ");
    scanf("%d", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("The difference of %d and %d is %d.\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Sorry, can't divide by zero! Restart and try again.\n");
            } else {
                result = num1 / num2;
                printf("The quotient of %d and %d is %d.\n", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator input! Restart and try again.\n");
    }

    printf("Thank you for using the C Arithmetic program!\n");
    return 0;
}