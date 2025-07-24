//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int n = 1024; // number of data points
    double freq = 100.0; // frequency of signal
    double amp = 1.0; // amplitude of signal

    double *data = (double*)malloc(n * sizeof(double));
    double *fft_real = (double*)malloc(n * sizeof(double));
    double *fft_imag = (double*)malloc(n * sizeof(double));

    // generate input data
    for (int i = 0; i < n; i++)
    {
        data[i] = amp * sin(2 * PI * freq * i / n);
    }

    // perform FFT
    for (int i = 0; i < n; i++)
    {
        fft_real[i] = 0;
        fft_imag[i] = 0;

        for (int j = 0; j < n; j++)
        {
            fft_real[i] += data[j] * cos(2 * PI * i * j / n);
            fft_imag[i] -= data[j] * sin(2 * PI * i * j / n);
        }
    }

    // print results
    for (int i = 0; i < n; i++)
    {
        printf("FFT[%d] = %lf + %lfi\n", i, fft_real[i], fft_imag[i]);
    }

    // clean up memory
    free(data);
    free(fft_real);
    free(fft_imag);

    return 0;
}