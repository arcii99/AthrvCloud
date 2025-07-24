//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
/* Happy Digital Signal Processing Example */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Hello there! Let's make some happy digital signal processing!\n");

    // Generate a sine wave signal with frequency 2 Hz and amplitude 1
    int signal_length = 100; // length of the signal
    double signal[signal_length];
    double frequency = 2.0;
    double amplitude = 1.0;
    double pi = 3.14159265358979323846;

    for (int i = 0; i < signal_length; i++) {
        signal[i] = amplitude * sin(2.0 * pi * frequency * i / (double)signal_length);
    }

    printf("Signal generated successfully!\n");

    // Add some noise to the signal
    for (int i = 0; i < signal_length; i++) {
        signal[i] += ((rand() % 21) - 10) / 100.0; // add random noise between -0.1 and 0.1
    }

    printf("Signal with noise added!\n");

    // Apply a simple moving average filter to the signal
    int window_size = 5;
    double filtered_signal[signal_length];
    double sum = 0;

    for (int i = 0; i < window_size; i++) {
        sum += signal[i];
    }
    
    for (int i = 0; i < signal_length - window_size; i++) {
        filtered_signal[i] = sum / window_size;
        sum -= signal[i];
        sum += signal[i + window_size];
    }

    printf("Signal filtered successfully!\n");

    // Calculate the root mean square of the filtered signal
    double rms = 0;

    for (int i = 0; i < signal_length - window_size; i++) {
        rms += pow(filtered_signal[i], 2);
    }

    rms = sqrt(rms / (signal_length - window_size));
    
    printf("RMS value of the filtered signal is: %f\n", rms);

    printf("We did it! Happy digital signal processing completed!\n");

    return 0;
}