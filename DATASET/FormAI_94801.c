//FormAI DATASET v1.0 Category: Digital signal processing ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void main(void){

    int size = 128; // the size of the signal
    double noise[size], signal[size], filtered[size], filter[size];
    double alpha = 0.1; // the alpha value for the filter
    int i;

    // Generate a noisy input signal
    for (i=0; i<size; i++){
        noise[i] = (double) rand()/RAND_MAX; // random noise values between 0 and 1
        signal[i] = sin((double)i/10) + noise[i]; // add sinusoidal signal to noise
    }

    // Generate the filter coefficients 
    double sum = 0;
    double coeff;
    for (i=0; i<size; i++){
        coeff = alpha * exp(-alpha*(double)i);
        filter[i] = coeff;
        sum += coeff;
    }

    // Scale the filter coefficients so the sum is 1
    for (i=0; i<size; i++){
        filter[i] /= sum;
    }

    // Perform the convolution of the signal and the filter 
    for (i=0; i<size; i++){
        filtered[i] = 0;
        for (int j=0; j<size; j++){
            if (i-j<0) break; // don't allow negative array indices
            filtered[i] += signal[j] * filter[i-j];
        }
    }

    // Print the input and output signals for comparison
    printf("Original signal:\n");
    for (i=0; i<size; i++){
        printf("%f ", signal[i]);
    }
    printf("\n");

    printf("Filtered signal:\n");
    for (i=0; i<size; i++){
        printf("%f ", filtered[i]);
    }
    printf("\n");
}