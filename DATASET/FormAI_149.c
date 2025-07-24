//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char operator;
    double num1, num2, result;

    printf("Welcome to the C Scientific Calculator!\n\n");

    // User Input Section

    printf("Please enter an operator (+, -, *, /, or ^): ");
    scanf("%c", &operator);

    // Check for Invalid Input

    if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '^') {
        printf("\nInvalid operator entered. Please try again.\n");
        return 0;
    }

    printf("\nPlease enter the first number: ");
    scanf("%lf", &num1);

    printf("\nPlease enter the second number: ");
    scanf("%lf", &num2);

    // Calculations Section

    if (operator == '+') {
        result = num1 + num2;
        printf("\nThe sum of %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
    }
    else if (operator == '-') {
        result = num1 - num2;
        printf("\nThe difference between %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
    }
    else if (operator == '*') {
        result = num1 * num2;
        printf("\nThe product of %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
    }
    else if (operator == '/') {
        if (num2 == 0) {
            printf("\nCannot divide by zero. Please try again.\n");
            return 0;
        }
        result = num1 / num2;
        printf("\nThe quotient of %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
    }
    else if (operator == '^') {
        result = pow(num1, num2);
        printf("\n%.2lf raised to the power of %.2lf is %.2lf.\n", num1, num2, result);
    }

    printf("\nThank you for using the C Scientific Calculator!\n");

    return 0;
}