//FormAI DATASET v1.0 Category: Audio processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct
{
    double real;
    double imag;
} complex;

void fft(complex *x, int n);
void ifft(complex *x, int n);

int main()
{
    int n = 16;
    complex x[] = {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}, {10,0}, {11,0}, {12,0}, {13,0}, {14,0}, {15,0}};

    fft(x, n);
    printf("FFT:\n");
    for(int i = 0; i < n; ++i)
    {
        printf("%.2f + %.2fi\n", x[i].real, x[i].imag);

    }
    ifft(x, n);
    printf("IFFT:\n");
    for(int i = 0; i < n; ++i)
    {
        printf("%.2f + %.2fi\n", x[i].real/n, x[i].imag/n);

    }

    return 0;

}

void fft(complex *x, int n)
{
    if(n == 1)
        return;

    complex even[n/2];
    complex odd[n/2];

    for(int i = 0; i < n/2; ++i)
    {
        even[i] = x[2*i];
        odd[i] = x[2*i + 1];
    }

    fft(even, n/2);
    fft(odd, n/2);

    for(int i = 0; i < n/2; ++i)
    {
        complex t = {cos(2*PI*i/n), -sin(2*PI*i/n)}; 
        t.real *= odd[i].real;
        t.imag *= odd[i].imag;

        x[i].real = even[i].real + t.real;
        x[i].imag = even[i].imag + t.imag;

        x[i + n/2].real = even[i].real - t.real;
        x[i + n/2].imag = even[i].imag - t.imag;
    }
}

void ifft(complex *x, int n)
{
    for(int i = 0; i < n; ++i)
    {
        x[i].imag *= -1;
    }

    fft(x, n);

    for(int i = 0; i < n; ++i)
    {
        x[i].imag *= -1;
        x[i].real /= n;
        x[i].imag /= n;
    }
}