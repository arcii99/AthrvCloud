//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define N 8
#define PI 3.14159265359

// Function prototype
void dft(float x[], float X_re[], float X_im[]);

int main()
{
    // Input signal x
    float x[N] = {0, 1, 2, 3, 4, 5, 6, 7};
    
    // Create arrays to hold DFT results
    float X_re[N], X_im[N];
    
    // Compute DFT of x using our function prototype
    dft(x, X_re, X_im);
    
    // Display DFT results
    printf("DFT of x:\n\n");
    for(int k=0; k<N; k++){
        printf("X[%d] = %.3f + j%.3f\n", k, X_re[k], X_im[k]);
    }
    
    return 0;
}

void dft(float x[], float X_re[], float X_im[])
{
    // Loop over all possible values of k
    for(int k=0; k<N; k++){
        
        // Initialize real and imaginary parts of X
        X_re[k] = 0.0;
        X_im[k] = 0.0;
        
        // Loop over all values of n (0 to N-1)
        for(int n=0; n<N; n++){
            
            // Compute terms for real and imaginary parts of X
            float term_re = x[n] * cos(2*PI*n*k/N);
            float term_im = -x[n] * sin(2*PI*n*k/N);
            
            // Add terms to corresponding X values
            X_re[k] += term_re;
            X_im[k] += term_im;
        }
    }
}