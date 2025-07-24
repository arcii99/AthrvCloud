//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int num_samples = 100;
    double sampling_rate = 44100.0;
    double frequency = 1000.0;
    double amplitude = 1.0;

    double time_step = 1.0 / sampling_rate;
    double max_time = (num_samples - 1) * time_step;

    double *signal = (double*) malloc(num_samples * sizeof(double));

    for (int i = 0; i < num_samples; i++)
    {
        double time = i * time_step;
        double phase = 2.0 * PI * frequency * time;
        double value = amplitude * sin(phase);
        signal[i] = value;
    }

    // Print out the generated signal
    for (int i = 0; i < num_samples; i++)
    {
        printf("%f\n", signal[i]);
    }

    free(signal);
    return 0;
}