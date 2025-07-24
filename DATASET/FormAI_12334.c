//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1)

int main()
{
    int n = 10;
    double x[n];
    double complex X[n];
    double fft[n];
    int i, j, k;

    // Initializing input signal x[n]
    for (i = 0; i < n; ++i) {
        x[i] = sin(i);
    }

    // Performing FFT algorithm on input signal x[n]
    for (i = 0; i < n; ++i) {
        X[i] = x[i] * cexp(-2 * PI * I * i / n);
    }
    for (i = 0; i < n / 2; ++i) {
        double complex even = 0, odd = 0;
        for (j = 0; j < n / 2; ++j) {
            even += X[2 * j] * cexp(-2 * PI * I * j * i / (n / 2));
            odd += X[2 * j + 1] * cexp(-2 * PI * I * j * i / (n / 2));
        }
        fft[i] = creal(even + cexp(-2 * PI * I * i / n) * odd);
        fft[i + n / 2] = creal(even - cexp(-2 * PI * I * i / n) * odd);
    }

    // Displaying results
    printf("Input Signal x[n]: ");
    for (i = 0; i < n; ++i) {
        printf("%.2lf ", x[i]);
    }
    printf("\n");

    printf("FFT Output: ");
    for (i = 0; i < n; ++i) {
        printf("%.2lf ", fft[i]);
    }
    printf("\n");

    return 0;
}