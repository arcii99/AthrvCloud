//FormAI DATASET v1.0 Category: Digital signal processing ; Style: grateful
#include <stdio.h>
#include <math.h>

#define N 32    /* Number of samples */
#define L 11    /* Length of filter tap */

void main()
{
    int i, j;
    float input[N], output[N], h[L], sum;
    float Fs = 1000;    /* Sampling frequency */
    float Fc = 100;     /* Cutoff frequency */

    /* Generate input signal */
    for (i=0; i<N; i++)
    {
        input[i] = sin(2*M_PI*50*(i/Fs)) + sin(2*M_PI*150*(i/Fs));
    }

    /* Generate filter coefficients (rectangular window) */
    for (i=0; i<L; i++)
    {
        h[i] = 1.0/L;
    }

    /* Perform filtering */
    for (i=0; i<N; i++)
    {
        sum = 0;
        for (j=0; j<L; j++)
        {
            /* Check for boundary condition */
            if (i-j < 0)
            {
                sum += h[j]*input[0];
            }
            else
            {
                sum += h[j]*input[i-j];
            }
        }
        output[i] = sum;
    }

    /* Display results */
    printf("Input signal:\n");
    for (i=0; i<N; i++)
    {
        printf("%f ", input[i]);
    }
    printf("\n\n");

    printf("Output signal:\n");
    for (i=0; i<N; i++)
    {
        printf("%f ", output[i]);
    }
    printf("\n\n");
}