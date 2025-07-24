//FormAI DATASET v1.0 Category: Digital signal processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 48000.0

double sine_wave(double frequency, double time)
{
    return sin(2 * M_PI * frequency * time);
}

double lowpass_filter(double input, double prev_output, double cutoff_freq, double time)
{
    double rc = 1 / (2 * M_PI * cutoff_freq);
    double alpha = 1 / (rc + (1/SAMPLE_RATE));
    return (alpha * input) + ((1 - alpha) * prev_output);
}

void print_waveform(double *waveform, int length)
{
    printf("[");
    for(int i=0; i<length; i++)
    {
        printf("%.3f, ", waveform[i]);
    }
    printf("]\n");
}

int main()
{
    double freq1 = 1000; // Hz
    double freq2 = 2000; // Hz
    double freq3 = 3000; // Hz

    double waveform1[1000], waveform2[1000], waveform3[1000];
    double output1[1000], output2[1000], output3[1000];

    for(int i=0; i<1000; i++)
    {
        double time = i / SAMPLE_RATE;
        waveform1[i] = sine_wave(freq1, time);
        waveform2[i] = sine_wave(freq2, time);
        waveform3[i] = sine_wave(freq3, time);
    }

    printf("Input waveforms:\n");
    printf("Waveform 1:\n");
    print_waveform(waveform1, 1000);
    printf("Waveform 2:\n");
    print_waveform(waveform2, 1000);
    printf("Waveform 3:\n");
    print_waveform(waveform3, 1000);

    double cutoff_freq = 1500; // Hz
    double prev_output1 = 0, prev_output2 = 0, prev_output3 = 0;

    for(int i=0; i<1000; i++)
    {
        output1[i] = lowpass_filter(waveform1[i], prev_output1, cutoff_freq, i / SAMPLE_RATE);
        output2[i] = lowpass_filter(waveform2[i], prev_output2, cutoff_freq, i / SAMPLE_RATE);
        output3[i] = lowpass_filter(waveform3[i], prev_output3, cutoff_freq, i / SAMPLE_RATE);

        prev_output1 = output1[i];
        prev_output2 = output2[i];
        prev_output3 = output3[i];
    }

    printf("Output waveforms:\n");
    printf("Waveform 1:\n");
    print_waveform(output1, 1000);
    printf("Waveform 2:\n");
    print_waveform(output2, 1000);
    printf("Waveform 3:\n");
    print_waveform(output3, 1000);

    return 0;
}