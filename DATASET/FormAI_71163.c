//FormAI DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

int main() {
  // Create buffer
  float buffer[BUFFER_SIZE];

  // Initialize buffer to all zeros
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] = 0.0f;
  }

  // Generate a 440Hz sine wave and add it to the buffer
  for (int i = 0; i < BUFFER_SIZE; i++) {
    float x = sinf(2.0f * PI * 440.0f * i / SAMPLE_RATE);
    buffer[i] += x;
  }

  // Apply gain to the buffer
  float gain = 0.5f;
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer[i] *= gain;
  }

  // Save buffer to a WAV file
  FILE *file = fopen("output.wav", "wb");
  if (file == NULL) {
    printf("Error: Could not open file\n");
    exit(1);
  }
  short int header[] = {
    0x4952,         // "RI"
    0x4646,         // "FF"
    0x2C,           // Size of WAV header
    0x100007,       // WAV format code
    SAMPLE_RATE,    // Sample rate
    SAMPLE_RATE * 1 * sizeof(short int),    // Byte rate
    1 * sizeof(short int),    // Block align
    16,             // Bits per sample
    0x64617461,     // "data"
    BUFFER_SIZE * sizeof(short int)    // Size of data chunk
  };
  fwrite(header, sizeof(header), 1, file);
  for (int i = 0; i < BUFFER_SIZE; i++) {
    short int x = (short int)(buffer[i] * 32767.0f);
    fwrite(&x, sizeof(x), 1, file);
  }
  fclose(file);

  printf("Shockingly, the audio processing example program has been executed successfully without any errors!\n");

  return 0;
}