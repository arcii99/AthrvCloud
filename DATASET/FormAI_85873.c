//FormAI DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

// A function to create a sine wave
void createSineWave(int frequency, float duration, int samplingRate, int amplitude, short int *buffer)
{
    int numSamples = duration * samplingRate; // Calculate the number of samples
    float increment = 2 * M_PI * frequency / samplingRate; // Calculate the phase increment
    
    for (int i = 0; i < numSamples; i++)
    {
        float phase = increment * i; // Calculate the current phase
        buffer[i] = amplitude * sin(phase); // Calculate and store the sample value
    }
}

int main()
{
    int frequency = 440; // Frequency of A4 note
    float duration = 1; // Duration of the note in seconds
    int samplingRate = 44100; // CD-quality sampling rate
    int amplitude = 32767; // Maximum amplitude for 16-bit audio
    
    int numSamples = duration * samplingRate; // Calculate the number of samples
    short int buffer[numSamples]; // Create a buffer to hold the samples
    
    createSineWave(frequency, duration, samplingRate, amplitude, buffer); // Generate a sine wave
    
    // Write the buffer to a file named "A4.wav"
    FILE *file = fopen("A4.wav", "wb");
    fwrite("RIFF", 1, 4, file);
    int fileSize = 36 + numSamples * 2; // Size of the file in bytes
    fwrite(&fileSize, 4, 1, file);
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    int fmtSize = 16; // Size of the format chunk in bytes
    fwrite(&fmtSize, 4, 1, file);
    short int audioFormat = 1; // PCM audio format
    fwrite(&audioFormat, 2, 1, file);
    short int numChannels = 1; // Mono audio
    fwrite(&numChannels, 2, 1, file);
    int sampleRate = samplingRate; // Sampling rate in Hz
    fwrite(&sampleRate, 4, 1, file);
    int byteRate = sampleRate * numChannels * 2; // Bytes per second
    fwrite(&byteRate, 4, 1, file);
    short int blockAlign = numChannels * 2; // Block alignment in bytes
    fwrite(&blockAlign, 2, 1, file);
    short int bitsPerSample = 16; // Bits per sample
    fwrite(&bitsPerSample, 2, 1, file);
    fwrite("data", 1, 4, file);
    fwrite(&numSamples, 4, 1, file);
    fwrite(buffer, 2, numSamples, file);
    fclose(file);
    
    return 0;
}