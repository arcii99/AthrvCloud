//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>

int main() {
    // initialize variables
    int num1, num2, result;
    char operator;

    // get input from user
    printf("Enter a mathematical expression (e.g. 2 + 3)\n");
    scanf("%d %c %d", &num1, &operator, &num2);

    // perform the calculation based on the operator entered
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
            result = num1 / num2;
            break;
        default:
            // if an invalid operator is entered, print an error message and exit
            printf("Invalid operator\n");
            return 1;
    }

    // print the result
    printf("%d %c %d = %d\n", num1, operator, num2, result);

    return 0;
}