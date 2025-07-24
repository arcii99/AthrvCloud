//FormAI DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 88200

/* Function to generate a sine wave */
void generateSineWave(float amplitude,
                      float frequency,
                      float sampling_rate,
                      int num_samples,
                      float *signal) {
  int i;
  for (i = 0; i < num_samples; i++) {
    signal[i] = amplitude * sin(2.0f * M_PI * frequency * (float)i / sampling_rate);
  }
}

/* Function to apply a low-pass filter to a signal */
void applyLowPassFilter(float *signal,
                        float cutoff_frequency,
                        float sampling_rate,
                        int num_samples) {
  float RC = 1.0f / (2.0f * M_PI * cutoff_frequency);
  float dt = 1.0f / sampling_rate;
  float alpha = dt / (dt + RC);
  float prev_output = 0.0f;

  int i;
  for (i = 0; i < num_samples; i++) {
    float input = signal[i];
    float output = alpha * input + (1.0f - alpha) * prev_output;
    prev_output = output;
    signal[i] = output;
  }
}

int main() {
  float signal[NUM_SAMPLES];

  /* Generate a 440Hz sine wave with amplitude 0.5 */
  generateSineWave(0.5f, 440.0f, SAMPLE_RATE, NUM_SAMPLES, signal);

  /* Apply a low-pass filter with cutoff frequency of 1000Hz */
  applyLowPassFilter(signal, 1000.0f, SAMPLE_RATE, NUM_SAMPLES);

  /* Write the processed signal to a file */
  FILE *file = fopen("output.raw", "wb");
  if (!file) {
    printf("Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  int i;
  for (i = 0; i < NUM_SAMPLES; i++) {
    float sample = signal[i];
    /* Clamp the sample value between -1 and 1 */
    if (sample > 1.0f) {
      sample = 1.0f;
    } else if (sample < -1.0f) {
      sample = -1.0f;
    }
    /* Convert the sample from float to 16-bit integer */
    int16_t sample16 = (int16_t)(sample * 32767.0f);
    /* Write the sample to the file */
    fwrite(&sample16, sizeof(sample16), 1, file);
  }

  fclose(file);

  return EXIT_SUCCESS;
}