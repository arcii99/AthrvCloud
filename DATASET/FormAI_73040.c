//FormAI DATASET v1.0 Category: Digital signal processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define M 5

int main()
{
    int i,j;
    float input_signal[N], output_signal[M];
    float filter_coeffs[M] = {0.1,0.2,0.3,0.2,0.1};

    // Generate input signal
    for(i=0;i<N;i++)
        input_signal[i] = sin(i*(M_PI/N));

    // Perform filtering
    for(i=0;i<M;i++)
    {
        output_signal[i] = 0;
        for(j=0;j<M;j++)
        {
            if(i-j < 0) continue;
            output_signal[i] += filter_coeffs[j] * input_signal[i-j];

        }
    }

    // Print input signal
    printf("Input signal:\n");
    for(i=0;i<N;i++)
        printf("%f ",input_signal[i]);

    // Print output signal
    printf("\nOutput signal:\n");
    for(i=0;i<M;i++)
        printf("%f ",output_signal[i]);

    return 0;
}