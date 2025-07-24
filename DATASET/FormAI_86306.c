//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void lowPassFilter(float input[], float output[], float cutoff, float sampleRate, int bufferSize) {
    float RC = 1.0 / (cutoff * 2.0 * M_PI);
    float dt = 1.0 / sampleRate;
    float alpha = dt / (RC + dt);
    output[0] = input[0];
    for (int i = 1; i < bufferSize; i++) {
        output[i] = alpha * input[i] + (1 - alpha) * output[i-1];
    }
}

void highPassFilter(float input[], float output[], float cutoff, float sampleRate, int bufferSize) {
    float RC = 1.0 / (cutoff * 2.0 * M_PI);
    float dt = 1.0 / sampleRate;
    float alpha = RC / (RC + dt);
    float prevIn = input[0];
    float prevOut = 0.0;
    for (int i = 1; i < bufferSize; i++) {
        output[i] = alpha * (prevOut + input[i] - prevIn);
        prevIn = input[i];
        prevOut = output[i];
    }
}

int main(int argc, char** argv) {
    float input[256];
    float output[256];
    float cutoff = 2000;
    float sampleRate = 44100;
    int bufferSize = 256;
    // generate some random input
    srand(0);
    for (int i = 0; i < bufferSize; i++) {
        input[i] = (float)rand() / RAND_MAX;
    }
    // apply low-pass filter
    lowPassFilter(input, output, cutoff, sampleRate, bufferSize);
    printf("Low-pass filtered output:\n");
    for (int i = 0; i < bufferSize; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");
    // apply high-pass filter
    highPassFilter(input, output, cutoff, sampleRate, bufferSize);
    printf("High-pass filtered output:\n");
    for (int i = 0; i < bufferSize; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");
    return 0;
}