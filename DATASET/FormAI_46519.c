//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for mathematical operations
#define EULER_NUMBER 2.71828182846
#define PI 3.14159265359

// Define sample rate and desired frequencies for the example signal
#define SAMPLE_RATE 44100.0
#define FREQ_1 1000
#define FREQ_2 2000

// Define the size of the signal buffer and a scaling factor for conversions
#define SIGNAL_BUFFER_SIZE 1024
#define SCALE_FACTOR 32767.0

// Define the signal buffer and associated indices
int16_t signal[SIGNAL_BUFFER_SIZE];
int signalIndex = 0;

// Define the example processing function
void processSignal() {
    // Loop over each sample in the buffer
    for (int i = 0; i < SIGNAL_BUFFER_SIZE; i++) {
        // Calculate the time since the start of the signal in seconds
        double time = (double) i / SAMPLE_RATE;

        // Calculate the amplitude of each frequency component
        double amplitude1 = sin(2 * PI * FREQ_1 * time);
        double amplitude2 = sin(2 * PI * FREQ_2 * time);

        // Calculate the total amplitude as a sum of the frequency components
        double totalAmplitude = amplitude1 + amplitude2;

        // Scale the amplitude to the range of the signal buffer values
        int16_t scaledAmplitude = (int16_t) (totalAmplitude * SCALE_FACTOR);

        // Store the amplitude in the signal buffer
        signal[i] = scaledAmplitude;
    }
}

int main() {
    // Generate the example signal
    processSignal();

    // Output the signal to a file for analysis
    FILE *outputFile = fopen("example_signal.dat", "wb");
    fwrite(signal, sizeof(int16_t), SIGNAL_BUFFER_SIZE, outputFile);
    fclose(outputFile);

    // Indicate that the example has completed successfully
    printf("Example program completed.\n");

    return 0;
}