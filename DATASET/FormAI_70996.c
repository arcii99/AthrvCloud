//FormAI DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the audio processing function
double audioProcessing(double sample) {
    double processedSample = sin(sample * M_PI); // Apply a sine wave filter
    processedSample *= 0.5; // Lower the volume by 50%
    return processedSample;
}

int main() {
    // Generate an array of audio samples
    double audioSamples[] = { 0.2, 0.5, 0.9, 0.7, 0.4, 0.1, -0.2, -0.6, -0.8, -0.4 };

    // Process each audio sample
    for (int i = 0; i < sizeof(audioSamples)/sizeof(double); i++) {
        double processedSample = audioProcessing(audioSamples[i]);
        printf("Original sample: %f Processed sample: %f\n", audioSamples[i], processedSample);
    }

    return 0;
}