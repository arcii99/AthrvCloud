//FormAI DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

typedef struct {
    float frequency;
    float phase;
} Oscillator;

Oscillator newOscillator(float frequency) {
    Oscillator oscillator;
    oscillator.frequency = frequency;
    oscillator.phase = 0;
    return oscillator;
}

float getNextSample(Oscillator *oscillator) {
    float amplitude = 0.5;
    float frequency = oscillator->frequency;
    float phase = oscillator->phase;

    float sample = amplitude * sin(2 * M_PI * frequency * phase);

    oscillator->phase += 1.0 / SAMPLE_RATE;
    oscillator->phase = fmod(oscillator->phase, 1.0);

    return sample;
}

int main() {
    float buffer[BUFFER_SIZE];
    Oscillator oscillator = newOscillator(440);

    int samplesProcessed = 0;
    while (samplesProcessed < SAMPLE_RATE) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = getNextSample(&oscillator);
        }

        // Some audio processing could happen here...
        // For this example, we'll just write to stdout
        fwrite(buffer, sizeof(float), BUFFER_SIZE, stdout);

        samplesProcessed += BUFFER_SIZE;
    }

    return 0;
}