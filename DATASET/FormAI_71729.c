//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {

    // allocate memory dynamically for two integers
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    // read input values from user
    printf("Enter two integers: ");
    scanf("%d %d", a, b);

    // calculate sum of two integers
    int sum = *a + *b;
    printf("Sum of %d and %d is %d\n", *a, *b, sum);

    // calculate difference of two integers
    int diff = *a - *b;
    printf("Difference of %d and %d is %d\n", *a, *b, diff);

    // calculate product of two integers
    int product = *a * *b;
    printf("Product of %d and %d is %d\n", *a, *b, product);

    // calculate quotient of two integers
    int quotient = *a / *b;
    printf("Quotient of %d and %d is %d\n", *a, *b, quotient);

    // calculate remainder of two integers
    int remainder = *a % *b;
    printf("Remainder of %d and %d is %d\n", *a, *b, remainder);

    // free memory allocated for integers
    free(a);
    free(b);

    return 0;
}