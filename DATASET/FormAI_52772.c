//FormAI DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

// Generate a sine wave
void generateSineWave(float frequency, float amplitude, float* buffer, int bufferSize)
{
    for (int i = 0; i < bufferSize; i++)
    {
        buffer[i] = amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE);
    }
}

// Add two audio buffers
void addAudioBuffers(float* buffer1, float* buffer2, float* outputBuffer, int bufferSize)
{
    for (int i = 0; i < bufferSize; i++)
    {
        outputBuffer[i] = buffer1[i] + buffer2[i];
    }
}

int main(int argc, const char * argv[]) 
{
    float frequency1 = 440; // Hz
    float amplitude1 = 0.5;
    
    float frequency2 = 880; // Hz
    float amplitude2 = 0.25;
    
    float buffer1[BUFFER_SIZE];
    float buffer2[BUFFER_SIZE];
    float outputBuffer[BUFFER_SIZE];
    
    generateSineWave(frequency1, amplitude1, buffer1, BUFFER_SIZE);
    generateSineWave(frequency2, amplitude2, buffer2, BUFFER_SIZE);
    addAudioBuffers(buffer1, buffer2, outputBuffer, BUFFER_SIZE);
    
    // Output the buffer to a file
    FILE* audioFile = fopen("output.raw", "wb");
    fwrite(outputBuffer, sizeof(float), BUFFER_SIZE, audioFile);
    fclose(audioFile);
    
    return 0;
}