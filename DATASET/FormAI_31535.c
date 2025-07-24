//FormAI DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// Function to generate a sine wave
void generateSineWave(int frequency, int duration, int samplingRate, double amplitude, int* output) {
    int numSamples = duration * samplingRate;
    double sampleInterval = 1.0 / samplingRate;
    double angularFrequency = 2 * PI * frequency;

    for (int i = 0; i < numSamples; i++) {
        double time = i * sampleInterval;
        double sample = amplitude * sin(angularFrequency * time);
        output[i] = (int) round(sample);
    }
}

int main() {
    // Set signal parameters
    int frequency = 500; // Hz
    int duration = 5; // seconds
    int samplingRate = 44100; // Hz
    double amplitude = 0.9;

    // Generate a sine wave
    int* output = (int*) malloc(duration * samplingRate * sizeof(int));
    generateSineWave(frequency, duration, samplingRate, amplitude, output);

    // Print out the first 10 samples of the wave
    for (int i = 0; i < 10; i++) {
        printf("%d\n", output[i]);
    }

    free(output);

    return 0;
}