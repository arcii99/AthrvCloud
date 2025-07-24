//FormAI DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to create a triangular wave
void create_triangular_wave(int freq, double duration, double sampling_rate) {
    int num_samples = (int)(duration * sampling_rate);
    double increment = ((double)freq * 2 * M_PI) / sampling_rate;

    double amplitude = 1.0; // Amplitude of the wave
    double phase = 0.0; // Initial phase of the wave

    double *samples = malloc(num_samples * sizeof(double));

    // Create the waveform
    for (int i = 0; i < num_samples; i++) {
        double value;
        if (i < num_samples / 2) {
            value = ((2 * amplitude) / (num_samples / 2)) * i;
        } else {
            value = (amplitude - ((2 * amplitude) / (num_samples / 2)) * (i - (num_samples / 2)));
        }
        samples[i] = value * sin(phase);
        phase += increment;
    }

    // Write the audio data to a file
    FILE *f = fopen("triangular_wave.raw", "wb");
    fwrite(samples, sizeof(double), num_samples, f);
    fclose(f);

    free(samples);
}

int main(int argc, char **argv) {
    int freq = 5000; // Frequency of the waveform in Hz
    double duration = 1.0; // Duration of the waveform in seconds
    double sampling_rate = 44100.0; // Sampling rate of the audio in Hz

    create_triangular_wave(freq, duration, sampling_rate);

    return 0;
}