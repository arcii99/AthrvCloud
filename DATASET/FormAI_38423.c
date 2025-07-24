//FormAI DATASET v1.0 Category: Calculator ; Style: peaceful
#include <stdio.h>

int main() {

    // Declare variables to store user input and result
    int num1, num2, result;
    char op;

    // Ask user for input
    printf("Welcome to the peaceful calculator! Please enter your first number: ");
    scanf("%d", &num1);

    printf("Please enter your operation (+ - * /): ");
    scanf(" %c", &op);

    printf("Please enter your second number: ");
    scanf("%d", &num2);

    // Perform calculation based on user input
    switch(op) {
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
            if(num2 == 0) {
                printf("Oops! Cannot divide by zero.\n");
                return 1;
            } else {
                result = num1 / num2;
                break;
            }
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    // Display result to user
    printf("%d %c %d = %d\n", num1, op, num2, result);
    printf("Thank you for using the peaceful calculator! Have a nice day :)");

    return 0;
}