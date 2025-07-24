//FormAI DATASET v1.0 Category: Audio processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

// Struct for waveform generation parameters
typedef struct
{
    int type;               // Type of waveform (0 = sine, 1 = square, 2 = triangle)
    double amplitude;       // Amplitude of waveform
    double frequency;       // Frequency of waveform
} WaveGen_Params;

// Function to generate waveform samples given waveform parameters and sample rate
void generateWaveform(WaveGen_Params params, int sampleRate, double duration, double **waveform)
{
    int numSamples = (int)(duration * sampleRate);
    *waveform = malloc(sizeof(double) * numSamples);

    double sample, tStep, phase = 0.0;
    int i;

    tStep = 1.0 / sampleRate;

    for (i = 0; i < numSamples; i++)
    {
        switch (params.type)
        {
            case 0:     // Sine wave
                sample = sin(2 * PI * params.frequency * i * tStep + phase);
                break;

            case 1:     // Square wave
                sample = (fmod(i * tStep, 1.0 / params.frequency) < (0.5 / params.frequency)) ? 1.0 : -1.0;
                break;

            case 2:     // Triangle wave
                sample = (fabs(fmod(i * tStep, 2.0 / params.frequency) - (1.0 / params.frequency)) * 4 - 1.0) * pow(-1, ((int)(i * tStep * params.frequency) % 2));
                break;

            default:    // Invalid waveform type
                sample = 0.0;
                break;
        }

        (*waveform)[i] = sample * params.amplitude;
    }
}

int main(int argc, char *argv[])
{
    int sampleRate = 44100;
    int numChannels = 1;
    double duration = 1.0;  // seconds

    WaveGen_Params params;
    params.type = 0;    // Sine wave
    params.amplitude = 0.5;
    params.frequency = 440.0;  // A4

    double *waveform;
    int numSamples = (int)(duration * sampleRate);

    generateWaveform(params, sampleRate, duration, &waveform);

    // Create and write header of WAV file
    FILE *file;
    char filename[100];
    sprintf(filename, "audio_output.wav");
    file = fopen(filename, "wb");

    int bitsPerSample = 16;
    int byteRate = sampleRate * numChannels * bitsPerSample / 8;
    int blockAlign = numChannels * bitsPerSample / 8;
    int dataSize = numSamples * numChannels * bitsPerSample / 8;

    // Write header
    fwrite("RIFF", 1, 4, file);
    fwrite(&dataSize + 36, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    fwrite("\x10\x00\x00\x00", 4, 1, file);     // Subchunk1Size
    fwrite("\x01\x00", 2, 1, file);              // AudioFormat
    fwrite(&numChannels, 2, 1, file);
    fwrite(&sampleRate, 4, 1, file);
    fwrite(&byteRate, 4, 1, file);
    fwrite(&blockAlign, 2, 1, file);
    fwrite(&bitsPerSample, 2, 1, file);
    fwrite("data", 1, 4, file);
    fwrite(&dataSize, 4, 1, file);

    // Write waveform data
    int i, j;
    short sample;
    for (i = 0; i < numSamples; i++)
    {
        for (j = 0; j < numChannels; j++)
        {
            sample = (short)(round(waveform[i] * 32767.0));
            fwrite(&sample, 2, 1, file);
        }
    }

    // Clean up
    free(waveform);
    fclose(file);
    
    return 0;
}