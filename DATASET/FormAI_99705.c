//FormAI DATASET v1.0 Category: Audio processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 44100

int main(void) {
    float frequency = 440.0;
    float amplitude = 0.5;
    float duration = 2.0;
    float sample_rate = 44100.0;

    int num_samples = (int) round(duration * sample_rate);
    float increment = frequency / sample_rate;
    float phase = 0.0;

    float* samples = (float*) malloc(num_samples * sizeof(float));

    for (int i = 0; i < num_samples; i++) {
        samples[i] = amplitude * sin(2.0 * M_PI * frequency * phase);
        phase += increment;
    }

    for (int i = 0; i < num_samples; i++) {
        samples[i] *= exp(-5.0 * i / num_samples);
    }

    for (int i = 0; i < num_samples; i++) {
        samples[i] *= (1 - exp(-5.0 * (num_samples - i - 1) / num_samples));
    }

    for (int i = 0; i < num_samples; i++) {
        samples[i] *= exp(-4000.0 * i / sample_rate);
    }

    for (int i = 0; i < num_samples; i++) {
        samples[i] *= exp(-5.0 * fabs(i - num_samples / 2) / num_samples);
    }

    FILE* file = fopen("output.raw", "wb");
    fwrite(samples, sizeof(float), num_samples, file);
    fclose(file);

    free(samples);

    return 0;
}