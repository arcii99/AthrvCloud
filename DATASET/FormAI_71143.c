//FormAI DATASET v1.0 Category: Digital signal processing ; Style: genious
#include <stdio.h>

// A Genius-style C program for implementing a FIR filter using digital signal processing

#define N 5 // Number of filter coefficients

float h[N] = {0.1, 0.2, 0.3, 0.2, 0.1}; // Filter coefficients

int main()
{
    float x[N] = {0}; // Input signal buffer
    float y = 0; // Output signal

    for (int i = 0; i < N; i++)
    {
        x[i] = i + 1; // Fill input signal buffer with some values
    }

    for (int n = 0; n < N; n++)
    {
        y = 0; // Clear output signal
        for (int k = 0; k < N; k++)
        {
            if (n - k >= 0) // Check if index is within bounds
            {
                y += h[k] * x[n - k]; // Convolution operation
            }
        }
        printf("y[%d] = %f\n", n, y); // Print output signal
    }

    return 0;
}