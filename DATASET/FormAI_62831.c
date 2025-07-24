//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1.0)

int main()
{
    int N = 8;
    int x[] = {1, 1, 1, 1, 0, 0, 0, 0};
    double re[N], im[N];

    for (int k = 0; k < N; k++)
    {
        re[k] = 0;
        im[k] = 0;

        for (int n = 0; n < N; n++)
        {
            re[k] += x[n] * cos(2 * PI * n * k / N);
            im[k] -= x[n] * sin(2 * PI * n * k / N);
        }
    }

    printf("Discrete Fourier Transform:\n");

    for (int k = 0; k < N; k++)
    {
        printf("X[%d] = %lf + j%lf\n", k, re[k], im[k]);
    }

    return 0;
}