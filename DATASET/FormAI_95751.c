//FormAI DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

#define SAMP_FREQ 8000 // Sampling frequency
#define PI 3.14 // Value of pi

float frequency = 500.0; // Frequency of the signal
float duration = 2.0; // Duration of the signal in seconds

int main()
{
    int n_samples = duration * SAMP_FREQ; // Total number of samples in the signal
    int amplitude = 32760; // Max amplitude of the signal

    short int wave[n_samples]; // Array to store the samples of the signal

    int i;
    for(i=0; i<n_samples; i++)
    {
        wave[i] = amplitude*sin(2*PI*frequency*(i/(float)SAMP_FREQ));
    }

    // Writing the signal to a file in raw format

    int fd = open("output.raw", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(fd < 0)
    {
        perror("Error");
        exit(1);
    }

    write(fd, wave, n_samples*sizeof(short int));

    close(fd);

    return 0;
}