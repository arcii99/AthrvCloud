//FormAI DATASET v1.0 Category: Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    char op;
    float num1, num2;

    printf("Welcome to the calculator program!\nPlease enter the operation you want to perform (+, -, *, /): ");
    scanf("%c", &op);

    printf("Enter the first number: ");
    scanf("%f", &num1);

    printf("Enter the second number: ");
    scanf("%f", &num2);

    switch (op) {
        case '+': printf("The sum of %f and %f is %.2f\n", num1, num2, num1 + num2);
                  break;
        case '-': printf("The difference of %f and %f is %.2f\n", num1, num2, num1 - num2);
                  break;
        case '*': printf("The product of %f and %f is %.2f\n", num1, num2, num1 * num2);
                  break;
        case '/': if (num2 != 0) {
                      printf("The quotient of %f and %f is %.2f\n", num1, num2, num1 / num2);
                  } else {
                      printf("Cannot divide by zero!\n");
                  }
                  break;
        default: printf("Invalid operation entered!\n");
                 break;
    }

    return 0;
}