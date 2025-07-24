//FormAI DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>

int main() {
    // Declare variables
    float num1, num2, result;
    char operator;

    // Ask user for input
    printf("Enter a number: ");
    scanf("%f", &num1);

    printf("Enter an operator (+,-,*,/): ");
    scanf(" %c", &operator);

    printf("Enter another number: ");
    scanf("%f", &num2);

    // Perform arithmetic operation based on the operator entered
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check if num2 is not zero before dividing
            if(num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: division by zero!\n");
                return 1;
            }
            break;
        default:
            printf("Error: invalid operator!\n");
            return 1;
    }

    // Print the result
    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0;
}