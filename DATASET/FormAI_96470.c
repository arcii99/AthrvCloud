//FormAI DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 2048

float envelope[BUFFER_SIZE];
float sine_wave[BUFFER_SIZE];

int main() {
    // Generate envelope
    for (int i = 0; i < BUFFER_SIZE; i++) {
        envelope[i] = cos(i * (M_PI / BUFFER_SIZE));
    }

    // Generate sine wave
    float frequency = 440; // Hz
    float increment = frequency / SAMPLE_RATE;
    float phase = 0;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        sine_wave[i] = sin(2 * M_PI * phase);
        phase += increment;
        if (phase > 1) phase -= 1;
    }

    // Apply envelope to sine wave
    for (int i = 0; i < BUFFER_SIZE; i++) {
        sine_wave[i] *= envelope[i];
    }

    // Output sine wave to audio device
    // Code for outputting to audio device.
    // Not included for simplicity of example.

    return 0;
}