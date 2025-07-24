//FormAI DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <math.h>

// Define constants
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

// Declare arrays for input and output signal
double input_signal[1000];
double output_signal[1000];

// Declare function for processing the signal
void process_signal(double* input_signal, double* output_signal, int num_samples, double cutoff_freq){

    // Calculate time step for given sample rate
    double dt = 1.0 / SAMPLE_RATE;

    // Calculate angular frequency of cutoff frequency
    double omega_c = 2 * PI * cutoff_freq;

    // Calculate coefficients for filter
    double a1 = -exp(-omega_c * dt);
    double b0 = 1 + a1;
    double b1 = -1;

    // Apply filter to input signal
    for(int i = 1; i < num_samples; i++){
        output_signal[i] = b0 * input_signal[i] + b1 * input_signal[i-1] + a1 * output_signal[i-1];
    }

}

int main(){

    // Generate input signal
    for(int i = 0; i < 1000; i++){
        input_signal[i] = sin(2 * PI * i * 1000 / SAMPLE_RATE); // Generate sine wave at 1000 Hz
    }

    // Process input signal with high-pass filter
    process_signal(input_signal, output_signal, 1000, 500); // Cutoff frequency of 500 Hz

    // Print output signal
    for(int i = 0; i < 1000; i++){
        printf("%f\n", output_signal[i]);
    }

    return 0;
}