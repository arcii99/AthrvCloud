//FormAI DATASET v1.0 Category: Digital signal processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000    // length of signal

double x[N], y[N];  // input and output signals
double h[N], w[N];  // impulse response and window function

void generate_signal() {
    // Generate input signal x[n] using a random number generator
    for (int n = 0; n < N; n++) {
        x[n] = rand() / (double)RAND_MAX;  // random value between 0 and 1
    }
}

void generate_impulse_response() {
    // Generate impulse response h[n] of low-pass filter
    for (int n = 0; n < N; n++) {
        if (n == N/2) {
            h[n] = 2.0 / M_PI;
        } else {
            h[n] = sin(2.0 * M_PI * (n - N/2)) / (M_PI * (n - N/2));
        }
    }
}

void generate_window() {
    // Generate window function w[n] for applying the filter
    for (int n = 0; n < N; n++) {
        w[n] = 0.5 * (1.0 - cos(2.0 * M_PI * n / (N-1)));
    }
}

void apply_filter() {
    // Apply filter to input signal x[n] using convolution
    for (int n = 0; n < N; n++) {
        y[n] = 0.0;
        for (int k = 0; k < N; k++) {
            if (n-k < 0) {
                break;
            }
            y[n] += x[k] * h[n-k];
        }
        y[n] *= w[n];
    }
}

void print_result() {
    // Print input, impulse response, window function and output signals
    printf("Input signal x[n]:\n");
    for (int n = 0; n < N; n++) {
        printf("%f\n", x[n]);
    }
    printf("\nImpulse response h[n]:\n");
    for (int n = 0; n < N; n++) {
        printf("%f\n", h[n]);
    }
    printf("\nWindow function w[n]:\n");
    for (int n = 0; n < N; n++) {
        printf("%f\n", w[n]);
    }
    printf("\nOutput signal y[n]:\n");
    for (int n = 0; n < N; n++) {
        printf("%f\n", y[n]);
    }
}

int main() {
    generate_signal();
    generate_impulse_response();
    generate_window();
    apply_filter();
    print_result();

    return 0;
}