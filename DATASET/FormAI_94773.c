//FormAI DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 32767

int main() {
    int frequency = 440;
    int duration = 1;
    int numberOfSamples = duration * SAMPLE_RATE;
    int i, rate;
    double theta;
    short int sample;

    FILE *file = fopen("output.raw", "wb");

    for(i = 0; i < numberOfSamples; i++){
        theta = 2 * M_PI * frequency * ((double)i / (double)SAMPLE_RATE);
        sample = (short int)(AMPLITUDE * sin(theta));
        fwrite(&sample, sizeof(sample), 1, file);
    }

    fclose(file);

    return 0;
}