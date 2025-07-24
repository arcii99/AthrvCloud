//FormAI DATASET v1.0 Category: Digital signal processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 16
#define PI 3.14159265358979323846

void DFT(double *real, double *imag)
{
    double re, im, sum_re = 0, sum_im = 0;

    for (int k = 0; k < N; k++) {
        for (int n = 0; n < N; n++) {
            re = cos(2 * PI * n * k / N);
            im = -sin(2 * PI * n * k / N);
            sum_re += real[n] * re - imag[n] * im;
            sum_im += real[n] * im + imag[n] * re;
        }

        printf("Frequency bin %d: %f + %fi\n", k, sum_re, sum_im);

        sum_re = 0;
        sum_im = 0;
    }
}

void main()
{
    double real[N] = {0.707, 1, 0.707, 0, -0.707, -1, -0.707, 0, 0.707, 1, 0.707, 0, -0.707, -1, -0.707, 0};
    double imag[N] = {0};

    DFT(real, imag);
}