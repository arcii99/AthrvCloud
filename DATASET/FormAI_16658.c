//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512         // number of samples in input signal
#define Fs 44100      // sampling frequency

int main()
{
    // Allocate continuous memory for input signal
    float *input_signal = (float*)malloc(sizeof(float) * N);

    // Generate input signal: A 1 kHz sine wave with amplitude 1 volt
    for(int i = 0; i < N; i++)
    {
        input_signal[i] = sin(2 * M_PI * 1000 * i/Fs);
    }

    // Allocate memory for output signal
    float *output_signal = (float*)calloc(N, sizeof(float));

    // Apply High-Pass Filter with cutoff frequency 500 Hz
    float fc = 500.0;       // Cutoff frequency in Hz
    float T = 1.0/Fs;       // Sampling period
    float R = 1.0;          // Resistance in ohms
    float C = 1.0/(2*M_PI*fc*R);     // Capacitance in farads
    float alpha = T/(T+C*R);         // Filter coefficient
    float prev_output = 0;      // Previous output for recursion

    for(int i = 0; i < N; i++)
    {
        output_signal[i] = alpha * input_signal[i] + (1.0 - alpha) * prev_output;
        prev_output = output_signal[i];
    }

    // Write output signal to file
    FILE *fp = fopen("output_signal.txt", "w");
    for(int i = 0; i < N; i++)
    {
        fprintf(fp, "%f\n", output_signal[i]);
    }
    fclose(fp);

    // Free memory
    free(input_signal);
    free(output_signal);

    return 0;
}