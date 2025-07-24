//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    int n = 64; // Number of samples
    int fs = 8000; // Sampling frequency in Hz
    float f = 500; // Signal frequency in Hz
    float amplitude = 1; // Signal amplitude
    float phase = PI/4; // Signal phase
    float duration = (float)n/fs; // Duration of signal in seconds

    float x[n]; // Input signal
    float y[n]; // Output signal

    // Generate input signal
    for(int i = 0; i < n; i++)
    {
        x[i] = amplitude*sin(2*PI*f*i/fs + phase);
    }

    // Low-pass filter coefficients
    float b[4] = {0.06136, 0.24545, 0.36718, 0.24545};
    float a[4] = {1.0000, -1.2794, 0.7919, -0.1529};

    // Apply low-pass filter
    for(int i = 0; i < n; i++)
    {
        y[i] = b[0]*x[i];
        for(int j = 1; j <= 3; j++)
        {
            if(i-j < 0)
                break;
            y[i] += b[j]*x[i-j] - a[j]*y[i-j];
        }
    }

    // Print input signal
    printf("Input signal:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%f ", x[i]);
    }
    printf("\n");

    // Print output signal
    printf("\nOutput signal:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%f ", y[i]);
    }
    printf("\n");

    return 0;
}