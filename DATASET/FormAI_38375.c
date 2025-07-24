//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 16000
#define PI 3.14159265359

float get_sine_wave(int frequency, float time)
{
    float amplitude = 10000.0;
    return amplitude * sin(2.0 * PI * time * frequency);
}

float get_square_wave(int frequency, float time)
{
    float amplitude = 10000.0;
    if (sin(2.0 * PI * time * frequency) >= 0)
        return amplitude;
    else
        return -amplitude;
}

int main()
{
    int i;
    FILE *fp;
    char *filename = "audio_output.raw";
    fp = fopen(filename, "w");
    float time = 0.0;
    float duration = 10.0; // in seconds
    int frequency = 1000;  // in Hz
    int num_samples = SAMPLE_RATE * duration;
    for (i = 0; i < num_samples; i++)
    {
        float sample = get_sine_wave(frequency, time);
        //float sample = get_square_wave(frequency, time);
        fwrite(&sample, sizeof(sample), 1, fp);
        time += 1.0 / SAMPLE_RATE;
    }
    fclose(fp);
    return 0;
}