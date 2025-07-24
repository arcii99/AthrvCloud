//FormAI DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

void low_pass_filter(double input[], double output[], int size, double cutoff_freq);

int main()
{
    int n = 64;                      //number of samples
    double input_signal[n];         //input signal
    double output_signal[n];        //output signal

    //generate input signal with random noise
    for(int i = 0; i < n; i++)     
    {
        input_signal[i] = 5*sin((PI*2*i*5)/n) + (rand() % 10)/10.0;
    }

    //apply low pass filter with cutoff frequency of 10Hz
    low_pass_filter(input_signal, output_signal, n, 10.0);

    //output input and output signals
    printf("Input signal: \n");
    for(int i = 0; i < n; i++)     
    {
        printf("%f ", input_signal[i]);
    }
    printf("\n");

    printf("Output signal: \n");
    for(int i = 0; i < n; i++)     
    {
        printf("%f ", output_signal[i]);
    }
    printf("\n");

    return 0;
}

void low_pass_filter(double input[], double output[], int size, double cutoff_freq)
{
    //initialize filter coefficients
    double RC = 1.0 / (2 * PI * cutoff_freq);
    double dt = 0.1;
    double alpha = dt / (RC + dt);
    double filter_state;

    //apply filter to input signal
    for(int i = 0; i < size; i++)     
    {
        filter_state += alpha * (input[i] - filter_state);
        output[i] = filter_state;
    }
}