//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

int main() {
    int num1, num2;
    float num3;
    char op;

    // Taking user input
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    printf("Enter a floating-point number: ");
    scanf("%f", &num3);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    // Performing arithmetic operations based on user input
    switch(op) {
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
            if(num2 == 0) {
                printf("Error! Cannot divide by zero.\n");
            }
            else {
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            }
            break;
        default:
            printf("Error! Invalid operator.\n");
            break;
    }

    // Doing some more arithmetic operations
    printf("%d %% %d = %d\n", num1, num2, num1 % num2);
    printf("%d / %.2f = %.2f\n", num1, num3, num1 / num3);
    printf("%.2f * %d = %.2f\n", num3, num2, num3 * num2);

    return 0;
}