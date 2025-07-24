//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define F_SAMPLING 8000

// Define the input signal
int input_signal[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

// Define the FIR filter coefficients
float fir_coeffs[] = {-0.00482380219945, -0.00181559575314, 0.01221898328246, 0.03779430007356,
                      0.06198522386291, 0.07379276757343, 0.06198522386291, 0.03779430007356,
                     0.01221898328246, -0.00181559575314, -0.00482380219945};

// Define the IIR filter coefficients
float iir_coeffs[] = {0.5, -0.7, 0.2};

// Define the buffers for the FIR filter and IIR filter
float fir_buffer[sizeof(fir_coeffs) / sizeof(float)] = {0};
float iir_buffer[sizeof(iir_coeffs) / sizeof(float)] = {0};

// Declare functions for FIR filter and IIR filter
float fir_filter(float input);
float iir_filter(float input);

int main() {
    // Define the sampling frequency and time vector
    int n_samples = sizeof(input_signal) / sizeof(int);
    float time[n_samples];
    for (int i = 0; i < n_samples; i++) {
        time[i] = (float) i / F_SAMPLING;
    }

    // Generate the filtered signals
    float filtered_signal_fir[n_samples];
    float filtered_signal_iir[n_samples];
    for (int i = 0; i < n_samples; i++) {
        filtered_signal_fir[i] = fir_filter((float) input_signal[i]);
        filtered_signal_iir[i] = iir_filter((float) input_signal[i]);
    }

    // Print the input signal and filtered signals
    printf("Time\tInput\tFIR Output\tIIR Output\n");
    for (int i = 0; i < n_samples; i++) {
        printf("%.4f\t%d\t%.4f\t%.4f\n", time[i], input_signal[i], filtered_signal_fir[i], filtered_signal_iir[i]);
    }

    return 0;
}

float fir_filter(float input) {
    // Shift the values in the FIR buffer
    for (int i = sizeof(fir_buffer) / sizeof(float) - 1; i > 0; i--) {
        fir_buffer[i] = fir_buffer[i - 1];
    }
    fir_buffer[0] = input;

    // Calculate the output of the FIR filter
    float output = 0;
    for (int i = 0; i < sizeof(fir_coeffs) / sizeof(float); i++) {
        output += fir_coeffs[i] * fir_buffer[i];
    }

    return output;
}

float iir_filter(float input) {
    // Shift the values in the IIR buffer
    for (int i = sizeof(iir_buffer) / sizeof(float) - 1; i > 0; i--) {
        iir_buffer[i] = iir_buffer[i - 1];
    }
    iir_buffer[0] = input;

    // Calculate the output of the IIR filter
    float output = iir_coeffs[0] * iir_buffer[0];
    for (int i = 1; i < sizeof(iir_coeffs) / sizeof(float); i++) {
        output += iir_coeffs[i] * iir_buffer[i];
    }

    return output;
}