//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float num1, num2, result;
    char operator;

    printf("\nWelcome to the Genius Scientific Calculator!\n\n");

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("\nEnter an operator (+, -, *, /, ^): ");
    scanf(" %c", &operator);

    if (operator == '^') {
        printf("\nEnter the second number for exponentiation: ");
        scanf("%f", &num2);
        result = pow(num1, num2);
    } else {
        printf("\nEnter the second number: ");
        scanf("%f", &num2);

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
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("\nDivision by zero is undefined.\n");
                    return 1;
                }
                break;
            default:
                printf("\nYou have entered an invalid operator.\n");
                return 1;
        }
    }

    printf("\nThe result of %.2f %c %.2f is %.2f.\n", num1, operator, num2, result);
    printf("\nThank you for using the Genius Scientific Calculator!\n");

    return 0;
}