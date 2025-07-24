//FormAI DATASET v1.0 Category: Digital signal processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void main()
{
    int n = 8;  // number of signal samples
    double f0 = 100;  // signal frequency
    double Fs = 10000;  // sampling frequency
    double Ts = 1/Fs;  // sampling interval
    double t[n];  // time vector
    double x[n];  // signal vector
    double Xr[n];  // real part of FFT result
    double Xi[n];  // imaginary part of FFT result
    int k;  // frequency index

    // Generate signal
    for(int i = 0; i < n; i++)
    {
        t[i] = i*Ts;
        x[i] = sin(2*PI*f0*t[i]);
        printf("Sample %d: x[%d] = %f\n", i+1, i, x[i]);
    }

    // Compute FFT
    for(k = 0; k < n; k++)
    {
        Xr[k] = 0;
        Xi[k] = 0;
        for(int i = 0; i < n; i++)
        {
            double angle = 2*PI*k*i/n;
            Xr[k] += x[i]*cos(angle);
            Xi[k] -= x[i]*sin(angle);
        }
        printf("FFT (%d): Xr[%d] = %f, Xi[%d] = %f\n", k+1, k, Xr[k], k, Xi[k]);
    }

    // Compute magnitude and phase
    double mag[n];
    double phase[n];
    for(int i = 0; i < n; i++)
    {
        mag[i] = sqrt(Xr[i]*Xr[i] + Xi[i]*Xi[i]);
        phase[i] = atan2(Xi[i], Xr[i]);
        printf("Magnitude (%d): |X[%d]| = %f\n", i+1, i, mag[i]);
        printf("Phase (%d): <X[%d] = %f\n", i+1, i, phase[i]);
    }
}