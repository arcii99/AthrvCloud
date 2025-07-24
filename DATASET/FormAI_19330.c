//FormAI DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_COUNT 100
#define PI 3.14159265358979323846

int main() {

    double signal[SAMPLE_COUNT]; // Declare array to store signal
    double result[SAMPLE_COUNT]; // Declare array to store processed signal

    // Generate a sample signal
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        signal[i] = sin(2 * PI * i / SAMPLE_COUNT);
    }

    // Apply audio processing algorithm
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        // Square each sample
        result[i] = signal[i] * signal[i];
    }

    // Print out the result for verification
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        printf("Sample %d: %f\n", i, result[i]);
    }

    return 0;
}