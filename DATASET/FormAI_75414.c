//FormAI DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>

#define N 500
#define PI 3.14159265358979323846

/* This program generates a sine wave signal of frequency 5 Hz and performs frequency domain analysis using FFT */

typedef struct {
    float real, imag;
} Complex;

Complex X[N];

void FFT(Complex* x, int n) {
    if(n == 1) {
        return;
    }
    Complex even[n/2], odd[n/2];
    for(int i = 0; i < n/2; i++) {
        even[i] = x[2*i];
        odd[i] = x[2*i+1];
    }

    FFT(even, n/2);
    FFT(odd, n/2);

    for(int k = 0; k < n/2; k++) {
        Complex t = {cos(2*PI*k/n), -sin(2*PI*k/n)};
        t.real *= odd[k].real;
        t.imag *= odd[k].imag;

        x[k].real = even[k].real + t.real;
        x[k].imag = even[k].imag + t.imag;
        x[k+n/2].real = even[k].real - t.real;
        x[k+n/2].imag = even[k].imag - t.imag;
    }
}

void genSignal(Complex* x, int n) {
    for(int i = 0; i < n; i++) {
        x[i].real = sin(2*PI*i*5/N);
        x[i].imag = 0;
    }
}

int main() {
    genSignal(X, N);
    FFT(X, N);

    printf("Frequency domain analysis of a sine signal of frequency 5 Hz:\n");
    for(int i = 0; i < N/2; i++) {
        float freq = i*1.0/N;
        float mag = sqrt(X[i].real*X[i].real + X[i].imag*X[i].imag);
        printf("%d Hz: %f\n", (int)(freq*N), mag);
    }

    return 0;
}