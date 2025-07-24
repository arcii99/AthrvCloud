//FormAI DATASET v1.0 Category: Audio processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLERATE 44100
#define FREQUENCY 440

int main(void) {

    float seconds = 5.0f;
    int sampleCount = SAMPLERATE * seconds;

    float *samples = malloc(sampleCount * sizeof(float));

    for (int i = 0; i < sampleCount; ++i) {
        float t = (float) i / SAMPLERATE;
        samples[i] = sinf(2.0f * M_PI * FREQUENCY * t);
    }

    FILE *file = fopen("output.raw", "wb");
    fwrite(samples, sizeof(float), sampleCount, file);
    fclose(file);

    free(samples);

    return 0;
}