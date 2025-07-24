//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float num1, num2, result;
    char operator;

    printf("Enter a number: ");
    scanf("%f", &num1);

    printf("Enter an operator (+, -, *, /, ^): ");
    scanf(" %c", &operator);

    if (operator == '^'){
        printf("Enter a power: ");
        scanf("%f", &num2);
    }
    else{
        printf("Enter another number: ");
        scanf("%f", &num2);
    }

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Cannot divide by zero.");
                break;
            }
            result = num1 / num2;
            printf("Result: %.2f", result);
            break;
        case '^':
            result = pow(num1, num2);
            printf("Result: %.2f", result);
            break;
        default:
            printf("Error: Invalid operator.");
            break;
    }

    return 0;
}