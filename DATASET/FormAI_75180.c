//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <math.h>

// Define constants
#define SAMPLE_RATE 44100
#define MAX_SIGNAL 32767
#define MIN_SIGNAL -32768

// Define variables
int frequency = 440; // default frequency of 440Hz
float amplitude = 0.5; // default amplitude of 0.5
float duration = 1.0; // default duration of 1 second

// Define function to generate sine wave
void generateSineWave(short* buffer, int samples)
{
  int i;
  float period = SAMPLE_RATE / frequency;
  for(i = 0; i < samples; i++)
  {
    float angle = (i / period) * M_PI * 2;
    buffer[i] = (short)(sin(angle) * amplitude * MAX_SIGNAL);
  }
}

// Define function to write to file in WAV format
void writeWavFile(char* filename, short* buffer, int samples)
{
  FILE* file = fopen(filename, "wb");
  if(file)
  {
    // Define WAV header
    char chunkId[4] = {'R', 'I', 'F', 'F'};
    int chunkSize = samples * sizeof(short) + 36;
    char format[4] = {'W', 'A', 'V', 'E'};
    char subchunk1Id[4] = {'f', 'm', 't', ' '};
    int subchunk1Size = 16;
    short audioFormat = 1;
    short numChannels = 1;
    int sampleRate = SAMPLE_RATE;
    int byteRate = SAMPLE_RATE * sizeof(short);
    short blockAlign = sizeof(short);
    short bitsPerSample = sizeof(short) * 8;
    char subchunk2Id[4] = {'d', 'a', 't', 'a'};
    int subchunk2Size = samples * sizeof(short);

    // Write header to file
    fwrite(chunkId, 1, 4, file);
    fwrite(&chunkSize, 4, 1, file);
    fwrite(format, 1, 4, file);
    fwrite(subchunk1Id, 1, 4, file);
    fwrite(&subchunk1Size, 4, 1, file);
    fwrite(&audioFormat, 2, 1, file);
    fwrite(&numChannels, 2, 1, file);
    fwrite(&sampleRate, 4, 1, file);
    fwrite(&byteRate, 4, 1, file);
    fwrite(&blockAlign, 2, 1, file);
    fwrite(&bitsPerSample, 2, 1, file);
    fwrite(subchunk2Id, 1, 4, file);
    fwrite(&subchunk2Size, 4, 1, file);

    // Write data to file
    fwrite(buffer, sizeof(short), samples, file);

    // Close file
    fclose(file);
  }
}

int main()
{
  int samples = duration * SAMPLE_RATE; // calculate number of samples based on duration
  short buffer[samples]; // create buffer to hold samples
  generateSineWave(buffer, samples); // generate sine wave
  writeWavFile("example.wav", buffer, samples); // write sine wave to file
  return 0;
}