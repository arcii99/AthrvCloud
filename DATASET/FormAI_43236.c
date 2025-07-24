//FormAI DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define PI 3.14159265358979323846

int main()
{
    // allocate memory for input/output data
    double* x = (double*) malloc(N * sizeof(double));
    double* y = (double*) malloc(N * sizeof(double));

    // initialize input data with a sine wave
    for(int i = 0; i < N; i++)
    {
        x[i] = sin(2 * PI * i / 10);
    }

    // compute the discrete Fourier transform (DFT) of the input data
    for(int k = 0; k < N; k++)
    {
        double re = 0, im = 0;
        for(int n = 0; n < N; n++)
        {
            double theta = 2 * PI * k * n / N;
            re += x[n] * cos(theta);
            im -= x[n] * sin(theta);
        }
        y[k] = sqrt(re * re + im * im); // compute amplitude spectrum
    }

    // print the amplitude spectrum
    for(int k = 0; k < N; k++)
    {
        printf("%d Hz: %f\n", k, y[k]);
    }

    // free memory
    free(x);
    free(y);

    return 0;
}