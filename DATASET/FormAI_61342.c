//FormAI DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining the constants
#define M 16         // Length of the filter
#define L 1024       // Length of the sequence
#define PI 3.1415926 // PI value

// Functions prototype
void generate_hamming_window(float* window, int length);
void generate_input_signal(float* signal, int length);
void perform_fft(float* signal, int length, float* output);

int main()
{
    // Generate a hamming window of length M
    float hamming_window[M];
    generate_hamming_window(hamming_window, M);

    // Generate input signal of length L
    float input_signal[L];
    generate_input_signal(input_signal, L);

    // Create filter coefficients using the hamming window
    float filter_coefficients[M];
    for (int i = 0; i < M; i++) {
        filter_coefficients[i] = hamming_window[i] * (0.54 - 0.46 * cos(2 * PI * i / (M - 1)));
    }

    // Apply filter using circular convolution
    float filtered_output[L];
    for (int i = 0; i < L; i++) {
        filtered_output[i] = 0;
        for (int j = 0; j < M; j++) {
            filtered_output[i] += input_signal[(i-j+M)%M] * filter_coefficients[j];
        }
    }

    // Perform FFT on the filtered output
    float fft_output[L];
    perform_fft(filtered_output, L, fft_output);

    printf("Original signal: \n");
    for (int i = 0; i < L; i++) {
        printf("%f ", input_signal[i]);
    }
    printf("\n\n");

    printf("Filtered signal: \n");
    for (int i = 0; i < L; i++) {
        printf("%f ", filtered_output[i]);
    }
    printf("\n\n");

    printf("FFT of filtered signal: \n");
    for (int i = 0; i < L; i++) {
        printf("%f ", fft_output[i]);
    }
    printf("\n");

    return 0;
}

// Function to generate a hamming window
void generate_hamming_window(float* window, int length)
{
    for (int i = 0; i < length; i++) {
        window[i] = 0.54 - 0.46 * cos(2 * PI * i / (length - 1));
    }
}

// Function to generate an input signal using a sine wave
void generate_input_signal(float* signal, int length)
{
    for (int i = 0; i < length; i++) {
        signal[i] = sin(2 * PI * i / length);
    }
}

// Function to perform FFT on a signal using Cooley-Tukey algorithm
void perform_fft(float* signal, int length, float* output)
{
    float real[length];
    float imag[length];

    for (int i = 0; i < length; i++) {
        real[i] = signal[i];
        imag[i] = 0;
    }

    // Decimation in time
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (j > i) {
            float temp = real[j];
            real[j] = real[i];
            real[i] = temp;
            temp = imag[j];
            imag[j] = imag[i];
            imag[i] = temp;
        }
        int k = length / 2;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }

    // Perform butterfly operations
    for (int s = 1; s <= log2(length); s++) {
        int m = pow(2, s);
        float wm_r = cos(-2 * PI / m);
        float wm_i = sin(-2 * PI / m);
        for (int k = 0; k < length; k += m) {
            float w_r = 1;
            float w_i = 0;
            for (int j = 0; j < m / 2; j++) {
                float t_r = w_r * real[k + j + m / 2] - w_i * imag[k + j + m / 2];
                float t_i = w_r * imag[k + j + m / 2] + w_i * real[k + j + m / 2];
                float u_r = real[k + j];
                float u_i = imag[k + j];
                real[k + j] = u_r + t_r;
                imag[k + j] = u_i + t_i;
                real[k + j + m / 2] = u_r - t_r;
                imag[k + j + m / 2] = u_i - t_i;
                float new_w_r = w_r * wm_r - w_i * wm_i;
                float new_w_i = w_r * wm_i + w_i * wm_r;
                w_r = new_w_r;
                w_i = new_w_i;
            }
        }
    }

    // Calculate magnitudes of the complex output
    for (int i = 0; i < length; i++) {
        output[i] = sqrt(pow(real[i], 2) + pow(imag[i], 2)) / length;
    }
}