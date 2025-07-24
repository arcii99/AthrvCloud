//FormAI DATASET v1.0 Category: Audio processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
float* normalize(float* buffer, int bufferSize);
void echo(float* buffer, int bufferSize, float delayInSeconds, float decay);
float calculateRMS(float* buffer, int bufferSize);

/* Main program */
int main() {
    // Load audio file into buffer
    float audioBuffer[1024];
    /* Properly load audio file into buffer */

    // Normalize audio
    normalize(audioBuffer, 1024);

    // Add echo effect
    echo(audioBuffer, 1024, 0.2, 0.6);

    // Calculate RMS of resulting audio
    float rms = calculateRMS(audioBuffer, 1024);
    printf("RMS: %f", rms);

    return 0;
}

/* Normalizes an audio buffer */
float* normalize(float* buffer, int bufferSize) {
    float maxAmplitude = 0;
    for (int i = 0; i < bufferSize; i++) {
        if (fabsf(buffer[i]) > maxAmplitude) {
            maxAmplitude = fabsf(buffer[i]);
        }
    }

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] /= maxAmplitude;
    }

    return buffer;
}

/* Adds echo effect to an audio buffer */
void echo(float* buffer, int bufferSize, float delayInSeconds, float decay) {
    int delayInSamples = (int)(delayInSeconds * 44100);

    for (int i = delayInSamples; i < bufferSize; i++) {
        buffer[i] += decay * buffer[i - delayInSamples];
    }
}

/* Calculates the root-mean-square of an audio buffer */
float calculateRMS(float* buffer, int bufferSize) {
    float sumOfSquares = 0;
    for (int i = 0; i < bufferSize; i++) {
        sumOfSquares += buffer[i] * buffer[i];
    }

    float meanSquare = sumOfSquares / bufferSize;
    float rms = sqrtf(meanSquare);

    return rms;
}