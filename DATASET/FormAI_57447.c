//FormAI DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

// Declare the audio processing function
void audio_processing(float *input_buffer, float *output_buffer);

int main(void) {
    // Allocate memory for input and output buffers
    float input_buffer[BUFFER_SIZE];
    float output_buffer[BUFFER_SIZE];

    // Fill the input buffer with a sine wave
    for (int i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
    }

    // Call the audio processing function
    audio_processing(input_buffer, output_buffer);

    // Print the output buffer
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", output_buffer[i]);
    }

    return 0;
}

void audio_processing(float *input_buffer, float *output_buffer) {
    // Declare local variables for the audio processing
    float accumulator = 0.0;
    float decay_coeff = exp(-1.0 / (0.1 * SAMPLE_RATE));
    float freq_shift = 1.2 * M_PI / SAMPLE_RATE;
    float phase = 0.0;

    // Process each sample in the buffer
    for (int i = 0; i < BUFFER_SIZE; i++) {
        // Get the current input sample
        float input_sample = input_buffer[i];

        // Apply a resonant low-pass filter
        float filtered_sample = input_sample + 0.8 * accumulator;
        accumulator = filtered_sample * decay_coeff;

        // Apply a frequency shifter
        float shifted_sample = filtered_sample * cos(phase);
        phase += freq_shift;
        if (phase > M_PI) {
            phase -= 2 * M_PI;
        }

        // Write the output sample to the buffer
        output_buffer[i] = shifted_sample;
    }
}