//FormAI DATASET v1.0 Category: Digital signal processing ; Style: all-encompassing
// This DSP program calculates the Discrete Fourier Transform (DFT) of a periodic function
// Given a periodic function, sampled at N equally-spaced points, this program calculates the DFT of the function
// The program then plots the magnitude of the DFT spectrum

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    int N = 64;                         // number of samples
    float signal[N];                    // array to store the sampled values of the periodic function
    float real_part[N], imag_part[N];   // arrays to store the real and imaginary parts of the DFT

    // Generate a periodic function
    for (int i = 0; i < N; i++)
    {
        signal[i] = sin(2*PI*i/N);
    }

    // Calculate the DFT
    for (int k = 0; k < N; k++)
    {
        real_part[k] = 0;
        imag_part[k] = 0;

        for (int n = 0; n < N; n++)
        {
            real_part[k] += signal[n] * cos(2*PI*k*n/N);
            imag_part[k] += -signal[n] * sin(2*PI*k*n/N);
        }
    }

    // Plot the magnitude of the DFT spectrum
    printf("DFT Magnitude Spectrum:\n");
    for (int k = 0; k < N; k++)
    {
        float magnitude = sqrt(pow(real_part[k], 2.0) + pow(imag_part[k], 2.0));
        printf("%f\n", magnitude);
    }

    return 0;
}