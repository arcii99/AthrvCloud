//FormAI DATASET v1.0 Category: Digital signal processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    // Define arrays to hold input and output samples
    double input_samples[100];
    double output_samples[100];

    // Generate input samples as sin wave
    for (int i = 0; i < 100; i++) {
        input_samples[i] = sin(2 * PI * i / 10);
    }

    // Apply smoothing filter to input signal
    for (int i = 0; i < 100; i++) {
        // Add nearby samples
        double average = input_samples[i];
        if (i > 0) {
            average += input_samples[i - 1];
        }
        if (i < 99) {
            average += input_samples[i + 1];
        }
        average /= 3;

        // Store filtered sample
        output_samples[i] = average;
    }

    // Print input and output signals
    printf("Input Samples:\n");
    for (int i = 0; i < 100; i++) {
        printf("%f ", input_samples[i]);
    }
    printf("\n\nOutput Samples:\n");
    for (int i = 0; i < 100; i++) {
        printf("%f ", output_samples[i]);
    }
    printf("\n");

    return 0;
}