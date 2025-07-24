//FormAI DATASET v1.0 Category: Digital signal processing ; Style: automated
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define N 256
#define PI 3.14159265358979323846

typedef float real;
typedef struct {
    real Re;
    real Im;
} complex;

// Function prototypes
void bit_reverse(complex* x, int n);
void fft(complex* x, int n);
void print_signal(complex* x, int n);

int main() {
    int i;
    complex x[N];

    // Generate input signal
    for (i = 0; i < N; i++) {
        x[i].Re = sin(2*PI*10*i/N) + sin(2*PI*30*i/N);
        x[i].Im = 0;
    }

    // Perform FFT
    fft(x, N);

    // Print output signal
    print_signal(x, N);

    return 0;
}

void bit_reverse(complex* x, int n) {
    int i, j;
    complex temp;

    j = 0;
    for (i = 0; i < n; i++) {
        if (j > i) {
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
        int k = n/2;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }
}

void fft(complex* x, int n) {
    int i, j, k;
    complex t, u;

    bit_reverse(x, n);

    for (i = 1; i < n; i *= 2) {
        real wpr = cos(PI/i);
        real wpi = -sin(PI/i);
        real wr = 1.0;
        real wi = 0.0;
        for (j = 0; j < i; j++) {
            for (k = j; k < n; k += 2*i) {
                t.Re = wr*x[k+i].Re - wi*x[k+i].Im;
                t.Im = wr*x[k+i].Im + wi*x[k+i].Re;
                u.Re = x[k].Re;
                u.Im = x[k].Im;
                x[k].Re = u.Re + t.Re;
                x[k].Im = u.Im + t.Im;
                x[k+i].Re = u.Re - t.Re;
                x[k+i].Im = u.Im - t.Im;
            }
            real temp = wr;
            wr = wr*wpr - wi*wpi;
            wi = wi*wpr + temp*wpi;
        }
    }
}

void print_signal(complex* x, int n) {
    printf("Index\t\tReal\t\tImaginary\tMagnitude\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%0.6f\t%0.6f\t%0.6f\n", i, x[i].Re, x[i].Im, sqrt(x[i].Re*x[i].Re + x[i].Im*x[i].Im));
    }
}