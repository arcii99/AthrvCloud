//FormAI DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Decentralized style function for processing audio samples
void processAudioSample(float *sample, float sampleRate, float duration) {
  float frequency = 440; // Default frequency of A4 note in Hz
  float sampleIndex = 0;
  float sampleStepSize = frequency / sampleRate;
  float sampleValue = 0;
  int numSamples = sampleRate * duration;

  // Generate a sine wave with the given frequency and sample rate
  for (int i = 0; i < numSamples; i++) {
    sampleValue = sin(sampleIndex * 2 * M_PI);
    sample[i] = sampleValue;
    sampleIndex += sampleStepSize;
  }

  // Normalize the sample values to a range between -1 and 1
  float maxValue = 0;
  for (int i = 0; i < numSamples; i++) {
    if (fabs(sample[i]) > maxValue) {
      maxValue = fabs(sample[i]);
    }
  }
  for (int i = 0; i < numSamples; i++) {
    sample[i] /= maxValue;
  }
}

int main() {
  float sampleRate = 44100; // Default sample rate in Hz
  float duration = 1; // Default duration in seconds
  float *sample = malloc(sampleRate * duration * sizeof(float));

  // Process the audio sample
  processAudioSample(sample, sampleRate, duration);

  // Print the sample values to the console
  for (int i = 0; i < sampleRate * duration; i++) {
    printf("%f\n", sample[i]);
  }

  free(sample);
  return 0;
}