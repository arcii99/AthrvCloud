//FormAI DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Function to generate a sine wave
float* generateSineWave(int frequency, int sampleRate, float duration) {
    int numSamples = round(duration * sampleRate);
    float* buffer = malloc(numSamples * sizeof(float));

    float phaseIncrement = 2 * PI * frequency / sampleRate;
    float phase = 0;

    for (int i = 0; i < numSamples; i++) {
        buffer[i] = sin(phase);
        phase += phaseIncrement;
    }

    return buffer;
}

// Function to normalize the samples to fit within [-1, 1]
void normalizeSamples(float* buffer, int numSamples) {
    float maxValue = 0;

    for (int i = 0; i < numSamples; i++) {
        if (fabs(buffer[i]) > maxValue) {
            maxValue = fabs(buffer[i]);
        }
    }

    float scaleFactor = 1 / maxValue;

    for (int i = 0; i < numSamples; i++) {
        buffer[i] *= scaleFactor;
    }
}

// Function to apply a low-pass filter to the samples
void lowPassFilter(float* buffer, int numSamples, int cutoffFrequency, int sampleRate) {
    float rc = 1.0 / (2 * PI * cutoffFrequency);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (rc + dt);
    float previousOutput = 0;

    for (int i = 0; i < numSamples; i++) {
        buffer[i] = alpha * buffer[i] + (1 - alpha) * previousOutput;
        previousOutput = buffer[i];
    }
}

// Main function for testing the audio processing functions
int main() {
    // Generate a sine wave with frequency of 440 Hz and duration of 1 second
    int frequency = 440;
    int sampleRate = 44100;
    float duration = 1;
    float* buffer = generateSineWave(frequency, sampleRate, duration);

    // Normalize the samples
    normalizeSamples(buffer, round(duration * sampleRate));

    // Apply a low-pass filter with cutoff frequency of 1000 Hz
    int cutoffFrequency = 1000;
    lowPassFilter(buffer, round(duration * sampleRate), cutoffFrequency, sampleRate);

    // Print the filtered samples to the console
    for (int i = 0; i < round(duration * sampleRate); i++) {
        printf("%f\n", buffer[i]);
    }

    // Free the memory allocated for the buffer
    free(buffer);

    return 0;
}