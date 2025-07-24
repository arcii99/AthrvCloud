//FormAI DATASET v1.0 Category: Digital signal processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_SIZE 1024
#define PI 3.14159265358979323846

int main()
{
    int i, j;
    double sample[SAMPLE_SIZE];
    double amplitude = 1.0;
    double frequency = 1000.0;
    double sampling_rate = 8000.0;
    double time[SAMPLE_SIZE];
    double rectified_sample[SAMPLE_SIZE];
    double filtered_sample[SAMPLE_SIZE];
    double filtered_time[SAMPLE_SIZE];
    double filter_coefficient = 0.1;
    double filter_delay = 0.0;

    // Generate a sine wave signal with given frequency and amplitude
    for(i = 0; i < SAMPLE_SIZE; i++)
    {
        time[i] = (double)i / sampling_rate;
        sample[i] = amplitude * sin(2.0 * PI * frequency * time[i]);
    }

    // Rectify the signal
    for(i = 0; i < SAMPLE_SIZE; i++)
    {
        if(sample[i] < 0.0)
            rectified_sample[i] = -sample[i];
        else
            rectified_sample[i] = sample[i];
    }

    // Apply a low-pass filter to remove high-frequency noise
    for(i = 0; i < SAMPLE_SIZE; i++)
    {
        filter_delay = filter_coefficient * sample[i] + (1.0 - filter_coefficient) * filter_delay;
        filtered_sample[i] = filter_delay;
        filtered_time[i] = (double)i / sampling_rate;
    }

    // Plot the original and filtered signals
    printf("time, sample, rectified, filtered\n");
    for(i = 0; i < SAMPLE_SIZE; i++)
    {
        printf("%f, %f, %f, %f\n", time[i], sample[i], rectified_sample[i], filtered_sample[i]);
    }

    return 0;
}