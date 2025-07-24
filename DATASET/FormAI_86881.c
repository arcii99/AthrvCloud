//FormAI DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

// Function to generate a sine wave
void generateSineWave(float freq, float* buffer, int numSamples) {
    for(int i = 0; i < numSamples; i++) {
        buffer[i] = sin(2.0 * M_PI * freq * i / SAMPLE_RATE);
    }
}

// Function to add two audio buffers with equal length
void addBuffers(float* buffer1, float* buffer2, float* result, int numSamples) {
    for(int i = 0; i < numSamples; i++) {
        result[i] = buffer1[i] + buffer2[i];
    }
}

// Function to apply delay effect to audio buffer
void applyDelayEffect(float* buffer, float* result, int numSamples, int delayTimeInMilliseconds, float feedback, float mix) {
    int delayTimeInSamples = delayTimeInMilliseconds * SAMPLE_RATE / 1000;
    float* delayBuffer = (float*) calloc(numSamples + delayTimeInSamples, sizeof(float));

    // Copy input buffer to result buffer
    memcpy(result, buffer, numSamples * sizeof(float));

    // Apply delay effect
    for(int i = delayTimeInSamples; i < numSamples + delayTimeInSamples; i++) {
        delayBuffer[i] = buffer[i - delayTimeInSamples] + feedback * delayBuffer[i - delayTimeInSamples];
        result[i - delayTimeInSamples] = result[i - delayTimeInSamples] * (1.0 - mix) + mix * delayBuffer[i];
    }

    // Free memory of delay buffer
    free(delayBuffer);
}

int main() {
    float freq1 = 440.0; // Frequency of first sine wave
    float freq2 = 880.0; // Frequency of second sine wave
    float buffer1[BUFFER_SIZE]; // First audio buffer
    float buffer2[BUFFER_SIZE]; // Second audio buffer
    float result[BUFFER_SIZE]; // Result audio buffer
    float feedback = 0.5; // Feedback for delay effect
    float mix = 0.5; // Mix for delay effect
    int delayTimeInMilliseconds = 500; // Delay time in milliseconds

    // Generate sine waves
    generateSineWave(freq1, buffer1, BUFFER_SIZE);
    generateSineWave(freq2, buffer2, BUFFER_SIZE);

    // Add sine waves
    addBuffers(buffer1, buffer2, result, BUFFER_SIZE);

    // Apply delay effect
    applyDelayEffect(result, result, BUFFER_SIZE, delayTimeInMilliseconds, feedback, mix);

    // Print result buffer values
    for(int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", result[i]);
    }

    return 0;
}