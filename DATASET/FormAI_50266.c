//FormAI DATASET v1.0 Category: Digital signal processing ; Style: active
#include <stdio.h>

// Declare global variables
int N = 10; // length of input signal
double input[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // input signal
double output[10];

// Define the FIR filter coefficients
double h[4] = {0.25, 0.25, 0.25, 0.25};

int main() {
    int n, k;
    
    // Apply the FIR filter to the input signal
    for (n = 0; n < N; n++) {
        output[n] = 0;
        for (k = 0; k < 4; k++) {
            if (n >= k) {
                output[n] += h[k] * input[n - k];
            }
        }
    }
    
    // Print the input signal and filtered output
    printf("Input signal:");
    for (n = 0; n < N; n++) {
        printf(" %.2f", input[n]);
    }
    printf("\nFiltered output:");
    for (n = 0; n < N; n++) {
        printf(" %.2f", output[n]);
    }
    printf("\n");
    
    return 0;
}