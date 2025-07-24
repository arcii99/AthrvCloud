//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
// A simple Digital Signal Processing program to compute the FFT of a signal
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

// Function to compute the FFT
void FFT(double* signal, int n) {
    double tmp_real, tmp_imag;
    double angle;
    int i, j, k, m;

    int num_steps = log(n) / log(2);

    // Bit-reverse the input signal
    for (i = 0; i < n; i++) {
        int mark = 0;
        for (j = 0; j < num_steps; j++) {
            if (i & (1 << j)) {
                mark |= (1 << (num_steps - j - 1));
            }
        }
        if (mark > i) {
            tmp_real = signal[i];
            signal[i] = signal[mark];
            signal[mark] = tmp_real;
        }
    }

    // Compute the FFT
    for (m = 1; m <= num_steps; m++) {
        int step_size = pow(2, m);
        int half_size = step_size / 2;
        angle = 2 * PI / step_size;
        double w_real = cos(angle);
        double w_imag = sin(angle);

        for (k = 0; k < n; k += step_size) {
            double wcurr_real = 1.0;
            double wcurr_imag = 0.0;

            for (j = 0; j < half_size; j++) {
                tmp_real = wcurr_real * signal[k + j + half_size] - wcurr_imag * signal[k + j + half_size];
                tmp_imag = wcurr_real * signal[k + j + half_size] + wcurr_imag * signal[k + j + half_size];
                signal[k + j + half_size] = signal[k + j] - tmp_real;
                signal[k + j] += tmp_real;
                wcurr_real = wcurr_real * w_real - wcurr_imag * w_imag;
                wcurr_imag = wcurr_real * w_imag + wcurr_imag * w_real;
            }
        }
    }
}

// Main function
int main() {
    int n = 16;
    double signal[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    printf("Original signal: ");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", signal[i]);
    }
    printf("\n");

    FFT(signal, n);

    printf("FFT: ");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", signal[i]);
    }
    printf("\n");

    return 0;
}