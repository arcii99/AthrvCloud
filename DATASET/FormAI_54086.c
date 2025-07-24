//FormAI DATASET v1.0 Category: Digital signal processing ; Style: real-life
// This program demonstrates how to perform real-time filtering of an audio signal 
// using digital signal processing algorithms in C language. 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILTER_ORDER 5
#define SAMPLING_RATE 44100
#define CUTOFF_FREQUENCY 2000

void filter(float *input, int len, float *output, float *coeff)
{
    float delay[FILTER_ORDER] = {0};
    int i, j;
    for (i = 0; i < len; i++)
    {
        output[i] = 0;
        for (j = FILTER_ORDER - 1; j > 0; j--)
        {
            delay[j] = delay[j - 1];
            output[i] += delay[j] * coeff[j];
        }
        delay[0] = input[i];
        output[i] += input[i] * coeff[0];
    }
}

int main()
{
    float coeff[FILTER_ORDER + 1];
    float input[SAMPLING_RATE], output[SAMPLING_RATE];
    int i;

    float omega_c = 2 * M_PI * CUTOFF_FREQUENCY / SAMPLING_RATE; 

    // Calculate filter coefficients using Butterworth filter design algorithm 
    float numerator[FILTER_ORDER + 1] = {1, 0, 0, 0, 0, 0};
    float denominator[FILTER_ORDER + 1] = {1, -1.61803399, 1.53208889, -0.80473785, 0.20019581, -0.02008341};

    for (i = 0; i <= FILTER_ORDER; i++)
    {
        coeff[i] = numerator[i] - denominator[i] * cos(omega_c) + sin(omega_c);
    }

    // Generate input signal by adding two sine waves of different frequencies 
    float freq1 = 1000;
    float freq2 = 5000;
    for (i = 0; i < SAMPLING_RATE; i++)
    {
        input[i] = sin(2 * M_PI * freq1 * i / SAMPLING_RATE) + sin(2 * M_PI * freq2 * i / SAMPLING_RATE);
    }

    // Filter the input signal using the designed filter 
    filter(input, SAMPLING_RATE, output, coeff);

    // Output the filtered signal to a file 
    FILE *fp = fopen("output.txt", "w");
    for (i = 0; i < SAMPLING_RATE; i++)
    {
        fprintf(fp, "%f\n", output[i]);
    }
    fclose(fp);

    return 0;
}