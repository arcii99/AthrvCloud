//FormAI DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define AMPLITUDE 0.8
#define FREQUENCY 440.0

int main() {
    // Define variables
    double time = 0.0;
    double step = 1.0 / SAMPLE_RATE;
    double sine_wave;
    double sine_wave_processed;

    // Generate sine wave
    while (time < 1.0) {
        sine_wave = AMPLITUDE * sin(2 * M_PI * FREQUENCY * time);
        time += step;

        // Add Audio Processing here
        sine_wave_processed = sin(2 * M_PI * FREQUENCY * time) * exp(-5.0 * time);

        // Output sine wave to speaker
        printf("%f\n", sine_wave_processed);
    }

    return 0;
}