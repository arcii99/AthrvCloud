//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
/* "The Case of the Noisy Signal" */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LENGTH 100

// Define function to generate a noisy signal
void generate_noisy_signal(float* signal, int length) {
    for (int i = 0; i < length; i++) {
        signal[i] = sin(i) + ((float)rand() / RAND_MAX) * 0.5 - 0.25;
    }
}

// Define function to calculate the mean of a signal
float mean(float* signal, int length) {
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += signal[i];
    }
    return sum / length;
}

// Define function to calculate the variance of a signal
float variance(float* signal, int length) {
    float m = mean(signal, length);
    float sum = 0;
    for (int i = 0; i < length; i++) {
        sum += pow(signal[i] - m, 2);
    }
    return sum / length;
}

// Define function to high-pass filter a signal
void high_pass_filter(float* signal, int length, float threshold) {
    for (int i = 0; i < length; i++) {
        if (signal[i] < threshold && signal[i] > -threshold) {
            signal[i] = 0;
        }
    }
}

int main() {

    // Generate a noisy signal
    float signal[SIGNAL_LENGTH];
    generate_noisy_signal(signal, SIGNAL_LENGTH);

    // Calculate the mean and variance of the signal
    float signal_mean = mean(signal, SIGNAL_LENGTH);
    float signal_variance = variance(signal, SIGNAL_LENGTH);

    // High-pass filter the signal to remove noise
    high_pass_filter(signal, SIGNAL_LENGTH, signal_variance * 0.5);

    // Print the filtered signal
    printf("Filtered signal:\n");
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        printf("%f ", signal[i]);
    }
    printf("\n");

    return 0;
}