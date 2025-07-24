//FormAI DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>

// This program takes in an array of integers and applies a low-pass filter using IIR filter coefficients
// The coefficients were pre-calculated using MATLAB and stored in the arrays b and a respectively
// The filter is implemented using direct form I

#define N 8 // Length of the input and output arrays
#define NB 3 // Length of the coefficient arrays

void iir_filter(const float input[], const float b[], const float a[], float output[]) {
    float delay_line[NB] = {0}; // Initialize delay line to 0
    for (int n = 0; n < N; n++) {
        // Calculate the current output sample
        output[n] = b[0] * input[n] + delay_line[0];

        // Update the delay line
        for (int i = NB-1; i > 0; i--) {
            delay_line[i] = b[i]*input[n] + a[i]*output[n] + delay_line[i-1];
        }
        delay_line[0] = b[1]*input[n] + a[1]*output[n];
    }
}

int main() {
    // Input and expected output
    float input[N] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
    float expected_output[N] = {0.1, 0.3, 0.6, 1.0, 1.5, 2.1, 2.8, 3.7};

    // Coefficient arrays
    float b[NB] = {0.1770, 0.3540, 0.1770};
    float a[NB] = {1.0000, -0.2367, 0.0753};

    // Output array
    float output[N] = {0};

    // Call the filter function
    iir_filter(input, b, a, output);

    // Compare the output with the expected output
    for (int n = 0; n < N; n++) {
        if (output[n] != expected_output[n]) {
            printf("Test failed: Output[%d] = %f, expected %f\n", n, output[n], expected_output[n]);
            return 1;
        }
    }

    printf("All tests passed!\n");
    return 0;
}