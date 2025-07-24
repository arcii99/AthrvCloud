//FormAI DATASET v1.0 Category: Audio processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 32767
#define FREQUENCY 440.0
#define PI 3.14159265359

int main() {
    int duration = 2;
    int num_samples = duration * SAMPLE_RATE;
    short *samples = malloc(num_samples * sizeof(short));

    for(int i = 0; i < num_samples; i++) {
        double t = (double)i / SAMPLE_RATE;
        samples[i] = AMPLITUDE * sin(2 * PI * FREQUENCY * t);
    }

    FILE *file = fopen("sine_wave.pcm", "wb");
    fwrite(samples, sizeof(short), num_samples, file);
    fclose(file);

    free(samples);

    return 0;
}