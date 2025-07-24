//FormAI DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLERATE 44100
#define DURATION 5
#define AMPLITUDE_FACTOR 32767
#define FREQUENCY 440

double getRadiansFromDegrees(double degrees) {
    return degrees * M_PI / 180;
}

short getSample(double time) {
    double radians = getRadiansFromDegrees(FREQUENCY * time);
    return (short) (AMPLITUDE_FACTOR * sin(radians));
}

int main(void) {
    FILE *audioFile = fopen("audio.raw", "wb");
    if (audioFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    unsigned long numSamples = SAMPLERATE * DURATION;
    short sample;
    double time;

    for (unsigned long i = 0; i < numSamples; i++) {
        time = (double) i / (double) SAMPLERATE;
        sample = getSample(time);
        fwrite(&sample, sizeof(sample), 1, audioFile);
    }

    fclose(audioFile);
    return 0;
}