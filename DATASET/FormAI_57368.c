//FormAI DATASET v1.0 Category: Audio processing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define BUFFER_SIZE 4096

void medievalNoise(unsigned char *buffer, int bufferSize)
{
    srand(time(NULL));
    for(int i = 0; i < bufferSize; i++)
    {
        buffer[i] = rand() % 256;
        buffer[i] = (unsigned char)(buffer[i] * sin(i * (3.14159265359 / 64)));
        buffer[i] = (unsigned char)((buffer[i] * sin(i * (3.14159265359 / 64))) + (rand() % 32));
        buffer[i] = (unsigned char)((buffer[i] * sin(i * (3.14159265359 / 128))) + (rand() % 16));
        buffer[i] = (unsigned char)((buffer[i] * sin(i * (3.14159265359 / 256))) + (rand() % 8));
    }
}

int main()
{
    unsigned char buffer[BUFFER_SIZE];
    medievalNoise(buffer, BUFFER_SIZE);
    FILE *outputFile;
    outputFile = fopen("medieval.wav", "wb");
    // WAV file header
    fprintf(outputFile, "RIFF----WAVEfmt ");
    unsigned int sampleRate = 44100; // CD quality
    unsigned int numChannels = 1; // mono
    unsigned int bitsPerSample = 8;
    unsigned int byteRate = sampleRate * numChannels * bitsPerSample / 8;
    unsigned short blockAlign = numChannels * bitsPerSample / 8;

    fwrite(&sampleRate, 4, 1, outputFile); // sample rate
    fwrite(&numChannels, 2, 1, outputFile); // mono/stereo
    fwrite(&bitsPerSample, 2, 1, outputFile); // bits per sample
    fwrite(&byteRate, 4, 1, outputFile); // byte rate
    fwrite(&blockAlign, 2, 1, outputFile); // block align

    fprintf(outputFile, "data----");
    fwrite(buffer, BUFFER_SIZE, 1, outputFile);
    fclose(outputFile);
    return 0;
}