//FormAI DATASET v1.0 Category: Audio processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define TWO_PI 6.283185307179586

float osc(float freq, float time) {
    return sin(freq * TWO_PI * time);
}

float envelope(float time) {
    if (time < 0.1) {
        return time / 0.1;
    } else if (time < 0.9) {
        return 1.0;
    } else {
        return (1.0 - time) / 0.1;
    }
}

int main() {
    int duration = 5; // in seconds
    int numberOfSamples = duration * SAMPLE_RATE;
    float *samples = (float *) malloc(sizeof(float) * numberOfSamples);

    float freq = 440.0; // A4
    float timeStep = 1.0 / SAMPLE_RATE;
    float time = 0.0;
    for (int i = 0; i < numberOfSamples; i++) {
        float amplitude = envelope(time) * osc(freq, time);
        samples[i] = amplitude;
        time += timeStep;
    }

    FILE* file = fopen("output.raw", "wb");
    for (int i = 0; i < numberOfSamples; i++) {
        fwrite(&samples[i], sizeof(float), 1, file);
    }
    fclose(file);

    free(samples);
    return 0;
}