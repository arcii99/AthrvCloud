//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 88200

int main() {
  short int sample[NUM_SAMPLES];
  double frequency = 440.0; // A4 note
  double amplitude = 0.5;
  double duration = 2.0;
  double phase = 0.0;

  // Generate sine wave
  for (int i = 0; i < NUM_SAMPLES; i++) {
    sample[i] = amplitude * sin(2.0 * M_PI * frequency * ((double)i / (double)SAMPLE_RATE) + phase) * 32767.0;
  }

  // Apply low-pass filter
  for (int i = 1; i < NUM_SAMPLES; i++) {
    sample[i] = (sample[i-1] + sample[i]) / 2;
  }

  // Write to WAV file
  FILE *outfile;
  outfile = fopen("output.wav", "wb");
  if (!outfile) {
    printf("Could not open file!\n");
    return 1;
  }

  // Write WAV header
  int byteRate = SAMPLE_RATE * sizeof(short int);
  int blockAlign = sizeof(short int);
  int dataLength = NUM_SAMPLES * sizeof(short int);
  int fileSize = 36 + dataLength;
  char header[] = {
    'R', 'I', 'F', 'F',
    (char)(fileSize & 0xff), (char)(fileSize >> 8 & 0xff),
    (char)(fileSize >> 16 & 0xff), (char)(fileSize >> 24 & 0xff),
    'W', 'A', 'V', 'E',
    'f', 'm', 't', ' ',
    16, 0, 0, 0,
    1, 0,
    1, 0,
    (char)(SAMPLE_RATE & 0xff), (char)(SAMPLE_RATE >> 8 & 0xff),
    (char)(SAMPLE_RATE >> 16 & 0xff), (char)(SAMPLE_RATE >> 24 & 0xff),
    (char)(byteRate & 0xff), (char)(byteRate >> 8 & 0xff),
    (char)(byteRate >> 16 & 0xff), (char)(byteRate >> 24 & 0xff),
    (char)(blockAlign & 0xff), (char)(blockAlign >> 8 & 0xff),
    16, 0,
    'd', 'a', 't', 'a',
    (char)(dataLength & 0xff), (char)(dataLength >> 8 & 0xff),
    (char)(dataLength >> 16 & 0xff), (char)(dataLength >> 24 & 0xff)
  };
  fwrite(header, sizeof(header), 1, outfile);

  // Write data
  fwrite(sample, sizeof(short int), NUM_SAMPLES, outfile);

  // Close file
  fclose(outfile);

  return 0;
}