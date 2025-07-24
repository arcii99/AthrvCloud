//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int num1, num2, sum, product;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Do some math
    sum = num1 + num2;
    product = num1 * num2;

    // Output the results
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The product of %d and %d is %d\n", num1, num2, product);

    return 0;
}