//FormAI DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILTER_SIZE 10

// Function to apply a FIR filter to an audio signal
void fir_filter(double* signal, double* filtered_signal, int signal_len, double* filter_coeffs)
{
    int i, j;
    double sum;

    for (i = FILTER_SIZE - 1; i < signal_len; i++)
    {
        // Convolve signal with filter coefficients
        sum = 0.0;
        for (j = 0; j < FILTER_SIZE; j++)
        {
            sum += signal[i - j] * filter_coeffs[j];
        }

        filtered_signal[i] = sum;
    }
}

int main()
{
    // Create an audio signal with noise
    int signal_len = 100;
    double signal[signal_len];
    double noise[signal_len];
    double filtered_signal[signal_len];

    int i;
    for (i = 0; i < signal_len; i++)
    {
        signal[i] = sin(2 * M_PI * i / 10) + sin(2 * M_PI * i / 5) + 0.5 * rand() / RAND_MAX;
        noise[i] = 0.5 * rand() / RAND_MAX; // Add some noise to the signal
    }

    // Define filter coefficients for a low-pass filter
    double filter_coeffs[FILTER_SIZE] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

    // Filter out noise from the audio signal
    fir_filter(signal, filtered_signal, signal_len, filter_coeffs);

    // Print the original signal, noise, and filtered signal
    printf("Original Signal:\n");
    for (i = 0; i < signal_len; i++)
    {
        printf("%f\n", signal[i]);
    }

    printf("Noise:\n");
    for (i = 0; i < signal_len; i++)
    {
        printf("%f\n", noise[i]);
    }

    printf("Filtered Signal:\n");
    for (i = 0; i < signal_len; i++)
    {
        printf("%f\n", filtered_signal[i]);
    }

    return 0;
}