//FormAI DATASET v1.0 Category: Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    float num1, num2;
    char op;

    printf("Welcome to Simple Calculator!\n");
    printf("Enter operator either + or - or * or /: ");
    scanf("%c", &op);

    printf("Enter two operands: ");
    scanf("%f %f", &num1, &num2);

    switch(op) {
        case '+':
            printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
            break;

        case '-':
            printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
            break;

        case '*':
            printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
            break;

        case '/':
            if(num2 == 0) {
                printf("Error: division by zero");
                break;
            }
            printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
            break;

        default:
            printf("Invalid operator");
            break;
    }

    return 0;
}