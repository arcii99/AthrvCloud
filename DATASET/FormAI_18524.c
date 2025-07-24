//FormAI DATASET v1.0 Category: Audio processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
  // Allocate memory for buffers
  float *in_buffer = (float *) malloc(sizeof(float) * BUFFER_SIZE);
  float *out_buffer = (float *) malloc(sizeof(float) * BUFFER_SIZE);

  // Fill input buffer with random noise
  for(int i = 0; i < BUFFER_SIZE; i++) {
    in_buffer[i] = ((float) rand() / RAND_MAX ) - 0.5; // range from -0.5 to 0.5
  }

  // Apply low-pass filter
  float RC = 1.0 / (2.0 * M_PI * 1000.0); // RC time constant for cutoff frequency of 1000 Hz
  float alpha = 1.0 / (RC + 1.0 / SAMPLE_RATE);
  float prev = 0.0;

  for(int i = 0; i < BUFFER_SIZE; i++) {
    out_buffer[i] = alpha * in_buffer[i] + (1 - alpha) * prev;
    prev = out_buffer[i];
  }

  // Apply amplitude modulation
  float mod_freq = 220; // 220 Hz sine wave
  float mod_amp = 0.5; // 50% modulation depth
  float time = 0.0;

  for(int i = 0; i < BUFFER_SIZE; i++) {
    out_buffer[i] *= (1.0 + mod_amp * sin(2.0 * M_PI * mod_freq * time));
    time += 1.0 / SAMPLE_RATE;
  }

  // Write output buffer to file
  FILE *file = fopen("audio.raw", "wb");
  fwrite(out_buffer, sizeof(float), BUFFER_SIZE, file);
  fclose(file);

  // Free memory
  free(in_buffer);
  free(out_buffer);

  return 0;
}