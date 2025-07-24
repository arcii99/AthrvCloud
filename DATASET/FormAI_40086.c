//FormAI DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SECONDS 5

typedef struct {
    float sample;
    float phase;
    float frequency;
    float amplitude;
} Oscillator;

float calculateSineWave(Oscillator *oscillator) {
    oscillator->sample = sin(2 * M_PI * oscillator->phase);
    oscillator->phase += oscillator->frequency / SAMPLE_RATE;
    return oscillator->sample * oscillator->amplitude;
}

float calculateTriangleWave(Oscillator *oscillator) {
    oscillator->sample = fabsf(fmodf(oscillator->phase, 1.0f) - 0.5f) * 4 - 1;
    oscillator->phase += oscillator->frequency / SAMPLE_RATE;
    return oscillator->sample * oscillator->amplitude;
}

float calculateSquareWave(Oscillator *oscillator) {
    oscillator->sample = fmodf(oscillator->phase, 1.0f) < 0.5f ? -1.0f : 1.0f;
    oscillator->phase += oscillator->frequency / SAMPLE_RATE;
    return oscillator->sample * oscillator->amplitude;
}

float calculateSawtoothWave(Oscillator *oscillator) {
    oscillator->sample = fmodf(oscillator->phase, 1.0f) * 2 - 1;
    oscillator->phase += oscillator->frequency / SAMPLE_RATE;
    return oscillator->sample * oscillator->amplitude;
}

int main() {
    Oscillator oscillator = {0};
    oscillator.amplitude = 0.5f;
    oscillator.frequency = 440.0f;
    float sample = 0;
    FILE *file = fopen("happy_audio.raw", "wb");
    for (int i = 0; i < SAMPLE_RATE * NUM_SECONDS; i++) {
        sample = calculateSquareWave(&oscillator) + calculateSineWave(&oscillator) + calculateTriangleWave(&oscillator) + calculateSawtoothWave(&oscillator);
        fwrite(&sample, sizeof(float), 1, file);
    }
    fclose(file);
    return 0;
}