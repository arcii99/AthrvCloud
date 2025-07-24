//FormAI DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLES 100 // number of samples to process
#define FREQUENCY 1000 // frequency of the signal

int main()
{
    int i;
    float signal[SAMPLES], filtered_signal[SAMPLES]; // initialize arrays for signal and filtered signal
    float omega = 2 * M_PI * FREQUENCY / SAMPLES; // calculate omega

    // set up signal as a sine wave
    for (i = 0; i < SAMPLES; i++) {
        signal[i] = sin(omega * i);
    }

    // perform a moving average filter on the signal
    for (i = 0; i < SAMPLES; i++) {
        filtered_signal[i] = (signal[i] + signal[(i-1+SAMPLES)%SAMPLES] + signal[(i-2+SAMPLES)%SAMPLES]) / 3;
    }

    // print out original and filtered signals
    for (i = 0; i < SAMPLES; i++) {
        printf("Sample %d: Original signal = %f, Filtered signal = %f\n", i, signal[i], filtered_signal[i]);
    }

    return 0;
}