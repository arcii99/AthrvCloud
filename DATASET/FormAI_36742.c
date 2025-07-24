//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a sine wave
void generate_sine_wave(int SAMPLE_RATE, double frequency, int length_ms, short *buffer) {
    const int waveform_table_size = SAMPLE_RATE / frequency;
    short waveform[waveform_table_size];
    const double period = 2.0 * M_PI / (double)waveform_table_size;
    for (int i = 0; i < waveform_table_size; i++) {
        waveform[i] = (short)(32767.0 * sin(i * period));
    }
    const int num_samples = SAMPLE_RATE * (length_ms / 1000.0);
    for (int i = 0; i < num_samples; i++) {
        const int waveform_index = i % waveform_table_size;
        buffer[i] += waveform[waveform_index];
    }
}

// Function to generate white noise
void generate_white_noise(int length_ms, short *buffer) {
    const int num_samples = 44100 * (length_ms / 1000.0);
    for (int i = 0; i < num_samples; i++) {
        buffer[i] += (rand() % 32767) - 16384;
    }
}

int main() {
    // Allocate memory for buffers
    const int BUFFER_SIZE = 44100;
    short *input_buffer = malloc(BUFFER_SIZE * sizeof(short));
    short *output_buffer = calloc(BUFFER_SIZE, sizeof(short));

    // Generate a sine wave and add it to the input buffer
    generate_sine_wave(44100, 440.0, 1000, input_buffer);

    // Generate white noise and add it to the input buffer
    generate_white_noise(1000, input_buffer);

    // Apply a low-pass filter to the input buffer
    const double RC = 1.0 / (2.0 * M_PI * 500.0);
    const double dt = 1.0 / 44100.0;
    const double alpha = dt / (RC + dt);
    double filtered_output = 0.0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        filtered_output += alpha * (input_buffer[i] - filtered_output);
        output_buffer[i] = (short)filtered_output;
    }

    // Cleanup
    free(input_buffer);
    free(output_buffer);
    return 0;
}