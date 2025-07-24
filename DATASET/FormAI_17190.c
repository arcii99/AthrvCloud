//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Our ken Thompson style program - a calculator that supports basic arithmetic operations

int main(void) {
    int firstOperand, secondOperand, result;
    char operation;

    printf("Enter the first operand: ");
    scanf("%d", &firstOperand);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation); // notice the space before %c to consume an extra newline character

    printf("Enter the second operand: ");
    scanf("%d", &secondOperand);

    switch (operation) {
        case '+':
            result = firstOperand + secondOperand;
            break;
        
        case '-':
            result = firstOperand - secondOperand;
            break;
        
        case '*':
            result = firstOperand * secondOperand;
            break;
        
        case '/':
            if (secondOperand == 0) {
                printf("Cannot divide by zero");
                exit(1); // exit with an error code
            }
            result = firstOperand / secondOperand;
            break;
        
        default:
            printf("Invalid operation");
            exit(1); // exit with an error code
    }

    printf("Result: %d\n", result);

    return 0;
}