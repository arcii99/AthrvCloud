//FormAI DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    // Create a signal array
    double signal[8000];

    // Generate a 1000 Hz sine wave with a sampling rate of 8000 Hz
    for (int i = 0; i < 8000; i++) {
        signal[i] = sin(2 * PI * 1000 * i / 8000);
    }

    // Apply a low-pass filter to the signal
    double filtered_signal[8000];
    double alpha = 0.05;
    filtered_signal[0] = signal[0];

    for (int i = 1; i < 8000; i++) {
        filtered_signal[i] = alpha * signal[i] + (1 - alpha) * filtered_signal[i-1];
    }

    // Apply a high-pass filter to the signal
    double filtered_signal2[8000];
    double beta = 0.1;
    filtered_signal2[0] = signal[0];

    for (int i = 1; i < 8000; i++) {
        filtered_signal2[i] = beta * (filtered_signal2[i-1] + signal[i] - signal[i-1]);
    }

    // Apply a gain to the signal
    double gain = 2.0;
    for (int i = 0; i < 8000; i++) {
        signal[i] *= gain;
        filtered_signal[i] *= gain;
        filtered_signal2[i] *= gain;
    }

    // Write the original signal to a file
    FILE *file1;
    file1 = fopen("original_signal.csv", "w");

    for (int i = 0; i < 8000; i++) {
        fprintf(file1, "%f\n", signal[i]);
    }

    fclose(file1);

    // Write the filtered signal to a file
    FILE *file2;
    file2 = fopen("filtered_signal.csv", "w");

    for (int i = 0; i < 8000; i++) {
        fprintf(file2, "%f\n", filtered_signal[i]);
    }

    fclose(file2);

    // Write the filtered signal 2 to a file
    FILE *file3;
    file3 = fopen("filtered_signal2.csv", "w");

    for (int i = 0; i < 8000; i++) {
        fprintf(file3, "%f\n", filtered_signal2[i]);
    }

    fclose(file3);

    return 0;
}