//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Claude Shannon
// Program to implement FIR filter for digital signal processing
#include <stdio.h>
#include <stdlib.h>

#define NUM_TAPS 10 // Length of filter coefficient array
#define NUM_SAMPLES 50 // Length of input signal array

float input_signal[NUM_SAMPLES] = {0.6, 0.2, -0.4, 0.8, -0.1, 0.3, -0.5, 0.9, -0.8, 0.4, -0.2, 0.5, -0.7, 0.1, -0.3, 0.6, -0.2, 0.4, -0.5, 0.7, -0.9, 0.3, -0.1, 0.8, -0.6, 0.2, -0.4, 0.8, -0.1, 0.3, -0.5, 0.9, -0.8, 0.4, -0.2, 0.5, -0.7, 0.1, -0.3, 0.6, -0.2, 0.4, -0.5, 0.7, -0.9, 0.3, -0.1, 0.8, -0.6, 0.2, -0.4};
float filter_coefficients[NUM_TAPS] = {0.1, 0.05, -0.05, -0.1, 0.1, -0.2, 0.3, -0.1, -0.05, 0.05};
float output_signal[NUM_SAMPLES];

int main()
{
    int i, j;
    float temp_output;

    // Apply FIR filter to input signal
    for(i=0; i<NUM_SAMPLES; i++)
    {
        temp_output = 0;
        for(j=0; j<NUM_TAPS; j++)
        {
            if(i-j >= 0)
            {
                temp_output += input_signal[i-j] * filter_coefficients[j];
            }
        }
        output_signal[i] = temp_output;
    }

    // Print input and output signals
    printf("Input Signal: ");
    for(i=0; i<NUM_SAMPLES; i++)
    {
        printf("%f ", input_signal[i]);
    }
    printf("\n\n");

    printf("Output Signal: ");
    for(i=0; i<NUM_SAMPLES; i++)
    {
        printf("%f ", output_signal[i]);
    }
    printf("\n");

    return 0;
}