//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

/* Function to find the sum of two integers */
int add(int a, int b) {
    return a + b;
}

/* Function to find the difference between two integers */
int subtract(int a, int b) {
    return a - b;
}

/* Function to find the product of two integers */
int multiply(int a, int b) {
    return a * b;
}

/* Main function */
int main() {
    int a, b;
    int sum, diff, prod;

    /* Input two integers */
    printf("Enter the first integer: ");
    scanf("%d", &a);

    printf("Enter the second integer: ");
    scanf("%d", &b);

    /* Call performance-critical functions */
    sum = add(a, b);
    diff = subtract(a, b);
    prod = multiply(a, b);

    /* Print the results */
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);

    return 0;
}