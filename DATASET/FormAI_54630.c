//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 1000
#define FILTER_COUNT 3

float inputSignal[NUM_SAMPLES];
float filteredSignal[NUM_SAMPLES];
float filterCoefficients[FILTER_COUNT] = {0.5, 0.3, 0.2};

// Function to generate a noisy input signal
void generateInputSignal() {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        inputSignal[i] = sin(2 * M_PI * i / 100) + (rand() % 100) / 1000.0;
    }
}

// Function to apply the FIR filter to the input signal
void applyFilter() {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        filteredSignal[i] = 0;
        for (int j = 0; j < FILTER_COUNT; j++) {
            if (i - j >= 0) {
                filteredSignal[i] += inputSignal[i - j] * filterCoefficients[j];
            }
        }
    }
}

int main() {
    generateInputSignal();
    applyFilter();

    // Print out the first 10 samples of the input signal and filtered signal
    printf("Input Signal: ");
    for (int i = 0; i < 10; i++) {
        printf("%.3f ", inputSignal[i]);
    }
    
    printf("\nFiltered Signal: ");
    for (int i = 0; i < 10; i++) {
        printf("%.3f ", filteredSignal[i]);
    }

    return 0;
}