//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 16
#define PI 3.14159265358979323846

int main() {
    int i;
    float input_signal[NUM_SAMPLES] = {0};
    float output_signal[NUM_SAMPLES] = {0};
    float impulse[NUM_SAMPLES] = {0};
    float filter_coefficients[NUM_SAMPLES/2 + 1] = {0};

    // Generate input signal (sinusoidal with noise)
    for (i = 0; i < NUM_SAMPLES; i++) {
        input_signal[i] = sin(2 * PI * i / NUM_SAMPLES) + (rand() % 10) / 10.0 - 0.5;
    }

    // Generate impulse response of low-pass filter
    for (i = 0; i < NUM_SAMPLES/2 + 1; i++) {
        if (i == 0) {
            filter_coefficients[i] = 1.0 / (2 * (NUM_SAMPLES/2) + 1);  // DC gain
        } else {
            filter_coefficients[i] = sin(2 * PI * i / NUM_SAMPLES) / (i * PI);  // Sinc function
        }
    }

    // Convolve input signal with filter coefficients
    for (i = 0; i < NUM_SAMPLES; i++) {
        if (i < NUM_SAMPLES/2 + 1) {
            impulse[i] = filter_coefficients[i];
        } else {
            impulse[i] = filter_coefficients[NUM_SAMPLES - i];
        }
    }

    for (i = 0; i < NUM_SAMPLES; i++) {
        int j;
        for (j = 0; j <= i; j++) {
            output_signal[i] += input_signal[j] * impulse[i-j];
        }
    }

    // Print input, impulse response, and output signals
    printf("Input signal: \n");
    for (i = 0; i < NUM_SAMPLES; i++) {
        printf("%.3f ", input_signal[i]);
    }
    printf("\n\nImpulse response: \n");
    for (i = 0; i < NUM_SAMPLES; i++) {
        printf("%.3f ", impulse[i]);
    }
    printf("\n\nOutput signal: \n");
    for (i = 0; i < NUM_SAMPLES; i++) {
        printf("%.3f ", output_signal[i]);
    }
    printf("\n");

    return 0;
}