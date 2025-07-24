//FormAI DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to generate a sine wave
void generateSineWave(int numSamples, float frequency, float samplingRate, float* buffer) {
    float period = 1.0 / frequency;
    float angularFrequency = 2.0 * M_PI * frequency;
    for (int i = 0; i < numSamples; i++) {
        float time = (float) i / samplingRate;
        float sineWave = sin(angularFrequency * time);
        buffer[i] = sineWave;
    }
}

// function to apply a low-pass filter to an audio signal
void applyLowPassFilter(float* buffer, int numSamples, float cutoffFrequency, float samplingRate) {
    float RC = 1.0 / (cutoffFrequency * 2.0 * M_PI);
    float dt = 1.0 / samplingRate;
    float alpha = dt / (RC + dt);
    float y = buffer[0];
    for (int i = 1; i < numSamples; i++) {
        y = alpha * buffer[i] + (1.0 - alpha) * y;
        buffer[i] = y;
    }
}

int main() {
    int numSamples = 44100; // 1 second of audio
    float samplingRate = 44100.0;
    float frequency = 440.0;
    float cutoffFrequency = 500.0;

    // generate a sine wave
    float* buffer = (float*) malloc(numSamples * sizeof(float));
    generateSineWave(numSamples, frequency, samplingRate, buffer);

    // apply low-pass filter
    applyLowPassFilter(buffer, numSamples, cutoffFrequency, samplingRate);

    // print out the first 10 samples of the filtered signal
    for (int i = 0; i < 10; i++) {
        printf("%f\n", buffer[i]);
    }

    free(buffer);
    return 0;
}