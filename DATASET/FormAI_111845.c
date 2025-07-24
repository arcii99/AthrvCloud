//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <math.h>

int main() {

    printf("Welcome to HappyCalc - the scientific calculator that will make you smile!\n\n");

    float num1, num2, result;
    char op;

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Choose an operation (+, -, *, /, ^): ");
    scanf(" %c", &op);

    if (op == '^') {
        printf("Enter the exponent: ");
        scanf("%f", &num2);
        result = pow(num1, num2);
    } else {
        printf("Enter the second number: ");
        scanf("%f", &num2);

        switch (op) {
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
                printf("Invalid operation. Please try again.\n");
                return 0;
        }
    }

    printf("The result is: %.2f\n\n", result);
    printf("Isn't math fun when you're happy? Thanks for using HappyCalc!\n");

    return 0;
}