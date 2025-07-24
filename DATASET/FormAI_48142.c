//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define N 64 // Number of samples
#define M 4 // Number of coefficients

// Generate a test signal: a linear combination of two sine waves
void generate_signal(double x[N]) {
    double f1 = 5.0; // Frequency of first sine wave
    double f2 = 15.0; // Frequency of second sine wave
    for (int n = 0; n < N; n++) {
        x[n] = 1.0 * sin(2.0 * M_PI * f1 * n / N) + 0.5 * sin(2.0 * M_PI * f2 * n / N);
    }
}

// Implement a FIR filter with M coefficients
void fir_filter(double x[N], double h[M], double y[N]) {
    for (int n = 0; n < N; n++) {
        y[n] = 0.0; // Initialize output sample
        for (int k = 0; k < M; k++) {
            if (n-k >= 0) {
                y[n] += h[k] * x[n-k]; // Compute convolution sum
            }
        }
    }
}

int main() {
    double x[N];
    double h[M] = {0.1, 0.2, 0.3, 0.4}; // Filter coefficients
    double y[N];
    
    // Generate test signal
    generate_signal(x);
    
    // Apply FIR filter
    fir_filter(x, h, y);
    
    // Print input and output signals
    printf("Input signal:\n");
    for (int n = 0; n < N; n++) {
        printf("%f ", x[n]);
    }
    printf("\n\nOutput signal:\n");
    for (int n = 0; n < N; n++) {
        printf("%f ", y[n]);
    }
    printf("\n");
    
    return 0;
}