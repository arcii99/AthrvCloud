//FormAI DATASET v1.0 Category: Audio processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793238462 

int main()
{
    // Declare and initialize variables
    int bufferSize = 1024;
    int sampleRate = 44100;
    float frequency = 440; // in Hz
    float phase = 0;
    float amplitude = 1.0;
    
    // Allocate memory for input and output buffers
    float* inputBuffer = (float*) malloc(bufferSize * sizeof(float));
    float* outputBuffer = (float*) malloc(bufferSize * sizeof(float));

    // Generate a sine wave of the desired frequency
    for (int i = 0; i < bufferSize; i++)
    {
        float currentSample = amplitude * sin(2 * PI * frequency * i / sampleRate + phase);
        inputBuffer[i] = currentSample;
    }
    
    // Apply a low-pass filter to the input signal
    for (int i = 1; i < bufferSize; i++)
    {
        outputBuffer[i] = inputBuffer[i] + 0.5 * inputBuffer[i-1];
    }
    
    // Write the output buffer to a file
    FILE* outputFile = fopen("output.wav", "wb");
    for (int i = 0; i < bufferSize; i++)
    {
        fwrite(&outputBuffer[i], sizeof(float), 1, outputFile);
    }
    fclose(outputFile);

    // Free memory used by buffers
    free(inputBuffer);
    free(outputBuffer);

    return 0;
}