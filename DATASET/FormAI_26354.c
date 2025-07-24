//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complex
#include <stdio.h>
#include <math.h>

#define N 128

float signal_real[N];
float signal_imag[N];
float filter_coeff[N];
float filter_delay[N];
float output_real[N];
float output_imag[N];

int main()
{
    int i, j;

    // Initialize signal values
    for(i = 0; i < N; i++)
    {
        signal_real[i] = sin(2 * M_PI * 4 * i / N);
        signal_imag[i] = cos(2 * M_PI * 4 * i / N);
    }

    // Initialize filter coefficients
    for(i = 0; i < N; i++)
    {
        if(i < N / 2)
            filter_coeff[i] = 1.0 / (1 + powf((i - N / 2.0) / (N / 8.0), 2));
        else
            filter_coeff[i] = 0.0;
    }

    // Apply filter to signal
    for(i = 0; i < N; i++)
    {
        // Shift delay line
        for(j = N - 1; j > 0; j--)
        {
            filter_delay[j] = filter_delay[j - 1];
        }
        filter_delay[0] = signal_real[i];

        // Apply filter to real part of signal
        output_real[i] = 0.0;
        for(j = 0; j < N; j++)
        {
            output_real[i] += filter_coeff[j] * filter_delay[j];
        }

        // Shift delay line
        for(j = N - 1; j > 0; j--)
        {
            filter_delay[j] = filter_delay[j - 1];
        }
        filter_delay[0] = signal_imag[i];

        // Apply filter to imaginary part of signal
        output_imag[i] = 0.0;
        for(j = 0; j < N; j++)
        {
            output_imag[i] += filter_coeff[j] * filter_delay[j];
        }
    }

    // Print results
    printf("Signal\t\tFiltered Signal\n");
    for(i = 0; i < N; i++)
    {
        printf("%f + %fi\t%f + %fi\n", signal_real[i], signal_imag[i], output_real[i], output_imag[i]);

        // Add some delay
        for(j = 0; j < 50000; j++);
    }

    return 0;
}