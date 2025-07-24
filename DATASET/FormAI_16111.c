//FormAI DATASET v1.0 Category: Audio processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Declare global variables
double threshold = 0.5;
double gain = 2.0;
double noise_cutoff = 0.3;

// Function to check if audio input is above threshold
bool is_above_threshold(double sample) {
    if (fabs(sample) > threshold) {
        return true;
    }
    return false;
}

int main() {
    // Initialize variables
    double sample_rate = 44100.0;
    int num_samples = 441000;
    double* input_signal = (double*)malloc(sizeof(double) * num_samples);
    double* output_signal = (double*)malloc(sizeof(double) * num_samples);

    // Generate input signal with random noise
    for (int i = 0; i < num_samples; i++) {
        input_signal[i] = sin(2.0 * M_PI * 440.0 * ((double)i / sample_rate)) + (rand() / (double)RAND_MAX - 0.5) * noise_cutoff;
    }

    // Apply gain to input signal if above threshold
    for (int i = 0; i < num_samples; i++) {
        if (is_above_threshold(input_signal[i])) {
            output_signal[i] = input_signal[i] * gain;
        } else {
            output_signal[i] = input_signal[i];
        }
    }

    // Write output signal to file
    FILE* output_file = fopen("output.wav", "wb");
    fwrite(output_signal, sizeof(double), num_samples, output_file);
    fclose(output_file);

    // Free memory
    free(input_signal);
    free(output_signal);
    return 0;
}