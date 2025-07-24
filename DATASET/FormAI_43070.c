//FormAI DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;

    // Reading inputs from user
    printf("Enter first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Error: Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Error: Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    // Checking for division by zero
    if (num2 == 0) {
        printf("Error: Cannot divide by zero!\n");
        exit(EXIT_FAILURE);
    }

    // Performing the division operation
    result = num1 / num2;

    // Checking for integer overflow
    if (num1 > 0 && num2 > 0 && result < 0) {
        printf("Error: Integer overflow detected!\n");
        exit(EXIT_FAILURE);
    }
    if (num1 < 0 && num2 < 0 && result < 0) {
        printf("Error: Integer overflow detected!\n");
        exit(EXIT_FAILURE);
    }

    // Printing the result
    printf("The result is: %d\n", result);

    return 0;
}