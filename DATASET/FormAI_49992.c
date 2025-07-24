//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>

// Define the number of samples in the input signal
#define N 10

int main() {
    // Define the input signal
    float x[N] = { 0.707, -0.707, 0.866, 0.5, -0.866, -0.5, 0.866, -0.5, -0.707, 0.707 };
    
    // Define the filter coefficients
    float b[4] = { 0.25, 0.25, 0.25, 0.25 };
    
    // Define the output signal (initialized with zeros)
    float y[N] = { 0 };
    
    // Apply the filter using convolution
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < 4; k++) {
            if (n - k >= 0) {
                y[n] += b[k] * x[n - k];
            }
        }
    }
    
    // Print the output signal
    for (int n = 0; n < N; n++) {
        printf("%f ", y[n]);
    }
    printf("\n");

    return 0;
}