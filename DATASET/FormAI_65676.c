//FormAI DATASET v1.0 Category: Digital signal processing ; Style: accurate
// This program is a digital filter that removes noise from a signal using digital signal processing (DSP).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define BUFFER_SIZE 1024

void apply_filter(double *input, double *output, int length, double *coefficients, int order);

int main(int argc, char **argv)
{
    double input[BUFFER_SIZE];
    double output[BUFFER_SIZE];
    double coefficients[3] = {0.1, 0.3, 0.1};
    int order = 2;
    int i;

    // Generate input signal
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        input[i] = sin(2 * M_PI * 440.0 * i / SAMPLE_RATE)
                      + sin(2 * M_PI * 880.0 * i / SAMPLE_RATE)
                      + sin(2 * M_PI * 1320.0 * i / SAMPLE_RATE);
    }

    // Apply filter
    apply_filter(input, output, BUFFER_SIZE, coefficients, order);

    // Print output
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%f\n", output[i]);
    }

    return 0;
}

void apply_filter(double *input, double *output, int length, double *coefficients, int order)
{
    int i, j;

    for (i = 0; i < length; i++)
    {
        output[i] = 0.0;

        for (j = 0; j <= order; j++)
        {
            if (i - j < 0)
            {
                continue;
            }

            output[i] += coefficients[j] * input[i - j];
        }
    }
}