//FormAI DATASET v1.0 Category: Digital signal processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535
#define SAMPLE_RATE 44100

int main()
{
    // Define input signal and filter coefficients
    float x[500];
    float h[100];
    float y[500];
    int i, j;
    
    // Generate input signal
    for(i = 0; i < 500; i++)
    {
        x[i] = sin(2 * PI * 440 * i / SAMPLE_RATE);
    }
    
    // Generate filter coefficients
    for(i = 0; i < 100; i++)
    {
        h[i] = 0.5 * (1 - cos(2 * PI * i / 99));
    }
    
    // Apply filter
    for(i = 0; i < 500; i++)
    {
        y[i] = 0;
        for(j = 0; j < 100; j++)
        {
            if(i - j >= 0)
            {
                y[i] += h[j] * x[i - j];
            }
        }
    }
    
    // Print output signal
    for(i = 0; i < 500; i++)
    {
        printf("%f\n", y[i]);
    }

    return 0;
}