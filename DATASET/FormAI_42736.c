//FormAI DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
/*
 * Arithmetic program - Written by Chatbot
 *
 * This program performs basic arithmetic operations based on user input.
 * It was inspired by Linus Torvalds' love for simplicity and efficiency.
 */

#include <stdio.h>

int main(void)
{
    int num1, num2, result;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    result = num1 + num2;
    printf("Addition result of %d and %d is %d.\n", num1, num2, result);

    result = num1 - num2;
    printf("Subtraction result of %d and %d is %d.\n", num1, num2, result);

    result = num1 * num2;
    printf("Multiplication result of %d and %d is %d.\n", num1, num2, result);

    if (num2 == 0)
    {
        printf("Cannot divide by zero.\n");
    }
    else
    {
        result = num1 / num2;
        printf("Division result of %d and %d is %d.\n", num1, num2, result);
    }

    return 0;
}