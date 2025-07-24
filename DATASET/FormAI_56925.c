//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int input, n, i, j;
    float output = 0, temp = 0, sample_rate = 48000, frequency;
    float amplitude = 1, phase_shift;
    float seconds, pi = acos(-1);
    
    printf("Enter the number of samples: ");
    scanf("%d", &n);

    float *x = calloc(n, sizeof(float));
    float *y_i = calloc(n, sizeof(float));
    float *y_q = calloc(n, sizeof(float));
    
    printf("\nEnter the frequency in Hz: ");
    scanf("%f", &frequency);
    
    printf("\nEnter the phase shift in degrees: ");
    scanf("%f", &phase_shift);
    
    seconds = (float)n / sample_rate;

    for(i=0; i<n; i++)
    {
        x[i] = (amplitude * sin(2 * pi * frequency * i / sample_rate + phase_shift));
        temp = x[i] * sin(2 * pi * frequency * i / sample_rate);
        y_q[i] = temp;
        temp = x[i] * cos(2 * pi * frequency * i / sample_rate);
        y_i[i] = temp;
    }
    
    for(i=0; i<n; i++)
    {
        output += (y_i[i] * y_i[i]) + (y_q[i] * y_q[i]);
    }

    output /= n;
    output = sqrt(output);
    
    printf("\nRMS Power of the given input signal is %.7f V", output);
    
    free(x);
    free(y_i);
    free(y_q);

    return 0;
}