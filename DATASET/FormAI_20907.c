//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

// Function to generate a sine wave
void generateSineWave(double frequency, int duration) {
    int amplitude = 32767; // maximum amplitude for signed 16-bit wave 
    int sampleRate = 44100; // standard sample rate of CD quality audio
    int numSamples = duration * sampleRate;
    double timeStep = 1.0 / sampleRate;
    double y, x;

    // Open file for writing binary data
    FILE *file = fopen("sine_wave.pcm", "wb");

    for(int i = 0; i < numSamples; i++) {
        x = (2 * PI * frequency * i * timeStep);
        y = (amplitude * sin(x));
        int sample = (int)y;
        fwrite(&sample, sizeof(sample), 1, file);
    }

    // Close file
    fclose(file);
    printf("Sine wave generated!\n");
}

// Function to apply low-pass filter
void applyLowPassFilter() {
    // Open file for reading binary data
    FILE *file = fopen("sine_wave.pcm", "rb");
    FILE *outfile = fopen("filtered_wave.pcm", "wb"); 

    int cutoffFrequency = 5000; // cutoff frequency of filter
    int sampleRate = 44100; // standard sample rate of CD quality audio
    int numSamples = 44100; // number of samples to process
    double RC = 1.0 / (cutoffFrequency * 2.0 * PI);
    double dt = 1.0 / sampleRate;
    double alpha = RC / (RC + dt);
    int prevSample = 0;
    int sample;

    while(fread(&sample, sizeof(sample), 1, file)) {
        sample = (int)(alpha * sample + (1.0 - alpha) * prevSample);
        prevSample = sample;
        fwrite(&sample, sizeof(sample), 1, outfile);
        numSamples--;
        if(numSamples <= 0) break; // stop filter after certain number of samples
    }

    // Close files
    fclose(file);
    fclose(outfile);
    printf("Low-pass filter applied!\n");
}

int main() {
    double frequency = 440; // standard A4 note frequency
    int duration = 5; // duration of sine wave in seconds
    generateSineWave(frequency, duration);
    applyLowPassFilter();
    return 0;
}