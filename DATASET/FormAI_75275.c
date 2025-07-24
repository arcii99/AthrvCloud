//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
    char operation;
    float num1, num2, result;

    printf("Enter operation (+, -, *, /, ^): ");
    scanf("%c", &operation);

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch(operation) {
        case '+':
            result = num1 + num2;
            printf("%0.2f + %0.2f = %0.2f", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%0.2f - %0.2f = %0.2f", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%0.2f * %0.2f = %0.2f", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero");
            } else {
                result = num1 / num2;
                printf("%0.2f / %0.2f = %0.2f", num1, num2, result);
            }
            break;
        case '^':
            result = pow(num1, num2);
            printf("%0.2f ^ %0.2f = %0.2f", num1, num2, result);
            break;
        default:
            printf("Invalid operation");
    }

    return 0;
}