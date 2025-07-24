//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
/* This program demonstrates the use of arithmetic operators in C programming */

#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod;
    float div;

    printf("Please enter two integers: ");
    scanf("%d%d", &num1, &num2);

    // Addition operator
    sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    // Subtraction operator
    diff = num1 - num2;
    printf("The difference between %d and %d is %d\n", num1, num2, diff);

    // Multiplication operator
    prod = num1 * num2;
    printf("The product of %d and %d is %d\n", num1, num2, prod);

    // Division operator
    if (num2 == 0) {
        printf("Cannot divide by zero.\n");
    }
    else {
        div = (float) num1 / num2;
        printf("The quotient of %d and %d is %.2f\n", num1, num2, div);
    }

    // Modulus operator
    int mod = num1 % num2;
    printf("The remainder when %d is divided by %d is %d\n", num1, num2, mod);

    return 0;
}