//FormAI DATASET v1.0 Category: Audio processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define BUFFER_SIZE 256
#define SAMPLE_RATE 44100
#define PI 3.1415926535

float lowpassFilter(float x, float y0, float a) {
    return (1 - a) * x + a * y0;
}

float highpassFilter(float x, float x0, float y0, float a) {
    return a * (y0 + x - x0);
}

void applyFilter(float *samples, int sampleCount, int filterType, float cutoffFrequency) {
    float RC = 1.0 / (cutoffFrequency * 2.0 * PI);
    float dt = 1.0 / SAMPLE_RATE;
    float alpha = RC / (RC + dt);

    float prevSample = samples[0];
    float prevFilteredSample = samples[0];

    for (int i = 1; i < sampleCount; i++) {
        float inputSample = samples[i];

        if (filterType == 1) {
            float outputSample = lowpassFilter(inputSample, prevFilteredSample, alpha);
            samples[i] = outputSample;
            prevFilteredSample = outputSample;
        } else if (filterType == 2) {
            float outputSample = highpassFilter(inputSample, prevSample, prevFilteredSample, alpha);
            samples[i] = outputSample;
            prevSample = inputSample;
            prevFilteredSample = outputSample;
        }
    }
}

void applyGain(float *samples, int sampleCount, float gain) {
    for (int i = 0; i < sampleCount; i++) {
        samples[i] *= gain;
    }
}

void applyPan(float *samples, int sampleCount, float pan) {
    float leftGain = cos(pan * PI / 2);
    float rightGain = sin(pan * PI / 2);

    for (int i = 0; i < sampleCount; i += 2) {
        float leftSample = samples[i];
        float rightSample = samples[i + 1];

        samples[i] = leftSample * leftGain;
        samples[i + 1] = rightSample * rightGain;
    }
}

int main() {
    float samples[BUFFER_SIZE];
    float cutoffFrequency = 500;
    float gain = 1.5;
    float pan = 0.5;

    // Generate some test samples
    for (int i = 0; i < BUFFER_SIZE; i++) {
        samples[i] = sin((float) i / SAMPLE_RATE * 2 * PI * 440);
    }

    // Apply a lowpass filter
    printf("Before filtering:\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", samples[i]);
    }
    printf("\n");

    applyFilter(samples, BUFFER_SIZE, 1, cutoffFrequency);

    printf("After filtering:\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", samples[i]);
    }
    printf("\n");

    // Apply a gain
    applyGain(samples, BUFFER_SIZE, gain);

    // Apply a pan
    applyPan(samples, BUFFER_SIZE, pan);

    printf("After gain and pan:\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", samples[i]);
    }
    printf("\n");

    return 0;
}