//FormAI DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>

int main() {
    int num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // note the space before %c to ignore whitespace characters left in buffer

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
            if(num2 == 0) {
                printf("Error! Cannot divide by zero.");
                return 1; // indicating an error occurred
            }
            result = num1 / num2;
            break;

        default:
            printf("Error! Invalid operator.");
            return 1; // indicating an error occurred
    }

    printf("%d %c %d = %d", num1, operator, num2, result);
    return 0; // indicating program ran successfully
}