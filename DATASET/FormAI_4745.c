//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, sum, diff, prod, quo, mod;

    // Take user input
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Perform arithmetic operations
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    mod = num1 % num2;

    // Display results
    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference between %d and %d is %d\n", num1, num2, diff);
    printf("Product of %d and %d is %d\n", num1, num2, prod);
    printf("Quotient when %d is divided by %d is %d\n", num1, num2, quo);
    printf("Remainder when %d is divided by %d is %d\n", num1, num2, mod);

    return 0;
}