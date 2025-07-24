//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Welcome to the AWESOME calculator!\n");
    printf("Please enter your first number: ");
    scanf("%d", &num1);
    printf("Please enter your operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Note the space before %c to consume the newline character
    printf("Please enter your second number: ");
    scanf("%d", &num2);

    if (operator == '+') {
        result = num1 + num2;
        printf("WOW! The result of %d %c %d is %d\n", num1, operator, num2, result);
    } else if (operator == '-') {
        result = num1 - num2;
        printf("AMAZING! The result of %d %c %d is %d\n", num1, operator, num2, result);
    } else if (operator == '*') {
        result = num1 * num2;
        printf("INCREDIBLE! The result of %d %c %d is %d\n", num1, operator, num2, result);
    } else if (operator == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            printf("UNBELIEVABLE! The result of %d %c %d is %d with a remainder of %d\n", num1, operator, num2, result, num1 % num2);
        } else {
            printf("OH NO! Cannot divide by zero!\n");
        }
    } else {
        printf("SORRY! Unknown operator.\n");
    }

    printf("Thank you for using our AWESOME calculator!\n");

    return 0;
}