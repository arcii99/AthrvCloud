//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void dft(double *x, double *output, int N) {
    int k, n;
    double re, im;

    for (k = 0; k < N; k++) {
        re = 0.0;
        im = 0.0;
        for (n = 0; n < N; n++) {
            re += x[n] * cos(2 * PI * k * n / N);
            im -= x[n] * sin(2 * PI * k * n / N);
        }
        output[k] = sqrt(re * re + im * im);
    }
}

int main() {
    int i, N = 8;
    double *x = malloc(N * sizeof(double));
    double *y = malloc(N * sizeof(double));

    // Generate a test signal
    for (i = 0; i < N; i++) {
        x[i] = sin(2 * PI * i / N);
    }

    // Compute the DFT
    dft(x, y, N);

    // Print the results
    for (i = 0; i < N; i++) {
        printf("%f\n", y[i]);
    }

    return 0;
}