//FormAI DATASET v1.0 Category: Digital signal processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double real;
    double imag;
} complex;

complex add(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complex multiply(complex a, complex b) {
    complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

int bit_reverse(int n, int bits) {
    int reversed = 0;
    for (int i = 0; i < bits; i++) {
        reversed <<= 1;
        reversed |= n & 1;
        n >>= 1;
    }
    return reversed;
}

void fft(complex *x, int n) {
    int bits = log2(n);
    for (int i = 0; i < n; i++) {
        int reversed = bit_reverse(i, bits);
        if (reversed > i) {
            complex temp = x[i];
            x[i] = x[reversed];
            x[reversed] = temp;
        }
    }
    for (int s = 1; s <= bits; s++) {
        int m = 1 << s;
        double theta = -2 * PI / m;
        complex wm = {cos(theta), sin(theta)};
        for (int k = 0; k < n; k += m) {
            complex w = {1, 0};
            for (int j = 0; j < m / 2; j++) {
                complex t = multiply(w, x[k + j + m/2]);
                complex u = x[k + j];
                x[k + j] = add(u, t);
                x[k + j + m/2] = add(u, add(t, t));
                w = multiply(w, wm);
            }
        }
    }
}

void ifft(complex *x, int n) {
    for (int i = 0; i < n; i++) {
        x[i].imag = -x[i].imag;
    }
    fft(x, n);
    for (int i = 0; i < n; i++) {
        x[i].real /= n;
        x[i].imag /= -n;
    }
}

int main() {
    int n = 16;
    complex x[] = {{0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7},
                   {8,8}, {9,9}, {10,10}, {11,11}, {12,12}, {13,13}, {14,14}, {15,15}};
    fft(x, n);
    printf("FFT:\n");
    for (int i = 0; i < n; i++) {
        printf("%f + %fi\n", x[i].real, x[i].imag);
    }
    ifft(x, n);
    printf("IFFT:\n");
    for (int i = 0; i < n; i++) {
        printf("%f + %fi\n", x[i].real, x[i].imag);
    }
    return 0;
}