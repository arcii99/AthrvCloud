//FormAI DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Define constants
#define SAMPLE_RATE 44100
#define FREQUENCY 440
#define AMPLITUDE 0.5

int main() {
    // Calculate the length of the waveform
    double waveform_length = 1.0 / FREQUENCY;

    // Calculate the number of samples per cycle
    int samples_per_cycle = (int) round(waveform_length * SAMPLE_RATE);

    // Allocate memory for the waveform
    double waveform[samples_per_cycle];

    // Fill in the waveform with a sine wave
    for (int i = 0; i < samples_per_cycle; i++) {
        waveform[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * i / SAMPLE_RATE);
    }

    // Print out the waveform
    for (int i = 0; i < samples_per_cycle; i++) {
        printf("%.3f\n", waveform[i]);
    }

    return 0;
}