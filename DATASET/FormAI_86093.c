//FormAI DATASET v1.0 Category: Digital signal processing ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void fft(double *real, double *imag, int n) {
    if(n <= 1) return;
    double even_real[n/2], even_imag[n/2], odd_real[n/2], odd_imag[n/2];
    for(int i = 0, re = 0, im = 0; i < n; i += 2, ++re, ++im) {
        even_real[re] = real[i];
        even_imag[im] = imag[i];
        odd_real[re] = real[i+1];
        odd_imag[im] = imag[i+1];
    }
    fft(even_real, even_imag, n/2);
    fft(odd_real, odd_imag, n/2);
    for(int k = 0; k < n/2; ++k) {
        double twiddle_real = cos(-2*PI*k/n);
        double twiddle_imag = sin(-2*PI*k/n);
        double x_real = odd_real[k] * twiddle_real - odd_imag[k] * twiddle_imag;
        double x_imag = odd_real[k] * twiddle_imag + odd_imag[k] * twiddle_real;
        real[k] = even_real[k] + x_real;
        imag[k] = even_imag[k] + x_imag;
        real[k+n/2] = even_real[k] - x_real;
        imag[k+n/2] = even_imag[k] - x_imag;
    }
}

int main() {
    double x[] = {1, 2, 3, 4};
    double y[] = {0, 0, 0, 0};
    fft(x, y, 4);
    for(int i = 0; i < 4; ++i) {
        printf("(%0.2f, %0.2f)\n", x[i], y[i]);
    }
}