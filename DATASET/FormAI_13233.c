//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_FREQUENCY 8000
#define PI 3.14159265358979323846

int main()
{
    int n, i;
    double amplitude, frequency, phase, time_signal, sum = 0.0, t;

    printf("Enter the amplitude of the signal: ");
    scanf("%lf", &amplitude);

    printf("Enter the frequency of the signal: ");
    scanf("%lf", &frequency);

    printf("Enter the phase of the signal: ");
    scanf("%lf", &phase);

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    double *x = (double*) malloc(sizeof(double) * n);

    for(i = 0; i < n; ++i)
    {
        t = 1.0 / SAMPLING_FREQUENCY;
        time_signal = i * t;

        x[i] = amplitude * sin(2 * PI * frequency * time_signal + phase);

        sum += x[i];

        printf("%f\n", x[i]);
    }

    printf("Average Amplitude = %f\n", sum/n);

    free(x);

    return 0;
}