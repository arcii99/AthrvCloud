//FormAI DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 100000

double sinWave(double frequency, double duration, double amplitude);

int main() {
    double freq = 440.0; // the frequency of the note played in Hz
    double duration = 2.0; // the duration of the note played in seconds
    double amplitude = 0.5; // the amplitude of the note played
    
    double samples[NUM_SAMPLES];
    double t = 0.0;
    double increment = 1.0 / SAMPLE_RATE;
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        samples[i] = sinWave(freq, duration, amplitude);
        t += increment;
    }
    
    // write data to output file
    FILE *outfile;
    outfile = fopen("output.raw", "wb");
    fwrite(samples, sizeof(double), NUM_SAMPLES, outfile);
    fclose(outfile);
    
    printf("Audio file created successfully!");
    
    return 0;
}

// generates a sin wave based on the given frequency, duration, and amplitude
double sinWave(double frequency, double duration, double amplitude) {
    double radiansPerSec = frequency * 2.0 * M_PI;
    return amplitude * sin(radiansPerSec * duration);
}