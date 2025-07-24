//FormAI DATASET v1.0 Category: Digital signal processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLES 1000

int main()
{
    int i;
    float input[SAMPLES], output[SAMPLES];

    // Generate input signal
    for(i=0; i<SAMPLES; i++)
    {
        input[i] = sin(2*M_PI*i/100) + 0.5*sin(4*M_PI*i/100);
    }

    // Apply low-pass filter
    lowPassFilter(input, output);

    // Print output signal
    for(i=0; i<SAMPLES; i++)
    {
        printf("%f\n", output[i]);
    }

    return 0;
}

void lowPassFilter(float input[], float output[])
{
    int i;
    float b[4] = {0.079703, 0.319831, 0.479746, 0.319831};
    float a[4] = {-0.327254, 0.613188, -0.202023, -0.083807};
    float x[4] = {0,0,0,0};
    float y[4] = {0,0,0,0};
    float yout;

    for(i=0; i<SAMPLES; i++)
    {
        yout = b[0]*input[i] + b[1]*x[0] + b[2]*x[1] + b[3]*x[2] - a[1]*y[0] - a[2]*y[1] - a[3]*y[2];
        output[i] = yout;

        // Shift delay lines
        x[2] = x[1];
        x[1] = x[0];
        x[0] = input[i];

        y[2] = y[1];
        y[1] = y[0];
        y[0] = yout;
    }
}