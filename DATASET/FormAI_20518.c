//FormAI DATASET v1.0 Category: Digital signal processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define FREQUENCY 440
#define AMPLITUDE 0.5

int main(void) {
    int num_samples = DURATION * SAMPLE_RATE;
    double *buffer = (double *)malloc(num_samples * sizeof(double));

    for(int i = 0; i < num_samples; i++) {
        double t = (double)i / SAMPLE_RATE;
        buffer[i] = AMPLITUDE * sin(2 * M_PI * FREQUENCY * t);
    }

    FILE *file = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(double), num_samples, file);
    fclose(file);

    free(buffer);
    return 0;
}