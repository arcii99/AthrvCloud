//FormAI DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* CONSTANTS */
#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

/* FUNCTION PROTOTYPES */
void process_audio_buffer(float *buffer, int size);

/* MAIN FUNCTION */
int main(void) {
  float buffer[BUFFER_SIZE] = {0.0};
  int i, j;

  for (i = 0; i < 5; i++) {
    /* Simulate incoming audio buffer */
    for (j = 0; j < BUFFER_SIZE; j++) {
      buffer[j] = sin(2 * M_PI * 440 * j / SAMPLE_RATE);
    }

    /* Process audio buffer */
    process_audio_buffer(buffer, BUFFER_SIZE);

    /* Output processed audio buffer */
    for (j = 0; j < BUFFER_SIZE; j++) {
      printf("%f\n", buffer[j]);
    }
  }

  return EXIT_SUCCESS;
}

/* FUNCTION DEFINITIONS */
void process_audio_buffer(float *buffer, int size) {
  int i;

  /* Invert every other sample */
  for (i = 0; i < size; i += 2) {
    buffer[i] = -buffer[i];
  }

  /* Apply gain of 0.5 */
  for (i = 0; i < size; i++) {
    buffer[i] *= 0.5;
  }
}