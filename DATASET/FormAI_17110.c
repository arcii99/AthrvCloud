//FormAI DATASET v1.0 Category: Audio processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100   // sample rate in Hz
#define DURATION 5          // duration of the sine wave in seconds
#define FREQUENCY 440       // frequency of the sine wave in Hz

int main()
{
    int samples = SAMPLE_RATE * DURATION;
    double frequency = FREQUENCY * 2 * M_PI / SAMPLE_RATE;

    short* waveform = (short*) malloc(samples * sizeof(short));

    for (int i = 0; i < samples; i++) {
        waveform[i] = 32767 * sin(frequency * i);
    }

    FILE* outputfile = fopen("sine_wave.raw", "wb");
    fwrite(waveform, sizeof(short), samples, outputfile);
    fclose(outputfile);

    free(waveform);

    return 0;
}