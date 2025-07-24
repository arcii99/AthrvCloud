//FormAI DATASET v1.0 Category: Digital signal processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440
#define AMPLITUDE 16384

int main()
{
    int num_samples = SAMPLE_RATE;
    short *samples = (short*) malloc(sizeof(short) * num_samples);

    double phase = 0.0;
    double phase_inc = 2.0 * M_PI * FREQUENCY / SAMPLE_RATE;

    for (int i = 0; i < num_samples; i++) {
        double sample = AMPLITUDE * sin(phase);
        samples[i] = (short) sample;

        phase += phase_inc;
        if (phase >= 2.0 * M_PI) {
            phase -= 2.0 * M_PI;
        }
    }

    FILE *file = fopen("sine_wave.pcm", "wb");
    fwrite(samples, sizeof(short), num_samples, file);
    fclose(file);

    free(samples);

    return 0;
}