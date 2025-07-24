//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 256

static void apply_bandpass_filter(float *input, float *output, int num_samples, float sample_rate, float low_freq, float high_freq)
{
    float w0 = 2.0 * M_PI * ((low_freq + high_freq) / 2) / sample_rate;
    float Q = (high_freq - low_freq) / w0;
    float alpha = sin(w0) / (2 * Q);
    float b0 = alpha;
    float b1 = 0;
    float b2 = -alpha;
    float a0 = 1 + alpha;
    float a1 = -2 * cos(w0);
    float a2 = 1 - alpha;

    for (int i = 0; i < num_samples; i++)
    {
        if (i >= 2)
        {
            output[i] = (b0 / a0) * input[i] + (b1 / a0) * input[i-1] + (b2 / a0) * input[i-2] - (a1 / a0) * output[i-1] - (a2 / a0) * output[i-2];
        }
    }
}

int main(int argc, char *argv[])
{
    float input_signal[BUFFER_SIZE] = {0};
    float output_signal[BUFFER_SIZE] = {0};
    float sample_rate = 44100.0;
    float low_freq = 300.0;
    float high_freq = 3000.0;

    // Generate input signal
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        input_signal[i] = 0.2 * sin(2 * M_PI * i / (sample_rate / 1000)) + 0.4 * sin(2 * M_PI * i / (sample_rate / 5000)) + 0.1;
    }

    // Apply bandpass filter
    apply_bandpass_filter(input_signal, output_signal, BUFFER_SIZE, sample_rate, low_freq, high_freq);

    // Print output signal
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%.5f\n", output_signal[i]);
    }

    return 0;
}