//FormAI DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

int main()
{
    double x[N], y[N], w[N];
    double pi = 3.14159265359;
    int i, j, k;

    for(i=0; i<N; i++)
    {
        x[i] = sin(2*pi*i/N) + sin(4*pi*i/N);
    }

    for(k=0; k<N; k++)
    {
        w[k] = 0;

        for(j=0; j<N; j++)
        {
            w[k] += x[j] * cos(2*pi*j*k/N);
        }

        y[k] = w[k];
    }

    for(i=0; i<N; i++)
    {
        printf("x[%d] = %lf, y[%d] = %lf\n", i, x[i], i, y[i]);
    }

    return 0;
}