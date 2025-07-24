//FormAI DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512
#define FREQUENCY 440

int main() {

  float buffer[BUFFER_SIZE];
  float phase = 0;
  float increment = 2.0 * M_PI * FREQUENCY / SAMPLE_RATE;

  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = sin(phase);
    phase += increment;
    phase = fmod(phase, 2.0 * M_PI);
  }

  FILE *f = fopen("output.pcm", "wb");
  fwrite(buffer, sizeof(float), BUFFER_SIZE, f);
  fclose(f);
  return 0;

}