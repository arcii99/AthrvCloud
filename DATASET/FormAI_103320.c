//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;

    printf("*****Arithmetic Operations Results*****\n");
    printf("Sum of %d and %d is: %d\n", a, b, sum);
    printf("Difference of %d and %d is: %d\n", a, b, difference);
    printf("Product of %d and %d is: %d\n", a, b, product);
    printf("Quotient of %d and %d is: %d\n", a, b, quotient);
    printf("Remainder of %d and %d is: %d\n", a, b, remainder);

    return 0;
}