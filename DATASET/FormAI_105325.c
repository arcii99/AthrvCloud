//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ultraprecise
#include <stdio.h>

// Defining constants
#define SIGNAL_LENGTH 16
#define FILTER_ORDER 3
#define M_PI 3.14159265358979323846

int main()
{
    // Create signal and filter coefficients arrays
    double signal[SIGNAL_LENGTH] = {0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707, 0.0, 0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707, 0.0};
    double b[FILTER_ORDER+1] = {1.0, -1.760041880343460, 0.904347406232004, -0.090195455856360};
    double a[FILTER_ORDER+1] = {0.065466718354368, -0.034934889054843, -0.067775441945931, 0.031089239424830};

    // Create arrays to hold signal before and after filtering
    double unfiltered_signal[SIGNAL_LENGTH];
    double filtered_signal[SIGNAL_LENGTH];

    // Copy signal to unfiltered_signal array
    for(int i=0; i<SIGNAL_LENGTH; i++){
        unfiltered_signal[i] = signal[i];
    }

    // Perform filtering using difference equation
    for (int n=0; n<SIGNAL_LENGTH; n++) {
        filtered_signal[n] = 0;
        for (int k=0; k<=FILTER_ORDER; k++) {
            if (n-k >= 0) {
                filtered_signal[n] += b[k] * unfiltered_signal[n-k];
            }
            if (n-k > 0) {
                filtered_signal[n] -= a[k] * filtered_signal[n-k];
            }
        }
    }

    // Print the filtered signal values
    printf("Filtered signal: ");
    for (int i=0; i<SIGNAL_LENGTH; i++) {
        printf("%.4f ", filtered_signal[i]);
    }
    printf("\n");

    return 0;
}