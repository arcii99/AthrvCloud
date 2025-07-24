//FormAI DATASET v1.0 Category: Digital signal processing ; Style: excited
/*
Welcome to the world of Digital Signal Processing!
Today, we're going to make some magic happen with some basic signal processing techniques.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int num_samples = 100; // Number of samples to generate
    double sample_rate = 1000.0; // Sampling rate in Hz
    double frequency = 50.0; // Signal frequency in Hz
    double amplitude = 1.0; // Signal amplitude
    double phase = 0.0; // Signal phase
    double signal[num_samples]; // Array to hold signal samples
    double window[num_samples]; // Array to hold window samples
    double filtered_signal[num_samples]; // Array to hold filtered signal samples
    double filter_coefficients[] = {0.2, 0.2, 0.2, 0.2, 0.2}; // Moving average filter coefficients
    int filter_size = sizeof(filter_coefficients)/sizeof(filter_coefficients[0]); // Filter size

    // Generate signal
    for (int i = 0; i < num_samples; i++) {
        signal[i] = amplitude*sin(2*M_PI*frequency*i/sample_rate + phase);
    }

    printf("Generated signal:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");

    // Generate window
    for (int i = 0; i < num_samples; i++) {
        window[i] = 0.5 - 0.5*cos(2*M_PI*i/(num_samples-1));
    }

    printf("Generated window:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%f ", window[i]);
    }
    printf("\n");

    // Apply window to signal
    for (int i = 0; i < num_samples; i++) {
        signal[i] *= window[i];
    }

    printf("Applied window to signal:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");

    // Apply filter to signal
    for (int i = 0; i < num_samples; i++) {
        filtered_signal[i] = 0.0;
        for (int j = 0; j < filter_size; j++) {
            if (i-j >= 0) {
                filtered_signal[i] += filter_coefficients[j]*signal[i-j];
            }
        }
    }

    printf("Applied filter to signal:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%f ", filtered_signal[i]);
    }
    printf("\n");

    return 0;
}