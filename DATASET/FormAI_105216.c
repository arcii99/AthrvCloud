//FormAI DATASET v1.0 Category: Audio processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979

int main() {
    int frequency = 440;  // Hz
    double duration = 1;  // seconds
    int sample_count = SAMPLE_RATE * duration;

    // Generate sine wave
    double* samples = malloc(sizeof(double) * sample_count);
    for (int i = 0; i < sample_count; i++) {
        double t = (double)i / SAMPLE_RATE;
        samples[i] = sin(2 * PI * frequency * t);
    }

    // Apply gain
    for (int i = 0; i < sample_count; i++) {
        samples[i] *= 0.5;
    }

    // Write to file
    FILE* fp = fopen("output.raw", "wb");
    fwrite(samples, sizeof(double), sample_count, fp);
    fclose(fp);

    free(samples);
    return 0;
}