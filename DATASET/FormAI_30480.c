//FormAI DATASET v1.0 Category: Syntax parsing ; Style: statistical
#include <stdio.h>

// Declare the variables
int num1, num2, result;
char operator;

int main() {
    printf("Enter an expression: ");
    scanf("%d %c %d", &num1, &operator, &num2);
    
    // Perform the operation based on the operator
    switch (operator) {
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
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                return 1;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Error: Invalid operator entered.\n");
            return 1;
    }
    
    // Print the result
    printf("%d %c %d = %d\n", num1, operator, num2, result);
    return 0;
}