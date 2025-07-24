//FormAI DATASET v1.0 Category: Audio processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512
#define PI 3.14159265358979323846

typedef struct {
    float frequency;
    float phase;
} Oscillator;

void process(float input[], float output[], int numSamples, Oscillator *oscillator) {

    float samples[BUFFER_SIZE];
    float frequency = oscillator->frequency;
    float phase = oscillator->phase;

    for (int i = 0; i < numSamples; i += BUFFER_SIZE) {
        int size = BUFFER_SIZE;
        if (i + BUFFER_SIZE > numSamples) {
            size = numSamples - i;
        }

        for (int j = 0; j < size; j++) {
            samples[j] = sin(2 * PI * (frequency / SAMPLE_RATE) * phase);
            phase++;
        }

        for (int j = 0; j < size; j++) {
            output[j + i] = input[j + i] * samples[j];
        }
    }

    oscillator->phase = phase;
}

int main() {
    float input[BUFFER_SIZE];
    float output[BUFFER_SIZE];
    Oscillator oscillator;
    oscillator.frequency = 440;
    oscillator.phase = 0;

    for (int i = 0; i < SAMPLE_RATE / BUFFER_SIZE * 5; i++) {
        // Fill input buffer with white noise
        for (int j = 0; j < BUFFER_SIZE; j++) {
            input[j] = ((float) rand() / (float) RAND_MAX) * 2 - 1;
        }

        process(input, output, BUFFER_SIZE, &oscillator);

        // Write output buffer to stdout
        fwrite(output, sizeof(float), BUFFER_SIZE, stdout);
    }

    return 0;
}