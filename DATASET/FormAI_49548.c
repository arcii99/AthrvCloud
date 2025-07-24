//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793
#define NUM_SAMPLES 1024
#define FREQ 100.0

typedef struct {
    float real;
    float imag;
} complex;

void printSpectrum(complex *signal) {
    int i;
    float spectrum[NUM_SAMPLES];

    for(i = 0; i < NUM_SAMPLES; i++) {
        spectrum[i] = sqrt(pow(signal[i].real, 2) + pow(signal[i].imag, 2));
        printf("%f\n", spectrum[i]);
    }
}

void FFT(complex *signal) {
    int i, j, k;
    int N = NUM_SAMPLES;
    complex temp;
    float angle;
    float real, imag;

    for(i = 0; i < N; i++) {
        j = i; k = 0;

        while(j >= 0) {
            temp.real = cos(k * 2 * PI * j / N);
            temp.imag = -1 * sin(k * 2 * PI * j / N);
            real = signal[i].real * temp.real - signal[i].imag * temp.imag;
            imag = signal[i].real * temp.imag + signal[i].imag * temp.real;

            signal[i].real = real;
            signal[i].imag = imag;

            j--; k++;
        }
    }

    j = 0;
    for(i = 0; i < N; i++) {
        if(j > i) {
            temp = signal[j];
            signal[j] = signal[i];
            signal[i] = temp;
        }

        k = N / 2;
        while(k >= 2 && j >= k) {
            j -= k;
            k /= 2;
        }

        j += k;
    }
}

int main() {
    int i;
    complex signal[NUM_SAMPLES];

    for(i = 0; i < NUM_SAMPLES; i++) {
        signal[i].real = sin(2 * PI * i * FREQ / NUM_SAMPLES);
        signal[i].imag = 0;
    }

    FFT(signal);
    printSpectrum(signal);

    return 0;
}