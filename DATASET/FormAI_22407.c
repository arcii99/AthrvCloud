//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a sinusoidal signal
void generateSignal(float signal[], int signalLength, float frequency, float amplitude) {
    for(int i = 0; i < signalLength; i++) {
        signal[i] = amplitude * sin(2 * M_PI * frequency * i / signalLength);
    }
}

// Function to filter a signal using moving average filter
void movingAverageFilter(float inputSignal[], float outputSignal[], int signalLength, int filterLength) {
    float filterSum = 0;

    for(int i = 0; i < filterLength; i++) {
        filterSum += inputSignal[i];
    }

    for(int i = filterLength; i < signalLength; i++) {
        outputSignal[i] = filterSum / filterLength;
        filterSum = filterSum - inputSignal[i - filterLength] + inputSignal[i];
    }
}

int main() {
    int signalLength = 100;
    int filterLength = 10;
    float frequency = 0.2;
    float amplitude = 10;

    float inputSignal[signalLength];
    generateSignal(inputSignal, signalLength, frequency, amplitude);
    printf("Input signal:\n");
    for(int i = 0; i < signalLength; i++) {
        printf("%.2f ", inputSignal[i]);
    }
    printf("\n");

    float outputSignal[signalLength];
    movingAverageFilter(inputSignal, outputSignal, signalLength, filterLength);
    printf("Output signal after moving average filtering:\n");
    for(int i = 0; i < signalLength; i++) {
        printf("%.2f ", outputSignal[i]);
    }
    printf("\n");

    return 0;
}