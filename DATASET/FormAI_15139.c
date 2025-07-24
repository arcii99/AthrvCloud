//FormAI DATASET v1.0 Category: Audio processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct complex {
    double r;   // real part
    double i;   // imaginary part
} Complex;

int main() {
    // generate an input signal
    const int N = 1024;
    double x[N];
    for (int i = 0; i < N; i++) {
        x[i] = sin(2 * PI * i / N * 10) + 0.5 * sin(2 * PI * i / N * 20);
    }

    // perform a DFT on the input signal
    Complex* X = (Complex*) malloc(N * sizeof(Complex));
    for (int k = 0; k < N; k++) {
        X[k].r = 0;
        X[k].i = 0;
        for (int n = 0; n < N; n++) {
            double phi = -2 * PI * k * n / N;
            Complex c = {cos(phi), sin(phi)};
            X[k].r += x[n] * c.r;
            X[k].i += x[n] * c.i;
        }
    }

    // apply a shape-shifting filter on the frequency domain signal
    for (int k = 0; k < N / 2; k++) {
        double r = sqrt(X[k].r * X[k].r + X[k].i * X[k].i);
        double phi = atan2(X[k].i, X[k].r);
        r = r * pow(sin(2 * PI * k / N), 2);   // shape-shifting filter
        X[k].r = r * cos(phi);
        X[k].i = r * sin(phi);
    }
    for (int k = N / 2; k < N; k++) {
        X[k].r = X[N - k].r;
        X[k].i = -X[N - k].i;
    }

    // perform an inverse DFT to get the output signal
    double y[N];
    for (int n = 0; n < N; n++) {
        y[n] = 0;
        for (int k = 0; k < N; k++) {
            double phi = 2 * PI * k * n / N;
            Complex c = {cos(phi), sin(phi)};
            y[n] += X[k].r * c.r - X[k].i * c.i;
        }
        y[n] /= N;
    }

    // print out the input and output signals
    for (int n = 0; n < N; n++) {
        printf("%f -> %f\n", x[n], y[n]);
    }

    // free up memory
    free(X);

    return 0;
}