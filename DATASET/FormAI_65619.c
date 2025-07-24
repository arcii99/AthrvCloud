//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
// C program for implementing FIR filter in DSP
#include <stdio.h>
#include <stdlib.h>

#define N 8

float input[N] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}; // input signals
float output[N]; // output signals
float coefficients[N] = {0.1, 0.2, 0.3, 0.1, 0.2, 0.1, 0.05, 0.05}; // filter coefficients

int main() {
    int i, j;

    for (i = 0; i < N; i++) {
        output[i] = 0.0;
        for (j = 0; j < N; j++) {
            if ((i - j) >= 0) {
                output[i] += input[i - j] * coefficients[j];
            }
        }
    }

    // Display the input signal
    printf("Input signal:\n");
    for (i = 0; i < N; i++) {
        printf("%f ", input[i]);
    }

    // Display the output of the FIR filter
    printf("\nOutput signal:\n");
    for (i = 0; i < N; i++) {
        printf("%f ", output[i]);
    }

    return 0;
}