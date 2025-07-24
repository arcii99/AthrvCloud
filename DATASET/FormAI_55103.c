//FormAI DATASET v1.0 Category: Audio processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SRATE 44100
#define PI 3.14159265358979323846

int main() {
    float frequency = 440.0;
    float phase = 0.0;
    float amplitude = 0.5;
    float duration = 2.0;
    float *buffer;
    int bufferSize = duration * SRATE;

    buffer = (float*)malloc(bufferSize * sizeof(float));

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = amplitude * sin(2.0 * PI * frequency * i / SRATE + phase);
    }

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] *= exp(-5.0 * i / SRATE); // Apply exponential decay to simulate a plucked string
        buffer[i] *= 0.5 + 0.5 * cos(2.0 * PI * i / SRATE); // Apply a cosine window to reduce clicks and pops
    }

    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = pow(buffer[i], 3); // Apply a non-linear distortion to emulate a guitar amplifier
    }

    // Audio output code goes here...

    free(buffer);
    return 0;
}