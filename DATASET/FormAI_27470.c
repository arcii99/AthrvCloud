//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.141592653589793

// This function calculates the Discrete Fourier Transform using the Cooley-Tukey algorithm
void dft(float *input, float *real, float *imag, int n) {
    if (n == 1) {
        *real = *input;
        *imag = 0;
    } else {
        float even_real[n/2], odd_real[n/2];
        float even_imag[n/2], odd_imag[n/2];
        for (int i = 0; i < n/2; i++) {
            even_real[i] = input[2*i];
            odd_real[i] = input[2*i+1];
            even_imag[i] = 0;
            odd_imag[i] = 0;
        }
        dft(even_real, real, imag, n/2);
        dft(odd_real, real+n/2, imag+n/2, n/2);
        for (int i = 0; i < n/2; i++) {
            float angle = -2*PI*i/n;
            float cos_val = cos(angle);
            float sin_val = sin(angle);
            float re = cos_val*real[n/2+i] - sin_val*imag[n/2+i];
            float im = sin_val*real[n/2+i] + cos_val*imag[n/2+i];
            real[n/2+i] = even_real[i] + re;
            imag[n/2+i] = even_imag[i] + im;
            real[i] = even_real[i] - re;
            imag[i] = even_imag[i] - im;
        }
    }
}

int main() {
    int num_samples = 16;
    float x[num_samples];
    float real[num_samples];
    float imag[num_samples];
    for (int i = 0; i < num_samples; i++) {
        x[i] = sin(2*PI*6*i/num_samples) + sin(2*PI*10*i/num_samples);
    }
    dft(x, real, imag, num_samples);
    printf("Real\t\tImaginary\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%f\t%f\n", real[i], imag[i]);
    }
    return 0;
}