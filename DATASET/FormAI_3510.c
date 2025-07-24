//FormAI DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

int main()
{
    int frequency, duration, sample_rate;
    double theta, amplitude;
    FILE *file;

    // prompt user for input
    printf("Enter the frequency of the tone in Hz: ");
    scanf("%d", &frequency);
    printf("Enter the duration of the tone in seconds: ");
    scanf("%d", &duration);
    printf("Enter the sample rate in Hz: ");
    scanf("%d", &sample_rate);

    // calculate the number of samples
    int num_samples = duration * sample_rate;

    // open the destination file
    file = fopen("output.raw", "wb");

    // generate the audio signal and write it to file
    for (int i = 0; i < num_samples; i++)
    {
        // calculate the angle theta
        theta = 2 * PI * i * frequency / sample_rate;

        // calculate the amplitude of the sample
        amplitude = sin(theta);

        // write the sample to file
        fwrite(&amplitude, sizeof(double), 1, file);
    }

    // close the file
    fclose(file);

    printf("Done!\n");

    return 0;
}