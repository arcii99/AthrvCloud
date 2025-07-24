//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 16

// Decentralized Discrete Fourier Transform function
void dft(double *x, double *y) {
    int k, n;
    double angle;
    for (k = 0; k < N; k++) {
        y[k] = 0;
        for (n = 0; n < N; n++) {
            angle = 2 * M_PI * k * n / N;
            y[k] += x[n] * cos(angle) - x[n] * sin(angle);
        }
        y[k] /= N;
    }
}

int main() {
    double x[] = {2.0, 1.0, 3.0, 4.0, 6.0, 9.0, 5.0, 8.0, 7.0, 3.0, 4.0, 1.0, 2.0, 5.0, 7.0, 8.0};
    double y[N];
    int i;

    printf("The original signal is:\n");
    for (i = 0; i < N; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\n\n");

    dft(x, y);

    printf("The frequency domain representation of the signal is:\n");
    for (i = 0; i < N; i++) {
        printf("%.2f + %.2fi\n", y[i]);
    }

    return 0;
}