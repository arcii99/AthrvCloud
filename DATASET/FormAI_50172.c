//FormAI DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>

/*
 * A program to calculate the value PI using the Machin formula:
 * PI/4 = 4*arctan(1/5) - arctan(1/239)
 * 
 * The program takes the number of iterations as an input from the user.
 * The more iterations, the more accurate the calculated value of PI.
 * 
 * Note: This program uses the C99 standard for interoperability.
 */

int main(void) {
    int iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    double pi = 0.0;
    for (int i = 0; i < iterations; i++) {
        double term1 = 4.0 * (1.0 / (2*i + 1));
        double term2 = 1.0 / (5.0 * (2*i + 1));
        double term3 = 1.0 / (239.0 * (2*i + 1));
        double term4 = (i % 2 == 0) ? 1.0 : -1.0;

        pi += term4 * (term1 * (4.0 * term2 - term3));
    }

    printf("Calculated value of PI: %f\n", pi);
    return 0;
}