//FormAI DATASET v1.0 Category: Digital signal processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 1024

// Twiddle factors for FFT
float W_real[N/2];
float W_imag[N/2];

// Function to calculate twiddle factors
void calculate_twiddles() {
    for (int i = 0; i < N/2; i++) {
        W_real[i] = cos(2 * PI * i / N);
        W_imag[i] = -sin(2 * PI * i / N);
    }
}

// Function to perform FFT on input signal
void FFT(float *input, float *output_real, float *output_imag) {
    // Butterfly structure
    for (int i = 2; i <= N; i *= 2) {
        for (int j = 0; j < N; j += i) {
            for (int k = 0; k < i/2; k++) {
                int index1 = j + k;
                int index2 = j + k + i/2;
                float temp_real = output_real[index2] * W_real[k] - output_imag[index2] * W_imag[k];
                float temp_imag = output_real[index2] * W_imag[k] + output_imag[index2] * W_real[k];
                output_real[index2] = output_real[index1] - temp_real;
                output_imag[index2] = output_imag[index1] - temp_imag;
                output_real[index1] += temp_real;
                output_imag[index1] += temp_imag;
            }
        }
    }
    // Normalization
    for (int i = 0; i < N; i++) {
        output_real[i] /= N;
        output_imag[i] /= N;
    }
}

int main() {
    // Generate test signal (sine wave with frequency of 50 Hz)
    float signal[N];
    for (int i = 0; i < N; i++) {
        signal[i] = sin(2 * PI * 50 * i / N);
    }

    // Initialize output arrays
    float output_real[N];
    float output_imag[N];
    for (int i = 0; i < N; i++) {
        output_real[i] = signal[i];
        output_imag[i] = 0;
    }

    // Perform FFT
    calculate_twiddles();
    FFT(signal, output_real, output_imag);

    // Print frequency analysis results
    for (int i = 0; i < N/2; i++) {
        float frequency = i * (float)N / (float)N;
        float amplitude = sqrt(output_real[i]*output_real[i] + output_imag[i]*output_imag[i]);
        printf("Frequency: %.2f Hz, Amplitude: %.2f\n", frequency, amplitude);
    }

    return 0;
}