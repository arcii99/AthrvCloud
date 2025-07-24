//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_SIZE 100     // number of samples
#define PI 3.14159265358979 // value of pi

int main() {
    double signal[SAMPLE_SIZE];     // initialize array for signal samples
    double filtered_signal[SAMPLE_SIZE];  // initialize array for filtered signal samples
    
    // generate a simple sine signal
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        signal[i] = sin(2 * PI * i / SAMPLE_SIZE);
    }
    
    // apply a simple moving average filter to the signal
    int filter_size = 5;    // define the size of the filter window
    double filter_coefficients[filter_size];    // initialize array for filter coefficients
    double filter_sum = 0;  // initialize variable to store the sum of filter coefficients
    
    // calculate the filter coefficients using a uniform distribution
    for (int i = 0; i < filter_size; i++) {
        filter_coefficients[i] = 1.0 / filter_size;
        filter_sum += filter_coefficients[i];
    }
    
    // normalize the filter coefficients to ensure that the filtered signal is not amplified or attenuated
    for (int i = 0; i < filter_size; i++) {
        filter_coefficients[i] /= filter_sum;
    }
    
    // apply the filter to the signal
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        double filtered_sample = 0;
        
        // apply the filter coefficients to the previous samples
        for (int j = 0; j < filter_size; j++) {
            int previous_sample_index = i - j;
            
            // handle edge cases by mirroring the signal
            if (previous_sample_index < 0) {
                previous_sample_index = abs(previous_sample_index);
            }
            if (previous_sample_index >= SAMPLE_SIZE) {
                previous_sample_index = 2 * SAMPLE_SIZE - previous_sample_index - 2;
            }
            
            // apply the filter coefficient to the previous sample
            filtered_sample += filter_coefficients[j] * signal[previous_sample_index];
        }
        
        // save the filtered sample to the filtered signal array
        filtered_signal[i] = filtered_sample;
    }
    
    // print out the original and filtered signals
    printf("Original Signal:\t\tFiltered Signal:\n");
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        printf("%0.6f\t\t\t%0.6f\n", signal[i], filtered_signal[i]);
    }
    
    return 0;
}