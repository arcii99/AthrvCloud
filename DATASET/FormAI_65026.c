//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>

// Function to compute the Discrete Fourier Transform of a given signal
void computeDFT(float x[], float Xre[], float Xim[], int N) {
    for(int k=0; k<N; k++) {
        Xre[k] = 0;
        Xim[k] = 0;
        for(int n=0; n<N; n++) {
            float theta = 2 * 3.14159265359 * k * n / N;
            Xre[k] += x[n] * cos(theta);
            Xim[k] += x[n] * sin(theta);
        }
    }
}

int main() {
    int N = 8; // Length of Signal
    float x[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Input Signal
    float Xre[N], Xim[N]; // Real and Imaginary Parts of DFT
    
    computeDFT(x, Xre, Xim, N); // Compute DFT of Input Signal
    
    // Print Results
    printf("Input Signal x[n] = ");
    for(int n=0; n<N; n++)
        printf("%.2f ", x[n]);
    
    printf("\n\nDiscrete Fourier Transform:\n");
    for(int k=0; k<N; k++)
        printf("X[%d] = %.2f + j%.2f\n", k, Xre[k], Xim[k]);
    
    return 0;
}