//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int i, N = 8;
    double x[] = {1, 2, 4, 8, 16, 8, 4, 2};
    double y_real[8], y_imag[8];

    // Compute FFT
    for (i = 0; i < N; i++)
    {
        y_real[i] = 0;
        y_imag[i] = 0;
        for (int j = 0; j < N; j++)
        {
            y_real[i] += x[j] * cos(2 * PI * i * j / N);
            y_imag[i] -= x[j] * sin(2 * PI * i * j / N);
        }
    }

    // Display FFT
    for (i = 0; i < N; i++)
    {
        printf("FFT[%d] = %f + %fi\n", i, y_real[i], y_imag[i]);
    }

    return 0;
}