//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Donald Knuth
// Donald Knuth style Digital Signal Processing Example

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Fs 44100                // Sampling frequency
#define f0 440                  // Fundamental frequency of sine wave
#define N 4096                  // Number of samples in signal
#define M 20                    // Number of filter coefficients
#define pi 3.14159265           // Pi approximation

int main()
{
    int n, m;
    double xn[N], yn[N], h[M], wn[M];     // Input signal, output signal, filter coefficients, window function

    // Generate input signal
    for(n=0; n<N; n++)
    {
        xn[n] = sin(2*pi*f0*n/Fs);
    }

    // Generate window function
    for(m=0; m<M; m++)
    {
        wn[m] = 0.54 - 0.46*cos(2*pi*m/(M-1));
    }

    // Generate filter coefficients
    for(m=0; m<M; m++)
    {
        h[m] = sin(2*pi*f0*(m-(M-1)/2)/Fs)/(pi*(m-(M-1)/2))*wn[m];
    }

    // Implement FIR filter
    for(n=M-1; n<N; n++)
    {
        yn[n] = 0;
        for(m=0; m<M; m++)
        {
            yn[n] += xn[n-m]*h[m];
        }
    }

    // Print input and output signals
    printf("n\tx(n)\ty(n)\n");
    for(n=0; n<N; n++)
    {
        printf("%d\t%f\t%f\n", n, xn[n], yn[n]);
    }

    return 0;
}