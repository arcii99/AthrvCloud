//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define PI 3.14159

int main() {

    int i, j, n;
    double x[N], y[N], z[N], omega1, omega2;

    // Create input signal x[n]
    for (i = 0; i < N; i++) {
        x[i] = sin(2 * PI * i / N) + sin(4 * PI * i / N);
    }

    // Perform a discrete Fourier transform on x[n]
    for (i = 0; i < N; i++) {
        y[i] = 0;
        for (j = 0; j < N; j++) {
            y[i] += x[j] * cos(2 * PI * i * j / N) - sin(2 * PI * i * j / N);
        }
    }

    // Create high frequency boost filter
    omega1 = 2 * PI * 20 / N;
    omega2 = 2 * PI * 40 / N;
    for (i = 0; i < N; i++) {
        z[i] = cos(omega1 * (i - N/2)) - cos(omega2 * (i - N/2));
    }

    // Apply high frequency boost filter to y[n]
    for (i = 0; i < N; i++) {
        y[i] *= z[i];
    }

    // Perform inverse discrete Fourier transform on y[n]
    for (i = 0; i < N; i++) {
        x[i] = 0;
        for (j = 0; j < N; j++) {
            x[i] += y[j] * cos(2 * PI * i * j / N) + sin(2 * PI * i * j / N);
        }
        x[i] /= N;
    }

    // Print results
    for (i = 0; i < N; i++) {
        printf("%lf\n", x[i]);
    }

    return 0;
}