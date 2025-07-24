//FormAI DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846

void dft(double complex *in, double complex *out, int size) {
    for (int k = 0; k < size; k++) {
        double complex sum = 0;
        for (int n = 0; n < size; n++) {
            double complex val = in[n] * cexp((-2 * PI * I * n * k) / size);
            sum += val;
        }
        out[k] = sum;
    }
}

void lowPassFilter(double complex *in, double complex *out, int size, double fc) {
    double delta = 1.0 / size; // The sampling interval
    double omega = 2 * PI * fc * delta; // Omega cutoff
    double alpha = sin(omega) / (2 * PI * delta); 
    double beta = (1 - cos(omega)) / 2;
    
    double complex y_prev = 0;
    double complex x_prev = 0;

    for (int n = 0; n < size; n++) {
        double complex y = alpha * (x_prev + in[n]) + beta * y_prev;
        out[n] = y;
        y_prev = y;
        x_prev = in[n];
    }
}

int main() {
    int size = 256; // Signal size
    double complex *in = malloc(size * sizeof(double complex));
    double complex *dft_out = malloc(size * sizeof(double complex));
    double complex *filtered_out = malloc(size * sizeof(double complex));

    // Generate a sine wave at 10Hz (1/256 interval)
    for (int n = 0; n < size; n++) {
        in[n] = sin(2 * PI * 10 * n / size);
    }

    // Compute the DFT
    dft(in, dft_out, size);

    // Apply a low-pass filter with a cutoff frequency of 5Hz
    lowPassFilter(in, filtered_out, size, 5);

    // Output the results
    for (int i = 0; i < size / 2; i++) {
        printf("DFT: %dHz - %.3lf + %.3lfi\n", i, creal(dft_out[i]), cimag(dft_out[i]));
    }

    printf("\n");

    for (int i = 0; i < size / 2; i++) {
        printf("Filtered: %dHz - %.3lf + %.3lfi\n", i, creal(filtered_out[i]), cimag(filtered_out[i]));
    }

    // Clean up
    free(in);
    free(dft_out);
    free(filtered_out);

    return 0;
}