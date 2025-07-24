//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265

int main()
{
    int duration = 5; // duration of the sound in seconds
    int num_samples = duration * SAMPLE_RATE;
    short *samples = malloc(sizeof(short) * num_samples); // allocate memory for the samples
    int frequency = 440; // frequency of the sound in Hz
    double amplitude = 32760.0; // maximum amplitude of the sound
    double phase_shift = PI * 2 * frequency / SAMPLE_RATE; // phase shift between samples
    double phase = 0; // initial phase
    
    for (int i = 0; i < num_samples; i++) {
        samples[i] = amplitude * sin(phase); // generate samples using sine wave
        phase += phase_shift; // update phase
    }
    
    FILE *file = fopen("sound.raw", "wb"); // open a binary file for writing
    fwrite(samples, sizeof(short), num_samples, file); // write samples to file
    fclose(file); // close the file
    
    free(samples); // free memory allocated for samples
    
    return 0;
}