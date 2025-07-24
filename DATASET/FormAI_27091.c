//FormAI DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define PI acos(-1.0)

void dft(double *x, double complex *X, int N) {
    for (int k = 0; k < N; k++) {
        double complex sum = 0;
        for (int n = 0; n < N; n++) {
            sum += x[n] * cexp(-I * 2 * PI * n * k / N);
        }
        X[k] = sum / N;
    }
}

void idft(double complex *X, double *x, int N) {
    for (int n = 0; n < N; n++) {
        double complex sum = 0;
        for (int k = 0; k < N; k++) {
            sum += X[k] * cexp(I * 2 * PI * n * k / N);
        }
        x[n] = creal(sum);
    }
}

int main() {
    int N = 8;
    double x[] = {1, 2, 4, 5, 3, 2, 1, 0};
    double complex X[N];

    printf("Original signal: ");
    for (int i = 0; i < N; i++) {
        printf("%lf ", x[i]);
    }

    dft(x, X, N);
    printf("\nDFT result: ");
    for (int i = 0; i < N; i++) {
        printf("%lf%+lfi ", creal(X[i]), cimag(X[i]));
    }

    idft(X, x, N);
    printf("\nIDFT result: ");
    for (int i = 0; i < N; i++) {
        printf("%lf ", x[i]);
    }

    return 0;
}