//FormAI DATASET v1.0 Category: Audio processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the number of samples and sample rate
#define NUM_SAMPLES 512
#define SAMPLE_RATE 44100

// Function to generate a sine wave signal
void generateSineWave(int frequency, float amplitude, float *signal) {
    // Calculate the angular frequency
    float w = 2 * 3.14159265359 * frequency / SAMPLE_RATE;
    int i;

    for(i = 0; i < NUM_SAMPLES; i++) {
        signal[i] = amplitude * sin(w * i);
    }
}

// Function to add two signals together
void addSignals(float *signal1, float *signal2, float *result) {
    int i;

    for(i = 0; i < NUM_SAMPLES; i++) {
        result[i] = signal1[i] + signal2[i];
    }
}

// Function to apply a low-pass filter
void lowPassFilter(float *signal, float *result, float cutoff) {
    // Calculate the filter coefficients
    float a0 = 1.0;
    float a1 = -2.0 * cutoff;
    float a2 = cutoff * cutoff;
    float b0 = a2;
    float b1 = 2.0 * a2;
    float b2 = a2;

    // Set initial values of y and x
    float y1 = 0.0;
    float y2 = 0.0;
    float x1 = 0.0;
    float x2 = 0.0;

    int i;
    for(i = 0; i < NUM_SAMPLES; i++) {
        // Calculate the new output value
        result[i] = (b0 * signal[i] + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2) / a0;

        // Shift the input and output values
        x2 = x1;
        x1 = signal[i];
        y2 = y1;
        y1 = result[i];
    }
}

int main() {
    // Generate two sine wave signals
    float signal1[NUM_SAMPLES];
    float signal2[NUM_SAMPLES];
    generateSineWave(440, 0.5, signal1);
    generateSineWave(880, 0.25, signal2);

    // Add the two signals together
    float combinedSignal[NUM_SAMPLES];
    addSignals(signal1, signal2, combinedSignal);

    // Apply a low-pass filter to the combined signal
    float filteredSignal[NUM_SAMPLES];
    lowPassFilter(combinedSignal, filteredSignal, 0.1);

    // Print out the filtered signal values
    int i;
    for(i = 0; i < NUM_SAMPLES; i++) {
        printf("Filtered signal value %d: %f\n", i, filteredSignal[i]);
    }

    return 0;
}