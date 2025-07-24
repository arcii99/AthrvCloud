//FormAI DATASET v1.0 Category: Digital signal processing ; Style: modular
#include <stdio.h>

#define PI 3.141592653589793

// Function to calculate the magnitude of a complex number
double mag(double real, double imaginary) {
    return sqrt(real * real + imaginary * imaginary);
}

// Function to add two complex numbers
void add_complex(double real1, double imaginary1, double real2, double imaginary2, double *result_real, double *result_imaginary) {
    *result_real = real1 + real2;
    *result_imaginary = imaginary1 + imaginary2;
}

// Function to multiply two complex numbers
void multiply_complex(double real1, double imaginary1, double real2, double imaginary2, double *result_real, double *result_imaginary) {
    *result_real = real1 * real2 - imaginary1 * imaginary2;
    *result_imaginary = real1 * imaginary2 + imaginary1 * real2;
}

// Function to perform Discrete Fourier Transform (DFT) on a given signal
void dft(double *x, double *X, int N) {
    int n, k;
    double real_sum, imaginary_sum;
    for (k = 0; k < N; k++) {
        real_sum = imaginary_sum = 0.0;
        for (n = 0; n < N; n++) {
            double angle = 2 * PI * n * k / N;
            real_sum += x[n] * cos(angle);
            imaginary_sum -= x[n] * sin(angle);
        }
        X[k] = mag(real_sum, imaginary_sum);
    }
}

// Function to perform Inverse Discrete Fourier Transform (IDFT) on a given signal
void idft(double *X, double *x, int N) {
    int n, k;
    double real_sum, imaginary_sum;
    for (n = 0; n < N; n++) {
        real_sum = imaginary_sum = 0.0;
        for (k = 0; k < N; k++) {
            double angle = 2 * PI * n * k / N;
            double real, imaginary;
            multiply_complex(X[k], -sin(angle), X[k], cos(angle), &real, &imaginary);
            real_sum += real;
            imaginary_sum += imaginary;
        }
        x[n] = 1.0 / N * real_sum;
    }
}

int main() {
    int N = 8;  // Number of samples in the signal
    double x[] = {1, 2, 3, 4, 5, 6, 7, 8};  // Input signal
    
    // Print the input signal
    printf("Input signal: ");
    for (int i = 0; i < N; i++) {
        printf("%g ", x[i]);
    }
    printf("\n");
    
    // Perform DFT on the input signal
    double X[N];
    dft(x, X, N);
    
    // Print the magnitude spectrum of the signal after DFT
    printf("Magnitude spectrum after DFT: ");
    for (int i = 0; i < N; i++) {
        printf("%g ", X[i]);
    }
    printf("\n");
    
    // Perform IDFT on the magnitude spectrum obtained after DFT
    double x_reconstructed[N];
    idft(X, x_reconstructed, N);
    
    // Print the reconstructed signal obtained after IDFT
    printf("Reconstructed signal after IDFT: ");
    for (int i = 0; i < N; i++) {
        printf("%g ", x_reconstructed[i]);
    }
    printf("\n");
    
    return 0;
}