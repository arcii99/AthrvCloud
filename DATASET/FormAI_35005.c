//FormAI DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

void discreteFourierTransform(double *x, double *y, int N) {
    for (int k = 0; k < N; k++) {
        double real = 0.0, imag = 0.0;
        for (int n = 0; n < N; n++) {
            double angle = 2 * PI * n * k / N;
            real += x[n] * cos(angle);
            imag -= x[n] * sin(angle);
        }
        y[k] = sqrt(real * real + imag * imag) / N;
    }
}

int main(void) {
    int N = 8;
    double x[N], y[N];
    
    // Initialize input sequence
    x[0] = 1;
    x[1] = 0;
    x[2] = 2;
    x[3] = 2;
    x[4] = 2;
    x[5] = 0;
    x[6] = 1;
    x[7] = 0;

    // Compute discrete Fourier transform
    discreteFourierTransform(x, y, N);

    // Print results
    for (int k = 0; k < N; k++) {
        printf("y[%d] = %lf\n", k, y[k]);
    }

    return 0;
}