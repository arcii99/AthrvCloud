//FormAI DATASET v1.0 Category: Audio processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100  // Sample rate in Hz
#define DURATION 5          // Duration of the audio in seconds

double generateWaveform(double time, double frequency) {
    return sin(2 * M_PI * time * frequency);
}

int main() {
    uint32_t numSamples = SAMPLE_RATE * DURATION;
    int16_t *audioData = (int16_t*) malloc(numSamples * sizeof(int16_t));

    double amplitude = INT16_MAX / 2;
    double frequency = 440; // A4 note
    double timeStep = 1.0 / SAMPLE_RATE;

    for (uint32_t i = 0; i < numSamples; i++) {
        double waveform = generateWaveform(i * timeStep, frequency);
        audioData[i] = amplitude * waveform;
    }

    FILE *outputFile = fopen("audioOutput.pcm", "wb");
    fwrite(audioData, sizeof(int16_t), numSamples, outputFile);
    fclose(outputFile);

    free(audioData);
    return 0;
}