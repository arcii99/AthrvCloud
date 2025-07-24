//FormAI DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512
#define FREQUENCY 440

int main(void) {
  float amplitude = 0.5; // 50% volume
  float pos = 0; // position in waveform
  int buffer_idx = 0; // position in buffer
  short buffer[BUFFER_SIZE]; // audio buffer
  for (int i = 0; i < BUFFER_SIZE; i++) {
    float sample = amplitude * sin(2 * M_PI * FREQUENCY * pos / SAMPLE_RATE);
    buffer[i] = (short) (sample * 32767); // convert from float to short
    pos++;
  }
  // write buffer to file
  FILE *fp = fopen("audio.raw", "wb");
  fwrite(buffer, sizeof(short), BUFFER_SIZE, fp);
  fclose(fp);
  printf("Audio file written successfully.\n");
  return 0;
}