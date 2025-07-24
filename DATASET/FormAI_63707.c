//FormAI DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, product, quotient, remainder;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = num1 + num2; // calculate sum
    diff = num1 - num2; // calculate difference
    product = num1 * num2; // calculate product
    quotient = num1 / num2; // calculate quotient
    remainder = num1 % num2; // calculate remainder

    printf("Sum of %d and %d is %d\n", num1, num2, sum);
    printf("Difference of %d and %d is %d\n", num1, num2, diff);
    printf("Product of %d and %d is %d\n", num1, num2, product);
    printf("Quotient when %d is divided by %d is %d\n", num1, num2, quotient);
    printf("Remainder when %d is divided by %d is %d\n", num1, num2, remainder);

    return 0;
}