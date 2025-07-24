//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scientific
/* This program demonstrates a basic implementation of the Discrete Fourier Transform (DFT) algorithm using C programming language for Digital Signal Processing (DSP) applications. It computes the frequency spectrum of a signal in the time domain using a given set of sample values */

#include <stdio.h> // for standard input/output functions
#include <math.h> // for mathematical functions

#define M_PI 3.14159265358979323846 // define the value of pi

void DFT(float x[], float Xr[], float Xi[], int N) {
    int n, m;
    float c, s;
    
    // loop through all frequencies
    for (m = 0; m < N; m++) {
        Xr[m] = Xi[m] = 0.0;
        
        // compute DFT for each frequency
        for (n = 0; n < N; n++) {
            c = cos(2 * M_PI * m * n / N);
            s = sin(2 * M_PI * m * n / N);
            
            Xr[m] += x[n] * c;
            Xi[m] += -x[n] * s;
        }
    }
}

int main() {
    int N = 10; // number of sample values
    float x[10] = {5, 8, 6, 1, 2, 4, 5, 9, 6, 3}; // sample values
    float Xr[10], Xi[10]; // real and imaginary parts of frequency spectrum
    
    // compute the DFT of the signal
    DFT(x, Xr, Xi, N);
    
    // print the frequency spectrum
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < N; i++) {
        printf("(%f, %f)\n", Xr[i], Xi[i]);
    }
    
    return 0;
}