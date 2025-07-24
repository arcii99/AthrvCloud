//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int sample_rate = 44100;
    int frequency = 440;
    int duration = 5;
    int amplitude = 32767;
    int num_samples = sample_rate * duration;
    double increment = 2.0 * PI * frequency / sample_rate;
    short buffer[num_samples];
    int i;

    for (i = 0; i < num_samples; i++) {
        buffer[i] = amplitude * sin(i * increment);
    }

    FILE *output_file = fopen("output.pcm", "wb");
    fwrite(buffer, sizeof(short), num_samples, output_file);
    fclose(output_file);

    return 0;
}