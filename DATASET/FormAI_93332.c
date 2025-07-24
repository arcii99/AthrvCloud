//FormAI DATASET v1.0 Category: Audio processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 512

void lowPassFilter(float samples[], int cutoffFreq, float sampleRate, int numSamples) {
    float s1 = (2 * M_PI * cutoffFreq) / sampleRate; 
    float s2 = 1 - exp(-s1);

    float y = 0;
    float prevY = 0;

    for (int i = 0; i < numSamples; i++) {
        y = prevY + s2 * (samples[i] - prevY);
        samples[i] = y;
        prevY = y;
    }
}

void highPassFilter(float samples[], int cutoffFreq, float sampleRate, int numSamples) {
    float s1 = (2 * M_PI * cutoffFreq) / sampleRate;
    float s2 = 1 - exp(-s1);

    float y = 0;
    float prevY = 0;

    for (int i = 0; i < numSamples; i++) {
        y = s2 * (prevY + samples[i] - samples[i-1]);
        samples[i] = y;
        prevY = y;
    }
}

void pitchShift(float samples[], float pitchRatio, int numSamples) {
    if (pitchRatio == 1.0) {
        return;
    }

    float* samplesCopy = malloc(numSamples * sizeof(float));
    for (int i = 0; i < numSamples; i++) {
        samplesCopy[i] = samples[i];
    }

    int newIndex = 0;
    for (int i = 0; i < numSamples; i++) {
        newIndex = (int) (i / pitchRatio);

        if (newIndex >= 0 && newIndex < numSamples) {
            samples[newIndex] = samplesCopy[i];
        }
    }

    free(samplesCopy);
}

int main() {
    float sampleRate = 44100.0;
    int numSamples = BUFFER_SIZE;
    float samples[BUFFER_SIZE] = { 0 };

    for (int i = 0; i < BUFFER_SIZE; i++) {
        float t = (float) i / sampleRate;

        samples[i] = sin(2 * M_PI * 440 * t) +
                     sin(2 * M_PI * 880 * t);
    }

    lowPassFilter(samples, 1000, sampleRate, numSamples);
    highPassFilter(samples, 1000, sampleRate, numSamples);
    pitchShift(samples, 1.5, numSamples);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", samples[i]);
    }

    return 0;
}