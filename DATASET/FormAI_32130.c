//FormAI DATASET v1.0 Category: Audio processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define AMPLITUDE 30000

int main()
{
    int total_samples = SAMPLE_RATE * DURATION;

    // Create a buffer to hold the audio data
    short *buffer = (short*)malloc(total_samples * sizeof(short));

    // Generate a sine wave at 440 Hz
    double frequency = 440;
    for (int i = 0; i < total_samples; i++) {
        double time = (double)i / SAMPLE_RATE;
        double sine_wave = sin(2 * M_PI * frequency * time);
        buffer[i] = (short)(AMPLITUDE * sine_wave);
    }

    // Apply a low-pass filter to the audio data
    double cutoff_frequency = 1000;
    double RC = 1 / (2 * M_PI * cutoff_frequency);
    double dt = 1 / (double)SAMPLE_RATE;
    double alpha = dt / (dt + RC);
    double prev_sample = 0;
    for (int i = 0; i < total_samples; i++) {
        double sample = (double)buffer[i] / AMPLITUDE;
        double filtered_sample = alpha * sample + (1 - alpha) * prev_sample;
        buffer[i] = (short)(filtered_sample * AMPLITUDE);
        prev_sample = filtered_sample;
    }

    // Save the audio data to a file
    FILE *file = fopen("output.pcm", "wb");
    fwrite(buffer, sizeof(short), total_samples, file);
    fclose(file);

    free(buffer);
    
    return 0;    
}