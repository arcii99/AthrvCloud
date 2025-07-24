//FormAI DATASET v1.0 Category: Digital signal processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int n = 8; // number of discrete time samples
    double x[] = {1, -2, 3, -4, 5, -6, 7, -8}; // discrete time input signal
    double y[n]; // discrete time output signal
    double h[] = {1, -1, 1, -1, 1, -1, 1, -1}; // LPF impulse response
    int M = 8; // filter length
    int i, j;

    for (i = 0; i < n; i++) {
        y[i] = 0.0; // initialize the output signal
        for (j = 0; j < M; j++) {
            if (i - j < 0) {
                continue; // skip if out of bounds
            }
            y[i] += h[j] * x[i - j]; // convolution sum
        }
    }

    // Display input signal
    printf("Input signal:\n");
    for (i = 0; i < n; i++) {
        printf("%f ", x[i]);
    }
    printf("\n");

    // Display impulse response
    printf("Impulse response:\n");
    for (i = 0; i < M; i++) {
        printf("%f ", h[i]);
    }
    printf("\n");

    // Display output signal
    printf("Output signal:\n");
    for (i = 0; i < n; i++) {
        printf("%f ", y[i]);
    }
    printf("\n");

    return 0;
}