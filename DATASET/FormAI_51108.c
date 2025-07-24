//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initialize random seed using the current time

    int a[10], b[10], c[10];
    double mean_a, mean_b, variance_a, variance_b, sum_a = 0, sum_b = 0;
    int i;

    // Generate random values for arrays a and b
    for (i=0; i<10; i++) {
        a[i] = rand() % 20;
        b[i] = rand() % 20;
    }

    // Compute the mean of array a
    for (i=0; i<10; i++) {
        sum_a += a[i];
    }
    mean_a = sum_a / 10.0;

    // Compute the variance of array a
    for (i=0; i<10; i++) {
        variance_a += pow(a[i] - mean_a, 2);
    }
    variance_a /= 9.0;

    // Compute the mean of array b
    for (i=0; i<10; i++) {
        sum_b += b[i];
    }
    mean_b = sum_b / 10.0;

    // Compute the variance of array b
    for (i=0; i<10; i++) {
        variance_b += pow(b[i] - mean_b, 2);
    }
    variance_b /= 9.0;

    // Compute the sum of arrays a and b
    for (i=0; i<10; i++) {
        c[i] = a[i] + b[i];
    }

    // Print the results
    printf("Array a: ");
    for (i=0; i<10; i++) printf("%d ", a[i]);
    printf("\n");

    printf("Array b: ");
    for (i=0; i<10; i++) printf("%d ", b[i]);
    printf("\n");

    printf("The mean of array a is %.2f\n", mean_a);
    printf("The variance of array a is %.2f\n", variance_a);
    printf("The mean of array b is %.2f\n", mean_b);
    printf("The variance of array b is %.2f\n", variance_b);

    printf("The sum of arrays a and b: ");
    for (i=0; i<10; i++) printf("%d ", c[i]);
    printf("\n");

    return 0;
}