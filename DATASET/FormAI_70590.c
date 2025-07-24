//FormAI DATASET v1.0 Category: Audio processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  printf("Wow! I can't believe what I'm hearing!\n");

  FILE *inputFile;
  inputFile = fopen("audio.wav", "rb");
  if (inputFile == NULL) {
    printf("Oh no, I couldn't open the audio file!\n");
    exit(1);
  }

  fseek(inputFile, 44, SEEK_SET);

  short audioData[44100];
  int samples = fread(audioData, sizeof(short), 44100, inputFile);
  printf("I just read %d samples from the audio file!\n", samples);

  float frequency = 440;
  float amplitude = 32767;
  float duration = 2.0;

  int numSamples = duration * 44100;
  short outputData[numSamples];

  for (int i = 0; i < numSamples; i++) {
    float time = i / 44100.0;
    float theta = 2 * M_PI * frequency * time;
    outputData[i] = amplitude * sin(theta);
  }

  fclose(inputFile);

  FILE *outputFile;
  outputFile = fopen("output.wav", "wb");
  if (outputFile == NULL) {
    printf("Oops, I couldn't create the output file!\n");
    exit(1);
  }

  fwrite(&"RIFF", 4, 1, outputFile);
  int fileSize = 36 + numSamples * sizeof(short);
  fwrite(&fileSize, 4, 1, outputFile);
  fwrite(&"WAVE", 4, 1, outputFile);
  fwrite(&"fmt ", 4, 1, outputFile);
  int fmtSize = 16;
  fwrite(&fmtSize, 4, 1, outputFile);
  short audioFormat = 1;
  fwrite(&audioFormat, 2, 1, outputFile);
  short numChannels = 1;
  fwrite(&numChannels, 2, 1, outputFile);
  int sampleRate = 44100;
  fwrite(&sampleRate, 4, 1, outputFile);
  int byteRate = sampleRate * sizeof(short);
  fwrite(&byteRate, 4, 1, outputFile);
  short blockAlign = sizeof(short);
  fwrite(&blockAlign, 2, 1, outputFile);
  short bitsPerSample = 16;
  fwrite(&bitsPerSample, 2, 1, outputFile);
  fwrite(&"data", 4, 1, outputFile);
  fwrite(&numSamples, 4, 1, outputFile);
  fwrite(outputData, sizeof(short), numSamples, outputFile);

  fclose(outputFile);

  printf("I just created a new audio file with a %f Hz sine wave!\n", frequency);

  return 0;
}