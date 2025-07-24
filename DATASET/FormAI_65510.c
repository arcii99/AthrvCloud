//FormAI DATASET v1.0 Category: Arithmetic ; Style: high level of detail
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Addition operation
    printf("Addition: %d + %d = %d\n", num1, num2, num1 + num2);

    // Subtraction operation
    printf("Subtraction: %d - %d = %d\n", num1, num2, num1 - num2);

    // Multiplication operation
    printf("Multiplication: %d * %d = %d\n", num1, num2, num1 * num2);

    // Division operation
    if (num2 == 0) {
        printf("Division by zero!\n");
    } else {
        printf("Division: %d / %d = %d\n", num1, num2, num1 / num2);
    }

    return 0;
}