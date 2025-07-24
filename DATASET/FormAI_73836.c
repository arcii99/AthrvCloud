//FormAI DATASET v1.0 Category: Audio processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 2048

// Function to apply the low-pass filter
void lowPassFilter(float buffer[], float cutoff, float sampleRate, int bufferLength)
{
    float f = 2.0 * M_PI * cutoff / sampleRate;
    float A = exp(-f);
    float B = 1.0 - A;

    float x1 = 0.0;

    for (int n = 0; n < bufferLength; n++) {
        float x0 = buffer[n];

        buffer[n] = B * (x0 + x1) / 2.0 - A * x1;

        x1 = buffer[n];
    }
}

int main()
{
    float sampleRate = 44100.0;
    float cutoff = 8000.0;
    float buffer[BUFFER_SIZE];

    // Generate a sine wave
    for (int i = 0; i < BUFFER_SIZE; i++) {
        float t = i / sampleRate;
        buffer[i] = sin(2.0 * M_PI * 1000.0 * t);
    }

    // Apply the low-pass filter
    lowPassFilter(buffer, cutoff, sampleRate, BUFFER_SIZE);

    // Print the filtered waveform
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", buffer[i]);
    }

    return 0;
}