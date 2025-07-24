//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N = 128;
    int k, n;
    float x[N], y[N], z[N];

    printf("Generate a happy sine wave!\n");

    for (n = 0; n < N; n++)
    {
        x[n] = sin(2 * M_PI * n / N * 4) * 0.5 + 0.5;
    }

    for (k = 0; k < N; k++)
    {
        float Re = 0, Im = 0;

        for (n = 0; n < N; n++)
        {
            float angle = 2 * M_PI * n * k / N;
            Re += x[n] * cos(angle);
            Im -= x[n] * sin(angle);
        }

        y[k] = sqrt(Re*Re + Im*Im);
        z[k] = atan2(Im, Re);
    }

    printf("The Happy DFT\n");
    printf("k\t|Y[k]|\t\targ(Y[k])\n");
    for (k = 0; k < N; k++)
    {
        printf("%d\t%0.4f\t%0.4f\n", k, y[k], z[k]);
    }

    return 0;
}