//FormAI DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    int N = 16; // Number of samples
    double x[N]; // Input sequence
    double X_re[N/2]; // Real part of DFT
    double X_im[N/2]; // Imaginary part of DFT
    int k, n; // Loop variables

    // Generate input sequence
    for (n = 0; n < N; n++) {
        x[n] = sin(2 * PI * n / N) + 0.5 * sin(4 * PI * n / N);
    }

    // Perform DFT
    for (k = 0; k < N/2; k++) {
        X_re[k] = 0;
        X_im[k] = 0;
        for (n = 0; n < N; n++) {
            X_re[k] += x[n] * cos(2 * PI * k * n / N);
            X_im[k] -= x[n] * sin(2 * PI * k * n / N);
        }
    }

    // Print result
    printf("Real and imaginary parts of DFT:\n");
    for (k = 0; k < N/2; k++) {
        printf("X[%d] = %lf + j%lf\n", k, X_re[k], X_im[k]);
    }

    return 0;
}