//FormAI DATASET v1.0 Category: Digital signal processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // Sample rate in Hz
#define FREQUENCY 440 // Tone frequency in Hz
#define DURATION 1 // Tone duration in seconds

void generate_tone(float frequency, float duration, float* buffer, int sample_rate) {
  const float TAU = 6.283185307179586476925286766559; // Tau constant
  const int SAMPLES = (int)(sample_rate * duration); // Number of samples to generate
  const float increment = frequency * TAU / sample_rate; // Phase increment per sample
  float phase = 0.0; // Current phase of the waveform

  for (int i = 0; i < SAMPLES; i++) {
    buffer[i] = sin(phase);
    phase += increment;
  }
}

int main() {
  printf("Generating sinewave with frequency %d, duration %d s, and sample rate %d Hz...\n", FREQUENCY, DURATION, SAMPLE_RATE);

  // Allocate memory for the buffer
  float* buffer = (float*)malloc(sizeof(float) * SAMPLE_RATE * DURATION);

  // Generate the tone
  generate_tone(FREQUENCY, DURATION, buffer, SAMPLE_RATE);

  // Write the audio data to a file
  FILE* fp = fopen("output.raw", "wb");
  fwrite(buffer, sizeof(float), SAMPLE_RATE * DURATION, fp);
  fclose(fp);

  // Free the buffer
  free(buffer);

  printf("Done!\n");
  return 0;
}