//FormAI DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024 // Number of samples
#define Fs 1000 // Sampling frequency

int main(void)
{
    // Generate input signal
    float input[N];
    for (int n = 0; n < N; n++)
    {
        input[n] = sin(2 * M_PI * 50 * n / Fs) + sin(2 * M_PI * 200 * n / Fs); // 50 Hz and 200 Hz sine waves
    }

    // Low pass filter (FIR)
    int M = 99; // Filter order
    float h[M + 1]; // Filter coefficients
    float fc = 100; // Cutoff frequency
    for (int n = 0; n <= M; n++)
    {
        if (n == (M / 2))
        {
            h[n] = 2 * fc / Fs;
        }
        else
        {
            h[n] = sin(2 * M_PI * fc * (n - M/2) / Fs) / (M_PI * (n - M/2));
        }
    }

    // Convolution
    float output[N];
    for (int n = 0; n < N; n++)
    {
        output[n] = 0;
        for (int k = 0; k <= M; k++)
        {
            if (n - k >= 0)
            {
                output[n] += h[k] * input[n-k];
            }
        }
    }

    // Display input and output signals
    printf("Sample\tInput\tOutput\n");
    for (int n = 0; n < N; n++)
    {
        printf("%d\t%f\t%f\n", n, input[n], output[n]);
    }

    return 0;
}