//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scientific
#include <stdio.h>
#include <math.h>

#define N 8

int main()
{
    // Define input signal
    float x[N] = {0.707,0.707,0,0,0,0,0,0};
    
    // Define coefficients for 2-point moving average filter
    float b[2] = {0.5,0.5};
    float a[2] = {1,0};
    
    // Define variables
    float y[N] = {0};
    float z[2] = {0};

    // Filter implementation using Direct Form II
    for(int n=0; n<N; n++){
        // Compute output y[n] using difference equation
        y[n] = b[0]*x[n] + b[1]*z[0] - a[1]*z[1];
        
        // Update delay line z
        z[1] = z[0];
        z[0] = y[n];
    }

    // Print input signal and filtered output
    printf("Input Signal\tFiltered Output\n");
    for(int n=0; n<N; n++){
        printf("%f\t%f\n", x[n], y[n]);
    }
    
    return 0;
}