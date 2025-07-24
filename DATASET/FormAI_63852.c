//FormAI DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

int main() {
    float frequency = 440.0;
    float amplitude = 0.5;
    float phase = 0.0;
    float duration = 2.0;
    float bufferSize = (float)BUFFER_SIZE;
    float samples[SAMPLE_RATE];

    float samplePeriod = 1.0 / (float)SAMPLE_RATE;
    float radiansPerSample = frequency * 2.0 * PI / (float)SAMPLE_RATE;

    for (int i = 0; i < SAMPLE_RATE; i++) {
        samples[i] = amplitude * sin(phase);
        phase += radiansPerSample;
    }

    FILE *file;
    file = fopen("sine-wave.pcm", "wb");
    fwrite(samples, sizeof(float), SAMPLE_RATE, file);
    fclose(file);

    printf("Sine wave with frequency %f generated successfully.\n", frequency);

    return 0;
}