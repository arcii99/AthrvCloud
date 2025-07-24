//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Function to generate a sinusoidal signal
void genSinusoidalSignal(float f, float fs, float dur, float A, float *x)
{
    int n, samples = dur * fs;
    for(n = 0; n < samples; ++n)
    {
        x[n] = A * sin(2 * PI * f * n / fs);
    }
}

// Function to generate a sawtooth signal
void genSawtoothSignal(float f, float fs, float dur, float A, float *x)
{
    int n, samples = dur * fs;
    float ts = 1 / f, t = 0;
    for(n = 0; n < samples; ++n)
    {
        x[n] = A * ((t - floor(t / ts) * ts) / ts - 0.5);
        t += 1 / fs;
    }
}

// Function to perform Discrete Fourier Transform (DFT)
void DFT(float *x, int N, float *Xr, float *Xi)
{
    int k, n;
    float arg;
    for(k = 0; k < N; ++k)
    {
        Xr[k] = 0;
        Xi[k] = 0;
        for(n = 0; n < N; ++n)
        {
            arg = 2 * PI * k * n / N;
            Xr[k] += x[n] * cos(arg);
            Xi[k] -= x[n] * sin(arg);
        }
    }
}

int main()
{
    int i, N = 256;
    float f = 50, fs = 1000, dur = 1, A = 1;
    float x[N], Xr[N], Xi[N], mag[N];
    
    // Generate a sinusoidal signal
    genSinusoidalSignal(f, fs, dur, A, x);
    
    // Perform DFT and calculate magnitude spectrum
    DFT(x, N, Xr, Xi);
    for(i = 0; i < N; ++i)
    {
        mag[i] = 2 * sqrt(Xr[i] * Xr[i] + Xi[i] * Xi[i]) / N;
    }
    
    // Print magnitude spectrum
    for(i = 0; i < N; ++i)
    {
        printf("%d, %f\n", i, mag[i]);
    }
    
    // Generate a sawtooth signal and repeat DFT
    genSawtoothSignal(f, fs, dur, A, x);
    DFT(x, N, Xr, Xi);
    for(i = 0; i < N; ++i)
    {
        mag[i] = 2 * sqrt(Xr[i] * Xr[i] + Xi[i] * Xi[i]) / N;
    }
    
    // Print magnitude spectrum
    for(i = 0; i < N; ++i)
    {
        printf("%d, %f\n", i, mag[i]);
    }
    
    return 0;
}