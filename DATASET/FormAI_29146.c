//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scientific
#include <stdio.h>

/* Declare variables */
int num1, num2, result;
char operator;

/* Prompt user for input */
int main() {
    printf("Please enter an expression in the format num1 operator num2: ");
    scanf("%d %c %d", &num1, &operator, &num2);

    /* Perform calculations based on operator */
    switch (operator) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        default: printf("Invalid operator"); return 1;
    }

    /* Print result */
    printf("%d %c %d = %d", num1, operator, num2, result);

    return 0;
}