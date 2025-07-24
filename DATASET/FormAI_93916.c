//FormAI DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILTER_LEN 10 // Length of the FIR filter

void apply_fir_filter(float *input, float *output, float *coefficients, int input_length);
void print_array(float *array, int length);

int main()
{
    float input_signal[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}; // Input signal
    float output_signal[FILTER_LEN + 9]; // Output signal
    float filter_coefficients[FILTER_LEN] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0}; // FIR filter coefficients

    printf("Input Signal: ");
    print_array(input_signal, 10);

    apply_fir_filter(input_signal, output_signal, filter_coefficients, 10);

    printf("Output Signal: ");
    print_array(output_signal, FILTER_LEN + 9);

    return 0;
}

// Function for applying FIR filter on the input signal
void apply_fir_filter(float *input, float *output, float *coefficients, int input_length)
{
    int i, j;
    float filter_out;

    for (i = 0; i < input_length + FILTER_LEN - 1; i++)
    {
        filter_out = 0.0;
        for (j = 0; j < FILTER_LEN; j++)
        {
            if (i >= j && i - j < input_length)
            {
                filter_out += input[i - j] * coefficients[j];
            }
        }
        output[i] = filter_out;
    }
}

// Function for printing an array
void print_array(float *array, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}