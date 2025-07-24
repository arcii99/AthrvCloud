//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Alan Touring
// This is a C Program to implement a Multirate Digital Signal Processing
// algorithm to sample and filter an incoming signal at different rates
// and frequencies.

#include <stdio.h>
#include <math.h>

#define N 8192    // number of input samples
#define M 16      // decimation factor
#define L 32      // interpolation factor

int main()
{
    // Generate input signal
    double x[N];
    double fs = 8000.0;
    double f1 = 400.0;
    double f2 = 1000.0;
    double dt = 1/fs;
    for (int i = 0; i < N; i++) {
        x[i] = sin(2*M_PI*f1*i*dt) + sin(2*M_PI*f2*i*dt);
    }

    // Decimate input signal
    double xd[N/M];
    int j = 0;
    for (int i = 0; i < N/M; i++) {
        xd[i] = x[j];
        j += M;
    }
    
    // Filter decimated signal using a lowpass FIR filter
    double h[128];
    double fc = fs/(2*M);
    for (int i = 0; i < 128; i++) {
        if (i == 64) {
            h[i] = 2*fc/fs;
        } else {
            h[i] = sin(2*M_PI*fc*(i-64)/fs)/(M_PI*(i-64));
        }
    }
    double yd[N/M];
    for (int i = 0; i < N/M; i++) {
        double sum = 0.0;
        for (int k = 0; k < 128; k++) {
            if (i*M-k >= 0) {
                sum += xd[i*M-k]*h[k];
            }
        }
        yd[i] = sum;
    }

    // Interpolate filtered signal using a sinc interpolation
    double y[N*L/M];
    for (int i = 0; i < N*L/M; i++) {
        double sum = 0.0;
        double t = i*dt/L;
        for (int k = 0; k < 128; k++) {
            if (t-k+(64/L) == 0) {
                sum += yd[i/L]*h[k];
            } else {
                sum += yd[i/L]*sin(M_PI*(t-((64/L)-k))*L/dt)/(M_PI*(t-((64/L)-k))*L/dt)*h[k];
            }
        }
        y[i] = sum;
    }

    // Print results
    printf("Input signal:\n");
    for (int i = 0; i < N; i++) {
        printf("%.6f\n", x[i]);
    }
    printf("Decimated signal:\n");
    for (int i = 0; i < N/M; i++) {
        printf("%.6f\n", xd[i]);
    }
    printf("Filtered decimated signal:\n");
    for (int i = 0; i < N/M; i++) {
        printf("%.6f\n", yd[i]);
    }
    printf("Interpolated signal:\n");
    for (int i = 0; i < N*L/M; i++) {
        printf("%.6f\n", y[i]);
    }

    return 0;
}