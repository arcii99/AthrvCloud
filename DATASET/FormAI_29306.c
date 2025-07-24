//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440

float sine_wave(float time)
{
    float radians = time * FREQUENCY * 2 * M_PI;
    return sinf(radians);
}

int main()
{
    float time = 0;
    float sample;
    FILE *output_file = fopen("sine_wave.pcm", "wb");
    
    if(!output_file)
    {
        printf("Error: Could not open output file.");
        return -1;
    }
    
    while (time < 1)
    {
        sample = sine_wave(time);
        fwrite(&sample, sizeof(sample), 1, output_file);
        time += 1.0 / SAMPLE_RATE;
    }

    fclose(output_file);
    return 0;
}