//FormAI DATASET v1.0 Category: Audio processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define SAMPLE_RATE 16000
#define SAMPLE_SIZE 2
#define NUM_SAMPLES SAMPLE_RATE
#define NUM_CHANNELS 1
#define NUM_BITS 16
#define PI 3.14159

// Function to generate a sine wave with given frequency and amplitude
void generateSineWave(double *buffer, double frequency, double amplitude, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        double t = (double) i / SAMPLE_RATE;
        buffer[i] += amplitude * sin(2 * PI * frequency * t);
    }
}

// Function to add noise to the audio signal
void addNoise(double *buffer, double noiseLevel, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        buffer[i] += noiseLevel * (((double) rand() / RAND_MAX) - 0.5);
    }
}

// Function to apply a low-pass filter to the audio signal
void applyLowPassFilter(double *buffer, double cutoff, int numSamples) {
    double RC = 1.0 / (2 * PI * cutoff);
    double dt = 1.0 / SAMPLE_RATE;
    double alpha = dt / (RC + dt);
    double y = 0;
    for (int i = 0; i < numSamples; i++) {
        double x = buffer[i];
        y += alpha * (x - y);
        buffer[i] = y;
    }
}

int main() {
    // Allocate memory for audio buffer
    double *audioBuffer = (double*) calloc(NUM_SAMPLES, sizeof(double));
    
    // Generate a 1000 Hz sine wave with amplitude 1
    generateSineWave(audioBuffer, 1000, 1, NUM_SAMPLES);
    
    // Add noise with standard deviation 0.1
    addNoise(audioBuffer, 0.1, NUM_SAMPLES);
    
    // Apply a low-pass filter with cutoff frequency 500 Hz
    applyLowPassFilter(audioBuffer, 500, NUM_SAMPLES);
    
    // Write audio buffer to file in WAV format
    FILE *file = fopen("audio.wav", "wb");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    
    // Write WAV file header
    uint16_t numChannels = NUM_CHANNELS;
    uint32_t sampleRate = SAMPLE_RATE;
    uint16_t bitsPerSample = NUM_BITS;
    uint32_t byteRate = sampleRate * numChannels * bitsPerSample / 8;
    uint16_t blockAlign = numChannels * bitsPerSample / 8;
    uint32_t subchunk2Size = NUM_SAMPLES * numChannels * bitsPerSample / 8;
    uint32_t chunkSize = 36 + subchunk2Size;
    fwrite("RIFF", 1, 4, file);
    fwrite(&chunkSize, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    fwrite("\x10\0\0\0", 4, 1, file);
    fwrite(&numChannels, 2, 1, file);
    fwrite(&sampleRate, 4, 1, file);
    fwrite(&byteRate, 4, 1, file);
    fwrite(&blockAlign, 2, 1, file);
    fwrite(&bitsPerSample, 2, 1, file);
    fwrite("data", 1, 4, file);
    fwrite(&subchunk2Size, 4, 1, file);
    
    // Write audio data
    for (int i = 0; i < NUM_SAMPLES; i++) {
        int16_t sample = (int16_t) round(audioBuffer[i] * 32767);
        fwrite(&sample, 2, 1, file);
    }
    
    // Close file and free memory
    fclose(file);
    free(audioBuffer);
    
    return 0;
}