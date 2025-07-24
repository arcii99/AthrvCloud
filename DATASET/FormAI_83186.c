//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
/* Digital Signal Processing Example Program */

#include <stdio.h>

#define N 16 // Number of samples
#define PI 3.1415926535 // Value of pi

int main() {
    int n, k;
    float x[N], realOut[N], imagOut[N], magnitude[N], phase[N];
    
    // Input the signal values
    printf("Enter %d values for the input signal:\n", N);
    for(n=0; n<N; n++) {
        scanf("%f", &x[n]);
    }
    
    // Compute Discrete Fourier Transform (DFT)
    for(k=0; k<N; k++) {
        realOut[k] = 0;
        imagOut[k] = 0;
        
        for(n=0; n<N; n++) {
            realOut[k] += x[n] * cos(2*PI*k*n/N);
            imagOut[k] -= x[n] * sin(2*PI*k*n/N);
        }
        
        magnitude[k] = sqrt(realOut[k]*realOut[k] + imagOut[k]*imagOut[k]);
        phase[k] = atan2(imagOut[k], realOut[k]);
    }
    
    // Output the results
    printf("\nDFT output:\n");
    for(k=0; k<N; k++) {
        printf("%2d: (%8.4f, %8.4f) Mag: %8.4f Phase: %8.4f\n", k, realOut[k], imagOut[k], magnitude[k], phase[k]);
    }
    
    return 0;
}