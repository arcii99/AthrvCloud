//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>

int main() {
    // declare variables
    int num1, num2;
    float result;

    // ask user for input values
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // perform addition
    result = num1 + num2;
    printf("Addition Result: %.2f\n", result);

    // perform subtraction
    result = num1 - num2;
    printf("Subtraction Result: %.2f\n", result);

    // perform multiplication
    result = num1 * num2;
    printf("Multiplication Result: %.2f\n", result);

    // perform division
    if (num2 != 0) {
        result = (float) num1 / num2;
        printf("Division Result: %.2f\n", result);
    } else {
        printf("Cannot perform division by zero\n");
    }

    // find the remainder
    if (num2 != 0) {
        int remainder = num1 % num2;
        printf("Remainder: %d\n", remainder);
    } else {
        printf("Cannot perform remainder operation when second number is zero\n");
    }

    return 0;
}