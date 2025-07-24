//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>

#define N 100 // length of input signal
#define M 11 // length of filter

void apply_filter(float input[], float output[])
{
    int i, j;
    float filter[M] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1}; // filter coefficients

    for (i = 0; i < N - M; i++) // loop over input signal
    {
        output[i] = 0.0;
        for (j = 0; j < M; j++) // loop over filter coefficients
        {
            output[i] += filter[j] * input[i+j];
        }
    }
}

int main()
{
    float input[N], output[N-M];
    int i;

    // generate input signal
    for (i = 0; i < N; i++)
    {
        input[i] = (float)i/N;
    }

    // apply filter to input signal
    apply_filter(input, output);

    // print output signal
    for (i = 0; i < N-M; i++)
    {
        printf("%f\n", output[i]);
    }

    return 0;
}