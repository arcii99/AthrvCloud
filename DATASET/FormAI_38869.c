//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h> // include standard I/O library

int main() {
    // Declare variables
    int num1, num2;
    char operator;

    // Prompt user for input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // add a space before %c to ignore newline character

    // Perform calculation based on operator
    switch(operator) {
        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Error: Invalid operator\n");
    }

    return 0; // Indicate successful program execution
}