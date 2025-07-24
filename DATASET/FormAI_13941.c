//FormAI DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>

int main() {
    printf("Welcome to Intelligent Arithmetic!\n");
    printf("This program can perform various arithmetic operations.\n");
    printf("Please enter two numbers and a desired operation symbol (+, -, *, /) separated by a space.\n");
    printf("For example, 5 3 + will add 5 and 3.\n");

    float num1, num2, result;
    char symbol;

    while (1) {
        scanf("%f %f %c", &num1, &num2, &symbol);

        if (symbol == '+') {
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
        } else if (symbol == '-') {
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
        } else if (symbol == '*') {
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
        } else if (symbol == '/') {
            if (num2 == 0) {
                printf("Error: cannot divide by zero.\n");
            } else {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            }
        } else {
            printf("Error: invalid operator.\n");
        }
        
        char choice;
        printf("Do you want to continue? (y/n)\n");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using Intelligent Arithmetic! Goodbye.\n");
            break;
        }
    }

    return 0;
}