//FormAI DATASET v1.0 Category: Digital signal processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define SIGNAL_LENGTH 100
#define FILTER_TAP_LENGTH 5

float signal[SIGNAL_LENGTH];
float filter_taps[FILTER_TAP_LENGTH] = {0.1, 0.3, 0.6, 0.3, 0.1};

// Function to generate random signal values for testing
void generateSignal(float *signal, int length) {
    for(int i=0; i<length; i++) {
        signal[i] = (float)rand()/(float)(RAND_MAX/10.0); // Signal value between 0 and 10
    }
}

// Function to apply filtering on signal using filter taps
void filterSignal(float *signal, int signal_length, float *filter_taps, int tap_length) {
    float output[signal_length];

    for(int i=0; i<signal_length; i++) {
        float sum = 0;

        for(int j=0; j<tap_length; j++) {
            if(i-j >= 0) {
                sum += signal[i-j] * filter_taps[j];
            }
        }

        output[i] = sum;
    }

    // Replace input signal with filtered output
    for(int i=0; i<signal_length; i++) {
        signal[i] = output[i];
    }
}

int main() {
    // Generate random signal for testing
    generateSignal(signal, SIGNAL_LENGTH);

    // Print original signal
    printf("Original signal:\n");
    for(int i=0; i<SIGNAL_LENGTH; i++) {
        printf("%f\t", signal[i]);
    }
    printf("\n\n");

    // Apply filter on signal
    filterSignal(signal, SIGNAL_LENGTH, filter_taps, FILTER_TAP_LENGTH);

    // Print filtered signal
    printf("Filtered signal:\n");
    for(int i=0; i<SIGNAL_LENGTH; i++) {
        printf("%f\t", signal[i]);
    }
    printf("\n\n");

    return 0;
}