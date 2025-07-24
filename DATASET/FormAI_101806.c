//FormAI DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024

int main()
{
    float buffer[BUFFER_SIZE];
    float sampleRate = 44100;
    float frequency = 1000;
    float amplitude = 0.5;
    float phaseShift = 0;

    // Generate a sine wave
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = amplitude * sin(2 * M_PI * frequency * (i / sampleRate) + phaseShift);
    }

    // Apply low-pass filter to the sine wave
    float cutoffFrequency = 500;
    float resonance = 0.7;
    float qValue = 1 / (2 * resonance);
    float omega = 2 * M_PI * cutoffFrequency / sampleRate;
    float alpha = sin(omega) / (2 * qValue);
    float b0 = (1 - cos(omega)) / 2;
    float b1 = 1 - cos(omega);
    float b2 = (1 - cos(omega)) / 2;
    float a0 = 1 + alpha;
    float a1 = -2 * cos(omega);
    float a2 = 1 - alpha;

    float x1 = 0;
    float x2 = 0;
    float y1 = 0;
    float y2 = 0;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        float input = buffer[i];
        float output = (b0 / a0) * input + (b1 / a0) * x1 + (b2 / a0) * x2 - (a1 / a0) * y1 - (a2 / a0) * y2;
        x2 = x1;
        x1 = input;
        y2 = y1;
        y1 = output;
        buffer[i] = output;
    }

    // Apply gain to the filtered signal
    float gain = 2;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] *= gain;
    }

    // Write the processed signal to a file
    FILE *fp;
    fp = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(float), BUFFER_SIZE, fp);
    fclose(fp);

    return 0;
}