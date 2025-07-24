//FormAI DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 1000
#define SAMPLING_RATE 44100
#define PI 3.14159265359

int main()
{
    int i;
    double sin_wave[NUM_SAMPLES];
    double square_wave[NUM_SAMPLES];
    double sawtooth_wave[NUM_SAMPLES];

    // Generate a sine wave
    for(i = 0; i < NUM_SAMPLES; i++)
    {
        sin_wave[i] = sin(2 * PI * i * 440 / SAMPLING_RATE);
    }

    // Generate a square wave
    for(i = 0; i < NUM_SAMPLES; i++)
    {
        if(sin_wave[i] > 0)
        {
            square_wave[i] = 1;
        }
        else
        {
            square_wave[i] = -1;
        }
    }

    // Generate a sawtooth wave
    for(i = 0; i < NUM_SAMPLES; i++)
    {
        sawtooth_wave[i] = 2 * (i % (NUM_SAMPLES / 440)) / (double)(NUM_SAMPLES / 440) - 1;
    }

    // Output the audio data to a file
    FILE *output_file = fopen("output.raw", "wb");
    if(output_file == NULL)
    {
        printf("Error: Could not open output file");
        return 1;
    }

    for(i = 0; i < NUM_SAMPLES; i++)
    {
        fwrite(&sin_wave[i], sizeof(double), 1, output_file);
        fwrite(&square_wave[i], sizeof(double), 1, output_file);
        fwrite(&sawtooth_wave[i], sizeof(double), 1, output_file);
    }

    fclose(output_file);

    return 0;
}