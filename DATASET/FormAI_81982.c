//FormAI DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100     // Sample rate of audio files
#define AMPLITUDE 32767       // Maximum amplitude of audio files

// Function to generate a sine wave
void generateSineWave(float* buffer, int numSamples, float frequency)
{
    float sampleRateInRadians = 2.0f * M_PI * frequency / (float)SAMPLE_RATE;
    float phase = 0.0f;

    for (int i = 0; i < numSamples; i++)
    {
        float sineValue = sin(phase);
        buffer[i] = sineValue * AMPLITUDE;

        phase += sampleRateInRadians;

        // Wrap the phase between 0 and 2*PI
        if (phase > 2.0f * M_PI)
        {
            phase -= 2.0f * M_PI;
        }
    }
}

// Function to apply low/high pass filter
void applyFilter(float* buffer, int numSamples, float cutoffFreq, int isLowPass)
{
    float RC = 1.0f / (2.0f * M_PI * cutoffFreq);
    float dt = 1.0f / SAMPLE_RATE;
    float alpha = RC / (RC + dt);
    float prevOutput = buffer[0];

    for (int i = 1; i < numSamples; i++)
    {
        float input = buffer[i];
        float output;
        if (isLowPass)
        {
            output = alpha * input + (1.0f - alpha) * prevOutput;
        }
        else
        {
            output = alpha * prevOutput + (1.0f - alpha) * input;
        }
        buffer[i] = output;
        prevOutput = output;
    }
}

int main()
{
    // Generate a sine wave of 1000 Hz
    int numSamples = 44100;
    float buffer[numSamples];
    float frequency = 1000.0f;

    generateSineWave(buffer, numSamples, frequency);

    // Apply a low pass filter with a cutoff frequency of 500 Hz
    float cutoffFreq = 500.0f;

    applyFilter(buffer, numSamples, cutoffFreq, 1);

    // Save the processed audio to a file
    FILE* file = fopen("output.bin", "wb");
    fwrite(buffer, sizeof(float), numSamples, file);
    fclose(file);

    return 0;
}