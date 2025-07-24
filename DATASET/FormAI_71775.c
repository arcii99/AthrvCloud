//FormAI DATASET v1.0 Category: Digital signal processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void calculateFFT(double* real, double* imag, int size, int sign) {
    int m = log2(size);
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (j > i) {
            double temp = real[j];
            real[j] = real[i];
            real[i] = temp;
            temp = imag[j];
            imag[j] = imag[i];
            imag[i] = temp;
        }
        int k = size >> 1;
        while (k <= j) {
            j -= k;
            k >>= 1;
        }
        j += k;
    }
    for (int n = 2; n <= size; n <<= 1) {
        double delta = sign * (2 * PI / n);
        double s = sin(delta / 2);
        double alpha = sin(delta);
        double beta = sin(delta / 2) * sqrt(2 - alpha);
        double imagTmp, realTmp;
        double q0R, q0I, q1R, q1I, q2R, q2I;
        for (int i = 0; i < size; i += n) {
            q0R = 1;
            q0I = 0;
            q1R = cos(delta);
            q1I = -sin(delta);
            for (int j = i; j < i + n / 2; j++) {
                q2R = q0R * real[j + n / 2] - q0I * imag[j + n / 2];
                q2I = q0R * imag[j + n / 2] + q0I * real[j + n / 2];
                realTmp = real[j];
                imagTmp = imag[j];
                real[j] += q2R;
                imag[j] += q2I;
                real[j + n / 2] = realTmp - q2R;
                imag[j + n / 2] = imagTmp - q2I;
                q2R = q0R * q1R - q0I * q1I;
                q0I = q0R * q1I + q0I * q1R;
                q0R = q2R;
            }
        }
    }
}

int main(void) {
    double real[] = {1, 2.5, -1, 0, 4, -2, -0.5, -3};
    double imag[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int size = sizeof(real) / sizeof(double);
    calculateFFT(real, imag, size, 1); // calculate forward FFT
    printf("Forward FFT: \n");
    for (int i = 0; i < size; i++) {
        printf("%f + %fi\n", real[i], imag[i]);
    }
    calculateFFT(real, imag, size, -1); // calculate inverse FFT
    printf("Inverse FFT: \n");
    for (int i = 0; i < size; i++) {
        printf("%f + %fi\n", real[i] / size, imag[i] / size);
    }
    return 0;
}