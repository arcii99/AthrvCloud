//FormAI DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Initialize variables
  int audioSampleRate = 44100;
  int audioBitDepth = 16;
  int audioDataSize = 44100 * audioBitDepth / 8;
  short audioData[audioDataSize];
  double frequency = 440.0;
  double time = 0.0;
  double seconds = 5.0;
  double amplitude = 32767.0;
  double pi = 3.14159265358979323846;

  // Generate a sine wave
  for (int i = 0; i < audioDataSize; i++) {
    audioData[i] = (short)(amplitude * sin(2.0 * pi * frequency * time));
    time += 1.0 / (double)audioSampleRate;
  }

  // Output the audio to a file
  FILE *fout = fopen("output.wav", "wb");
  fwrite("RIFF", 4, 1, fout);
  fwrite(&audioDataSize, 4, 1, fout);
  fwrite("WAVE", 4, 1, fout);
  fwrite("fmt ", 4, 1, fout);
  int fmtSize = 16;
  fwrite(&fmtSize, 4, 1, fout);
  short audioFormat = 1;
  fwrite(&audioFormat, 2, 1, fout);
  short audioChannels = 1;
  fwrite(&audioChannels, 2, 1, fout);
  int audioSampleRateBits = audioSampleRate;
  fwrite(&audioSampleRateBits, 4, 1, fout);
  int byteRate = audioSampleRate * audioBitDepth / 8;
  fwrite(&byteRate, 4, 1, fout);
  short blockAlign = audioBitDepth / 8;
  fwrite(&blockAlign, 2, 1, fout);
  fwrite(&audioBitDepth, 2, 1, fout);
  fwrite("data", 4, 1, fout);
  fwrite(&audioDataSize, 4, 1, fout);
  fwrite(audioData, audioDataSize, 1, fout);
  fclose(fout);

  // Exit the program
  return 0;
}