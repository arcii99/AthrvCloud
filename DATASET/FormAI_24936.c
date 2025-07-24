//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
/*
 * This is a scientific program that performs arithmetic operations on two
 * given numbers and outputs the results. The program supports the following
 * operations: addition, subtraction, multiplication, and division.
 *
 * How it works:
 * 1. The program prompts the user to enter two numbers
 * 2. The program prompts the user to select an arithmetic operation
 * 3. Based on the user's selection, the program performs the arithmetic
 *    operation and outputs the result
 *
 * Inputs: two numbers and an operator
 * Outputs: result of the arithmetic operation
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>

int main() {
    float num1, num2, result;
    char operator;

    // Prompt the user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    // Prompt the user to select an arithmetic operation
    printf("Select an arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform the arithmetic operation based on the user's selection
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f", num1, num2, result);
            break;

        case '/':
            if (num2 == 0) {
                printf("Error: cannot divide by zero");
            } else {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f", num1, num2, result);
            }
            break;

        default:
            printf("Error: invalid operator");
            break;
    }

    return 0;
}