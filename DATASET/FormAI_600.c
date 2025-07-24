//FormAI DATASET v1.0 Category: Audio processing ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 256

float lowpassFilter(float input, float prevOutput, float alpha) {
    return alpha * input + (1 - alpha) * prevOutput;
}

int main() {
    float input[BUFFER_SIZE], output[BUFFER_SIZE], prevOutput = 0.0f;
    float cutoffFrequency = 4000.0f / SAMPLE_RATE;
    float alpha = 2 * M_PI * cutoffFrequency / (2 * M_PI * cutoffFrequency + 1);

    // Generate a test signal
    for(int i = 0; i < BUFFER_SIZE; i++) {
        float time = (float)i / SAMPLE_RATE;
        input[i] = sinf(2 * M_PI * 440.0f * time);
    }

    // Low-pass filter the test signal
    for(int i = 0; i < BUFFER_SIZE; i++) {
        output[i] = lowpassFilter(input[i], prevOutput, alpha);
        prevOutput = output[i];
    }

    // Output the filtered signal to a file
    FILE *outputFile = fopen("output.pcm", "wb");
    for(int i = 0; i < BUFFER_SIZE; i++) {
        short sample = (short)(output[i] * 32767.0f);
        fwrite(&sample, sizeof(short), 1, outputFile);
    }
    fclose(outputFile);

    return 0;
}