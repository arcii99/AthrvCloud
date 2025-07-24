//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int frequency = 440; // initial frequency
    int sampling_rate = 44100; // sampling rate
    int duration = 5; // duration in seconds
    int amplitude = 32767; // maximum amplitude of 16-bit audio

    int total_samples = sampling_rate * duration; // total number of audio samples
    int i;

    // allocate memory for output buffer
    short int* output_buffer = (short int*) malloc(sizeof(short int) * total_samples);

    // generate sine wave
    for (i = 0; i < total_samples; i++) {
        double time = (double) i / sampling_rate;
        double angle = 2 * PI * frequency * time;
        short int sample = amplitude * sin(angle);
        output_buffer[i] = sample;
    }

    // write output buffer to file
    FILE* output_file = fopen("output.raw", "wb");
    if (output_file != NULL) {
        fwrite(output_buffer, sizeof(short int), total_samples, output_file);
        fclose(output_file);
    } else {
        printf("Error opening output file.\n");
    }

    free(output_buffer); // free memory for output buffer

    return 0;
}