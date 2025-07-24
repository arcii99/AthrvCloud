//FormAI DATASET v1.0 Category: Digital signal processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    int n = 10;  // Number of discrete samples
    double fs = 8000;  // Sampling frequency
    double f1 = 1020;  // Frequency of sinusoid to be filtered
    double f2 = 2000;  // Frequency of interfering sinusoid
    double A1 = 1;  // Amplitude of sinusoid to be filtered
    double A2 = 0.5;  // Amplitude of interfering sinusoid
    double wn = 2 * PI * f1 / fs;  // Normalized frequency
    double w2n = 2 * PI * f2 / fs;  // Interfering normalized frequency
    double theta = PI / 4;  // Phase shift of sinusoid to be filtered
    double x[n];  // Input signal
    double y[n];  // Output signal
    
    // Generate input signal
    for (int i = 0; i < n; i++) {
        x[i] = A1 * sin(wn * i + theta) + A2 * sin(w2n * i);
    }
    
    // Implement low-pass filter with cutoff frequency 1200 Hz
    double b0 = 0.1493;
    double b1 = 0.2986;
    double b2 = 0.1493;
    double a1 = 0.4328;
    double a2 = -0.1712;
    
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (int i = 0; i < n; i++) {
        y[i] = b0 * x[i] + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
        x2 = x1;
        x1 = x[i];
        y2 = y1;
        y1 = y[i];
    }
    
    // Print output signal to console
    for (int i = 0; i < n; i++) {
        printf("%f ", y[i]);
    }
    printf("\n");
    
    return 0;
}