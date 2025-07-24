//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    
    //initialize input signal
    int n, N = 8; 
    double x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double complex X[8];
    
    //calculate DFT of input signal
    for(int k=0; k<N; k++) {
        X[k] = 0;
        for(int t=0; t<N; t++) {
            X[k] += x[t] * cexp(-I*2*PI*k*t/N);
        }
    }

    //output results
    printf("Input Signal (x):\n");
    for(int i=0; i<N; i++) {
        printf("%f ", x[i]);
    }
    
    printf("\n\nDFT Results (X):\n");
    for(int i=0; i<N; i++) {
        printf("%f + %fi\n", creal(X[i]), cimag(X[i]));
    }
    
    return 0;
}