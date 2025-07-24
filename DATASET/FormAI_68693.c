//FormAI DATASET v1.0 Category: Digital signal processing ; Style: accurate
/* This program demonstrates a simple implementation of FIR filter using C DSP techniques */
#include <stdio.h>
#include <stdlib.h>

// FIR Filter coefficients
float B[5] = {0.2, 0.3, 0.4, 0.1, 0.5};

// Input Signal
float input[10] = {5, 9, 8, 3, 2, 1, 4, 6, 3, 2};

// Output Signal
float output[10];

// FIR Function 
void FIR(float *input, float *output, float *B, int input_size, int B_size) {
    // Fill initial values
    for(int i=0; i<B_size; i++) {
        output[i] = input[i];
    }
    // Implement FIR filter
    for(int i=B_size-1; i<input_size; i++) {
        output[i] = 0;
        for(int j=0; j<B_size; j++) {
            output[i] += input[i-j] * B[j];
        }
    }
}

// Test the FIR Function
int main() {
    FIR(input, output, B, 10, 5);
    for(int i=0; i<10; i++) {
        printf("%0.1f ", output[i]);
    }
    return 0;
}