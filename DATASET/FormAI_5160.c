//FormAI DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.141592653589793

// function to generate a sine wave
void generateSineWave(double frequency, double duration, short *buffer) {
    int numSamples = duration * SAMPLE_RATE;
    double samplePeriod = 1.0 / SAMPLE_RATE;
    double amplitude = 32767;

    for (int i = 0; i < numSamples; i++) {
        double t = i * samplePeriod;
        buffer[i] = amplitude * sin(2 * PI * frequency * t);
    }
}

// function to apply a low-pass filter to the input signal
void lowPassFilter(double *signal, int numSamples, double cutoffFrequency) {
    double RC = 1.0 / (2 * PI * cutoffFrequency);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    double yPrev = 0;

    for (int i = 0; i < numSamples; i++) {
        double y = alpha * signal[i] + (1 - alpha) * yPrev;
        yPrev = y;
        signal[i] = y;
    }
}

int main() {
    // generate a 1 kHz sine wave
    double frequency = 1000;
    double duration = 1;
    short buffer[SAMPLE_RATE];
    generateSineWave(frequency, duration, buffer);

    // apply a low-pass filter with a cutoff frequency of 500 Hz
    double cutoffFrequency = 500;
    double signal[SAMPLE_RATE];
    for (int i = 0; i < SAMPLE_RATE; i++) {
        signal[i] = buffer[i];
    }
    lowPassFilter(signal, SAMPLE_RATE, cutoffFrequency);

    // write the filtered signal to a file
    FILE *file = fopen("output.raw", "wb");
    if (file != NULL) {
        fwrite(signal, sizeof(double), SAMPLE_RATE, file);
        fclose(file);
    }

    return 0;
}