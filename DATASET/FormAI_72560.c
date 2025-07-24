//FormAI DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define audio buffer size
#define BUFFER_SIZE 4096

int main(void)
{
    // Declare buffers for audio input and output
    float input_buffer[BUFFER_SIZE];
    float output_buffer[BUFFER_SIZE];

    // Declare variables for frequency and amplitude of sawtooth wave
    float saw_freq = 440.0;
    float saw_amp = 1.0;

    // Fill input buffer with sawtooth wave
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        input_buffer[i] = sin(2.0 * PI * saw_freq * (float)i / 44100.0);
        input_buffer[i] *= saw_amp;
    }

    // Declare variables for low-pass filter
    float cutoff_freq = 1000.0;
    float resonance = 0.5;
    float feedback_amount = resonance + resonance / (1.0 - cutoff_freq / 22050.0);
    float filter_buffer[2] = {0.0, 0.0};

    // Apply low-pass filter to input buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        float feedback = filter_buffer[1] * feedback_amount;
        filter_buffer[0] = input_buffer[i] - feedback;
        output_buffer[i] = (filter_buffer[0] + filter_buffer[1]) / 2.0;
        filter_buffer[1] = filter_buffer[0];
    }

    // Declare variables for delay effect
    float delay_time = 0.5;
    float delay_feedback = 0.7;
    float delay_mix = 0.5;
    int delay_samples = (int)(delay_time * 44100.0);
    float delay_buffer[BUFFER_SIZE] = {0.0};

    // Apply delay effect to output buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        float delay_input = output_buffer[i] + delay_feedback * delay_buffer[i % delay_samples];
        delay_buffer[i % delay_samples] = delay_input;
        output_buffer[i] = (1.0 - delay_mix) * output_buffer[i] + delay_mix * delay_input;
    }

    // Declare variables for reverb effect
    float reverb_decay = 0.5;
    float reverb_mix = 0.5;
    int reverb_delay = 4410;
    float reverb_buffer[BUFFER_SIZE] = {0.0};

    // Apply reverb effect to output buffer
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        float reverb_input = output_buffer[i] + reverb_decay * reverb_buffer[i % reverb_delay];
        reverb_buffer[i % reverb_delay] = reverb_input;
        output_buffer[i] = (1.0 - reverb_mix) * output_buffer[i] + reverb_mix * reverb_input;
    }

    // Print output buffer to stdout
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%f\n", output_buffer[i]);
    }

    return 0;
}