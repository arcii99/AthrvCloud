//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void cosineWave(int *output, int frequency, int samplesPerSecond, int duration) {
    double amplitude = 10000;
    double phase = 0;
    double omega = 2 * PI * frequency;
    int i;
    for (i = 0; i < samplesPerSecond * duration; i++) {
        double t = (double)i / samplesPerSecond;
        output[i] = (int)(amplitude * cos(omega * t + phase));
    }
}

void plotSignal(int *signal, int samplesPerSecond, int duration) {
    int i, j;
    int plotHeight = 50;
    int maxAmplitude = 10000;
    for (i = 0; i < duration * samplesPerSecond; i++) {
        double amplitude = (double)signal[i] / maxAmplitude * (plotHeight - 1) / 2;
        int numStars = (int)(amplitude + (plotHeight - 1)/2);
        for (j = 0; j < numStars; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int frequency = 440; // A4 note
    int samplesPerSecond = 44100; // CD quality
    int duration = 5; // seconds
    int *output = (int*)malloc(sizeof(int) * samplesPerSecond * duration);
    cosineWave(output, frequency, samplesPerSecond, duration);
    plotSignal(output, samplesPerSecond, duration);
    free(output);

    return 0;
}