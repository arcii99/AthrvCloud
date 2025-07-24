//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ada Lovelace
/* This program applies a digital filter to a signal using the convolution method. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Sampling rate in Hz
#define SIGNAL_LENGTH 2000 // Number of samples in signal
#define FILTER_LENGTH 1000 // Number of samples in filter

double signal[SIGNAL_LENGTH]; // Input signal array
double filter[FILTER_LENGTH]; // Filter array
double filtered_signal[SIGNAL_LENGTH]; // Resulting filtered signal array

void generate_signal() // Generate input signal
{
    int i;
    for(i = 0; i < SIGNAL_LENGTH; i++)
    {
        signal[i] = sin((double)i * 2.0 * M_PI / ((double)SIGNAL_LENGTH / 200.0)) +
                    0.5 * sin((double)i * 2.0 * M_PI / ((double)SIGNAL_LENGTH / 600.0));
    }
}

void generate_filter() // Generate filter
{
    int i;
    for(i = 0; i < FILTER_LENGTH; i++)
    {
        filter[i] = exp(-((double)i * 2.0 / FILTER_LENGTH));
    }
}

void convolve() // Convolve input signal with filter
{
    int i, j;
    double sum;
    for(i = 0; i < SIGNAL_LENGTH; i++)
    {
        sum = 0;
        for(j = 0; j < FILTER_LENGTH; j++)
        {
            if(i - j >= 0 && i - j < SIGNAL_LENGTH)
            {
                sum += signal[i - j] * filter[j];
            }
        }
        filtered_signal[i] = sum;
    }
}

void print_result() // Prints resulting filtered signal
{
    int i;
    for(i = 0; i < SIGNAL_LENGTH; i++)
    {
        printf("%f\n", filtered_signal[i]);
    }
}

int main()
{
    generate_signal();
    generate_filter();
    convolve();
    print_result();
    return 0;
}