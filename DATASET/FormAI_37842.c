//FormAI DATASET v1.0 Category: Scientific ; Style: enthusiastic
#include <stdio.h>

// This is an exciting program that showcases the use of a mathematical function.

int main() {
    int x;
    printf("What number would you like to calculate the square root of?: ");
    scanf("%d", &x);   // User input for number to calculate the square root of

    double output;
    asm volatile("fld %1; fsqrt; fstp %0;" : "=m" (output) : "m" (x)); // Assembly code for calculating square root

    printf("The square root of %d is %f!", x, output);   // Output result
    return 0;
}