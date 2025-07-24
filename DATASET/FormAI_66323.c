//FormAI DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Define the sampling rate
#define BUFFER_SIZE 512 // Define the buffer size
#define NUM_CHANNELS 1 // Define the number of channels (1 for mono)

int main() {
    // Allocate memory for input/output buffers
    float* input = (float*)malloc(sizeof(float) * BUFFER_SIZE * NUM_CHANNELS);
    float* output = (float*)malloc(sizeof(float) * BUFFER_SIZE * NUM_CHANNELS);

    // Generate a sine wave as an input signal
    for (int i = 0; i < BUFFER_SIZE; i++) {
        float t = (float)i / SAMPLE_RATE;
        for (int ch = 0; ch < NUM_CHANNELS; ch++) {
            input[i * NUM_CHANNELS + ch] = sin(2.0 * M_PI * 440.0 * t);
        }
    }

    // Apply a simple low-pass filter to the input signal
    float prev_output = 0.0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        float input_sample = input[i * NUM_CHANNELS];
        float output_sample = 0.5 * input_sample + 0.5 * prev_output;
        prev_output = output_sample;
        output[i * NUM_CHANNELS] = output_sample;
    }

    // Free memory used by input/output buffers
    free(input);
    free(output);

    return 0;
}