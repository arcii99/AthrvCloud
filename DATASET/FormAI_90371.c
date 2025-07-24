//FormAI DATASET v1.0 Category: Audio processing ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUF_SIZE 1024

int main() {
  // Initialize samples buffer
  float samples[BUF_SIZE];

  // Generate sine wave with frequency of 440 Hz
  for (int i = 0; i < BUF_SIZE; i++) {
    samples[i] = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
  }

  // Normalize samples to range of -1 to 1
  float max_sample = 0;
  for (int i = 0; i < BUF_SIZE; i++) {
    if (samples[i] > max_sample) {
      max_sample = samples[i];
    }
  }
  for (int i = 0; i < BUF_SIZE; i++) {
    samples[i] /= max_sample;
  }

  // Apply low-pass filter with cutoff frequency of 2000 Hz
  float cutoff_freq = 2000;
  float RC = 1 / (2 * M_PI * cutoff_freq);
  float alpha = 1 / (1 + RC * SAMPLE_RATE);
  float y_prev = 0;
  float x_prev = 0;
  for (int i = 0; i < BUF_SIZE; i++) {
    float x_curr = samples[i];
    float y_curr = alpha * x_curr + (1 - alpha) * y_prev;
    y_prev = y_curr;
    x_prev = x_curr;
    samples[i] = y_curr;
  }

  // Apply gain of -6 dB
  float gain = pow(10, -6.0/20);
  for (int i = 0; i < BUF_SIZE; i++) {
    samples[i] *= gain;
  }

  // Output samples to file
  FILE* output_file = fopen("output.pcm", "wb");
  fwrite(samples, sizeof(float), BUF_SIZE, output_file);
  fclose(output_file);

  return 0;
}