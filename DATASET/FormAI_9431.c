//FormAI DATASET v1.0 Category: Digital signal processing ; Style: careful
// This program performs a basic low-pass filtering algorithm to a discrete time-domain signal
// The algorithm implements a first-order recursive exponential weighting function 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALPHA 0.2 // exponential smoothing constant
#define N 100 // number of samples in the signal

int main(){

    // initialize the input signal and filtered signal arrays
    float input_signal[N];
    float filtered_signal[N];

    // define a random input signal using a uniform distribution
    srand(2);
    for(int i=0; i<N; i++){
        input_signal[i] = (float)rand()/RAND_MAX - 0.5;
    }

    // perform the low-pass filtering algorithm
    filtered_signal[0] = input_signal[0]; // initialize first filtered signal value
    for(int i=1; i<N; i++){
        filtered_signal[i] = ALPHA*input_signal[i] + (1-ALPHA)*filtered_signal[i-1];
    }

    // print the input and filtered signals to the console
    printf("Input Signal:\n");
    for(int i=0; i<N; i++){
        printf("%f, ", input_signal[i]);
    }
    printf("\n\nFiltered Signal:\n");
    for(int i=0; i<N; i++){
        printf("%f, ", filtered_signal[i]);
    }
    printf("\n");

    return 0;
}