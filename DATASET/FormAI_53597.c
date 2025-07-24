//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int n, i;
    double x[100], y[100], re, im;

    printf("Enter the length of the sequence (n): ");
    scanf("%d", &n);

    printf("Enter the sequence values:\n");

    for(i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }

    // Compute the DFT
    for(i = 0; i < n; i++) {
        re = 0;
        im = 0;

        for(int j = 0; j < n; j++) {
            re += x[j] * cos(2 * PI * i * j / n);
            im -= x[j] * sin(2 * PI * i * j / n);
        }

        y[i] = sqrt(re * re + im * im);
    }

    // Print the DFT results
    printf("\nThe DFT sequence values:\n");

    for(i = 0; i < n; i++) {
        printf("|X[%d]| = %lf\n", i, y[i]);
    }

    return 0;
}