//FormAI DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    // Create input signal
    int input_signal_length = 64;
    float input_signal[input_signal_length];
    for(int i = 0; i < input_signal_length; i++)
    {
        input_signal[i] = sin(2 * PI * i / input_signal_length);
    }
    
    // Create low-pass filter coefficients
    int filter_order = 3;
    float cutoff_frequency = 0.2;
    float low_pass_filter[filter_order + 1];
    for(int i = 0; i <= filter_order; i++)
    {
        if(i == filter_order/2)
        {
            low_pass_filter[i] = 2 * cutoff_frequency;
        }
        else
        {
            float constant = sin(2 * PI * cutoff_frequency * (i - filter_order/2)) / (PI * (i - filter_order/2));
            low_pass_filter[i] = constant * (0.54 - 0.46 * cos(2 * PI * i / filter_order));
        }
    }
    
    // Convolve input signal with low-pass filter
    int output_signal_length = input_signal_length - filter_order;
    float output_signal[output_signal_length];
    for(int i = filter_order/2; i < input_signal_length - filter_order/2; i++)
    {
        float conv_result = 0;
        for(int j = 0; j <= filter_order; j++)
        {
            conv_result += input_signal[i - filter_order/2 + j] * low_pass_filter[j];
        }
        output_signal[i - filter_order/2] = conv_result;
    }
    
    // Print input signal and output signal
    printf("Input signal:\n");
    for(int i = 0; i < input_signal_length; i++)
    {
        printf("%.2f ", input_signal[i]);
    }
    printf("\n");
    
    printf("Output signal:\n");
    for(int i = 0; i < output_signal_length; i++)
    {
        printf("%.2f ", output_signal[i]);
    }
    printf("\n");
    
    return 0;
}