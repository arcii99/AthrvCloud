//FormAI DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 128          // length of input signal
#define M 64           // length of filter coefficients
#define Fs 44100       // sampling frequency
#define f0 1000        // frequency of input signal

int main()
{
    float x[N];           // input signal
    float h[M];           // filter coefficients
    float y[N + M - 1];   // output signal
    float t = 0;          // time variable
    float dt = 1 / (float)Fs;
    float fc = f0/2;      // cutoff frequency of filter
    int n, k;

    // Generate input signal as sine wave at f0 Hz
    for (n = 0; n < N; n++)
    {
        x[n] = sin(2 * M_PI * f0 * t);
        t += dt;
    }

    // Generate filter coefficients for a low-pass FIR filter
    for (k = 0; k < M; k++)
    {
        if (k == (M - 1) / 2)
            h[k] = 2 * fc / Fs;
        else
            h[k] = sin(2 * M_PI * fc * (k - (M - 1) / 2) / Fs) / (M_PI * (k - (M - 1) / 2));
    }

    // Convolve input signal with filter coefficients
    for (n = 0; n < N + M - 1; n++)
    {
        y[n] = 0;
        for (k = 0; k < M; k++)
        {
            if (n < k)
                continue;
            if (n - k >= N)
                continue;
            y[n] += x[n - k] * h[k];
        }
    }

    // Print input and output signals to file
    FILE* fp_in = fopen("input_signal.txt", "w");
    FILE* fp_out = fopen("output_signal.txt", "w");

    for (n = 0; n < N; n++)
        fprintf(fp_in, "%d %f\n", n, x[n]);

    for (n = 0; n < N + M - 1; n++)
        fprintf(fp_out, "%d %f\n", n, y[n]);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}