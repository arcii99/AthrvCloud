//FormAI DATASET v1.0 Category: Digital signal processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate Discrete Fourier Transform (DFT)
void DFT(int *input, int *real_output, int *imag_output, int size) {
    for (int k = 0; k < size; k++) {
        real_output[k] = imag_output[k] = 0;
        for (int n = 0; n < size; n++) {
            double angle = 2 * PI * k * n / (double) size;
            real_output[k] += input[n] * cos(angle);
            imag_output[k] -= input[n] * sin(angle);
        }
    }
}

int main() {
    // Creating sample input signal
    int size = 16;
    int input[size];
    for (int i = 0; i < size; i++) {
        double x = 2 * PI * i / (double) size;
        input[i] = sin(3 * x) + 0.5 * sin(5 * x);
    }
    
    // Calculating DFT of the input signal
    int real_output[size], imag_output[size];
    DFT(input, real_output, imag_output, size);

    // Displaying the real and imaginary parts of DFT
    printf("DFT Real Output:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", (double) real_output[i]);
    }
    printf("\n\nDFT Imaginary Output:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", (double) imag_output[i]);
    }

    return 0;
}