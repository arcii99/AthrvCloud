//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

// Function to perform FFT
void fft(double *X, int n) {
    if (n == 1)
        return;

    double *X_odd = (double*) malloc(n/2 * sizeof(double));
    double *X_even = (double*) malloc(n/2 * sizeof(double));

    // divide X into odd and even halves
    for (int i = 0; i < n/2; i++) {
        X_even[i] = X[2*i];
        X_odd[i] = X[2*i+1];
    }

    // perform recursion on even and odd halves
    fft(X_even, n/2);
    fft(X_odd, n/2);

    // calculate twiddle factors
    double w_real, w_imag;
    double theta = 2*PI/n;
    double w_x, w_y;
    for (int i = 0; i < n/2; i++) {
        w_real = cos(i*theta);
        w_imag = -sin(i*theta);

        w_x = w_real*X_odd[i] - w_imag*X_even[i+n/2];
        w_y = w_imag*X_odd[i] + w_real*X_even[i+n/2];

        // combine even and odd halves
        X[2*i] = X_even[i] + w_x;
        X[2*i+1] = X_odd[i] + w_y;
    }

    free(X_even);
    free(X_odd);
}

int main() {
    int n = 8; // length of signal
    double x[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // input signal
    double X[8]; // output signal

    // Perform FFT on input signal
    fft(x, n);

    // Print output signal
    for (int i = 0; i < n; i++) {
        printf("%lf + %lfi\n", creal(X[i]), cimag(X[i]));
    }

    return 0;
}