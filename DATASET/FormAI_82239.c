//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FRAMESIZE 512
#define SAMPLERATE 44100
#define TWOPI 6.2831853

float sine(float freq, float phase, float *position) {
  float value = sin(TWOPI * freq * (*position) + phase);
  (*position) += 1.0 / SAMPLERATE;
  if (*position >= 1.0) {
    (*position) -= 1.0;
  }
  return value;
}

float noise() {
  return ((float)rand() / (float)RAND_MAX) * 2.0 - 1.0;
}

int main() {
  float buffer[FRAMESIZE];
  float position = 0.0;
  float freq = 440.0;
  float phase = 0.0;
  float amplitude = 0.1;
  float noiseLevel = 0.05;
  int i;

  for (i = 0; i < FRAMESIZE; i++) {
    buffer[i] = sine(freq, phase, &position) * amplitude + noise() * noiseLevel;
  }

  printf("Generated audio samples:\n");
  for (i = 0; i < FRAMESIZE; i++) {
    printf("%f\n", buffer[i]);
  }

  return 0;
}